#include <QtGui/QApplication>
#include "mainwindow.h"
#include "complexe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Complexe c(1,0);
    Complexe d(3,5);

    Complexe e=Somme(c,d);
    std::cout<<e.GetPartieReelle()<<"+ i "<<e.GetPartieImaginaire()<<"\n";

    e=c.Produit(d);

    std::cout<<e.GetPartieReelle()<<"+ i "<<e.GetPartieImaginaire();
    return a.exec();
}
