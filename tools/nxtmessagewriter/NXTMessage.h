#ifndef NXTMESSAGE_H
#define NXTMESSAGE_H

#include <iostream>
#include <string>

#include <QtCore/QString>
#include <QtCore/QByteArray>
#include <QtCore/QDebug>

using std::hex;

class NXTMessage
{
private:
    QByteArray *m_Message;

public:
    NXTMessage( const QString &message );
    ~NXTMessage();

    void dumpToConsole();
    const QByteArray & getMessageBytes() const;
};

#endif // NXTMESSAGE_H
