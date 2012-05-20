#ifndef ENTIER_H
#define ENTIER_H

#include "reel.h"

class Entier : public Reel
{
    int _entier;

private:
    Entier(): Reel(0), _entier(0){}
    Entier(int i): Reel(), _entier(i){} //problème: il faut changer la valeur de la chaine

public:
    int GetEntier() const {return _entier;}
};

#endif // ENTIER_H
