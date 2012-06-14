#include "complexe.h"


Complexe* Complexe:: Somme(const Complexe* c)const{

    // return Complexe(m_reelle+c.m_reelle, m_reelle+c.m_imaginaire);
    return new Complexe(m_reelle+c->GetPartieReelle(), m_imaginaire+c->GetPartieImaginaire());
}

Complexe* Complexe::Oppose()const{
    return new Complexe(-m_reelle, -m_imaginaire);
}

Complexe* Complexe::Difference(const Complexe *c) const{
    return Somme(c->Oppose());
}

Complexe* Complexe::Produit(const Complexe* c) const{
    float r, i;
    r=m_reelle*c->m_reelle - m_imaginaire*c->m_imaginaire;
    i=m_reelle*c->m_imaginaire + m_imaginaire*c->m_reelle;
    return new Complexe(r,i);

}

Complexe* Complexe::Inverse() const{
    float d=(pow(m_reelle,2)+pow(m_imaginaire,2));

    return new  Complexe(m_reelle/d, -m_imaginaire/d);
}

Complexe* Complexe::Quotient(const Complexe* c) const{

    Complexe* y=c->Inverse();
    return Produit(y) ;
}

QString Complexe::Afficher()const{


    if(!m_imaginaire)
        return QString(QString::number(m_reelle));

    return QString(QString::number(m_reelle)+"$"+QString::number(m_imaginaire));

}
