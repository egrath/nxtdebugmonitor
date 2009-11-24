#ifndef SERIALPORTWRITER_H
#define SERIALPORTWRITER_H

#include <windows.h>

#include <QtCore/QDebug>
#include <QtCore/QString>

class SerialPortWriter
{
private:
    HANDLE m_PortHandle;

public:
    SerialPortWriter();
    ~SerialPortWriter();

    void sendData( const QByteArray &data );
};

#endif // SERIALPORTWRITER_H
