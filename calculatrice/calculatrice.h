#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <stack>
#include "complexe.h"
#include "rationnel.h"

enum Angle {RADIAN, DEGRE};
enum Type{RATIONNEL, COMPLEXE, ENTIER};

class Calculatrice
        /*!
                  */
{
    std::stack<Constante*> m_pileStockage;
    int m_taille;
    Angle m_angle;
    Type m_type;


public:
    Calculatrice();
};

#endif // CALCULATRICE_H
