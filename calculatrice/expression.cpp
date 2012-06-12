#include "expression.h"

QStack<QString> Expression::TransformerExpression(){
    QStack<QString> m_stack;// pile intermediaire
    QStack<QString> m_ResStack; //la pile finale
    QString m_res = "res"; //pour simuler le resultat de l'operation
    QString m_err = "Erreur";
    QString m_operand = "";
    QString m_fct = "";
    QString m_expr = "";
    QString m_a, m_b;
    int i;

    i = 1;
    //pour supprimer les cotes
    while(i < m_expression.size()-1){
        m_expr.append(m_expression[i]);
        i++;
    }
    m_expression = m_expr;

    i = 0;
    while(i < m_expression.size()){
        if(QString::compare(QString(m_expression[i])," ") == 0){
            m_expr.append(m_expression[i]);
            i++;

            //supprimer les espaces en trop
            while(QString::compare(QString(m_expression[i])," ") == 0)
                i++;

        }
        m_expr.append(m_expression[i]);
        i++;
    }

    i = 0;
    while(i < m_expression.size()){

        if(QString::compare(QString(m_expression[i])," ") == 0){

            if(m_fct != ""){
                if(m_fct == "SIN"|| m_fct == "COS" || m_fct == "TAN" || m_fct == "COSH"
                   || m_fct == "LN" || m_fct == "LOG" || m_fct == "INV"|| m_fct == "SQRT"
                   || m_fct == "SQR" || m_fct == "CUBE"|| m_fct == "!" || m_fct == "POW"
                   || m_fct == "MOD"|| m_fct == "SIGN"){

                    if(m_stack.isEmpty()){
                        m_ResStack.push(m_err);
                        return m_ResStack;
                    }
                    m_a = m_stack.pop();
                    if(m_a == "res"){
                        m_ResStack.push(m_a);
                    }
                    m_stack.push(m_res);
                    m_ResStack.push(m_fct);
                    m_fct = "";
                }
                else{
                    m_ResStack.push(m_err);
                    return m_ResStack;
                }
            }

            else if(QString::compare(m_operand,"") != 0){
                m_stack.push(m_operand);
                m_operand = "";
            }
        }

        else if(QString(m_expression[i]).contains("+") || QString(m_expression[i]).contains("-")
            || QString(m_expression[i]).contains("*") || QString(m_expression[i]).contains("/")){
            if(m_stack.size() >= 2){
                m_a = m_stack.pop();
                m_b = m_stack.pop();

                if(m_a == "res")
                    m_ResStack.push(m_a);

                if(m_b == "res")
                    m_ResStack.push(m_b);
                m_ResStack.push(QString(m_expression[i]));
                m_stack.push(m_res);
            }
            else{
                m_ResStack.push(m_err);
                return m_ResStack;
            }
        }

        else if(m_expression[i] >= '0' && m_expression[i] <= '9'){
            m_operand.append(m_expression[i]);
        }

        else{
            m_fct.append(m_expression[i]);
        }
        i++;

    }

    if(m_stack.size() != 1)
        m_ResStack.push(m_err);

    return m_ResStack;
}





