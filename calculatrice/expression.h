#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "constante.h"

QString ExpressionValide(QString expression);//Cette méthode permet de vérifier que l'on entre une expression valide entre côtes
//avec le bon nombre d'éléments::

class Expression: public Constante
{
public:
    Expression();
    Expression(QString expression):Constante(ExpressionValide(expression))
    {
    }
    QString GetExpression() const {return m_constante;}

//void conversion();
};




#endif // EXPRESSION_H
