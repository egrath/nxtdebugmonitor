#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QtCore/QDebug>
#include <QtCore/QSettings>
#include <QtGui/QFont>

class SettingsManager
{
private:
    QSettings *m_Settings;
    QString m_SerialPortName;
    int m_SerialPortSpeed;
    int m_SerialPortStopbits;
    int m_SerialPortDatabits;
    QString m_SerialPortParity;
    QFont m_Font;

public:
    SettingsManager();
    ~SettingsManager();

    QString getSerialPortName() const;
    int getSerialPortSpeed() const;
    int getSerialPortDatabits() const;
    int getSerialPortStopbits() const;
    QString getSerialPortParity() const;
    QFont getFont() const;

    void setSerialPortName( QString &name );
    void setSerialPortSpeed( int speed );
    void setSerialPortDatabits( int databits );
    void setSerialPortStopbits( int stopbits );
    void setSerialPortParity( QString &parity );
    void setFont( QFont &font );

    void save();
};

#endif // SETTINGSMANAGER_H
