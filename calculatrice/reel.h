#ifndef REEL_H
#define REEL_H

#include "nombre.h"
/*
#include "constante.h"


class Reel : public Constante
{
protected:
    float m_reel;
   virtual void conversion(Constante& nombre){/*this->m_reel= nombre.GetConstante().toFloat();}

public:
    Reel():Constante(),m_reel(0){}
    Reel(float r):Constante(QString::number(double(r))), m_reel(r){}
   /* Reel(Constante& nombre): m_reel(nombre.GetConstante().toFloat()){
            m_constante=nombre.GetConstante();

//}

    float GetReel() const {return m_reel;}


};
   //*/
//*
class Reel : public Nombre
{
protected:
   float m_reel;
   virtual void conversion(Nombre& nombre){/*this->m_reel= nombre.GetConstante().toFloat();*/}

public: //Il faudra passer les constructeurs en private après avoir fait les fabriques
    Reel():Nombre(),m_reel(0){}
    Reel(float r):Nombre(QString::number(double(r))), m_reel(r){}
   /* Reel(Constante& nombre): m_reel(nombre.GetConstante().toFloat()){
            m_constante=nombre.GetConstante();

//}


//*/

public:
    float GetReel() const {return m_reel;}

};
//*/


#endif // REEL_H
