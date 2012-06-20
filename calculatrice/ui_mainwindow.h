/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed 20. Jun 18:19:14 2012
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAnnuler;
    QAction *actionRetablir;
    QAction *actionQuitter;
    QAction *actionAbout;
    QWidget *centralWidget;
    QPlainTextEdit *pile;
    QLineEdit *lineEdit;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QPushButton *b0;
    QPushButton *b7;
    QPushButton *b8;
    QPushButton *b9;
    QPushButton *b4;
    QPushButton *b5;
    QPushButton *b6;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *bVirgule;
    QPushButton *bDollar;
    QPushButton *bCote;
    QPushButton *bSpace;
    QPushButton *bSup;
    QPushButton *bEval;
    QPushButton *bEnter;
    QPushButton *bMoins;
    QPushButton *bDivision;
    QPushButton *bFois;
    QSpacerItem *horizontalSpacer;
    QPushButton *bSign;
    QPushButton *bInv;
    QPushButton *bPlus;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_8;
    QPushButton *bMean;
    QPushButton *bSum;
    QPushButton *bDup;
    QPushButton *bSwap;
    QPushButton *bClear;
    QPushButton *bDrop;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_6;
    QPushButton *bCos;
    QPushButton *bSin;
    QPushButton *bTan;
    QPushButton *bSinh;
    QPushButton *bTanh;
    QPushButton *bLn;
    QPushButton *bLog;
    QPushButton *bCosh;
    QPushButton *bMod;
    QPushButton *bFact;
    QPushButton *bSqrt;
    QPushButton *bCube;
    QPushButton *bSqr;
    QPushButton *bPow;
    QGroupBox *groupBox_4;
    QLineEdit *nbOpPile;
    QGroupBox *groupBox_3;
    QCheckBox *Complexe;
    QFrame *line;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *bEntier;
    QRadioButton *bRationnel;
    QRadioButton *bReel;
    QGroupBox *groupBox_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *bRadian;
    QRadioButton *bDegre;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(909, 513);
        actionAnnuler = new QAction(MainWindow);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        actionRetablir = new QAction(MainWindow);
        actionRetablir->setObjectName(QString::fromUtf8("actionRetablir"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pile = new QPlainTextEdit(centralWidget);
        pile->setObjectName(QString::fromUtf8("pile"));
        pile->setGeometry(QRect(490, 40, 171, 271));
        pile->setReadOnly(true);
        pile->setTextInteractionFlags(Qt::NoTextInteraction);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 471, 20));
        lineEdit->setReadOnly(true);
        gridLayoutWidget_5 = new QWidget(centralWidget);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(40, 50, 411, 261));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setMargin(11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        b0 = new QPushButton(gridLayoutWidget_5);
        b0->setObjectName(QString::fromUtf8("b0"));

        gridLayout_5->addWidget(b0, 3, 0, 1, 1);

        b7 = new QPushButton(gridLayoutWidget_5);
        b7->setObjectName(QString::fromUtf8("b7"));

        gridLayout_5->addWidget(b7, 0, 0, 1, 1);

        b8 = new QPushButton(gridLayoutWidget_5);
        b8->setObjectName(QString::fromUtf8("b8"));

        gridLayout_5->addWidget(b8, 0, 1, 1, 1);

        b9 = new QPushButton(gridLayoutWidget_5);
        b9->setObjectName(QString::fromUtf8("b9"));

        gridLayout_5->addWidget(b9, 0, 2, 1, 1);

        b4 = new QPushButton(gridLayoutWidget_5);
        b4->setObjectName(QString::fromUtf8("b4"));

        gridLayout_5->addWidget(b4, 1, 0, 1, 1);

        b5 = new QPushButton(gridLayoutWidget_5);
        b5->setObjectName(QString::fromUtf8("b5"));

        gridLayout_5->addWidget(b5, 1, 1, 1, 1);

        b6 = new QPushButton(gridLayoutWidget_5);
        b6->setObjectName(QString::fromUtf8("b6"));

        gridLayout_5->addWidget(b6, 1, 2, 1, 1);

        b1 = new QPushButton(gridLayoutWidget_5);
        b1->setObjectName(QString::fromUtf8("b1"));

        gridLayout_5->addWidget(b1, 2, 0, 1, 1);

        b2 = new QPushButton(gridLayoutWidget_5);
        b2->setObjectName(QString::fromUtf8("b2"));

        gridLayout_5->addWidget(b2, 2, 1, 1, 1);

        b3 = new QPushButton(gridLayoutWidget_5);
        b3->setObjectName(QString::fromUtf8("b3"));

        gridLayout_5->addWidget(b3, 2, 2, 1, 1);

        bVirgule = new QPushButton(gridLayoutWidget_5);
        bVirgule->setObjectName(QString::fromUtf8("bVirgule"));
        bVirgule->setEnabled(true);

        gridLayout_5->addWidget(bVirgule, 3, 1, 1, 1);

        bDollar = new QPushButton(gridLayoutWidget_5);
        bDollar->setObjectName(QString::fromUtf8("bDollar"));

        gridLayout_5->addWidget(bDollar, 3, 2, 1, 1);

        bCote = new QPushButton(gridLayoutWidget_5);
        bCote->setObjectName(QString::fromUtf8("bCote"));

        gridLayout_5->addWidget(bCote, 12, 2, 1, 1);

        bSpace = new QPushButton(gridLayoutWidget_5);
        bSpace->setObjectName(QString::fromUtf8("bSpace"));

        gridLayout_5->addWidget(bSpace, 12, 0, 1, 1);

        bSup = new QPushButton(gridLayoutWidget_5);
        bSup->setObjectName(QString::fromUtf8("bSup"));

        gridLayout_5->addWidget(bSup, 12, 1, 1, 1);

        bEval = new QPushButton(gridLayoutWidget_5);
        bEval->setObjectName(QString::fromUtf8("bEval"));

        gridLayout_5->addWidget(bEval, 14, 2, 1, 1);

        bEnter = new QPushButton(gridLayoutWidget_5);
        bEnter->setObjectName(QString::fromUtf8("bEnter"));

        gridLayout_5->addWidget(bEnter, 14, 0, 1, 2);

        bMoins = new QPushButton(gridLayoutWidget_5);
        bMoins->setObjectName(QString::fromUtf8("bMoins"));

        gridLayout_5->addWidget(bMoins, 1, 4, 1, 1);

        bDivision = new QPushButton(gridLayoutWidget_5);
        bDivision->setObjectName(QString::fromUtf8("bDivision"));

        gridLayout_5->addWidget(bDivision, 3, 4, 1, 1);

        bFois = new QPushButton(gridLayoutWidget_5);
        bFois->setObjectName(QString::fromUtf8("bFois"));

        gridLayout_5->addWidget(bFois, 2, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 3, 1, 1);

        bSign = new QPushButton(gridLayoutWidget_5);
        bSign->setObjectName(QString::fromUtf8("bSign"));

        gridLayout_5->addWidget(bSign, 12, 4, 1, 1);

        bInv = new QPushButton(gridLayoutWidget_5);
        bInv->setObjectName(QString::fromUtf8("bInv"));

        gridLayout_5->addWidget(bInv, 14, 4, 1, 1);

        bPlus = new QPushButton(gridLayoutWidget_5);
        bPlus->setObjectName(QString::fromUtf8("bPlus"));

        gridLayout_5->addWidget(bPlus, 0, 4, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 340, 521, 91));
        gridLayoutWidget_6 = new QWidget(groupBox);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(0, 30, 491, 62));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setMargin(11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        bMean = new QPushButton(gridLayoutWidget_6);
        bMean->setObjectName(QString::fromUtf8("bMean"));

        gridLayout_8->addWidget(bMean, 0, 0, 1, 1);

        bSum = new QPushButton(gridLayoutWidget_6);
        bSum->setObjectName(QString::fromUtf8("bSum"));

        gridLayout_8->addWidget(bSum, 0, 1, 1, 1);

        bDup = new QPushButton(gridLayoutWidget_6);
        bDup->setObjectName(QString::fromUtf8("bDup"));

        gridLayout_8->addWidget(bDup, 0, 2, 1, 1);

        bSwap = new QPushButton(gridLayoutWidget_6);
        bSwap->setObjectName(QString::fromUtf8("bSwap"));

        gridLayout_8->addWidget(bSwap, 1, 0, 1, 1);

        bClear = new QPushButton(gridLayoutWidget_6);
        bClear->setObjectName(QString::fromUtf8("bClear"));

        gridLayout_8->addWidget(bClear, 1, 1, 1, 1);

        bDrop = new QPushButton(gridLayoutWidget_6);
        bDrop->setObjectName(QString::fromUtf8("bDrop"));

        gridLayout_8->addWidget(bDrop, 1, 2, 1, 1);

        gridLayoutWidget_7 = new QWidget(centralWidget);
        gridLayoutWidget_7->setObjectName(QString::fromUtf8("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(700, 40, 178, 271));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setMargin(11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        bCos = new QPushButton(gridLayoutWidget_7);
        bCos->setObjectName(QString::fromUtf8("bCos"));

        gridLayout_6->addWidget(bCos, 0, 0, 1, 1);

        bSin = new QPushButton(gridLayoutWidget_7);
        bSin->setObjectName(QString::fromUtf8("bSin"));

        gridLayout_6->addWidget(bSin, 1, 0, 1, 1);

        bTan = new QPushButton(gridLayoutWidget_7);
        bTan->setObjectName(QString::fromUtf8("bTan"));

        gridLayout_6->addWidget(bTan, 2, 0, 1, 1);

        bSinh = new QPushButton(gridLayoutWidget_7);
        bSinh->setObjectName(QString::fromUtf8("bSinh"));

        gridLayout_6->addWidget(bSinh, 1, 1, 1, 1);

        bTanh = new QPushButton(gridLayoutWidget_7);
        bTanh->setObjectName(QString::fromUtf8("bTanh"));

        gridLayout_6->addWidget(bTanh, 2, 1, 1, 1);

        bLn = new QPushButton(gridLayoutWidget_7);
        bLn->setObjectName(QString::fromUtf8("bLn"));

        gridLayout_6->addWidget(bLn, 3, 0, 1, 1);

        bLog = new QPushButton(gridLayoutWidget_7);
        bLog->setObjectName(QString::fromUtf8("bLog"));

        gridLayout_6->addWidget(bLog, 3, 1, 1, 1);

        bCosh = new QPushButton(gridLayoutWidget_7);
        bCosh->setObjectName(QString::fromUtf8("bCosh"));

        gridLayout_6->addWidget(bCosh, 0, 1, 1, 1);

        bMod = new QPushButton(gridLayoutWidget_7);
        bMod->setObjectName(QString::fromUtf8("bMod"));

        gridLayout_6->addWidget(bMod, 6, 0, 1, 1);

        bFact = new QPushButton(gridLayoutWidget_7);
        bFact->setObjectName(QString::fromUtf8("bFact"));

        gridLayout_6->addWidget(bFact, 6, 1, 1, 1);

        bSqrt = new QPushButton(gridLayoutWidget_7);
        bSqrt->setObjectName(QString::fromUtf8("bSqrt"));

        gridLayout_6->addWidget(bSqrt, 4, 1, 1, 1);

        bCube = new QPushButton(gridLayoutWidget_7);
        bCube->setObjectName(QString::fromUtf8("bCube"));

        gridLayout_6->addWidget(bCube, 5, 0, 1, 1);

        bSqr = new QPushButton(gridLayoutWidget_7);
        bSqr->setObjectName(QString::fromUtf8("bSqr"));

        gridLayout_6->addWidget(bSqr, 4, 0, 1, 1);

        bPow = new QPushButton(gridLayoutWidget_7);
        bPow->setObjectName(QString::fromUtf8("bPow"));

        gridLayout_6->addWidget(bPow, 5, 1, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(490, 10, 191, 21));
        nbOpPile = new QLineEdit(groupBox_4);
        nbOpPile->setObjectName(QString::fromUtf8("nbOpPile"));
        nbOpPile->setGeometry(QRect(150, 0, 31, 20));
        nbOpPile->setMaxLength(3);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(510, 320, 371, 181));
        Complexe = new QCheckBox(groupBox_3);
        Complexe->setObjectName(QString::fromUtf8("Complexe"));
        Complexe->setGeometry(QRect(150, 120, 221, 21));
        Complexe->setChecked(true);
        line = new QFrame(groupBox_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(180, 60, 16, 61));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 30, 151, 111));
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 30, 99, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        bEntier = new QRadioButton(verticalLayoutWidget);
        bEntier->setObjectName(QString::fromUtf8("bEntier"));

        verticalLayout->addWidget(bEntier);

        bRationnel = new QRadioButton(verticalLayoutWidget);
        bRationnel->setObjectName(QString::fromUtf8("bRationnel"));

        verticalLayout->addWidget(bRationnel);

        bReel = new QRadioButton(verticalLayoutWidget);
        bReel->setObjectName(QString::fromUtf8("bReel"));
        bReel->setChecked(true);

        verticalLayout->addWidget(bReel);

        verticalLayoutWidget->raise();
        line->raise();
        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(210, 30, 111, 91));
        verticalLayoutWidget_2 = new QWidget(groupBox_5);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 30, 101, 52));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        bRadian = new QRadioButton(verticalLayoutWidget_2);
        bRadian->setObjectName(QString::fromUtf8("bRadian"));
        bRadian->setChecked(true);

        verticalLayout_2->addWidget(bRadian);

        bDegre = new QRadioButton(verticalLayoutWidget_2);
        bDegre->setObjectName(QString::fromUtf8("bDegre"));

        verticalLayout_2->addWidget(bDegre);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 909, 25));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menu->menuAction());
        menuMenu->addAction(actionAnnuler);
        menuMenu->addAction(actionRetablir);
        menuMenu->addAction(actionQuitter);
        menu->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculatrice", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRetablir->setText(QApplication::translate("MainWindow", "R\303\251tablir", 0, QApplication::UnicodeUTF8));
        actionRetablir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        pile->setPlainText(QString());
        b0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        b0->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        b7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        b7->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        b8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        b8->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        b9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        b9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        b4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        b4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        b5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        b5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        b6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        b6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        b1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        b1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        b2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        b2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        b3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        b3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        bVirgule->setText(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        bVirgule->setShortcut(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        bDollar->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        bDollar->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        bCote->setText(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        bCote->setShortcut(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        bSpace->setText(QApplication::translate("MainWindow", "SPACE", 0, QApplication::UnicodeUTF8));
        bSpace->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        bSup->setText(QApplication::translate("MainWindow", "<--", 0, QApplication::UnicodeUTF8));
        bSup->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        bEval->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        bEval->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        bEnter->setText(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        bEnter->setShortcut(QApplication::translate("MainWindow", "Enter", 0, QApplication::UnicodeUTF8));
        bMoins->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        bMoins->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        bDivision->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        bDivision->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        bFois->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        bFois->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        bSign->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        bInv->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        bPlus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        bPlus->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Op\303\251rations pile", 0, QApplication::UnicodeUTF8));
        bMean->setText(QApplication::translate("MainWindow", "MEAN", 0, QApplication::UnicodeUTF8));
        bSum->setText(QApplication::translate("MainWindow", "SUM", 0, QApplication::UnicodeUTF8));
        bDup->setText(QApplication::translate("MainWindow", "DUP", 0, QApplication::UnicodeUTF8));
        bSwap->setText(QApplication::translate("MainWindow", "SWAP", 0, QApplication::UnicodeUTF8));
        bClear->setText(QApplication::translate("MainWindow", "CLEAR", 0, QApplication::UnicodeUTF8));
        bClear->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        bDrop->setText(QApplication::translate("MainWindow", "DROP", 0, QApplication::UnicodeUTF8));
        bCos->setText(QApplication::translate("MainWindow", "COS", 0, QApplication::UnicodeUTF8));
        bSin->setText(QApplication::translate("MainWindow", "SIN ", 0, QApplication::UnicodeUTF8));
        bTan->setText(QApplication::translate("MainWindow", "TAN", 0, QApplication::UnicodeUTF8));
        bSinh->setText(QApplication::translate("MainWindow", "SINH", 0, QApplication::UnicodeUTF8));
        bTanh->setText(QApplication::translate("MainWindow", "TANH", 0, QApplication::UnicodeUTF8));
        bLn->setText(QApplication::translate("MainWindow", "LN", 0, QApplication::UnicodeUTF8));
        bLog->setText(QApplication::translate("MainWindow", "LOG", 0, QApplication::UnicodeUTF8));
        bCosh->setText(QApplication::translate("MainWindow", "COSH", 0, QApplication::UnicodeUTF8));
        bMod->setText(QApplication::translate("MainWindow", "MOD", 0, QApplication::UnicodeUTF8));
        bFact->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        bFact->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        bSqrt->setText(QApplication::translate("MainWindow", "SQRT", 0, QApplication::UnicodeUTF8));
        bCube->setText(QApplication::translate("MainWindow", "CUBE", 0, QApplication::UnicodeUTF8));
        bSqr->setText(QApplication::translate("MainWindow", "SQR", 0, QApplication::UnicodeUTF8));
        bPow->setText(QApplication::translate("MainWindow", "POW", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Nombre d'\303\251l\303\251ments", 0, QApplication::UnicodeUTF8));
        nbOpPile->setText(QString());
        groupBox_3->setTitle(QString());
        Complexe->setText(QApplication::translate("MainWindow", "Complexe Autoris\303\251s", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Type de Constante", 0, QApplication::UnicodeUTF8));
        bEntier->setText(QApplication::translate("MainWindow", "Entier", 0, QApplication::UnicodeUTF8));
        bRationnel->setText(QApplication::translate("MainWindow", "Rationnel", 0, QApplication::UnicodeUTF8));
        bReel->setText(QApplication::translate("MainWindow", "R\303\251el", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Angle", 0, QApplication::UnicodeUTF8));
        bRadian->setText(QApplication::translate("MainWindow", "Radian", 0, QApplication::UnicodeUTF8));
        bDegre->setText(QApplication::translate("MainWindow", "Degr\303\251", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
