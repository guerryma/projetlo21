#include <QtGui/QApplication>
#include "mainwindow.h"
#include <typeinfo>
#include "expression.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

  Complexe* c= new Complexe(5,0);
  QString op("+");
//   Complexe* d=new Complexe(2,-1);


//    Complexe* e=c->Somme(d);

   Expression e2("'1 1 +'");
   Expression* e3= e2.ConcatenerDevant("LN");
   std::cout<<e3->Afficher().toStdString();




//    std::cout<<e->Afficher().toStdString()<<"\n";




    return a.exec();
}
