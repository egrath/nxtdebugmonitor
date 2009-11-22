#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <windows.h>
#include <QtCore/QDebug>
#include <QtCore/QString>
#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QList>

class SerialPort
{
private:
    static SerialPort *m_Instance;
    QList<QString> *m_Ports;

    SerialPort();
    ~SerialPort();
    void getSerialPorts();

public:    
    static SerialPort * getInstance();
    static void removeInstance();
    QList<QString> & getAvailablePortNames() const;
};

#endif // SERIALPORT_H
