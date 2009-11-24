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
    ctm.ReadIntervalTimeout = 100;
    ctm.ReadTotalTimeoutMultiplier = 0;
    ctm.ReadTotalTimeoutConstant = 0;

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
    DWORD read;

    SetCommMask( m_SerialPortHandle, EV_RXCHAR );

    while( m_Run )
    {
        unsigned char data;
        ReadFile( m_SerialPortHandle, &data, 1, &read, 0 );

        if( data == 0x80 ) // Start of NXT Mailbox message
        {
            qDebug() << "SerialPortListener - have magic 0x80";
            ReadFile( m_SerialPortHandle, &data, 1, &read, 0 );
            if( data == 0x09 ) // Magic Byte 2 ok?
            {
                qDebug() << "SerialPortListener - have magic 0x09";
                ReadFile( m_SerialPortHandle, &data, 1, &read, 0 );
                if( data >= 0x00 && data <= 0x09 ) // Mailbox number ok?
                {
                    qDebug() << "SerialPortListener - have mailbox" << data;
                    ReadFile( m_SerialPortHandle, &data, 1, &read, 0 );
                    int len = ( int ) data;

                    qDebug() << "SerialPortListener - have len" << data;

                    unsigned char *msg = new unsigned char[4+len];
                    ReadFile( m_SerialPortHandle, msg + 4, len, &read, 0 );
                    if( ( int ) read == len )
                    {
                        // Build entire message
                        msg[0] = 0x80;
                        msg[1] = 0x09;
                        msg[2] = 0x00;
                        msg[3] = ( unsigned char ) len;

                        qDebug() << "SerialPortListener - have complete msg";

                        QString m = decoder->decodeMessage( msg, len +4 );
                        emit( messageReceived( m ));
                    }
                    else
                    {
                        qDebug() << "SerialPortHandle - not enought data to complete message";
                    }
                }
            }
        }
    }
#endif

    delete decoder;
}

void SerialPortListener::stopListener()
{
    m_Run = false;
}
