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

    virtual void Signe()=0;
    virtual void Inverse()=0;

};

#endif // CONSTANTE_H


