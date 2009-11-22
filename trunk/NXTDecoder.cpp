#include "NXTDecoder.h"

QString NXTDecoder::decodeMessage( unsigned char *bytes, unsigned int len )
{
    if( len < 7 )
        return QString();

    qDebug() << "NXTDecoder - decoding message:";
    for( int index = 0; index < len; index ++ )
        cout << hex << "[" << ( int ) bytes[index] << "]";
    cout << endl;

    // Simple method of decoding the NXT Message: Strip first 6 bytes ...
    int rawStringLen = len -8;
    qDebug() << "Message string len: " << rawStringLen;

    unsigned char *msg = new unsigned char[rawStringLen +2];
    memcpy( msg, ( bytes + 6 ), rawStringLen );

    msg[rawStringLen] = '\0';

    QString message(( char * ) msg );
    delete msg;

    return QString( message );
}
