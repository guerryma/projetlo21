#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include "complexe.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //Calculatrice m_calc;
    QStack <Complexe> m_pStock; //! pile de stockage de la calculatrice
    QStack <QString> m_pAff; //! pile d'affichage de la calculatrice

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

    void BEvalPressed();
    void BSpacePressed();

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

public:
    void ClavierNumerique();
    void ClavierSignes();
    void ClavierPile();
    void ClavierOperateurUnaire();
    void ClavierAutresFonctions();
    void AfficherStack(int m_param);
};


#endif // MAINWINDOW_H
