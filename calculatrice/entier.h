#ifndef ENTIER_H
#define ENTIER_H

#include "rationnel.h"

class Entier : public Rationnel
{
    /*
      Un entier est un Rationnel de dénominateur = 1
      Toutes les opérations applicables à un Rationnel le sont à un entier
      On a le même problème que pour le rationnel avec num et dénom =>
      Ne pas faire hériter rationnel de Réel? Après tout il y a  beaucoup de fonctions à redéfinir
      */

public:
    Entier(): Rationnel(){}
    Entier(int i): Rationnel(i,1){}
    virtual ~Entier();

//Accesseurs:
    int GetEntier() const {return this->m_numerateur;}
    void SetEntier(int n){this->SetNumerateur(n);}

 //Fonctions de calcul

    Entier Factorielle();
    Entier Modulo();

    //type int ou entier? Conversion implicite? Surcharge des opérateurs?

};

#endif // ENTIER_H
