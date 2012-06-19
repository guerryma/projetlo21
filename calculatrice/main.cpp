#include <QtGui/QApplication>
#include "mainwindow.h"
#include <typeinfo>
#include "expression.h"
#include <QFile>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//  Complexe* c= new Complexe(5,0);
//  QString op("+");
 Complexe* d=new Complexe(2.0,-1.3);




//    Complexe* e=c->Somme(d);

//   Expression e2("'1 1 +'");
//   Expression* e3= e2.ConcatenerDevant("LN");
//   std::cout<<e3->Afficher().toStdString();




//    std::cout<<e->Afficher().toStdString()<<"\n";

QFile test("../out.dat");
test.open(QIODevice::ReadWrite);
QDataStream out(&test);


out<<d;


test.close();

test.open(QIODevice::ReadWrite);

QDataStream in(&test);

Complexe* e= new Complexe(5,3);
in>>e;
test.close();
std::cout<<e->Afficher().toStdString();


// QFile file("../file.dat");
// file.open(QIODevice::ReadWrite);
// QDataStream out(&file);   // we will serialize the data into the file
// out << QString("the answer is");   // serialize a string
// out << (qint32)42;        // serialize an integer
// file.close();
// file.open(QIODevice::ReadWrite);
// QDataStream in(&file);    // read the data serialized from the file
// QString str;
// qint32 z;
// in >> str >> z;           // extract "the answer is" and 42
// file.close();

//std::cout<<str.toStdString()<<z;

    return a.exec();
}
