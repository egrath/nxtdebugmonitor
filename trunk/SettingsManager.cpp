#include "SettingsManager.h"

SettingsManager::SettingsManager()
{
    m_Settings = new QSettings( "egrath", "NXT DebugMonitor" );

#if WIN32
    m_SerialPortName = m_Settings->value( "SerialPortName", QVariant( "COM1" )).toString();
#endif
    m_SerialPortSpeed = m_Settings->value( "SerialPortSpeed", QVariant( 9600 )).toInt();
    m_SerialPortDatabits = m_Settings->value( "SerialPortDatabits", QVariant( 8 )).toInt();
    m_SerialPortStopbits =  m_Settings->value( "SerialPortStopbits", QVariant( 1 )).toInt();
    m_SerialPortParity = m_Settings->value( "SerialPortParity", QVariant( "N" )).toString();

    QString fontString = m_Settings->value( "Font", QVariant( QString() )).toString();
    if( ! fontString.isEmpty() )
    {
        QFont fnt;
        fnt.fromString( fontString );
        m_Font = fnt;
    }
    else
        m_Font = QFont();

    qDebug() << "SettingsManager - Port name = " << m_SerialPortName;
    qDebug() << "SettingsManager - Speed = " << m_SerialPortSpeed;
    qDebug() << "SettingsManager - Stopbits = " << m_SerialPortStopbits;
    qDebug() << "SettingsManager - Databits = " << m_SerialPortDatabits;
    qDebug() << "SettingsManager - Parity = " << m_SerialPortParity;
    qDebug() << "SettingsManager - Font = " << m_Font.toString();
}

SettingsManager::~SettingsManager()
{
    delete m_Settings;
}

QString SettingsManager::getSerialPortName() const
{
    return m_SerialPortName;
}

int SettingsManager::getSerialPortSpeed() const
{
    return m_SerialPortSpeed;
}

int SettingsManager::getSerialPortDatabits() const
{
    return m_SerialPortDatabits;
}

int SettingsManager::getSerialPortStopbits() const
{
    return m_SerialPortStopbits;
}

QString SettingsManager::getSerialPortParity() const
{
    return m_SerialPortParity;
}

QFont SettingsManager::getFont() const
{
    return m_Font;
}

void SettingsManager::setSerialPortName( QString &name )
{
    m_SerialPortName = name;
    m_Settings->setValue( "SerialPortName", QVariant( m_SerialPortName ));
}

void SettingsManager::setSerialPortDatabits( int databits )
{
    m_SerialPortDatabits = databits;
    m_Settings->setValue( "SerialPortDatabits", QVariant( databits ));
}

void SettingsManager::setSerialPortStopbits( int stopbits )
{
    m_SerialPortStopbits = stopbits;
    m_Settings->setValue( "SerialPortStopbits", QVariant( stopbits ));
}

void SettingsManager::setSerialPortParity( QString &parity )
{
    m_SerialPortParity = parity;
    m_Settings->setValue( "SerialPortParity", QVariant( parity ));
}

void SettingsManager::setSerialPortSpeed( int speed )
{
    m_SerialPortSpeed = speed;
    m_Settings->setValue( "SerialPortSpeed", QVariant( speed ));
}

void SettingsManager::setFont( QFont &font )
{
    m_Font = font;
    m_Settings->setValue( "Font", QVariant( m_Font.toString() ));
}

void SettingsManager::save()
{
    m_Settings->sync();
}
