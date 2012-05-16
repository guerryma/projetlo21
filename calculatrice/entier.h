#ifndef ENTIER_H
#define ENTIER_H

#include "reel.h"

class Entier : public Reel
{
    int _entier;

public:
    Entier(): Reel(0), _entier(0){}
    Entier(int i): Reel(), _entier(i){} //problème: il faut changer la valeur de la chaine
    //Entier(Reel& i):Reel(), _entier(int(i.GetReel)) //idem
    //Entier(Constante& r):

    int GetEntier() const {return _entier;}
};

#endif // ENTIER_H
