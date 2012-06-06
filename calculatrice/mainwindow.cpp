#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ClavierNumerique();
    ClavierSignes();

    //fenetre
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ClavierNumerique(){
    QObject::connect(ui->b0, SIGNAL(clicked()), this, SLOT(Num0Pressed()));
    QObject::connect(ui->b1, SIGNAL(clicked()), this, SLOT(Num1Pressed()));
    QObject::connect(ui->b2, SIGNAL(clicked()), this, SLOT(Num2Pressed()));
    QObject::connect(ui->b3, SIGNAL(clicked()), this, SLOT(Num3Pressed()));
    QObject::connect(ui->b4, SIGNAL(clicked()), this, SLOT(Num4Pressed()));
    QObject::connect(ui->b5, SIGNAL(clicked()), this, SLOT(Num5Pressed()));
    QObject::connect(ui->b6, SIGNAL(clicked()), this, SLOT(Num6Pressed()));
    QObject::connect(ui->b7, SIGNAL(clicked()), this, SLOT(Num7Pressed()));
    QObject::connect(ui->b8, SIGNAL(clicked()), this, SLOT(Num8Pressed()));
    QObject::connect(ui->b9, SIGNAL(clicked()), this, SLOT(Num9Pressed()));
}

void MainWindow::Num0Pressed(){ui->lineEdit->setText(ui->lineEdit->text()+"0");}
void MainWindow::Num1Pressed(){ui->lineEdit->setText(ui->lineEdit->text()+"1");}
void MainWindow::Num2Pressed(){ui->lineEdit->setText(ui->lineEdit->text()+"2");}
void MainWindow::Num3Pressed(){ui->lineEdit->setText(ui->lineEdit->text()+"3");}
void MainWindow::Num4Pressed(){ui->lineEdit->setText(ui->lineEdit->text()+"4");}
void MainWindow::Num5Pressed(){ui->lineEdit->setText(ui->lineEdit->text()+"5");}
void MainWindow::Num6Pressed(){ui->lineEdit->setText(ui->lineEdit->text()+"6");}
void MainWindow::Num7Pressed(){ui->lineEdit->setText(ui->lineEdit->text()+"7");}
void MainWindow::Num8Pressed(){ui->lineEdit->setText(ui->lineEdit->text()+"8");}
void MainWindow::Num9Pressed(){ui->lineEdit->setText(ui->lineEdit->text()+"9");}

void MainWindow::ClavierSignes(){
    QObject::connect(ui->bCote, SIGNAL(clicked()), this, SLOT(BCotePressed()));
    QObject::connect(ui->bDollar, SIGNAL(clicked()), this, SLOT(BDollarPressed()));
    QObject::connect(ui->bFact, SIGNAL(clicked()), this, SLOT(BFactPressed()));
    QObject::connect(ui->bVirgule, SIGNAL(clicked()), this, SLOT(BVirgulePressed()));
    QObject::connect(ui->bFois, SIGNAL(clicked()), this, SLOT(BFoisPressed()));
    QObject::connect(ui->bMoins, SIGNAL(clicked()), this, SLOT(BMoinsPressed()));
    QObject::connect(ui->bPlus, SIGNAL(clicked()), this, SLOT(BPlusPressed()));
    QObject::connect(ui->bDivision, SIGNAL(clicked()), this, SLOT(BDivisionPressed()));
    QObject::connect(ui->bEval, SIGNAL(clicked()), this, SLOT(BEvalPressed()));
    QObject::connect(ui->bSpace, SIGNAL(clicked()), this, SLOT(BSpacePressed()));
    QObject::connect(ui->bSup, SIGNAL(clicked()), this->ui->lineEdit, SLOT(clear()));
}

void MainWindow::BCotePressed(){ui->lineEdit->setText(ui->lineEdit->text()+"'");}/// pas de shortcut!!!
void MainWindow::BDollarPressed(){ui->lineEdit->setText(ui->lineEdit->text()+"$");}
void MainWindow::BFactPressed(){ui->lineEdit->setText(ui->lineEdit->text()+"!");}
void MainWindow::BVirgulePressed(){ui->lineEdit->setText(ui->lineEdit->text()+",");}
void MainWindow::BFoisPressed(){ui->lineEdit->setText(ui->lineEdit->text()+"* ");}
void MainWindow::BMoinsPressed(){ui->lineEdit->setText(ui->lineEdit->text()+"- ");}
void MainWindow::BPlusPressed(){ui->lineEdit->setText(ui->lineEdit->text()+"+ ");}
void MainWindow::BDivisionPressed(){ui->lineEdit->setText(ui->lineEdit->text()+"/ ");}
void MainWindow::BEvalPressed(){ui->lineEdit->setText("ok");}//EmpilerPileAffichage(ui->lineEdit));}
void MainWindow::BSpacePressed(){ui->lineEdit->setText(ui->lineEdit->text()+" ");}

//void MainWindow::EmpilerPileAffichage(QLineEdit line){


//}
