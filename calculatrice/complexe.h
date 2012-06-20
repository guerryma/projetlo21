#ifndef COMPLEXE_H
#define COMPLEXE_H
#include "constante.h"
#include<iostream>
#include <cmath>
#include <QtCore/qmath.h>
#include <QVariant>



//! Un complexe est composé de 2 attributs floats:  la partie réelle et la partie imaginaire. Un réel est un complexe par défaut
class Complexe: public Constante

{

protected:
    float m_reelle;//! <partie reelle
    float m_imaginaire;//! <partie imaginaire

public:

    Complexe():Constante("complexe"), m_reelle(0), m_imaginaire(0){}
    Complexe(float r, float i=0): Constante("complexe"), m_reelle(r),m_imaginaire(i){}




    //Accesseurs
    float GetPartieReelle() const {return m_reelle;}
    float GetPartieImaginaire() const {return m_imaginaire;}
    void SetPartieReelle(float r ){m_reelle=r;}
    void SetPartieImaginaire(float i){m_imaginaire=i;}

    //Autres mÃ©thodes
    QString Afficher() const;
    bool IsNul(){if(!m_reelle && !m_imaginaire) return true; return false;}


    //Fonctions de calcul
    Complexe* Somme(const Complexe* c) const;     //!< Calcule la somme de deux complexes et renvoie un complexe
    Complexe* Difference(Complexe* c) const;     //!< Calcule la somme de deux complexes et renvoie un complexe
    Complexe* Produit(const Complexe* c) const; //!< Calcule le produit de deux complexes et renvoie un complexe
    Complexe* Quotient(Complexe* c) const; //!< Calcule le quotient de deux complexes et renvoie un complexe

    Complexe* Oppose();
    void Signe();
    void Inverse();
    Complexe* PowC(Complexe* c)const; //!< Calcule la puissance d'un complexe par rapport a un autre entre en parametre et retourne un complexe

    Complexe* Sinus() const; //!< Calcule le sinus d'un complexe en radiant et renvoie un complexe
    Complexe* Cosinus() const; //!< Calcule le cosinus d'un complexe en radiant et renvoie un complexe
    Complexe* Tang() const; //!< Calcule la tangente d'un complexe en radiant et renvoie un complexe

    Complexe* SinusH() const; //!< Calcule le sinus hyperbolique d'un complexe et renvoie un complexe
    Complexe* CosinusH() const; //!< Calcule le cosinus hyperbolique d'un complexe et renvoie un complexe
    Complexe* TangH() const; //!< Calcule la tangente hyperbolique d'un complexe et renvoie un complexe

    Complexe* LnC()const; //!< Calcule le logarithme neperien d'un complexe et renvoie un complexe
    Complexe* LogC()const; //!< Calcule le logarithme decimal d'un complexe et renvoie un complexe


    Complexe* RacineC()const;//!< Calcule la racine carree d'un complexe et renvoie un complexe


    Complexe* Carre()const; //!< Calcule le carre d'un complexe et renvoie un complexe
    Complexe* CubeC()const; //!< Calcule le cube d'un complexe et renvoie un complexe

    Complexe* to_degre()const {return new Complexe((3.14/float(180)*m_reelle), 0);} //!< Fonction qui convertit un angle de radiant en degre
    friend QDataStream & operator >> (QDataStream &, Complexe*&);

private:
    Complexe* Conjugue() const{ return  new Complexe(m_reelle, -m_imaginaire);} //!< Renvoie le conjuguÃ© d'un nombre complexe. Fonction utile pour les racines et les quotients
    Complexe* InversePrive();


};

//Entrees et sorties fichier
QDataStream & operator << (QDataStream & out, const Complexe& Valeur);
QDataStream & operator >> (QDataStream & in,  Complexe& Valeur);





#endif // COMPLEXE_H
