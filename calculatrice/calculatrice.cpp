#include "calculatrice.h"
#include"expression.h"


bool Calculatrice::OperationBinaire(char operation){
    /*! Traitement d'un opérateur binaire: les opérandes sont dépilées puis l'opération est calculée
      En fonction du type d'opération envoyé en paramètre.
      */
    if(m_pStock.size()>1){
        Constante* op1 = m_pStock.pop();
        Constante* op2 =m_pStock.pop();


        QString type;
        Complexe* c1;
        Complexe* c2;
        Rationnel* r1;
        Rationnel* r2;


        /*! type Permettra de stocker le type de constante:
          cc pour 2 complexes
          rr pour 2 rationnels
          rc ou cr pour cpx et rationnel
          pour une expression => Il faudra gérer concaténation en fonction du type
          */

        //! Détermination du type de constante

        if (op1->GetType()=="complexe" && op2->GetType()=="complexe")
        {
            c1=dynamic_cast<Complexe*>(op1);
            c2=dynamic_cast<Complexe*>(op2);

            type="cc";
        }

        else if (op1->GetType()=="rationnel"&& op2->GetType()=="rationnel"){
            r1=dynamic_cast<Rationnel*>(op1);
            r2=dynamic_cast<Rationnel*>(op2);

            type="rr";
        }



        switch(operation){
        case '+':
            if (type=="cc") //! somme cpx cpx
            {

                //Complexe* res=c1->Somme(c2);
                m_pStock.push(c1->Somme(c2));
                return true;
            }

            if(type=="rr"){ //! somme rat rat
                Rationnel* res=r1->Somme(r2);
                m_pStock.push(res);
                return true;
            }
            // Traiter les cas où rationnel + complexe.
            break;

            //! Soustraction
        case '-':
            if (type=="cc") //! <soustraction cpx cpx
            {

                Complexe* res=c1->Difference(c2);
                m_pStock.push(res);
                return true;
            }

            if(type=="rr"){ //! <soustraction rat rat
                Rationnel* res=r1->Difference(r2);
                m_pStock.push(res);
                return true;
            }

            break;

            //! Produit:
        case '*':
            if (type=="cc") //! produit cpx cpx
            {

                Complexe* res=c1->Produit(c2);
                m_pStock.push(res);
                return true;
            }

            if(type=="rr"){ //! produit rat rat
                Rationnel* res=r1->Produit(r2);/* Complexe**/
                m_pStock.push(res);
                return true;
            }

            break;
            //! Division:
        case '/':
            //! Dans le cas de la division réelle sur des complexes, on réalise la division et on retourne un complexe
            if (m_type==REEL){
                if (type=="cc") //! Division cpx cpx
                {

                   Complexe* res=c1->Quotient(c2);
                    m_pStock.push(res);
                    return true;
                }
            }



            if(type=="rr"){ //! Division rat rat
                Rationnel* res=r1->Quotient(r2);
                m_pStock.push(res);
                return true;
            }

            break;


        default:
            break;
        }
    }
    else std::cout<<"La pile ne contient pas assez d'éléments";
    return false;//envoyer une exception


}


//void Calculatrice::OperationBinaire2(char operation){
//    std::cout<<"coucou";
//}

/* Algorithme opération binaire
  1. Récupérer les 2 opérandes. DOnc checker qu'il y en a au moins 2. Sinon envoyer erreur
  et réempiler la donnée.
  2. Vérifier le type.
Si ce sont des nb alors on peut faire l'opération.
Si c'est une expression alors il faut la concaténer.

  3. Appeler la méthode correspondante
  Division: vérifier le mode pour voir l'opération effectuée
  Mode Complexe On/Of: checker avant l'affichage du résultat si on est en mode On.
  Sinon choisir traitement.

  */
bool Calculatrice::MajPileS(QString s){
    Constante* c;

    /*! Cas 1: On a entr� une expression: elle est construite
      La v�rification se fera seulement si on appelle EVAL */
    if(s.startsWith("'")){
        if(s.endsWith("'")) c= new Expression(s);

        else  return false;

    }

    /*! Cas 2: on entre une constante complexe.
      Rappel: On ne peut pas rentrer un rationnel directement. Un rationnel est construit slmt si on d�pile
      2 op�randes et que l'on est en mode rationnel
      */

    //! Complexe "classique" seulement si le mode complexe est activ�. sinon renvoyer une erreur.
    else if(s.contains("$")&& m_modeComplexe ){
        int n=s.indexOf('$');
        QStringRef re=s.leftRef(n);
        QStringRef im=s.rightRef(n);
        if(EstUnNombre(QString(re.toString()))&& EstUnNombre(QString(im.toString())))
            c= new Complexe(re.toString().toFloat(), im.toString().toFloat());
        else return false;
    }
    else if(EstUnNombre(s)) c= new Complexe(s.toFloat());
        else return false;

     m_pStock.push(c);
    //m_calc.EmpilerPileA(s); Gestion  historique
    return true;

}

