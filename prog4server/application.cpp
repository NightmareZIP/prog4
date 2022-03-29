#include "application.h"
#include "polinom.h"
#include "common.h"

TApplication::TApplication(int argc, char *argv[])
            : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}

void TApplication::recieve(QByteArray msg)
{
    QString answer, s;
    number  a, b, c, x, v;
    msg>>a>>b>>c;
    TPolinom p(a,b,c);
    int pos = msg.indexOf(separator.toLatin1());
    int t = msg.left(pos).toInt();
    switch (t)
    {
        case VALUE_REQUEST:
            msg = msg.right(msg.length()-pos-1);
            msg>>x;
            v = p.value(x);
            s<<(QString)x<<(QString)v;
            answer<<QString().setNum(VALUE_ANSWER);
            answer += s;
            break;
        case PRINT_CLASSIC_REQUEST:
            p.setPrintMode(EPrintModeClassic);
            s<<p;
            answer<<QString().setNum(PRINT_ANSWER)<<s;
            break;

        case PRINT_CANONIC_REQUEST:
            p.setPrintMode(EPrintModeCanonic);
            s<<p;
            answer<<QString().setNum(PRINT_ANSWER)<<s;
            break;

        case ROOT_REQUEST:
            p.findRoot();
            if (p.get_D() < 0){
                s+=QString("No roots");
            }
            else{
                s+=QString("x1 = " + p.get_first_root() + " x2 = " + p.get_second_root());
            }

            answer<<QString().setNum(PRINT_ROOT)<<s;
            break;
        default: return;
        }

    comm->send(answer.toUtf8());
}
