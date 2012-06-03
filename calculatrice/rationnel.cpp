#include "rationnel.h"


Rationnel Rationnel::Inverse(){
    if (m_numerateur==0) throw RationnelException("Erreur Inverse d'un nombre nul");

    else return Rationnel(m_denominateur, m_numerateur);
}

Rationnel Somme(Rationnel r1, Rationnel r2){
   int d, n;
   d=r1.GetDenominateur()*r2.GetDenominateur();
   n=r1.GetNumerateur()*r2.GetDenominateur()+r2.GetNumerateur()*r1.GetDenominateur();

   return Rationnel(n,d);
}

Rationnel Produit(Rationnel r1, Rationnel r2){
   return Rationnel(r1.GetNumerateur()*r2.GetNumerateur(), r1.GetDenominateur()*r2.GetDenominateur());
}

Rationnel Division(Rationnel r1, Rationnel r2){
    return Produit(r1, r2.Inverse());
}

