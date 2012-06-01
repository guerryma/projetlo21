#include "complexe.h"
#include <cmath>

Complexe Somme(Complexe c1, Complexe c2){

   // return Complexe(m_reelle+c.m_reelle, m_reelle+c.m_imaginaire);
    return Complexe(c1.GetPartieReelle()+c2.GetPartieReelle(), c1.GetPartieImaginaire()+c2.GetPartieImaginaire());
}

Complexe Complexe::Produit(Complexe c){
    float r, i;
    r=m_reelle*c.m_reelle - m_imaginaire*c.m_imaginaire;
    i=m_reelle*c.m_imaginaire + m_imaginaire*c.m_reelle;
    return Complexe(r,i);

}

Complexe Complexe::Inverse(){
    float d=(pow(m_reelle,2)+pow(m_imaginaire,2));

    return Complexe(m_reelle/d, -m_imaginaire/d);
}

Complexe Complexe::Quotient(Complexe c){

    Complexe y=c.Inverse();
    return Produit(y) ;
}
