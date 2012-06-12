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



        switch(operation){
        case '+':
            if (op1->GetType()=="complexe" && op2->GetType()=="complexe")
            {
                Complexe* c1=dynamic_cast<Complexe*>(op1);
                Complexe* c2=dynamic_cast<Complexe*>(op2);


                Complexe* res=c1->Somme(c2);
                m_pStock.push(res);
            }
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


