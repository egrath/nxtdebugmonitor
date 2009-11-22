#ifndef SERIALPORTLISTENER_H
#define SERIALPORTLISTENER_H

#include <iostream>

#include <QtCore/QDebug>
#include <QtCore/QThread>

#include "SettingsManager.h"
#include "NXTDecoder.h"

#if WIN32
#include <windows.h>
#endif

using std::cout;
using std::endl;
using std::hex;
using std::dec;

class SerialPortListener : public QThread
{
    Q_OBJECT

private:
    static const int INPUTBUFFER_LEN;
    volatile bool m_Run;

#if WIN32
    HANDLE m_SerialPortHandle;
#endif      
    SettingsManager *m_Settings;

    bool m_SerialPortOpened;    
    bool setPortParameters();       

public:
    SerialPortListener();
    ~SerialPortListener();

    void openSerialPort();
    void stopListener();

    // QThread
    virtual void run();

signals:
    void messageReceived( QString message );
};

#endif // SERIALPORTLISTENER_H
