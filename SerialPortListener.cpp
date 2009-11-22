#include "SerialPortListener.h"

const int SerialPortListener::INPUTBUFFER_LEN = 256;

// PRIVATE
void SerialPortListener::openSerialPort()
{
#if WIN32
    QString portName( "\\\\.\\" + m_Settings->getSerialPortName() );
    if(( m_SerialPortHandle = CreateFile( portName.toStdWString().c_str(), GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0 )) ==
       INVALID_HANDLE_VALUE )
    {
        emit( messageReceived( "Failed to open serial port for reading" ));        
    }
    else
    {        
        m_SerialPortOpened = true;    

        // Purge buffers
        PurgeComm( m_SerialPortHandle, PURGE_RXCLEAR );
        PurgeComm( m_SerialPortHandle, PURGE_TXCLEAR );

        if( ! setPortParameters() )
        {
            CloseHandle( m_SerialPortHandle );
            m_SerialPortOpened = false;
            emit( messageReceived( "Failed to set port parameters" ));
        }
        else
        {
            QString message = "\nPort opened successfully: " +
                    m_Settings->getSerialPortName() + "/" +
                    QVariant( m_Settings->getSerialPortSpeed() ).toString() + "/" +
                    QVariant( m_Settings->getSerialPortDatabits() ).toString() + "/" +
                    m_Settings->getSerialPortParity() + "/" +
                    QVariant( m_Settings->getSerialPortStopbits() ).toString();

            emit( messageReceived( message ));
        }
    }    
#endif
}

bool SerialPortListener::setPortParameters()
{
    if( ! m_SerialPortOpened )
        return false;

#if WIN32
    // Set port parameters
    DCB control;
    FillMemory( &control, sizeof( control ), 0 );
    control.DCBlength = sizeof( control );

    QString connectionString;
    connectionString.append( "baud=" + QVariant( m_Settings->getSerialPortSpeed() ).toString() );
    connectionString.append( " parity=" + QVariant( m_Settings->getSerialPortParity()).toString() );
    connectionString.append( " data=" + QVariant( m_Settings->getSerialPortDatabits() ).toString() );
    connectionString.append( " stop=" + QVariant( m_Settings->getSerialPortStopbits() ).toString() );

    qDebug() << connectionString;

    if( ! BuildCommDCB( connectionString.toStdWString().c_str(), &control ))
    {
        emit( messageReceived( "BuildCommDCB" ));
        return false;
    }

    if( ! SetCommState( m_SerialPortHandle, &control ))
    {
        qDebug() << "SerialPortListener - SetCommState error " << GetLastError();
        return false;
    }

    // Set timeout
    COMMTIMEOUTS ctm;
    ctm.ReadIntervalTimeout = 50;
    ctm.ReadTotalTimeoutMultiplier = 500;
    ctm.ReadTotalTimeoutConstant = 50;
    ctm.WriteTotalTimeoutConstant = 50;
    ctm.WriteTotalTimeoutMultiplier = 50;

    if( ! SetCommTimeouts( m_SerialPortHandle, &ctm ))
    {
        emit( messageReceived( "SetCommTimeout" ));
        return false;
    }

    return true;
#endif    
}

// PUBLIC
SerialPortListener::SerialPortListener()
{
    m_SerialPortOpened = false;
    m_Settings = new SettingsManager();
}

SerialPortListener::~SerialPortListener()
{
    qDebug() << "SerialPortListener::dtor";

    if( m_SerialPortOpened )
    {
#if WIN32
        CloseHandle( m_SerialPortHandle );
#endif
    }

    delete m_Settings;
}

void SerialPortListener::run()
{
    qDebug() << "SerialPortListener::run";
    m_Run = true;

    NXTDecoder *decoder = new NXTDecoder();

#if WIN32
    // Win32 version of reading from serial port
    unsigned char* readBuffer = new unsigned char[INPUTBUFFER_LEN+1];
    DWORD read;
    DWORD commEvent;

    SetCommMask( m_SerialPortHandle, EV_RXCHAR );
    while( m_Run )
    {
        if( WaitCommEvent( m_SerialPortHandle, &commEvent, 0 ))
        {
            qDebug() << "SerialPortListener - CommEvent!";

            int bufferPos = 0;
            do
            {
                ReadFile( m_SerialPortHandle, &readBuffer[bufferPos++], 1, &read, 0 );

                // If our internal buffer is full, process it immediatly
                if( bufferPos == INPUTBUFFER_LEN )
                {
                    qDebug() << "SerialPortListener - buffer full, sending now";
                    emit( messageReceived( decoder->decodeMessage( readBuffer, bufferPos )));
                    bufferPos = 0;
                }
            }
            while( read );

            qDebug() << "SerialPortListener - No more to read, emitting";

            // After we have read from the port process
            if( bufferPos > 0 )
            {
                emit( messageReceived( decoder->decodeMessage( readBuffer, bufferPos )));
            }
        }
    }

    delete readBuffer;
#endif

    delete decoder;
}

void SerialPortListener::stopListener()
{
    m_Run = false;
}
