#include "calculatrice.h"


Constante* Calculatrice::OperationBinaire(char operation){
    /*! Traitement d'un opérateur binaire: les opérandes sont dépilées puis l'opération est calculée
      En fonction du type d'opération envoyé en paramètre.
      */
    if(!m_pStock.empty()){
        Constante* op1 = m_pStock.top();
        m_pStock.pop();
        if (!m_pStock.empty()){
            Constante* op2 =m_pStock.top();
            m_pStock.pop();

            /*switch(operation){
            case 's':
                re
            }*/



        }
        else std::cout<<"Pile vide"; //envoyer une exception

    }
    else std::cout<<"Pile vide"; //envoyer une exception

}

/* Algorithme opération binaire
  1. Récupérer les 2 opérandes. DOnc checker qu'il y en a au moins 2. Sinon envoyer erreur
  et réempiler la donnée.
  2. Vérifier le type.
Si ce sont des nb alors on peut faire l'opération.
Si c'est une expression alors il faut la concaténer.
Si complexe vérifier mode complexe On.

  3. Appeler la méthode correspondante (grâce �  la surcharge des opérateurs.
  Il faudra donc gérer les op de style Complexe/Rationnel
  Division: vérifier le mode pour voir l'opération effectuée
  Mode Complexe On/Of: checker avant l'affichage du résultat si on est en mode On.
  Sinon choisir traitement.

  */


