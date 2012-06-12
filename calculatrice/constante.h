#ifndef CONSTANTE_H
#define CONSTANTE_H
#include <QString>

class Constante
{
    QString m_type;
public:
    Constante(){}
    Constante(QString type): m_type(type){}
    virtual QString Afficher() const=0;
    virtual ~Constante(){};

    QString GetType() const {return m_type;}


    //Opérations

    //virtual Constante* Somme(const Constante* c)const {return new Constante();}
    //virtual Constante* operator +(Constante * c)const;

};

#endif // CONSTANTE_H


