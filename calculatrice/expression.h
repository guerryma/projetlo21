#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "constante.h"
#include <QStack>
#include <QQueue>
#include <QString>
#include <QChar>
#include <QRegExp>


//! Constante expression: chaine de constantes et d'opérateurs pouvant être évaluée
class Expression: public Constante
{
    /*!
  Une expression est encadrÃ©e par des cotes ''
  Il s'agit d'une expression en polonaise inversée qui pourra être évaluée.

  */

    QString m_expression;

public:

    Expression(QString expr): Constante("expression"),m_expression(expr){}

    QString GetExpression() const {return m_expression;}
    void SetExpression(QString s){ m_expression=s;}


    QQueue<QString> TransformerExpression();
    /*! Fonction verifie la validite d'une expression,
      et retourne une file de string si l'expression est valide.
      Si elle n'est pas valide, elle renvoie une
      file contenant en premier element le mot "Erreur".
    */


    QString Afficher() const {return m_expression;}

    //OpÃ©rations
    void Signe(){};
    void Inverse(){ConcatenerDevant("INV");};
    bool IsNul(){return false;}
    //! Dans le cas d'une operation binaire, si l'expression est la 1ere opérande (càd dernier elem empilÃ©)
    Expression* ConcatenerDevant(const QString& operateur,const Constante* constante=0);
    //! Dans le cas d'une operation binaire, si l'expression est la 2e opérande (càd avant dernier elem empilÃ©)
    Expression* ConcatenerDerriere( const QString& operateur, const Constante* constante);


    friend QDataStream & operator >> (QDataStream & , Expression*&);



};
//! Renvoie true si la chaine est un nombre, entier ou dÃ©cimal
bool EstUnNombre(QString s);
//! Renvoie true si la chaine est un entier, positif ou nÃ©gatif
bool EstUnEntier(QString s);

QDataStream & operator << (QDataStream & out, const Expression& Valeur);
QDataStream & operator >> (QDataStream & in,  Expression& Valeur);



#endif // EXPRESSION_H
