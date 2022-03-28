#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <QWidget>
using namespace std;
class TRational
{
        static char SEPARATOR;

        int numerator, denominator;
public:
    TRational();
    TRational(int, int);
    TRational(const int&);
    TRational(const QByteArray&);
    void NOD();

    TRational operator+ (TRational);

    TRational operator* (TRational);
    TRational operator* (int);

    TRational operator/ (TRational);
    TRational operator- (TRational);
    TRational operator- ();
    friend  TRational sqrt(TRational);

    friend  QString& operator<<(QString&, TRational);



    friend QByteArray& operator>>(QByteArray&,TRational&);


    bool operator>= (int);
    bool operator== (int);
    bool operator< (int);

    operator QString ();
    static void setSeparator(char);


    friend ostream& operator<<(ostream&, TRational);
    friend istream& operator>>(istream&, TRational&);


};

#endif // RATIONAL_H
