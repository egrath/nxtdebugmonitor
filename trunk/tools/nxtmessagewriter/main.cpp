#include <QtCore/QDebug>

#include "NXTMessage.h"
#include "SerialPortWriter.h"

static char *g_ExecName;

void printHelp();

int main( int argc, char **argv )
{
    g_ExecName = argv[0];
    if( argc != 2 )
    {
        printHelp();
        return -1;
    }

    NXTMessage *msg = new NXTMessage( argv[1] );
    SerialPortWriter *writer = 0;

    try
    {
        writer = new SerialPortWriter();
    }
    catch( QString &exception )
    {
        qDebug() << "got exception: " << exception;
        return -1;
    }

    msg->dumpToConsole();
    writer->sendData( msg->getMessageBytes() );

    delete writer;
    delete msg;
}

void printHelp()
{
    qDebug() << "NXTMessageWriter - send NXT formatted Mailbox message to serial port";
    qDebug() << "usage:" << g_ExecName << "<message>";
}
