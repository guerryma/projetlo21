#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include "complexe.h"
#include "expression.h"
#include "rationnel.h"
#include <QStack>
#include <QQueue>
#include <iostream>


enum Angle{RADIAN, DEGRE};
enum Type{RATIONNEL, REEL, ENTIER};

class Calculatrice
        /*!
                  */
{
    QStack<Constante*> m_pStock;
    QStack<QString> m_pAff;
    int m_taille; //! taille de la pile d'affichage
    Angle m_angle;
    Type m_type;
    bool m_modeComplexe;


public:
    Calculatrice(){}
   inline Calculatrice(int taille=10, Angle angle=DEGRE, Type type=REEL, bool complexe=true):
        m_taille(taille), m_angle(angle), m_type(type), m_modeComplexe(complexe){}

   //Accesseurs
int GetTaille() const {return m_taille;}
Angle GetAngle() const {return m_angle;}
Type GetType() const {return m_type;}
bool GetModeComplexe() const {return m_modeComplexe;}

void SetTaille(int n){m_taille=n;}
void SetAngle(Angle a){m_angle=a;}
void SetType(Type t){m_type=t;}
void SetModeComplexe(bool b){m_modeComplexe=b;}

//Operations sur les piles (accesseurs de pile)
void EmpilerPileA(QString s){m_pAff.push(s);}
QString DepilerPileA(){return m_pAff.pop();}
bool EstVidePileA(){return m_pAff.isEmpty();}

QStack<Constante*> GetPileS()const {return m_pStock;}
void EmpilerPileS(Constante* c); //!< Permet d'empiler tout en vérifiant la taille.
void push(Constante* c);
Constante* DepilerPileS(){return m_pStock.pop();}
bool EstVidePileS(){return m_pStock.isEmpty();}

//Gestion de la pile (calculs)

bool OperationBinaire(char operation);
bool EvalExpression(QQueue<QString> pileExpr,Expression* expr=0);
bool Signe();
bool Inverse();

//Operations unaires
bool Sin();

//Opérations sur la pile
bool MajPileS(QString s);
bool Swap();
bool Sum();
bool Mean();
void Clear();
bool Dup();
bool Drop();



};

#endif // CALCULATRICE_H
