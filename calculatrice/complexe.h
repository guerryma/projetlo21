#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "constante.h"
#include "rationnel.h"
#include <QString>


class Complexe
{
    /*
      Les objets complexe sont composés d'une partie réelle et d'une partie imaginaire de type float.
      Tous les calculs peuvent être réalisés en float.
      Cependant on pourra autoriser grâce au design pattern factory la fabrication de complexe à partir de
      Rationnels. (à confirmer)

    //  */
protected:
   QString m_complexe;//utile?
   float m_reelle;
   float m_imaginaire;

   public:

   Complexe():m_complexe(""), m_reelle(0), m_imaginaire(0){}

   inline Complexe(float reelle, float imaginaire=0): m_complexe("$"),
       m_reelle(reelle),m_imaginaire(imaginaire){} // trouver concaténation QString

   // Complexe(Rationnel r); //Méthode à partir d'un Rationnel

    Complexe FabricationComplexe(QString s);

    virtual ~Complexe();

//Accesseurs
   float GetPartieReelle() const {return m_reelle;}
   float GetPartieImaginaire() const {return m_imaginaire;}
    void SetPartieReelle(float r ){m_reelle=r;}
    void SetPartieImaginaire(float i){m_imaginaire=i;}


    // Fonctions de calcul à implémenter dans ce fichier

/*
    virtual Complexe<T> Somme(Complexe<T> c);
    virtual Complexe<T> Oppose(Complexe<T> c);
    virtual Complexe<T> Produit(Complexe<T> c);
    virtual Complexe<T> Division(Complexe<T> c);
    virtual Complexe<T> Soustraction(Complexe<T> c);

    virtual Complexe<T> Carre();
    virtual Complexe<T> Cube();
    //*/

// Operateurs



};




#endif // COMPLEXE_H
