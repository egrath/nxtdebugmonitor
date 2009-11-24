#include "NXTDecoder.h"

QString NXTDecoder::decodeMessage( unsigned char *bytes, unsigned int len )
{
    if( len < 7 )
        return QString();

    qDebug() << "NXTDecoder - decoding message:";
    for( int index = 0; index < ( int ) len; index ++ )
        cout << hex << "[" << ( int ) bytes[index] << "]";
    cout << endl;

    if(( bytes[0] == 0x80 || bytes[0] == 0x00 ) && bytes[1] == 0x09 ) // valid NXT Mailbox message?
    {
        int stringLen = ( int ) bytes[3]; // String length
        if( stringLen == 0 || ( int ) len < stringLen )
            return QString();

        // Read actual message
        unsigned char *buffer = new unsigned char[stringLen];
        for( int index = 0; index < stringLen; index ++ )
        {
            *( buffer + index ) = *( bytes + 4 + index );
        }

        QString message(( char * ) buffer );
        delete buffer;

        qDebug() << "NXTDecoder - decoded message is:" << message;

        return message;
    }    

    return QString();
}
