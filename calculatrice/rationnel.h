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


class Rationnel: public Constante
{
    /*! Classe Rationnel:
        Un rationnel est composé de 2 entiers: le numérateur et le dénominateur.
        Un dénominateur nul lévera une exception

      */
protected:

    int m_numerateur;
    int m_denominateur;

public:

    Rationnel():Constante("rationnel"),m_numerateur(0), m_denominateur(1){}
    inline Rationnel(int num, int den=1): Constante("rationnel"),m_numerateur(num), m_denominateur(den? den:1){
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
    Rationnel* Inverse() const;//! Calcule l'inverse d'une fraction en vérifiant que le numérateur n'est pas nul
    Rationnel* Oppose() const;
    Rationnel* Somme(const Rationnel* r2) const;
    Rationnel* Difference(const Rationnel* r2) const;
    Rationnel* Produit (const Rationnel* r2) const;
    Rationnel* Quotient(const Rationnel* r2) const;
    //Autres fonctions
    QString Afficher() const;
};






#endif // RATIONNEL_H
