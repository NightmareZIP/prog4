#ifndef TPOLINOM_H
#define TPOLINOM_H

#include <QWidget>
#include "number.h"
#include <iostream>
#include <math.h>       /* sqrt */
using namespace std;

enum EPrintMode{
    EPrintModeClassic,
    EPrintModeCanonic,
};

class TPolinom
{
    EPrintMode printMode;
    number a,b,c;
    string first_sign, second_sign;
    number D, first_root, second_root;
public:

    TPolinom(number, number, number);
    friend ostream& operator<<(ostream&, TPolinom&);
    friend QString& operator<<(QString&, TPolinom&);

    number value(number);
    void setPrintMode(EPrintMode);
    void findRoot();
    number get_first_root();
    number get_second_root();
    number get_D();

};

#endif // TPOLINOM_H
