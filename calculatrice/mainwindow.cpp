#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ClavierNumerique();
    ClavierSignes();
    ClavierPile();
    ClavierOperateurUnaire();
    ClavierAutresFonctions();

    //fenetre
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));

    //paramètres par défaut
    ui->bEntier->setChecked(true);
    ui->bNon->setChecked(true);
    ui->bDegre->setChecked(true);
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
void MainWindow::BSpacePressed(){ui->lineEdit->setText(ui->lineEdit->text()+" ");}

void MainWindow::ClavierPile(){
    QObject::connect(ui->bSwap, SIGNAL(clicked()), this, SLOT(BSwapPressed()));
    QObject::connect(ui->bSum, SIGNAL(clicked()), this, SLOT(BSumPressed()));
    QObject::connect(ui->bMean, SIGNAL(clicked()), this, SLOT(BMeanPressed()));
    QObject::connect(ui->bClear, SIGNAL(clicked()), this, SLOT(BClearPressed()));
    QObject::connect(ui->bDup, SIGNAL(clicked()), this, SLOT(BDupPressed()));
    QObject::connect(ui->bDrop, SIGNAL(clicked()), this, SLOT(BDropPressed()));

}

void MainWindow::BSwapPressed(){ui->lineEdit->setText("bouton Swap");}
void MainWindow::BSumPressed(){ui->lineEdit->setText("bouton Sum");}
void MainWindow::BMeanPressed(){ui->lineEdit->setText("bouton Mean");}
void MainWindow::BClearPressed(){ui->lineEdit->setText("bouton Clear");}
void MainWindow::BDupPressed(){ui->lineEdit->setText("bouton Dup");}
void MainWindow::BDropPressed(){ui->lineEdit->setText("bouton Drop");}


void MainWindow::ClavierOperateurUnaire(){
    QObject::connect(ui->bCos, SIGNAL(clicked()), this, SLOT(BCosPressed()));
    QObject::connect(ui->bCosh, SIGNAL(clicked()), this, SLOT(BCosHPressed()));
    QObject::connect(ui->bSin, SIGNAL(clicked()), this, SLOT(BSinPressed()));
    QObject::connect(ui->bSinh, SIGNAL(clicked()), this, SLOT(BSinHPressed()));
    QObject::connect(ui->bTan, SIGNAL(clicked()), this, SLOT(BTanPressed()));
    QObject::connect(ui->bTanh, SIGNAL(clicked()), this, SLOT(BTanHPressed()));
    QObject::connect(ui->bLn, SIGNAL(clicked()), this, SLOT(BLnPressed()));
    QObject::connect(ui->bLog, SIGNAL(clicked()), this, SLOT(BLogPressed()));
    QObject::connect(ui->bInv, SIGNAL(clicked()), this, SLOT(BInvPressed()));
    QObject::connect(ui->bCube, SIGNAL(clicked()), this, SLOT(BCubePressed()));
    QObject::connect(ui->bSqrt, SIGNAL(clicked()), this, SLOT(BSqrtPressed()));
    QObject::connect(ui->bSqr, SIGNAL(clicked()), this, SLOT(BSqrPressed()));
}
//Boutons Operateurs unaires
void MainWindow::BCosPressed(){ui->lineEdit->setText("bouton Cos");}
void MainWindow::BCosHPressed(){ui->lineEdit->setText("bouton CosH");}
void MainWindow::BSinPressed(){ui->lineEdit->setText("bouton Sin");}
void MainWindow::BSinHPressed(){ui->lineEdit->setText("bouton SinH");}
void MainWindow::BTanPressed(){ui->lineEdit->setText("bouton Tan");}
void MainWindow::BTanHPressed(){ui->lineEdit->setText("bouton TanH");}
void MainWindow::BLnPressed(){ui->lineEdit->setText("bouton Ln");}
void MainWindow::BLogPressed(){ui->lineEdit->setText("bouton Log");}
void MainWindow::BInvPressed(){ui->lineEdit->setText("bouton Inv");}
void MainWindow::BCubePressed(){ui->lineEdit->setText("bouton Cube");}
void MainWindow::BSqrtPressed(){ui->lineEdit->setText("bouton Sqrt");}
void MainWindow::BSqrPressed(){ui->lineEdit->setText("bouton Sqr");}

void MainWindow::ClavierAutresFonctions(){
    QObject::connect(ui->bMod, SIGNAL(clicked()), this, SLOT(BModPressed()));
    QObject::connect(ui->bSign, SIGNAL(clicked()), this, SLOT(BSignPressed()));
    QObject::connect(ui->bPow, SIGNAL(clicked()), this, SLOT(BPowPressed()));

}
    //Boutons autres fonctions
void MainWindow::BModPressed(){ui->lineEdit->setText("bouton Mod");}
void MainWindow::BSignPressed(){ui->lineEdit->setText("bouton Sign");}
void MainWindow::BPowPressed(){ui->lineEdit->setText("bouton Pow");}


void MainWindow::BEvalPressed(){
    QString s = ui->lineEdit->text();
    int i = 0;
    if(s.contains("'")){
        if(QString(s[0]).contains("'") && QString(s[s.size()-1]).contains("'")){
            ui->lineEdit->setText("expression");
        }
        else ui->lineEdit->setText("Erreur");
    }

    else if(s.contains("+")){
        if(s.count("+") > 1)
           ui->lineEdit->setText("Erreur");
        else{
            while(i < s.size()){
                if(QString(s[i]).contains(" ") || QString(s[i]).contains("+"))
                    i++;
                else{
                    ui->lineEdit->setText("Erreur");
                    return;
                }

            }
            ui->lineEdit->setText("ok +");
        }
        //else ui->lineEdit->setText("ok +");
    }

    else if(s.contains("-")){
        if(s.count("-") > 1)
           ui->lineEdit->setText("Erreur");
        else{
            while(i < s.size()){
                if(QString(s[i]).contains(" ") || QString(s[i]).contains("-"))
                    i++;
                else{
                    ui->lineEdit->setText("Erreur");
                    return;
                }

            }
            ui->lineEdit->setText("ok -");
        }
    }

    else if(s.contains("*")){
        if(s.count("*") > 1)
           ui->lineEdit->setText("Erreur");
        else{
            while(i < s.size()){
                if(QString(s[i]).contains(" ") || QString(s[i]).contains("*"))
                    i++;
                else{
                    ui->lineEdit->setText("Erreur");
                    return;
                }

            }
            ui->lineEdit->setText("ok *");
        }
    }

    else if(s.contains("/")){
        if(s.count("/") > 1)
           ui->lineEdit->setText("Erreur");
        else{
            while(i < s.size()){
                if(QString(s[i]).contains(" ") || QString(s[i]).contains("/"))
                    i++;
                else{
                    ui->lineEdit->setText("Erreur");
                    return;
                }

            }
            ui->lineEdit->setText("ok /");
        }
    }

    else if(s.contains("$")){
        if(s.count("$") > 1)
           ui->lineEdit->setText("Erreur");
        else ui->lineEdit->setText("complexe");
    }

    else if(s.contains(",")){
        if(s.count(",") > 1)
           ui->lineEdit->setText("Erreur");
        else ui->lineEdit->setText("réel");
    }

    else{
        while(i < s.size()){
            if(s[i] >= '0' && s[i] <= '9')
                i++;
            else{
                ui->lineEdit->setText("Erreur");
                return;
            }
        }
        ui->lineEdit->setText("entier");
    }

}//->setText("ok");}//EmpilerPileAffichage(ui->lineEdit));}

//void MainWindow::EmpilerPileAffichage(QLineEdit line){


//}
