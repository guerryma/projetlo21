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

    //param�tres par d�faut
    ui->bEntier->setChecked(true);
    ui->bNon->setChecked(true);
    ui->bDegre->setChecked(true);
    ui->nbOpPile->setText("5");
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

void MainWindow::Num0Pressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"0");
}

void MainWindow::Num1Pressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"1");
}

void MainWindow::Num2Pressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"2");
}

void MainWindow::Num3Pressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"3");
}

void MainWindow::Num4Pressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"4");
}

void MainWindow::Num5Pressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"5");
}

void MainWindow::Num6Pressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"6");
}

void MainWindow::Num7Pressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"7");
}
void MainWindow::Num8Pressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"8");
}

void MainWindow::Num9Pressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"9");
}

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

void MainWindow::BCotePressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"'");
}/// pas de shortcut!!!

void MainWindow::BDollarPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"$");
}

void MainWindow::BFactPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"!");
}

void MainWindow::BVirgulePressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+",");
}

void MainWindow::BFoisPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"* ");
}

void MainWindow::BMoinsPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"- ");
}

void MainWindow::BPlusPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"+ ");
}

void MainWindow::BDivisionPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"/ ");
}

void MainWindow::BSpacePressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+" ");
}

void MainWindow::ClavierPile(){
    QObject::connect(ui->bSwap, SIGNAL(clicked()), this, SLOT(BSwapPressed()));
    QObject::connect(ui->bSum, SIGNAL(clicked()), this, SLOT(BSumPressed()));
    QObject::connect(ui->bMean, SIGNAL(clicked()), this, SLOT(BMeanPressed()));
    QObject::connect(ui->bClear, SIGNAL(clicked()), this, SLOT(BClearPressed()));
    QObject::connect(ui->bDup, SIGNAL(clicked()), this, SLOT(BDupPressed()));
    QObject::connect(ui->bDrop, SIGNAL(clicked()), this, SLOT(BDropPressed()));

}

void MainWindow::BSwapPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Swap");
}

void MainWindow::BSumPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Sum");
}

void MainWindow::BMeanPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Mean");
}

void MainWindow::BClearPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Clear");
}

void MainWindow::BDupPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Dup");
}

void MainWindow::BDropPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Drop");
}


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
void MainWindow::BCosPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Cos");
}

void MainWindow::BCosHPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton CosH");
}

void MainWindow::BSinPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Sin");
}

void MainWindow::BSinHPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton SinH");
}

void MainWindow::BTanPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Tan");
}

void MainWindow::BTanHPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton TanH");
}

void MainWindow::BLnPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Ln");
}

void MainWindow::BLogPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Log");
}

void MainWindow::BInvPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Inv");
}

void MainWindow::BCubePressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Cube");
}

void MainWindow::BSqrtPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Sqrt");
}

void MainWindow::BSqrPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Sqr");
}


void MainWindow::ClavierAutresFonctions(){
    QObject::connect(ui->bMod, SIGNAL(clicked()), this, SLOT(BModPressed()));
    QObject::connect(ui->bSign, SIGNAL(clicked()), this, SLOT(BSignPressed()));
    QObject::connect(ui->bPow, SIGNAL(clicked()), this, SLOT(BPowPressed()));

}
    //Boutons autres fonctions
void MainWindow::BModPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Mod");
}

void MainWindow::BSignPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Sign");
}

void MainWindow::BPowPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("bouton Pow");
}



void MainWindow::BEvalPressed(){
    QString s = ui->lineEdit->text();
    int i = 0;
    QString m_pRe;
    QString m_pIm;

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
        else{
            i = 0;
            while(i < s.size() && s[i] != '$'){
                m_pRe.append(s[i]);
                i++;
            }
            i++;
            while(i < s.size()){
                m_pIm.append(s[i]);
                i++;
            }
            Complexe m_c = Complexe(m_pRe.toFloat(), m_pIm.toFloat());
            m_pStock.push(m_c);
            m_pAff.push(s);
            AfficherStack(ui->nbOpPile->text().toInt());
            ui->lineEdit->clear();
        }
    }

    else if(s.contains(",")){
        if(s.count(",") > 1)
           ui->lineEdit->setText("Erreur");
        else{
            Complexe m_c = Complexe(s.toFloat());
            m_pStock.push(m_c);
            m_pAff.push(s);
            AfficherStack(ui->nbOpPile->text().toInt());
            ui->lineEdit->clear();
        }
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
        Complexe m_c = Complexe(s.toInt());
        m_pStock.push(m_c);
        m_pAff.push(s);
        AfficherStack(ui->nbOpPile->text().toInt());

        ui->lineEdit->clear();


        //ui->lineEdit->setText("entier");
    }

}
void MainWindow::AfficherStack(int m_param){
    QStack<QString> m_stack2;
    QString m_c;
    int i = 0;

    ui->pile->clear();

    while(i < m_param && !m_pAff.isEmpty()){
        m_c = m_pAff.pop();
        m_stack2.push(m_c);
    }

    while(!m_stack2.isEmpty()){
        m_c = m_stack2.pop();
        ui->pile->insertPlainText(m_c+"\n");
        m_pAff.push(m_c);
    }


}

//->setText("ok");}//EmpilerPileAffichage(ui->lineEdit));}

//void MainWindow::EmpilerPileAffichage(QLineEdit line){


//}
