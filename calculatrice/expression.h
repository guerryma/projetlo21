#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "constante.h"
#include <QString>


class Expression//: public Constante
{
/*!
  Une expression est encadrée par des cotes ''
  Il s'agit d'une expression en polonaise inversée qui pourra être évaluée.

  //*/
    QString m_expression;
public:
    Expression();

    QString GetExpression() const {return m_expression;}

QString Afficher();
};




#endif // EXPRESSION_H
