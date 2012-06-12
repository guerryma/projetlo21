#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "constante.h"
#include <QStack>
#include <QString>


<<<<<<< HEAD

=======
class Expression: public Constante
>>>>>>> a8533b4760f228fdbe6474b40a904f2fa0f6dc27
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
    /*! Fonction verifie la validite d'une expression,
      et retourne une pile de string si elle est valide.
      Si l'expression n'est pas valide, elle renvoie une
      pile ne contenant que "Erreur".
      */

QString Afficher() const {return m_expression;}
};




#endif // EXPRESSION_H
