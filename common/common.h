#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages
{
    VALUE_REQUEST = 1,
    VALUE_ANSWER = 2,
    ROOT_REQUEST = 3,
    PRINT_ROOT = 4 ,
    PRINT_CLASSIC_REQUEST  = 5,
    PRINT_CANONIC_REQUEST = 6,
    PRINT_ANSWER = 7,
};

extern const QChar separator;
QString& operator<< (QString&,const QString&);

#endif // COMMON_H
