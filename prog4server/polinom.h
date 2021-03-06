#ifndef TPOLINOM_H
#define TPOLINOM_H

#include <QWidget>
#include <iostream>
#include <math.h>       /* sqrt */

#include "rational.h"
typedef TRational number;

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
TPolinom::TPolinom(number x, number y, number z)
{
    printMode = EPrintModeClassic;
    a = x;
    b = y;
    c = z;
    if (b >= 0){
            first_sign = '+';
        }
        else{
            first_sign = "";
        }
        if (c >=  0){
            second_sign = '+';
        }
        else{
            second_sign = "";
        }
}
ostream& operator<< (ostream& os, TPolinom& p){
    if (p.printMode == EPrintModeClassic){
        //os<<p.a<<"x^2+"<<p.b<<"x+"<<p.c;
        os<<p.a<<"x^2"<<p.first_sign<<p.b<<"x"<<p.second_sign<<p.c;

    }
    else{
        p.findRoot();
        if (p.D < 0){
            os<<"No roots";
        }
        else{
            os<<p.a<<"(x-"<<p.first_root<<")"<<"(x-"<<p.second_root<<")";
        }
    }
    return os;
}

QString& operator<< (QString& os, TPolinom& p){
    if (p.printMode == EPrintModeClassic){
        //os<<p.a<<"x^2+"<<p.b<<"x+"<<p.c;
        os<<p.a;
        os+="x^2";
        os+= QString::fromStdString(p.first_sign);
        os<<p.b;
        os+="x";
        os+= QString::fromStdString(p.second_sign);
        os<<p.c;

    }
    else{
        p.findRoot();
        if (p.D < 0){
            os += "No roots";
        }
        else{
            os<<p.a;
            os+="(x-";
            os<<p.first_root;
            os+=")(x-";
            os<<p.second_root;
            os+=")";
        }
    }
    return os;
}
number TPolinom::value(number x){
    return a*x*x + b*x + c;
}
void  TPolinom::setPrintMode(EPrintMode m){
   printMode = m;
}
void TPolinom::findRoot(){
    D = b*b-a*c*4;
    if (D >= 0) {
        first_root = (-b-sqrt(D))/(a*2);
        second_root = (-b+sqrt(D))/(a*2);
        if (!(a*first_root*first_root+b*first_root+c == 0 && a*first_root*first_root+b*first_root+c == 0)){
            D = -1; //???? ???????????? ???????? ???????????????? ?????????? ???? ?????????????????????? ?????????????????? ??????????????????
        }
    }

}

number TPolinom::get_D(){
    return D;
}
number TPolinom::get_first_root(){
    return first_root;
}
number TPolinom::get_second_root(){
    return second_root;
}
