#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "reel.h"
#include "entier.h"
#include"rationnel.h"



class Complexe : public Constante
{
    /*
      Les objets complexe sont composés d'une partie réelle et d'une partie imaginaire de type Constante.
      Ces attributs sont soit des Entiers, soit des Réels, soit des Rationnels. les deux attributs sont
      de même type. Le type est choisi en fonction du mode de la calculette

    //  */
/*protected:
    Nombre* _reelle;
    Nombre* _imaginaire;
    //Peut-on créer une classe dont le type des attributs n'est pas connu à l'avance?
    //Idee1: 6 attributs privés
    //Idee2: classe nombre (abstraite ou pas? )Et constructeur nombre privé.
    //Idee3: utiliser des pointeurs

private:
    Complexe(): _reelle(0), _imaginaire(0){}
    Complexe(Nombre* reelle, Nombre* imaginaire): _reelle(reelle),_imaginaire(imaginaire){}

public:
    Nombre GetPartieReelle() const {return *_reelle;}
    Nombre GetPartieImaginaire() const {return *_imaginaire;}


//*/
};



#endif // COMPLEXE_H
