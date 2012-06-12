#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "constante.h"
#include <QStack>
#include <QString>


class Expression//: public Constante
{
/*!
  Une expression est encadrée par des cotes ''
  Il s'agit d'une expression en polonaise inversée qui pourra être évaluée.

  //*/
    QString m_expression;
public:
    Expression(QString m_exp): m_expression(m_exp){}

    QString GetExpression() const {return m_expression;}


    QStack<QString> TransformerExpression();
    /*! Fonction verifie la validite d'une expression,
      et retourne une pile de string si elle est valide.
      Si l'expression n'est pas valide, elle renvoie une
      pile ne contenant que "Erreur".
      */

QString Afficher();
};




#endif // EXPRESSION_H
