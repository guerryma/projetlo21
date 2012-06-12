#include "calculatrice.h"


void Calculatrice::OperationBinaire(char operation){
    /*! Traitement d'un opérateur binaire: les opérandes sont dépilées puis l'opération est calculée
      En fonction du type d'opération envoyé en paramètre.
      */
    if(m_pStock.size()>1){
        Constante* op1 = m_pStock.top();
        m_pStock.pop();

        Constante* op2 =m_pStock.top();
        m_pStock.pop();

        QString type;
        Complexe* c1;
        Complexe* c2;
        Rationnel* r1;
        Rationnel* r2;
        /*! Permettra de stocker le type de constante:
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

                Complexe* res=c1->Somme(c2);
                m_pStock.push(res);
            }

            if(type=="rr"){ //! somme rat rat
                Rationnel* res=r1->Somme(r2);
                m_pStock.push(res);
            }
            // Traiter les cas où rationnel + complexe.
            break;

            //! Soustraction
        case '-':
            if (type=="cc") //! <soustraction cpx cpx
            {

                Complexe* res=c1->Difference(c2);
                m_pStock.push(res);
            }

            if(type=="rr"){ //! <soustraction rat rat
                Rationnel* res=r1->Difference(r2);
                m_pStock.push(res);
            }

            break;

            //! Produit:
        case '*':
            if (type=="cc") //! produit cpx cpx
            {

                Complexe* res=c1->Produit(c2);
                m_pStock.push(res);
            }

            if(type=="rr"){ //! produit rat rat
                Rationnel* res=r1->Produit(r2);
                m_pStock.push(res);
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
                }
            }



            if(type=="rr"){ //! Division rat rat
                Rationnel* res=r1->Quotient(r2);
                m_pStock.push(res);
            }

            break;


        default:
            break;

        }
    }else std::cout<<"La pile ne contient pas assez d'éléments"; //envoyer une exception

}

/* Algorithme opération binaire
  1. Récupérer les 2 opérandes. DOnc checker qu'il y en a au moins 2. Sinon envoyer erreur
  et réempiler la donnée.
  2. Vérifier le type.
Si ce sont des nb alors on peut faire l'opération.
Si c'est une expression alors il faut la concaténer.

  3. Appeler la méthode correspondante (grâce à la surcharge des opérateurs.
  Il faudra donc gérer les op de style Complexe/Rationnel
  Division: vérifier le mode pour voir l'opération effectuée
  Mode Complexe On/Of: checker avant l'affichage du résultat si on est en mode On.
  Sinon choisir traitement.

  */


