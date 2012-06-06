#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <stack>
#include "complexe.h"
#include "rationnel.h"

enum Angle {RADIAN, DEGRE};
enum Type{RATIONNEL, REEL, ENTIER};

class Calculatrice
        /*!
                  */
{
    std::stack<Constante*> m_pileStockage;
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





};

#endif // CALCULATRICE_H
