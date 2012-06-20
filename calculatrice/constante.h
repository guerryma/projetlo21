#ifndef CONSTANTE_H
#define CONSTANTE_H
#include <QString>
#include <QDataStream>

//! Classe abstraite dont héritent les Complexes, les Expressions et les Rationnels
class Constante
{
protected:
    QString m_type;
    void SetType(QString t){m_type=t;}
public:
    Constante(){}
    Constante(QString type): m_type(type){}
    Constante(const Constante* & constante){ m_type=constante->m_type;}
    virtual QString Afficher() const=0;//! Affichage de la constante adapté en fonction de son type
    virtual ~Constante(){};

    QString GetType() const {return m_type;}



    //Opérations

    virtual void Signe()=0;//! Patron de fonction: on surchargera ces fonctions pour qu'elles appellent la méthode associée sans avoir besoin de caster la constante
    virtual void Inverse()=0;
    virtual bool IsNul()=0;

    friend QDataStream & operator >> (QDataStream &, Constante*&);

};


#endif // CONSTANTE_H


