#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "constante.h"
#include "rationnel.h"
#include <QString>

#include<iostream>


class Complexe
        /*!
          Les objets complexe sont composés d'une partie réelle et d'une partie imaginaire de type float.
          Tous les calculs peuvent être réalisés en float.
          Cependant on pourra autoriser grâce au design pattern factory la fabrication de complexe à partir de
          Rationnels. (à confirmer)

        //  */

{

protected:
  // QString m_complexe;//utile?
   float m_reelle;//! <partie reelle
   float m_imaginaire;

   public:

   Complexe():/*m_complexe(""),*/ m_reelle(0), m_imaginaire(0){}
   // Complexe(Rationnel r); //Méthode à partir d'un Rationnel
   Complexe(float r, float i=0): m_reelle(r),m_imaginaire(i){}

    Complexe FabricationComplexe(QString s);

    //~Complexe();

//Accesseurs
   float GetPartieReelle() const {return m_reelle;}
   float GetPartieImaginaire() const {return m_imaginaire;}
    void SetPartieReelle(float r ){m_reelle=r;}
    void SetPartieImaginaire(float i){m_imaginaire=i;}


    //Fonctions de calcul


Complexe Produit(Complexe c); //!< Calcule le produit de deux complexes et renvoie un complexe
Complexe Racine(); //! < Calcule la racine carrée de l'objet. ce nombre peut être négatif
Complexe Quotient(Complexe c); //!< Calcule le quotient de deux complexes et renvoie un complexe

private:
Complexe Conjugue(){ return Complexe(m_reelle, -m_imaginaire);}
         //! < Renvoie le conjugué d'un nombre complexe. Fonction utile pour les racines et les quotients
Complexe Inverse();
};

Complexe Somme(Complexe c1, Complexe c2);     //!< Calcule la somme de deux complexes et renvoie un complexe







#endif // COMPLEXE_H
