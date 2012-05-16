#ifndef REEL_H
#define REEL_H

#include "constante.h"

class Reel : public Constante
{
protected:
    float m_reel;
    virtual void conversion(Constante& nombre);

public:
    Reel():Constante(),m_reel(0){};
    Reel(float r):Constante(QString::number(double(r))), m_reel(r){};
    Reel(Constante& nombre);

    float GetReel() const {return m_reel;}





};

#endif // REEL_H
