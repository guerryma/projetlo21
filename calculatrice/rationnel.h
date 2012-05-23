#ifndef RATIONNEL_H
#define RATIONNEL_H

#include<QString>
#include <iostream>

class RationnelException{
    std::string info;
public:
    RationnelException(const std::string& s):info(s){}
    const std::string& getInfo() const {return info;}
};


class Rationnel
{
    /* Classe Rationnel:
        Un rationnel est composé de 2 entiers.

      */
protected:

    int m_numerateur;
    int m_denominateur;

public:

    Rationnel():m_numerateur(0), m_denominateur(1){}// Reel<int> ou float?
    inline Rationnel(int num, int den=1):  m_numerateur(num), m_denominateur(den? den:1){
        if(!den) throw RationnelException("Erreur, division par zéro\n");

    }
    Rationnel(QString s);


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

    /*
    virtual Rationnel Division(Rationnel r);
    virtual Rationnel Produit(Rationnel r);
    virtual Rationnel Somme(Rationnel r);
    //Opposé? SOulève le problème des attributs.


      //*/

};



#endif // RATIONNEL_H
