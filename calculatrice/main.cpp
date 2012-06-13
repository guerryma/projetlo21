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

   Complexe *c=new Complexe(5,0);
   Complexe* d=new Complexe(2,-1);


    Complexe* e=c->Somme(d);

    Expression e2("'1 1 +'");
        if(EstUnNombre("46")) cout<<"46 est un nombre\n";

        if(EstUnNombre("-46")) cout<<"-46 est un nombre\n";
        if(EstUnNombre("0,46")) cout<<"0.46 est un nombre\n";



    //std::cout<<e.GetPartieReelle()<<"+ i "<<e.GetPartieImaginaire()<<"\n";

   // e=c.Quotient(d);

    //std::cout<<e.GetPartieReelle()<<"+ i "<<e.GetPartieImaginaire();
    std::cout<<e->Afficher().toStdString()<<"\n";
    std::cout<<typeid(e).name();
    //std::cout<<e->Afficher().toStdString();


    return a.exec();
}
