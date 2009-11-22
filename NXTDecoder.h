#ifndef NXTDECODER_H
#define NXTDECODER_H

#include <iostream>
#include <QtCore/QDebug>
#include <QtCore/QString>

using std::cout;
using std::hex;
using std::endl;

class NXTDecoder
{
public:
    QString decodeMessage( unsigned char *bytes, unsigned int len );
};

#endif // NXTDECODER_H
