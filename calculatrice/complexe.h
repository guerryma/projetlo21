#ifndef COMPLEXE_H
#define COMPLEXE_H
#include "constante.h"
#include<iostream>


class Complexe: public Constante
        /*!
                  Les objets complexe sont composés d'une partie réelle et d'une partie imaginaire de type float.
                  Tous les calculs peuvent être réalisés en float.
                  Cependant on pourra autoriser grâce au design pattern factory la fabrication de complexe à partir de
                  Rationnels. (à confirmer)

                //  */

{

protected:
    float m_reelle;//! <partie reelle
    float m_imaginaire;

public:

    Complexe():/*m_complexe(""),*/Constante("Complexe"), m_reelle(0), m_imaginaire(0){}
    // Complexe(Rationnel r); //Méthode à partir d'un Rationnel
    Complexe(float r, float i=0): Constante("Complexe"), m_reelle(r),m_imaginaire(i){}


    //Complexe FabricationComplexe(QString s);

    //Accesseurs
    float GetPartieReelle() const {return m_reelle;}
    float GetPartieImaginaire() const {return m_imaginaire;}
    void SetPartieReelle(float r ){m_reelle=r;}
    void SetPartieImaginaire(float i){m_imaginaire=i;}

    //Autres méthodes
    QString Afficher();


    //Fonctions de calcul
    Complexe* Somme(Complexe c);     //!< Calcule la somme de deux complexes et renvoie un complexe
    Complexe* Produit(Complexe c); //!< Calcule le produit de deux complexes et renvoie un complexe
    Complexe* Racine(); //! < Calcule la racine carrée de l'objet. ce nombre peut être négatif
    Complexe* Quotient(Complexe c); //!< Calcule le quotient de deux complexes et renvoie un complexe

private:
    Complexe* Conjugue(){ return  new Complexe(m_reelle, -m_imaginaire);}
    //! < Renvoie le conjugué d'un nombre complexe. Fonction utile pour les racines et les quotients
    Complexe Inverse();
};


//reste à faire: racine







#endif // COMPLEXE_H
