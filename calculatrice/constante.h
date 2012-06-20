#ifndef CONSTANTE_H
#define CONSTANTE_H
#include <QString>
#include <QDataStream>

class Constante
{
protected:
    QString m_type;
    void SetType(QString t){m_type=t;}
public:
    Constante(){}
    Constante(QString type): m_type(type){}
    Constante(const Constante* & constante){ m_type=constante->m_type;}
    virtual QString Afficher() const=0;
    virtual ~Constante(){};

    QString GetType() const {return m_type;}



    //Opérations

    virtual void Signe()=0;
    virtual void Inverse()=0;
    virtual bool IsNul()=0;

    friend QDataStream & operator >> (QDataStream &, Constante*&);

};

//Entrees sorties fichier

#endif // CONSTANTE_H


