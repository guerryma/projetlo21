#include "rationnel.h"


Rationnel* Rationnel::Inverse() const{
    if (m_numerateur==0) throw RationnelException("Erreur Inverse d'un nombre nul");

    else return new Rationnel(m_denominateur, m_numerateur);
}

Rationnel* Rationnel::Somme(const Rationnel* r2) const{
   int d, n;
   d=m_denominateur*r2->GetDenominateur();
   n=m_numerateur*r2->GetDenominateur()+r2->GetNumerateur()*m_denominateur;

   return new Rationnel(n,d);
}

Rationnel* Rationnel::Oppose() const{
    return new Rationnel(-m_numerateur, m_denominateur);
}

Rationnel* Rationnel::Difference(const Rationnel *r2) const{
    return Somme(r2->Oppose());
}

Rationnel* Rationnel::Produit(const Rationnel* r2)const{
   return new Rationnel(m_numerateur*r2->GetNumerateur(), m_denominateur*r2->GetDenominateur());
}

Rationnel* Rationnel::Quotient(const Rationnel* r2)const{
    return Produit(r2->Inverse());
}

QString Rationnel::Afficher() const{
    return QString(QString::number(m_numerateur)+"/"+QString::number(m_denominateur));
}

void Rationnel::VerifSigne(){
    if(m_denominateur<0){

            m_denominateur=-m_denominateur;
            m_numerateur=-m_numerateur;
        }
}
