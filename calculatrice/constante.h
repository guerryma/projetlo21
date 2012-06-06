#ifndef CONSTANTE_H
#define CONSTANTE_H
#include <QString>

class Constante
{
    QString m_type;
public:
    Constante(){}
    Constante(QString type): m_type(type){}
    virtual QString Afficher()=0;
    virtual ~Constante(){};


    //Opérations

};

#endif // CONSTANTE_H
