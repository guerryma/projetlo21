#include <QtGui/QApplication>
#include "mainwindow.h"
#include "complexe.h"
#include "expression.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Complexe c(5,0);
    Complexe d(2,-1);

    //Expression e2("'1 1 +'");

    Complexe* e=c.Somme(d);

    //std::cout<<e.GetPartieReelle()<<"+ i "<<e.GetPartieImaginaire()<<"\n";

   // e=c.Quotient(d);

    //std::cout<<e.GetPartieReelle()<<"+ i "<<e.GetPartieImaginaire();
    //std::cout<<e->Afficher().toStdString();
    //std::cout<<"ojuhhkkmokllkkkkkkkkkkk";


    return a.exec();
}
