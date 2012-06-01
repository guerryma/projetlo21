#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "constante.h"


class Expression: public Constante
{
/*!
  Une expression est encadrée par des cotes ''
  Il s'agit d'une expression en polonaise inversée qui pourra être évaluée.

  //*/
public:
    Expression();

    QString GetExpression() const {return m_constante;}

//void conversion();
};




#endif // EXPRESSION_H
