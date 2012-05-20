#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"
#include "nombre.h"
#include <iostream>

class RationnelException{
    std::string info;
public:
    RationnelException(const std::string& s):info(s){}
    const std::string& getInfo() const {return info;}
};


class Rationnel : public Nombre
{
    /* Classe Rationnel:
      Prends en paramètre 2 entiers. La saisie d'un dénominateur nul provoque la levée d'une exception
      //*/

    int _numerateur;
    int _denominateur;

private:

    Rationnel():_numerateur(0), _denominateur(1){}
    inline Rationnel(int num, int den): _numerateur(num), _denominateur(den? den:1){
        if(!den) throw RationnelException("Erreur, division par zéro\n");

    }

public:

    int GetNumerateur() const {return _numerateur;}
    int GetDenominateur() const {return _denominateur;}
};



#endif // RATIONNEL_H
