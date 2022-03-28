#include "interface.h"
#include "common.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Работа №4");
    setFixedSize(300,250);

    name_a = new QLabel("a =",this);
    name_a->setGeometry(50,20,30,25);
    a_n = new QLineEdit("1",this);
    a_n->setGeometry(90,20,50,25);
    delimeter_a = new QLabel("/",this);
    delimeter_a->setGeometry(150,20,30,25);
    a_d = new QLineEdit("1",this);
    a_d->setGeometry(190,20,50,25);

    name_b = new QLabel("b =",this);
    name_b->setGeometry(50,50,30,25);
    b_n = new QLineEdit("1",this);
    b_n->setGeometry(90,50,50,25);
    delimeter_b = new QLabel("/",this);
    delimeter_b->setGeometry(150,50,30,25);
    b_d = new QLineEdit("1",this);
    b_d->setGeometry(190,50,50,25);

    name_c = new QLabel("c =",this);
    name_c->setGeometry(50,80,30,25);
    c_n = new QLineEdit("1",this);
    c_n->setGeometry(90,80,50,25);
    delimeter_c = new QLabel("/",this);
    delimeter_c->setGeometry(150,80,30,25);
    c_d = new QLineEdit("1",this);
    c_d->setGeometry(190,80,50,25);

    name_x = new QLabel("x =",this);
    name_x->setGeometry(50,110,30,25);
    x_n = new QLineEdit("1",this);
    x_n->setGeometry(90,110,50,25);
    delimeter_x = new QLabel("/",this);
    delimeter_x->setGeometry(150,110,30,25);
    x_d = new QLineEdit("1",this);
    x_d->setGeometry(190,110,50,25);

    value_btn = new QPushButton("знач.",this);
    value_btn->setGeometry(10,150,60,30);
    root_btn = new QPushButton("корни",this);
    root_btn->setGeometry(80,150,60,30);
    print_classic_btn = new QPushButton("класс.",this);
    print_classic_btn->setGeometry(160,150,60,30);
    print_canonic_btn = new QPushButton("канон.",this);
    print_canonic_btn->setGeometry(230,150,60,30);

    output = new QLabel(this);
    output->setGeometry(10,200,280,25);

    connect(value_btn,SIGNAL(pressed()),
            this,SLOT(formRequest()));
    connect(print_classic_btn,SIGNAL(pressed()),
            this,SLOT(formRequest()));

    connect(print_canonic_btn,SIGNAL(pressed()),
            this,SLOT(formRequest()));
    connect(root_btn,SIGNAL(pressed()),
            this,SLOT(formRequest()));
}

TInterface::~TInterface()
{
    delete a_n;
    delete a_d;
    delete name_a;
    delete delimeter_a;

    delete b_n;
    delete b_d;
    delete name_b;
    delete delimeter_b;

    delete c_n;
    delete c_d;
    delete name_c;
    delete delimeter_c;

    delete x_n;
    delete x_d;
    delete name_x;
    delete delimeter_x;

    delete value_btn;
    delete root_btn;
    delete print_classic_btn;
    delete print_canonic_btn;

    delete output;
}

void TInterface::formRequest()
{
    QString msg;
    msg << a_n->text() << a_d->text();
    msg << b_n->text() << b_d->text();
    msg << c_n->text() << c_d->text();
    QPushButton *btn = (QPushButton*)sender();
    if (btn == value_btn)
    {
        msg << QString().setNum(VALUE_REQUEST);
        msg << x_n->text() << x_d->text();
    }
    if (btn == print_classic_btn)
        msg << QString().setNum(PRINT_CLASSIC_REQUEST);

    if (btn == root_btn)
    {
        msg << QString().setNum(ROOT_REQUEST);
    }

    if (btn == print_canonic_btn)
    {
        msg << QString().setNum(PRINT_CANONIC_REQUEST);
    }
    emit request(msg);
}

void TInterface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);
    switch (t)
    {
        case VALUE_ANSWER:
            text = "p(";
            p = msg.indexOf(separator);
            text += msg.left(p);
            text += ") = ";
            text += msg.right(msg.length()-p-1);
            output->setText(text);
            break;
        case PRINT_ANSWER:
            text = "p(x) = ";
            text += msg;
            output->setText(text);
            break;
        case PRINT_ROOT:
            text = "";
            text += msg;
            output->setText(text);
            //text;
            break;
        default: break;
    }
}
