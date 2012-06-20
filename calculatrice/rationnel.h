#ifndef RATIONNEL_H
#define RATIONNEL_H

#include<QString>
#include <iostream>
#include <stdexcept>
//#include <exception>
#include "constante.h"
#include "complexe.h"
#include "expression.h"

class RationnelException /*: public exception*/ {
    QString info;
public:
    RationnelException(const QString& s):info(s){}
    const QString& what() const {return info;}
};

//! Fraction d'entiers. Un entier est un rationnel dont le d�nominateur vaut 1
class Rationnel: public Constante
{
    /*! Classe Rationnel:
        Un rationnel est composé de 2 entiers: le numérateur et le dénominateur.
        Un dénominateur nul lévera une exception

      */
protected:

    int m_numerateur;
    int m_denominateur;
    float m_float;

private:
    void VerifSigne();//! <Met �  jour le signe du rationnel dans le numérateur
    void SetFloat(){m_float=(float)m_numerateur/(float)m_denominateur;}//! calcule le réel correspondant

public:

    Rationnel():Constante("rationnel"),m_numerateur(0), m_denominateur(1), m_float(0){}
    inline Rationnel(int num, int den=1): Constante("rationnel"),m_numerateur(num), m_denominateur(den? den:1){
        if(!den) throw RationnelException("Erreur, division par zéro\n");
        SetFloat();
        VerifSigne();

    }



    //Accesseurs
    int GetNumerateur() const {return m_numerateur;}
    int GetDenominateur() const {return m_denominateur;}
    int GetFloat() const {return m_float;}

    void SetNumerateur(int num) {m_numerateur=num; VerifSigne(); SetFloat();}
    inline void SetDenominateur(int den){
        if(den) {
            m_denominateur=den;
            VerifSigne();
            SetFloat();
        }
        else throw RationnelException("Erreur, division par zéro\n");
    }


    //Fonctions de calcul
    Rationnel* Inverse2();//! Calcule l'inverse d'une fraction en vérifiant que le numérateur n'est pas nul
    void Inverse();
    Rationnel* Oppose();
    void Signe();
    Rationnel* Somme(const Rationnel* r2) const;
    Rationnel* Difference(Rationnel* r2) const;
    Rationnel* Produit (const Rationnel* r2) const;
    Rationnel* Quotient(Rationnel* r2) const;

    Rationnel* Facto()const;
    Rationnel* Modulo(Rationnel* r)const;

    //Autres fonctions
    QString Afficher() const;
    bool IsNul(){if(!m_numerateur) return true; return false;}


    //Conversion
    Complexe* to_complexe()const {return new Complexe(m_float);}//! Convertit en complexe r�el
    static Rationnel* to_rationnel(Complexe* c);//! Convertit un complexe en rationnel entier

    friend QDataStream & operator >> (QDataStream &, Rationnel*&);

};

QDataStream & operator << (QDataStream & out, const Rationnel& Valeur);
QDataStream & operator >> (QDataStream & in,  Rationnel& Valeur);






#endif // RATIONNEL_H
