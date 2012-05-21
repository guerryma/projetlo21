#ifndef REEL_H
#define REEL_H

#include "complexe.h"

#include "constante.h"

template <typename T>
class Reel : public Complexe<T>
{
    /* Un réel est Un complexe dont la partie imaginaire est nulle.
      Un réel peut être de type int ou float.
      */

protected:
   virtual void conversion(Constante& nombre){/*this->m_reel= nombre.GetConstante().toFloat();*/}
    //a supprimer

public:
    Reel<T>():Complexe<T>(){}
    Reel(T r):Complexe<T>(r,0){}
    virtual ~Reel();

    //Fonctions de calcul. Il faudra surcharger les opérateurs plutôt que changer le type des fonctions

    //Hésitation: type retour reel<float> ou float?

    float Cos();
    float Sin();
    float Tan();
    float CosH();
    float SinH();
    float TanH();
    float Ln();
    float Log();

    float Puissance(int n);
    float Racine();
    virtual Reel<T> Inverse(); // T car il s'agit d'un rationnel lorsque l'on est en mode rationnel.






};



#endif // REEL_H
