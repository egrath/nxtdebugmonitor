#include "SerialPortWriter.h"

SerialPortWriter::SerialPortWriter()
{
    // Because this is just a test tool, we use hardcoded variables
    m_PortHandle = CreateFile( L"\\\\.\\COM1", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );
    if( m_PortHandle == INVALID_HANDLE_VALUE )
        throw( QString( "failed to open serial port" ));

    DCB control;
    FillMemory( &control, sizeof( control ), 0 );
    control.DCBlength = sizeof( control );
    if( ! BuildCommDCB( L"COM1: baud=9600 parity=N data=8 stop=1", &control ))
        throw( QString( "failed to build DCB" ));

    if( ! SetCommState( m_PortHandle, &control ))
        throw( QString( "failed to set DCB" ));

    qDebug() << "SerialPortWriter: successfully opened port";
}

SerialPortWriter::~SerialPortWriter()
{
    qDebug() << "SerialPortWriter: closed port";
    CloseHandle( m_PortHandle );
}

void SerialPortWriter::sendData( const QByteArray &data )
{
    if( m_PortHandle == INVALID_HANDLE_VALUE )
        throw( QString( "port not opened" ));

    DWORD numBytesWritten;
    WriteFile( m_PortHandle, data.constData(), data.length(), &numBytesWritten, 0 );
    if(( int ) numBytesWritten != data.length() )
        qDebug() << "SerialPortWriter: failed to send data (input lenth != sent length)";
    else
        qDebug() << "SerialPortWriter: sent" << data.length() << "bytes to port";
}
