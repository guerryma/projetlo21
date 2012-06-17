#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "constante.h"
#include <QStack>
#include <QString>
#include <QChar>
#include <QRegExp>



class Expression: public Constante
{
/*!
  Une expression est encadrée par des cotes ''
  Il s'agit d'une expression en polonaise inversée qui pourra être évaluée.

  //*/
    QString m_expression;

public:
    Expression(QString expr): /*Constante("Expr"),*/ m_expression(expr){}


    QString GetExpression() const {return m_expression;}


    QStack<QString> TransformerExpression();


QString Afficher() const {return m_expression;}


};
bool EstUnNombre(QString s);
bool EstUnEntier(QString s);




#endif // EXPRESSION_H
