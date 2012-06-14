#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), m_calc(new Calculatrice(10, DEGRE, ENTIER))
{
    ui->setupUi(this);
    ClavierNumerique();
    ClavierSignes();
    ClavierPile();
    ClavierOperateurUnaire();
    ClavierAutresFonctions();

    //fenetre
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));



    //paramètrage
    ui->bEntier->setChecked(true);
    ui->bDegre->setChecked(true);
    ui->nbOpPile->setText(QString::number(m_calc->GetTaille()));
    ui->pile->setMaximumBlockCount(m_calc->GetTaille());
    QObject::connect(ui->Complexe, SIGNAL(toggled(bool)),this,SLOT(BComplexeChecked(bool)));

}


MainWindow::~MainWindow()
{
    delete ui;
    delete m_calc;
}

//Gestion des erreurs
void MainWindow::Erreur(QString raison){
    ui->lineEdit->setText(raison);
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
    QObject::connect(ui->bEnter, SIGNAL(clicked()), this, SLOT(BEnterPressed2()));
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
    ui->lineEdit->setText(ui->lineEdit->text()+"! ");
}

void MainWindow::BVirgulePressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+",");
}

void MainWindow::BFoisPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->OperationBinaire('*'))
            MajVuePile();


    }
    else ui->lineEdit->text().append('*');

}

void MainWindow::BMoinsPressed(){
    if (ui->lineEdit->text().isEmpty()){

         ui->lineEdit->setText("-");
    }
         else if(ui->lineEdit->text()=="-"){
         if(m_calc->OperationBinaire('-'))
             MajVuePile();
         ui->lineEdit->clear();

    }
    else ui->lineEdit->text().append('-');

}

void MainWindow::BPlusPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->OperationBinaire('+'))
            MajVuePile();


    }
    else ui->lineEdit->text().append('+');



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
    QObject::connect(ui->nbOpPile, SIGNAL(editingFinished()), this, SLOT(ReglerParamX()));

}

void MainWindow::BSwapPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("SWAP");
}

void MainWindow::BSumPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("SUM");
}

void MainWindow::BMeanPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("MEAN");
}

void MainWindow::BClearPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("CLEAR");
}

void MainWindow::BDupPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("DUP");
}

void MainWindow::BDropPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText("DROP");
}

void MainWindow::ReglerParamX(){
    if(ui->nbOpPile->text() == ""){
        ui->nbOpPile->setText(QString::number(m_calc->GetTaille()));
    }
    ui->pile->setMaximumBlockCount(ui->nbOpPile->text().toInt()+ 1);
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
    ui->lineEdit->setText(ui->lineEdit->text()+"COS ");
}

void MainWindow::BCosHPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"COSH ");
}

void MainWindow::BSinPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"SIN ");
}

void MainWindow::BSinHPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"SINH ");
}

void MainWindow::BTanPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"TAN ");
}

void MainWindow::BTanHPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"TANH ");
}

void MainWindow::BLnPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"LN ");
}

void MainWindow::BLogPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"LOG");
}

void MainWindow::BInvPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"INV ");
}

void MainWindow::BCubePressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"CUBE ");
}

void MainWindow::BSqrtPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"SQRT ");
}

void MainWindow::BSqrPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"SQR ");
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
    ui->lineEdit->setText(ui->lineEdit->text()+"MOD ");
}

void MainWindow::BSignPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"SIGN ");
}

void MainWindow::BPowPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"POW ");
}

void MainWindow::BEvalPressed(){

}

void MainWindow::BEnterPressed(){

    /*! Fonction à déplacer ds calculatrice si temps
      Eventuellement remplacer erreur par l'expression fausse qui doit etre modifiée,
      et envoyer un QMessageBox erreur dans l'expression
*/

    QStack <QString> stack;
    QString s = ui->lineEdit->text();
    QString s2;
    int i = 0;
    QString pRe;
    QString pIm;
    Constante* c;



    //si il y a des espaces avant il faut les supprimer
    if(QString(s[i]).contains(" ")){
        s2 = s;
        s = "";
        while(QString(s2[i]).contains(" ")){
            i++;
        }
        while(s2[i] != '\0'){
            s.append(s2[i]);
            i++;
        }
        s.append('\0');
        s2 = "";
    }

    //si il y a des cotes on empile une expression (la vérif se fait par éval)
    if(s.contains("'")){
        if(QString(s[0]).contains("'") && QString(s[s.size()-1]).contains("'")){
            // Expression e = Expression(s); Ce qui ne marche pas!
            // m_calc->EmpilerPileS(&e);
            //m_calc->EmpilerPileA(s);
            //ui->pile->insertPlainText(s+"\n");
            ui->lineEdit->clear();
            /*
            stack = e.TransformerExpression();
            if(!stack.isEmpty()){
            s2 = stack.first();

            if(QString::compare(s2, "Erreur", Qt::CaseInsensitive) == 0)
                ui->lineEdit->setText("Erreur");
            else
                ui->lineEdit->setText("OK");
            }

            else
                ui->lineEdit->setText("Erreur");
            */
        }

        else ui->lineEdit->setText("Erreur"); // expliquer qu'il manque une cote
        //laisser l'utilisateur corriger
    }

    /*else if(s.contains("+")){
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
            ui->lineEdit->setText("ok +"); //appel a la fonction + de la calculatrice
        }
    }
*/
    else if(s=="+"){
        m_calc->OperationBinaire('+');
        ui->lineEdit->clear();
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
            ui->lineEdit->setText("ok -"); //appel a la fonction - de la calculatrice
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
            ui->lineEdit->setText("ok *"); //appel a la fonction * de la calculatrice
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
            ui->lineEdit->setText("ok /");//appel a la fonction / de la calculatrice(attention voir les modes)
        }
    }
    //! Si on a un complexe

    else if(s.contains("$")){//sinon si ça continet un $
        if(s.count("$") > 1)//s'il n' en a qu'un seul
            ui->lineEdit->setText("Erreur");
        else{//c'est que c'est un complexe
            i = 0;
            while(i < s.size() && s[i] != '$'){//on recupere la partie reelle
                pRe.append(s[i]);
                i++;
            }
            i++;//on saute le $
            while(i < s.size()){//on recupere la partie imaginaire
                pIm.append(s[i]);
                i++;
            }
            c= new Complexe(pRe.toFloat(), pIm.toFloat());

        }
    }

    else if(s.contains(",")){//sinon si ça contient une virgule
        if(s.count(",") > 1) //s'il n'y en a qu'une seule
            ui->lineEdit->setText("Erreur");
        else{//c'est que c'est un reel
            c= new Complexe(s.toFloat());

        }
    }

    else{//sinon c'est que c'est un entier
        while(i < s.size()){
            if(s[i] >= '0' && s[i] <= '9')
                i++;
            else{
                ui->lineEdit->setText("Erreur");
                return;
            }
        }
        c= new Complexe(s.toInt());

    }
    m_calc->EmpilerPileS(c);
    m_calc->EmpilerPileA(s);
    ui->pile->insertPlainText(c->Afficher()+"\n");
    ui->lineEdit->clear();


}

void MainWindow::BEnterPressed2(){
    if(m_calc->MajPileS(ui->lineEdit->text()))
     MajVuePile();
    ui->lineEdit->clear();


}

void MainWindow::MajVuePile(){
    ui->pile->clear();
    /*for(QStack<Constante*>::iterator it=m_calc->GetPileS().begin(); it!=m_calc->GetPileS().end(); it++)*/
    for(int i=0;i<m_calc->GetPileS().size();i++){
        ui->pile->insertPlainText(/*(*it)*/m_calc->GetPileS()[i]->Afficher()+"\n");
    }
}

void  MainWindow::BComplexeChecked(bool b){
    m_calc->SetModeComplexe(b);
}
