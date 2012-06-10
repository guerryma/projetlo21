#include <QtGui/QApplication>
#include "mainwindow.h"
#include "complexe.h"
#include <typeinfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

   Complexe *c=new Complexe(5,0);
   Complexe* d=new Complexe(2,-1);

    Complexe* e=c->Somme(d);

    //std::cout<<e.GetPartieReelle()<<"+ i "<<e.GetPartieImaginaire()<<"\n";

   // e=c.Quotient(d);

    //std::cout<<e.GetPartieReelle()<<"+ i "<<e.GetPartieImaginaire();
    std::cout<<e->Afficher().toStdString()<<"\n";
    std::cout<<typeid(e).name();
    return a.exec();
}
