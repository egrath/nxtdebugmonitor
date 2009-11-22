#include "SerialPort.h"

SerialPort * SerialPort::m_Instance;

SerialPort::SerialPort()
{
    m_Ports = new QList<QString>();
}

SerialPort::~SerialPort()
{
    delete m_Ports;
}

void SerialPort::getSerialPorts()
{
    qDebug() << "SerialPort - enumerating ports ...";
    for( int index = 1; index < 255; index ++ )
    {
        QString portName( "COM" + QVariant( index ).toString() );
        HANDLE portHandle;

        if(( portHandle = CreateFile( QString( "\\\\.\\" + portName ).toStdWString().c_str(), GENERIC_READ | GENERIC_WRITE,
                                      0, 0, OPEN_EXISTING, 0, 0 )) != INVALID_HANDLE_VALUE )
        {            
            qDebug() << "valid com port: " << portName;
            m_Ports->push_back( portName );

            CloseHandle( portHandle );
        }
    }
    qDebug() << "SerialPort - enum finished";
}

SerialPort * SerialPort::getInstance()
{
    if( m_Instance == 0 )
    {
        m_Instance = new SerialPort();
        m_Instance->getSerialPorts();
    }

    return m_Instance;
}

void SerialPort::removeInstance()
{
    delete m_Instance;
    m_Instance = 0;
}

QList<QString> & SerialPort::getAvailablePortNames() const
{
    return *m_Ports;
}
