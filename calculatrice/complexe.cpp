#include "complexe.h"
#include <cmath>

Complexe* Complexe:: Somme(Complexe c){

   // return Complexe(m_reelle+c.m_reelle, m_reelle+c.m_imaginaire);
    return new Complexe(m_reelle+c.GetPartieReelle(), m_imaginaire+c.GetPartieImaginaire());
}


Complexe* Complexe::Produit(Complexe c){
    float r, i;
    r=m_reelle*c.m_reelle - m_imaginaire*c.m_imaginaire;
    i=m_reelle*c.m_imaginaire + m_imaginaire*c.m_reelle;
    return new Complexe(r,i);

}

Complexe Complexe::Inverse(){
    float d=(pow(m_reelle,2)+pow(m_imaginaire,2));

    return  Complexe(m_reelle/d, -m_imaginaire/d);
}

Complexe* Complexe::Quotient(Complexe c){

    Complexe y=c.Inverse();
    return Produit(y) ;
}

QString Complexe::Afficher(){
    return QString(QString::number(m_reelle)+" +i "+QString::number(m_imaginaire));
}
