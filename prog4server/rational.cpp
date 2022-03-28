#include "rational.h"
#include "common.h"
#include <math.h>       /* sqrt */

char TRational::SEPARATOR = separator.toLatin1();

TRational::TRational()
{

}

TRational::TRational(const int& up)
{
    numerator = up;
    denominator = 1;
    this->NOD();
}

TRational::TRational(int up, int down)
{
    numerator = up;
    denominator = down;
    this->NOD();
}
TRational::TRational(const QByteArray& arr)
{
    int p = arr.indexOf(SEPARATOR);
    numerator = arr.left(p).toInt();
    denominator = arr.right(arr.length()-p-1).toInt();
}
void TRational::NOD(){
    int up = abs(numerator);
    int down = abs(denominator);
    if (up == 0) return;
    while (up != down) {
      if (up>down) {
        up = up-down;
      }
      else {
        down = down-up;
      }
    }
    this->numerator = numerator/up;
    this->denominator = denominator/up;
}

TRational TRational::operator+(TRational c)
{
    TRational t;

    t.numerator = c.numerator*denominator+ numerator*c.denominator;
    t.denominator = denominator*c.denominator;
    t.NOD();

    return t;
}

TRational TRational::operator*(TRational c)
{
    TRational t;
    t.numerator = numerator*c.numerator;
    t.denominator = denominator*c.denominator;
    t.NOD();
    return t;
}
TRational TRational::operator*(int c)
{
    TRational t;
    t.numerator = numerator*c;
    t.denominator = denominator;
    t.NOD();
    return t;
}
TRational TRational::operator-(TRational c)
{
    TRational t;
    t.numerator = numerator*c.denominator-c.numerator*denominator;
    t.denominator = denominator*c.denominator;
    t.NOD();
    return t;
}
TRational TRational::operator-()
{
    TRational t;
    t.numerator = -numerator;
    t.denominator = denominator;
    return t;
}
TRational TRational::operator/(TRational c)
{
    TRational t;
    t.numerator = numerator*c.denominator;
    t.denominator = denominator*c.numerator;
    t.NOD();
    return t;
}
bool TRational::operator==(int c)
{
    return denominator*c == numerator ;
}

bool TRational::operator<(int c)
{

    return numerator < denominator * c;
}
bool TRational::operator>=(int c)
{

    return numerator >= denominator * c;
}
TRational sqrt(TRational c)
{
    TRational t;
    t.numerator =  sqrt(c.numerator);
    t.denominator = sqrt(c.denominator);
    t.NOD();
    return t;
}


ostream& operator<<(ostream& os, TRational c){
    os<<c.numerator<<"/"<<c.denominator;
    return os;
}

QString& operator<<(QString& s, TRational c){
    s += QString().setNum(c.numerator);
    s += "/";
    s += QString().setNum(c.denominator);
    return s;
}
istream& operator>>(istream& is, TRational& c){
    is>>c.numerator>>c.denominator;
    while (c.denominator <= 0){
        std::cout << "Denominator must be bigger than zero\n";
        is>>c.numerator>>c.denominator;

    }
    c.NOD();
    return is;
}

TRational::operator QString ()
{
    QString s = "";
    s += QString().setNum(numerator);
    s += "/";
    s += QString().setNum(denominator);
    return s;
}

QByteArray& operator>>(QByteArray& arr, TRational& c)
{
    int p = arr.indexOf(TRational::SEPARATOR);
    p = arr.indexOf(TRational::SEPARATOR,p+1);
    if (p > 0)
    {
        c = TRational(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}

void TRational::setSeparator(char ch)
{
    SEPARATOR = ch;
}

