#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), m_calc(new Calculatrice(this)), m_log(new LogSystem()), m_msg(new LogMessage())
{
    ui->setupUi(this);
    MajVuePile();
    ClavierNumerique();
    ClavierVueExecution();
    ClavierPile();
    ClavierOperateurUnaire();
    ClavierOperateurBinaire();
    Parametres();



    //fenetre
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    QObject::connect(ui->actionAnnuler, SIGNAL(triggered()),this,SLOT(Annuler()));
    QObject::connect(ui->actionRetablir, SIGNAL(triggered()),this,SLOT(Retablir()));



    //paramètrage

    if(m_calc->GetType()==REEL)ui->bReel->setChecked(true);
    else if(m_calc->GetType()==RATIONNEL)ui->bRationnel->setChecked(true);
    else if(m_calc->GetType()==ENTIER)ui->bEntier->setChecked(true);

    if(m_calc->GetAngle()==RADIAN)ui->bRadian->setChecked(true);
    else if(m_calc->GetAngle()==DEGRE)ui->bDegre->setChecked(true);


    ui->Complexe->setChecked(m_calc->GetModeComplexe());


    ui->nbOpPile->setText(QString::number(m_calc->GetTaille()));
    ui->pile->setMaximumBlockCount(m_calc->GetTaille());
    QObject::connect(ui->Complexe, SIGNAL(toggled(bool)),this,SLOT(BComplexeChecked(bool)));

}


MainWindow::~MainWindow()
{
    delete ui;
    //delete m_calc;
}

//Gestion des erreurs
void MainWindow::Erreur(QString raison){

    QMessageBox::critical(this, "Erreur", raison);

    m_msg->SetMessage(raison);
    m_msg->SetPriorite(HAUTE);
    m_log->Logger(m_msg);
}
void MainWindow::Attention(QString warning){
    QMessageBox::warning(this, "Attention",warning);


    m_msg->SetMessage(warning);
    m_msg->SetPriorite(HAUTE);
    m_log->Logger(m_msg);
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

    QObject::connect(ui->bCote, SIGNAL(clicked()), this, SLOT(BCotePressed()));
    QObject::connect(ui->bDollar, SIGNAL(clicked()), this, SLOT(BDollarPressed()));
    QObject::connect(ui->bVirgule, SIGNAL(clicked()), this, SLOT(BVirgulePressed()));
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

void MainWindow::BCotePressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"'");
}

void MainWindow::BDollarPressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"$");
}
void MainWindow::BVirgulePressed(){
    if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+",");

}

//Parametres
void MainWindow::Parametres(){
    QObject::connect(ui->bRationnel, SIGNAL(toggled(bool)), this, SLOT(BRationnelChecked(bool)));
    QObject::connect(ui->bReel, SIGNAL(toggled(bool)), this, SLOT(BReelChecked(bool)));
    QObject::connect(ui->bEntier, SIGNAL(toggled(bool)), this, SLOT(BEntierChecked(bool)));
    QObject::connect(ui->bDegre, SIGNAL(toggled(bool)), this, SLOT(BDegreChecked(bool)));
    QObject::connect(ui->bRadian, SIGNAL(toggled(bool)), this, SLOT(BRadianChecked(bool)));
    QObject::connect(ui->nbOpPile, SIGNAL(textChanged(QString)), this, SLOT(ReglerParamX(QString)));

}

void  MainWindow::BComplexeChecked(bool b){
    m_calc->SetModeComplexe(b);
}
void MainWindow::BRationnelChecked(bool b){
    if(b)
        m_calc->SetType(RATIONNEL);
}
void MainWindow::BReelChecked(bool b){
    if(b)
        m_calc->SetType(REEL);
}
void MainWindow::BEntierChecked(bool b){
    if(b)
        m_calc->SetType(ENTIER);
}
void MainWindow::BDegreChecked(bool b){
    if(b)
        m_calc->SetAngle(DEGRE);
}
void MainWindow::BRadianChecked(bool b){
    if(b)
        m_calc->SetAngle(RADIAN);
}
void MainWindow::ReglerParamX(QString n){

    m_calc->SetTaille(n.toInt());
    if(m_calc->GetTaille()!=n.toInt()){

        n=QString::number(m_calc->GetTaille());
        ui->nbOpPile->setText(n);
    }
    ui->pile->setMaximumBlockCount(n.toInt()+ 1);

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
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Swap()){
            MajVuePile();

            m_msg->SetMessage("Swap");
            m_msg->SetPriorite(BASSE);
            m_log->Logger(m_msg);
        }

        else{
            Erreur("Erreur swap");
            MajVuePile();
        }

    }
}

void MainWindow::BSumPressed(){

    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Sum()){
            MajVuePile();

            m_msg->SetMessage("Sum");
            m_msg->SetPriorite(BASSE);
            m_log->Logger(m_msg);
        }

        else{
            Erreur("Erreur sum");
            MajVuePile();
        }
    }
    else Erreur("Erreur sum");
}

void MainWindow::BMeanPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Mean()){
            MajVuePile();

            m_msg->SetMessage("Mean");
            m_msg->SetPriorite(BASSE);
            m_log->Logger(m_msg);
        }

        else{
            Erreur("Erreur mean");
            MajVuePile();
        }
    }
    else Erreur("Erreur mean");
}

void MainWindow::BClearPressed(){
    m_calc->Clear();
    MajVuePile();

    m_msg->SetMessage("Suppression des éléments dans la pile");
    m_msg->SetPriorite(BASSE);
    m_log->Logger(m_msg);
}

void MainWindow::BDupPressed(){
    if(m_calc->Dup())
        MajVuePile();

    //else QMessageBox pas assez d'elements dans la pile
}

void MainWindow::BDropPressed(){
    if(m_calc->Drop())
        MajVuePile();

    //else QMessageBox pas assez d'elements dans la pile
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
    QObject::connect(ui->bSign, SIGNAL(clicked()), this, SLOT(BSignPressed()));
    QObject::connect(ui->bFact, SIGNAL(clicked()), this, SLOT(BFactPressed()));
}
//Boutons Operateurs unaires
void MainWindow::BCosPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Cos())
            MajVuePile();

        else{
            Erreur("Erreur cos");
            MajVuePile();
        }

        if(m_calc->Cos()){
            MajVuePile();
            m_msg->SetMessage("Calcul du cos");
            m_msg->SetPriorite(BASSE);
            m_log->Logger(m_msg);
        }

        else{
            Erreur("Erreur cos");
            MajVuePile();
            m_msg->SetMessage("Erreur calcul du cos");
            m_msg->SetPriorite(HAUTE);
            m_log->Logger(m_msg);
        }
    }
}

void MainWindow::BCosHPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->CosH())
            MajVuePile();

        if(m_calc->CosH()){
            MajVuePile();
            m_msg->SetMessage("Calcul du cosH");
            m_msg->SetPriorite(BASSE);
            m_log->Logger(m_msg);
        }

        else{
            Erreur("Erreur cosh");
            MajVuePile();
        }
    }
}

void MainWindow::BSinPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Sin()){
            MajVuePile();

            m_msg->SetMessage("Calcul du sin");
            m_msg->SetPriorite(BASSE);
            m_log->Logger(m_msg);
        }

        else{
            Erreur("Erreur sin");
            MajVuePile();
        }
    }
}

void MainWindow::BSinHPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->SinH())
            MajVuePile();

        if(m_calc->SinH()){
            MajVuePile();
            m_msg->SetMessage("Calcul du sinH");
            m_msg->SetPriorite(BASSE);
            m_log->Logger(m_msg);
        }


        else{
            Erreur("Erreur sinh");
            MajVuePile();
        }
    }
}

void MainWindow::BTanPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Tan())
            MajVuePile();

        if(m_calc->Tan()){
            MajVuePile();
            m_msg->SetMessage("Calcul de tan");
            m_msg->SetPriorite(BASSE);
            m_log->Logger(m_msg);
        }


        else{
            Erreur("Erreur tan");
            MajVuePile();
        }
    }
}

void MainWindow::BTanHPressed(){
    if (ui->lineEdit->text().isEmpty()){


        if(m_calc->TanH())
            MajVuePile();

        if(m_calc->TanH()){
            MajVuePile();
            m_msg->SetMessage("Calcul de tanH");
            m_msg->SetPriorite(BASSE);
            m_log->Logger(m_msg);
        }

        else{
            Erreur("Erreur tanh");
            MajVuePile();
        }
    }
}

void MainWindow::BLnPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Ln())
            MajVuePile();

        else{
            Erreur("Erreur ln");
            MajVuePile();
        }
    }
}

void MainWindow::BLogPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Log())
            MajVuePile();

        else{
            Erreur("Erreur log");
            MajVuePile();
        }
    }
}

void MainWindow::BInvPressed(){
    if(m_calc->Inverse()) MajVuePile();

}

void MainWindow::BCubePressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Cube())
            MajVuePile();

        else{
            Erreur("Erreur cube");
            MajVuePile();
        }
    }
}

void MainWindow::BSqrtPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Sqrt())
            MajVuePile();

        else{
            Erreur("Erreur sqrt");
            MajVuePile();
        }
    }
}

void MainWindow::BSqrPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Sqr())
            MajVuePile();

        else{
            Erreur("Erreur sqr");
            MajVuePile();
        }
    }
}

void MainWindow::BSignPressed(){
    if(m_calc->Signe()) MajVuePile();
}

void MainWindow::BFactPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Fact())
            MajVuePile();

        else{
            Erreur("Erreur fact");
            MajVuePile();
        }
    }
}

void MainWindow::ClavierOperateurBinaire(){
    QObject::connect(ui->bMod, SIGNAL(clicked()), this, SLOT(BModPressed()));
    QObject::connect(ui->bPow, SIGNAL(clicked()), this, SLOT(BPowPressed()));
    QObject::connect(ui->bFois, SIGNAL(clicked()), this, SLOT(BFoisPressed()));
    QObject::connect(ui->bMoins, SIGNAL(clicked()), this, SLOT(BMoinsPressed()));
    QObject::connect(ui->bPlus, SIGNAL(clicked()), this, SLOT(BPlusPressed()));
    QObject::connect(ui->bDivision, SIGNAL(clicked()), this, SLOT(BDivisionPressed()));

}
//Boutons Opérateurs Binaire
void MainWindow::BModPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Mod())
            MajVuePile();

        else{
            Erreur("Erreur mod");
            MajVuePile();
        }
    }
}

void MainWindow::BFoisPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->OperationBinaire('*'))
            MajVuePile();
        ui->lineEdit->setText(ui->lineEdit->text()+"*");


    }
    else ui->lineEdit->setText(ui->lineEdit->text()+"*");

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
    else ui->lineEdit->setText(ui->lineEdit->text()+"-");

}

void MainWindow::BPlusPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->OperationBinaire('+'))
            MajVuePile();


    }
    else ui->lineEdit->setText(ui->lineEdit->text()+"+");



}

void MainWindow::BDivisionPressed(){
    if (ui->lineEdit->text().isEmpty()){
        try{
            if(m_calc->OperationBinaire('/'))
                MajVuePile();
            else ui->lineEdit->setText(ui->lineEdit->text()+"/");

        }
        catch(RationnelException e){
            Erreur(e.what());
        }
        catch(CalculatriceException e){
            Attention(e.what());
        }
    }

    else ui->lineEdit->setText(ui->lineEdit->text()+"/");
}
void MainWindow::BPowPressed(){
    if (ui->lineEdit->text().isEmpty()){

        if(m_calc->Pow())
            MajVuePile();

        else{
            Erreur("Erreur pow");
            MajVuePile();
        }
    }
}





//Fonctions d'exécution et vue

void MainWindow::ClavierVueExecution(){

    QObject::connect(ui->bEval, SIGNAL(clicked()), this, SLOT(BEvalPressed()));
    QObject::connect(ui->bEnter, SIGNAL(clicked()), this, SLOT(BEnterPressed2()));
    QObject::connect(ui->bSpace, SIGNAL(clicked()), this, SLOT(BSpacePressed()));
    QObject::connect(ui->bSup, SIGNAL(clicked()), this, SLOT(BSupPressed()));
}

void MainWindow::BSupPressed(){
    if(ui->lineEdit->text().isEmpty()){
        m_calc->Drop();
        MajVuePile();

    }
    else if(QString::compare(ui->lineEdit->text(), "Erreur", Qt::CaseInsensitive) == 0)
        ui->lineEdit->clear();
    else{
        QString s = ui->lineEdit->text();
        s.truncate(s.size()-1);
        ui->lineEdit->setText(s);
    }
}

void MainWindow::BSpacePressed(){
    if(!ui->lineEdit->text().isEmpty())
        ui->lineEdit->setText(ui->lineEdit->text()+" ");
}

void MainWindow::BEvalPressed(){
    QString s = ui->lineEdit->text();

    if(s.isEmpty()) {// C'est qu'on cherche à dépiler une constante
        QQueue<QString> tmp;
        if(m_calc->EvalExpression(tmp)) MajVuePile();
    }
    else if (s.startsWith("'") && s.endsWith("'")){
        //Alors on a entré une expression, il faut la construire, la tester et l'évaluer
        Expression* e= new Expression(s);
        QQueue<QString> file= e->TransformerExpression();

        if(m_calc->EvalExpression(file,e)){

            MajVuePile();
            ui->lineEdit->clear();
        }

    }
}


void MainWindow::BEnterPressed2(){
    try{
        if(ui->lineEdit->text().isEmpty()){
            m_calc->Dup();
            MajVuePile();
            m_msg->SetMessage("Dupplication du premier élement de la pile");
            m_msg->SetPriorite(BASSE);
            m_log->Logger(m_msg);

        }

        if(m_calc->MajPileS(ui->lineEdit->text())){
            MajVuePile();
            ui->lineEdit->clear();
        }
    }
    catch(const QString chaine){

        Erreur(chaine);

    }


}

void MainWindow::MajVuePile(){
    ui->pile->clear();
    for(int i=0;i<m_calc->GetPileS().size();i++){
        ui->pile->insertPlainText(m_calc->GetPileS()[i]->Afficher()+"\n");
    }
}
//Sauvegarde du contexte et des paramètres
void MainWindow::closeEvent(QCloseEvent * event){
    m_calc->EnregistrerParametres();
    m_calc->SauvegarderPile();
    delete m_calc;

    event->accept();
}
void MainWindow::Annuler(){
    if(m_calc->Annuler()) MajVuePile();
}
void MainWindow::Retablir(){
    if(m_calc->Retablir()) MajVuePile();
}
