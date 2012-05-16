#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <QString>

class Constante
{
    //"Classe abstraite dont tous les éléments manipulés par la calculatrice dérivent."
protected:
    QString m_constante;
    virtual void conversion(Constante& nombre)=0; //Convertira la chaine de caractère en l'objet approprié

public:
    Constante(): m_constante(""){}
    Constante(QString constante): m_constante(constante){}

    QString GetConstante() const {return m_constante;}



};



#endif // CONSTANTE_H
