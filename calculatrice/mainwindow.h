#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include "calculatrice.h"
#include <QMessageBox>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    Calculatrice* m_calc;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    //Boutons numeriques de 0-9
    void Num0Pressed();
    void Num1Pressed();
    void Num2Pressed();
    void Num3Pressed();
    void Num4Pressed();
    void Num5Pressed();
    void Num6Pressed();
    void Num7Pressed();
    void Num8Pressed();
    void Num9Pressed();

    //Boutons signes
    void BCotePressed();
    void BDollarPressed();
    void BFactPressed();
    void BVirgulePressed();

    //Boutons opérations binaires
    void BFoisPressed();
    void BMoinsPressed();
    void BPlusPressed();
    void BDivisionPressed();

    void BSpacePressed();
    void BEvalPressed();
    void BEnterPressed2();
    void BSupPressed();


    //Boutons pile
    void BSwapPressed();
    void BSumPressed();
    void BMeanPressed();
    void BClearPressed();
    void BDupPressed();
    void BDropPressed();


    //Boutons Operateurs unaires
    void BCosPressed();
    void BCosHPressed();
    void BSinPressed();
    void BSinHPressed();
    void BTanPressed();
    void BTanHPressed();
    void BLnPressed();
    void BLogPressed();
    void BInvPressed();
    void BCubePressed();
    void BSqrtPressed();
    void BSqrPressed();

    //Boutons autres fonctions
    void BModPressed();
    void BSignPressed();
    void BPowPressed();

    //Parametrage
    void ReglerParamX(QString n);
    void BComplexeChecked(bool b);
    void BDegreChecked(bool b);
    void BRadianChecked(bool b);
    void BReelChecked(bool b);
    void BRationnelChecked(bool b);
    void BEntierChecked(bool b);

protected:
    //Fenetre
    void closeEvent(QCloseEvent *);

public:
    void ClavierNumerique();
    void ClavierVueExecution();
    void ClavierPile();
    void ClavierOperateurUnaire();
    void ClavierOperateurBinaire();
    void Parametres();
    void Erreur(QString raison);
    void MajVuePile();
    //void AfficherStack();
};


#endif // MAINWINDOW_H
