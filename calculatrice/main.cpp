#include <QtGui/QApplication>
#include "mainwindow.h"
#include "complexe.h"
#include <typeinfo>
#include <calculatrice.h>

#include "expression.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//   Complexe *c=new Complexe(5,0);
//   Complexe* d=new Complexe(2,-1);


//    Complexe* e=c->Somme(d);

//    Expression e2("'1 1 +'");


//    std::cout<<e->Afficher().toStdString()<<"\n";


    return a.exec();
}
