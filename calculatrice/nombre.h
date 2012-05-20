#ifndef NOMBRE_H
#define NOMBRE_H

#include "constante.h"

class Nombre : public Constante
{
public:
    Nombre():Constante(){};
    Nombre(QString nombre): Constante(nombre){}
    void methodebidon();
};

#endif // NOMBRE_H
