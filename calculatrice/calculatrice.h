#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <Qstack>
#include "complexe.h"
#include "rationnel.h"

enum Angle {RADIAN, DEGRE};
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
   inline Calculatrice(int taille, Angle angle, Type type, bool complexe):
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

//Operations sur les piles
void EmpilerPileA(QString m_s){m_pAff.push(m_s);}
QString DepilerPileA(){return m_pAff.pop();}
bool EstVidePileA(){return m_pAff.isEmpty();}

void EmpilerPileS(Constante* m_c){m_pStock.push(m_c);}
Constante* DepilerPileS(){return m_pStock.pop();}
bool EstVidePileS(){return m_pStock.isEmpty();}

//Gestion de la pile (calculs)
void OperationBinaire(QString Operation);
void AfficherStack(int m_param);





};

#endif // CALCULATRICE_H
