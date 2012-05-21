#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "constante.h"


template <typename T>
class Complexe : public Constante
{
    /*
      Les objets complexe sont composés d'une partie réelle et d'une partie imaginaire de type Constante.
      Ces attributs sont soit des Entiers, soit des Réels, soit des Rationnels. les deux attributs sont
      de même type. Le type est choisi en fonction du mode de la calculette

    //  */
protected:
   T m_reelle;
   T m_imaginaire;

public:
    Complexe(): m_reelle(0), m_imaginaire(0){}
    Complexe(T reelle, T imaginaire): m_reelle(reelle),m_imaginaire(imaginaire){}
    virtual ~Complexe();

//Accesseurs
    T GetPartieReelle() const {return m_reelle;}
    T GetPartieImaginaire() const {return m_imaginaire;}
    void SetPartieReelle(T r ){m_reelle=r;}
    void SetPartieImaginaire(T i){m_imaginaire=i;}


    // Fonctions de calcul à implémenter dans ce fichier


    virtual Complexe<T> Somme(Complexe<T> c);
    virtual Complexe<T> Oppose(Complexe<T> c);
    virtual Complexe<T> Produit(Complexe<T> c);
    virtual Complexe<T> Division(Complexe<T> c);
    virtual Complexe<T> Soustraction(Complexe<T> c);

    virtual Complexe<T> Carre();
    virtual Complexe<T> Cube();






};



#endif // COMPLEXE_H
