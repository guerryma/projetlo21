#ifndef RATIONNEL_H
#define RATIONNEL_H

#include<QString>
#include <iostream>
#include <stdexcept>
#include<exception>
#include "constante.h"

class RationnelException{
    std::string info;
public:
    RationnelException(const std::string& s):info(s){}
    const std::string& getInfo() const {return info;}
};


class Rationnel//: public Constante
{
    /*! Classe Rationnel:
        Un rationnel est composé de 2 entiers: le numérateur et le dénominateur.
        Un dénominateur nul lévera une exception

      */
protected:

    int m_numerateur;
    int m_denominateur;

public:

    Rationnel():m_numerateur(0), m_denominateur(1){}
    inline Rationnel(int num, int den=1):  m_numerateur(num), m_denominateur(den? den:1){
        if(!den) throw RationnelException("Erreur, division par zéro\n");

    }
  //virtual ~Rationnel();



//Accesseurs
    int GetNumerateur() const {return m_numerateur;}
    int GetDenominateur() const {return m_denominateur;}
    void SetNumerateur(int num) {m_numerateur=num;}
    inline void SetDenominateur(int den){
        if(den) m_denominateur=den;
        else throw RationnelException("Erreur, division par zéro\n");
    }


    //Fonctions de calcul
    Rationnel Inverse();//! Calcule l'inverse d'une fraction en vérifiant que le numérateur n'est pas nul

};
Rationnel Somme(Rationnel r1, Rationnel r2);
Rationnel Division(Rationnel r1, Rationnel r2);
Rationnel Produit (Rationnel r1, Rationnel r2);





#endif // RATIONNEL_H
