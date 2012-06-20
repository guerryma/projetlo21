#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include "complexe.h"
#include "expression.h"
#include "rationnel.h"
#include <QStack>
#include <QQueue>
#include <iostream>
#include <QSettings>
#include<QFile>
#include <QDataStream>
#include<QVector>


enum Angle{RADIAN, DEGRE};
enum Type{RATIONNEL, REEL, ENTIER};

class CalculatriceException /*: public exception*/ {
    QString info;
public:
    CalculatriceException(const QString& s):info(s){}
    const QString& what() const {return info;}
};

//! La Classe calculatrice gère toutes les opérations sur les constantes
class Calculatrice
        /*! La classe Calculatrice est le coeur de l'application.
       Elle permet de réaliser toutes les opérations sur les Constantes.
       Les paramètres de la pile sont sauvegardés à chaque exécution.
                          */
{
    QStack<Constante*> m_pStock;
    int m_taille; //! taille de la pile d'affichage
    int m_MAX; //! taille max de la pile
    Angle m_angle;
    Type m_type;
    bool m_modeComplexe;//! si le mode complexe n'est pas activé,on ne peut pas créer de complexes non réels

    QSettings m_param;

    /*!
      Attributs permettant d'�  annuler ou rétablir:
      A chaque modification, on empile la pile courante dans m_memoAnnul.
      A chaque Annulation, on empile la pile annulée dans m_memoRetab
      A chaque Retablissement, on considère que l'on a modifié la table et donc
      on empile la pile courante avant de charger la nouvelle.

      */
    QStack<QStack<Constante*> > m_memoAnnul;
    QStack<QStack<Constante*> > m_memoRetab;




public:
    Calculatrice(){}
     inline Calculatrice(QObject* parent=0):
       m_MAX(20), m_param("../parametres.ini", QSettings::IniFormat, parent)
    {
        ChargerOptions();
       // ChargerPile();

        m_memoAnnul.push(m_pStock);

    }


   //Accesseurs
int GetTaille() const {return m_taille;}
Angle GetAngle() const {return m_angle;}
Type GetType() const {return m_type;}
bool GetModeComplexe() const {return m_modeComplexe;}

void SetTaille(int n){m_taille=n;}
void SetAngle(Angle a){m_angle=a;}
void SetType(Type t){m_type=t;}
void SetModeComplexe(bool b){m_modeComplexe=b;}

//Operations sur les piles

QStack<Constante*> GetPileS()const {return m_pStock;}
void EmpilerPileS(Constante* c); //!< Permet d'empiler tout en vérifiant la taille et en sauvegardant la pile courante.
Constante* DepilerPileS();//! <Permet de dépiler tout en sauvegardant dans la pile d'annulation

//Gestion de la pile (calculs)

bool OperationBinaire(char operation);//!< Permet de gérer les opérations + * / -
bool EvalExpression(QQueue<QString> pileExpr,Expression* expr=0);//!< Evaluation d'une constante expression
bool Signe();
bool Inverse();
bool Mod(); //!< Calcule le modulo d'un entier et renvoie un booleen
bool Pow(); //!< Calcule la puissance d'un entier, rationnel ou reel et renvoie un booleen


//Operations unaires
bool Sin(); //!< Calcule le sinus d'un entier, rationnel ou reel et renvoie un booleen
bool Cos(); //!< Calcule le cosinus d'un entier, rationnel ou reel et renvoie un booleen
bool Tan(); //!< Calcule la tangente d'un entier, rationnel ou reel et renvoie un booleen
bool SinH(); //!< Calcule le sinus  hyperbolique d'un entier, rationnel ou reel et renvoie un booleen
bool CosH(); //!< Calcule le cosinus hyperbolique d'un entier, rationnel ou reel et renvoie un booleen
bool TanH(); //!< Calcule la tangente hyperbolique d'un entier, rationnel ou reel et renvoie un booleen
bool Ln(); //!< Calcule le logarithme neperien d'un entier, rationnel ou reel et renvoie un booleen
bool Log(); //!< Calcule le logarithme decimal d'un entier, rationnel ou reel et renvoie un booleen
bool Sqrt();  //!< Calcule la racine carree d'un entier, rationnel ou reel et renvoie un booleen
bool Sqr();  //!< Calcule le carre d'une constante (entier, rationnel, reel ou complexe) et renvoie un booleen
bool Cube(); //!< Calcule le cube d'une constante (entier, rationnel, reel ou complexe) et renvoie un booleen
bool Fact(); //!< Calcule le factoriel d'un entier et renvoie un booleen

//Opérations sur la pile
bool MajPileS(QString s);//!< Permet d'empiler les constantes entrées par l'utilisateur dans le type approprié
bool Swap();
/* ! Inversion de l'�l�ment num�ro x et l'�l�ment num�ro y de la pile (o�
x et y sont les arguments de l'op�rateur) (entier)
*/

bool Sum();
/* ! Somme des x premiers �l�ments de la pile (o� x est l'argument)
(entier)
*/

bool Mean();
/* ! Moyenne des x premiers �l�ments de la pile (o� x est l'argument)
(entier)
 */

void Clear(); // !< Vide la pile
bool Dup(); // !<Duplique le premier element de la pile
bool Drop(); // !<Supprime le premier element de la pile
bool DropTete();

//Parametrage
    void EnregistrerParametres();//!< sauvegarde les paramètres pour la prochaine exécution
    void SauvegarderPile();
    bool Annuler();
    bool Retablir();
private:
    void ChargerOptions();
    void ChargerPile();
};

QDataStream & operator << (QDataStream & out, Constante* & Valeur);
QDataStream & operator >> (QDataStream & in,  Constante* & Valeur);


#endif // CALCULATRICE_H
