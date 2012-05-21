#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "reel.h"
#include <iostream>

class RationnelException{
    std::string info;
public:
    RationnelException(const std::string& s):info(s){}
    const std::string& getInfo() const {return info;}
};


class Rationnel : public Reel<int>
{
    /* Classe Rationnel:
      Reel qui comporte en plus un dénominateur.
      Une question se pose: faut-il conserver le résultat de la division en tant que réel dans la
      partie réelle du rationnel?
      Sinon il y aura perte d'information (notamment complexe de mauvais type)
      Il serait peut être plus judicieux de faire dériver Rationnel de complexe sans passer par réel.
      On aurait quand même le problème pour num/partie réelle


      */
protected:

    int m_numerateur;
    int m_denominateur;

public:

    Rationnel():Reel<int>(),m_numerateur(0), m_denominateur(1){}// Reel<int> ou float?
    inline Rationnel(int num, int den): Reel<int>(num), m_numerateur(num), m_denominateur(den? den:1){
        if(!den) throw RationnelException("Erreur, division par zéro\n");

    }
    virtual ~Rationnel();

//Accesseurs
    int GetNumerateur() const {return m_numerateur;}
    int GetDenominateur() const {return m_denominateur;}
    void SetNumerateur(int num) {m_numerateur=num;}
    inline void SetDenominateur(int den){
        if(den) m_denominateur=den;
        else throw RationnelException("Erreur, division par zéro\n");
    }

    //Fonctions de calcul

    /*
    virtual Rationnel Inverse();
    //*/

    //*
    virtual Rationnel Division(Rationnel r);
    virtual Rationnel Produit(Rationnel r);
    virtual Rationnel Somme(Rationnel r);
    //Opposé? SOulève le problème des attributs.


      //*/

};



#endif // RATIONNEL_H
