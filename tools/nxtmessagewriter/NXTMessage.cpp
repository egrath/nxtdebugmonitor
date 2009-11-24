#include "NXTMessage.h"

// Private

// Public
NXTMessage::NXTMessage( const QString &message )
{
    m_Message = new QByteArray();

    // Building NXT Mailbox Message
    m_Message->append(( char ) 0x80 ); // Magic Byte 1
    m_Message->append(( char ) 0x09 ); // Magic Byte 2
    m_Message->append(( char ) 0x00 ); // Mailbox (0-9)
    m_Message->append(( char ) message.length() +1 ); // Length of message incl. \0
    m_Message->append( message.toStdString().c_str(), message.length() +1 ); // Actual message as ASCII String
}

NXTMessage::~NXTMessage()
{
    delete m_Message;
}

void NXTMessage::dumpToConsole()
{
    qDebug() << "NXTMessage: total message length is" << m_Message->length();

    for( int index = 0; index < m_Message->length(); index ++ )
    {
        char byte = m_Message->at( index );
        qDebug() << "NXTMessage: Pos" << index << " [" << hex << ( unsigned int ) ( unsigned char ) byte << "] ASCII = " << (( byte >= 32 && byte <= 127 ) ? byte : ' ' );
    }
}

const QByteArray & NXTMessage::getMessageBytes() const
{
    return *m_Message;
}
