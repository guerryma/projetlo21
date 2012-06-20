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
    float m_imaginaire;

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
    Complexe* PowC(Complexe* c)const;

    Complexe* Sinus() const;
    Complexe* Cosinus() const;
    Complexe* Tang() const;

    Complexe* SinusH() const;
    Complexe* CosinusH() const;
    Complexe* TangH() const;

    Complexe* LnC()const;
    Complexe* LogC()const;

    Complexe* RacineC()const;//!< Calcule la racine carrÃ©e de l'objet.

    Complexe* Carre()const;
    Complexe* CubeC()const;

    Complexe* to_degre()const {return new Complexe((3.14/float(180)*m_reelle), 0);}
    friend QDataStream & operator >> (QDataStream &, Complexe*&);

private:
    Complexe* Conjugue() const{ return  new Complexe(m_reelle, -m_imaginaire);} //!< Renvoie le conjuguÃ© d'un nombre complexe. Fonction utile pour les racines et les quotients
    Complexe* InversePrive();


};

//Entrees et sorties fichier
QDataStream & operator << (QDataStream & out, const Complexe& Valeur);
QDataStream & operator >> (QDataStream & in,  Complexe& Valeur);





#endif // COMPLEXE_H
