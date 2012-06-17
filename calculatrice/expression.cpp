#include "expression.h"

QStack<QString> Expression::TransformerExpression(){
    /*! Fonction verifie la validite d'une expression,
      et retourne une pile de string si elle est valide.
      Si l'expression n'est pas valide, elle renvoie une
      pile ne contenant en dernier element "Erreur".
      */
    QStack<QString> stack;// pile intermediaire
    QStack<QString> resStack; //la pile finale
    QString res = "res"; //pour simuler le resultat de l'operation
    QString err = "Erreur";
    QString operand = ""; //operand + - / ou *
    QString fct = ""; //les fonctions unaires
    QString expr = ""; //expression intermediaire
    QString a, b; //constantes
    int i;

    i = 1;
    //on copie l'expression dans une variable intermediaire en supprimant les cotes
    while(i < m_expression.size()-1){
        expr.append(m_expression[i]);
        i++;
    }
    m_expression = expr; //on remet l'expression recuperee sans les cotes dans l'attribut

    i = 0;
    while(i < m_expression.size()){//on parcourt l'expression sans les cotes
        if(QString::compare(QString(m_expression[i])," ") == 0){//si le caractere est un espace
            expr.append(m_expression[i]);//on l'ajoute une fois dans l'expression que l'on veut recuperer
            i++;//on passe au caractere suivant

            //et on supprime les espaces en trop
            while(QString::compare(QString(m_expression[i])," ") == 0)
                i++;
            //quand on sort de la boucle, on est sur un caractere qui n'est pas un espace
        }
        expr.append(m_expression[i]);//que l'on ajoute a l'expr que l'on veut recuperer
        i++; //on passe au caractere suivant
    }

    i = 0;
    while(i < m_expression.size()){ //on parcourt maintenant l'expression pour tester sa validite

        if(QString::compare(QString(m_expression[i])," ") == 0){//si on a un espace il faut regarder
                        //si on vient de recuperer une fonction, une constante ou un operateur

            if(fct != ""){//si la variable qui contient les fonctions unaires n'est pas nulle
                if(fct == "SIN"|| fct == "COS" || fct == "TAN" || fct == "COSH"
                        || fct == "LN" || fct == "LOG" || fct == "INV"|| fct == "SQRT"
                        || fct == "SQR" || fct == "CUBE"|| fct == "!" || fct == "POW"
                        || fct == "MOD"|| fct == "SIGN"){//si ça correspond a l'une de ces valeurs

                    if(stack.isEmpty()){//si la pile est vide
                        resStack.push(err);//on empile sur la pile de resultat le message d'erreur
                        return resStack;//et on retourne la pile resultat
                    }
                    a = stack.pop();//on depile une constante de la pile intermediare
                    if(a != "res"){ //si ce n'est une constante qui simule le resultat
                        resStack.push(a); //on l'empile dans la pile de resultat
                    }
                    stack.push(res); //on empile la variable qui simule le resultat dans la pile
                    resStack.push(fct);//on empile la fonction unaire sur la pile de resultat
                    fct = "";//on remet le contenu de la variable à 0
                }
                else{//sinon si ça ne correspond a aucune des fonctions comparees plus haut
                    resStack.push(err); //on empile la variable erreur sur la pile de resultat
                    return resStack;//et on renvoie la pile de resultat
                }
            }

            else if(QString::compare(operand,"") != 0){//sinon si la variable qui contient les operandes n'est pas nulle
                if(operand.contains("$")){ //si l'operande contient $
                    if(operand.count("$") > 1){ // si il le contient en plusieurs exemplaire
                        resStack.push(err);
                        return resStack;
                    }
                }

                else if(operand.contains(",")){ //si l'operande contient ,
                    if(operand.count(",") > 1){ // si il le contient en plusieurs exemplaire
                        resStack.push(err);
                        return resStack;
                    }
                }

                else if(operand.contains("/")){ //si l'operande contient /
                    if(operand.count("/") > 1){ // si il le contient en plusieurs exemplaire
                        resStack.push(err);
                        return resStack;
                    }
                }
                stack.push(operand);//on empile l'orerande dans la pile intermediaire
                operand = ""; //on remet la variable a 0
            }
        }

        //sinon si on a un de ces operateur
        else if(QString(m_expression[i]).contains("+") || QString(m_expression[i]).contains("-")
                || QString(m_expression[i]).contains("*") || QString(m_expression[i]).contains("/") && QString(m_expression[i-1]).contains(" ")){
            if(stack.size() >= 2){//on verifie que l'on a au moins deux constantes
                a = stack.pop(); //on depile les deux constantes
                b = stack.pop();

                if(b != "res") //si ce n'est pas une variable qui simule un resultat
                    resStack.push(b); //on empile la constante dans la pile de resultat

                if(a != "res") //si ce n'est pas une variable qui simule un resultat
                    resStack.push(a);//on empile la constante dans la pile de resultat

                resStack.push(QString(m_expression[i]));//on empile l'operande dans la pile de resultat
                stack.push(res);//on empile une variable qui simule le resultat dans la pile intermediaire
            }
            else{//sinon c'est que la pile ne contient pas assez d'argument
                resStack.push(err);//empilement de l'erreur dans la pile de resultat
                return resStack;//on retourne la pile de resultat
            }
        }

        else if(m_expression[i] >= '0' && m_expression[i] <= '9' ||
                m_expression[i] == ',' && m_expression[i-1] >= '0' && m_expression[i-1] <= '9'
                || m_expression[i] == '$' && m_expression[i-1] >= '0' && m_expression[i-1] <= '9'
                || m_expression[i] == '/' && m_expression[i-1] >= '0' && m_expression[i-1] <= '9'){ //sinon si on a un chiffre entre 0 et 9 ou un complexe ou un reel
            operand.append(m_expression[i]);//on ajoute les chiffres pour en faire un nombre
        }

        else{
            fct.append(m_expression[i]); // sinon c'est que c'est une fonction
        }
        i++;

    }

    //A la fin de la boucle
    if(stack.size() != 1) //si on a pas une seule constante dans la pile c'est que l'expression n'est pas valide
        resStack.push(err); //et donc on empile l'erreur

    return resStack;//on retourne la pile de resultat
}


bool EstUnNombre(QString s){
    /*! VÃ©rifie que la chaine entrÃ©e est  bien un float*/


    QRegExp nombre("^[\-]{0,1}[0-9]{1,}(([\.\,]{0,1}[0-9]{1,})|([0-9]{0,}))$");
    if (s.contains(nombre)) return true;
    return false;

}

bool EstUnEntier(QString s){
    QRegExp entier("^[+-]?[0-9]+$");
    if(s.contains(entier)) return true;
    return false;

}


