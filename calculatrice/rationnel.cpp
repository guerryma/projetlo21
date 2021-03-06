#include "rationnel.h"


Rationnel* Rationnel::Inverse2(){
    if (m_numerateur==0) throw RationnelException("Erreur Inverse d'un nombre nul");

    else{
        int den=m_numerateur;
        int num=m_denominateur;
        this->SetDenominateur(1); // Il faut changer la valeur du dénominateur pour que VérifSigne ne tranforme pas le rationnel
        this->SetNumerateur(num);
        this->SetDenominateur(den);

        return this;
    }
}
void Rationnel::Inverse(){
    Inverse2();
}

Rationnel* Rationnel::Somme(const Rationnel* r2) const{
    int d, n;
    d=m_denominateur*r2->GetDenominateur();
    n=m_numerateur*r2->GetDenominateur()+r2->GetNumerateur()*m_denominateur;

    return new Rationnel(n,d);
}

Rationnel* Rationnel::Oppose() {
    SetNumerateur(-m_numerateur);
    return this;
}
void Rationnel::Signe(){
    Oppose();
}

Rationnel* Rationnel::Difference(Rationnel *r2) const{
    return Somme(r2->Oppose());
}

Rationnel* Rationnel::Produit(const Rationnel* r2)const{
    return new Rationnel(m_numerateur*r2->GetNumerateur(), m_denominateur*r2->GetDenominateur());
}

Rationnel* Rationnel::Quotient(Rationnel* r2)const{
    return Produit(r2->Inverse2());
}

QString Rationnel::Afficher() const{
    if(m_denominateur==1) return QString(QString::number(m_numerateur));
    return QString(QString::number(m_numerateur)+"/"+QString::number(m_denominateur));
}

void Rationnel::VerifSigne(){
    if(m_denominateur<0){

        m_denominateur=-m_denominateur;
        m_numerateur=-m_numerateur;
    }
    if(m_denominateur==m_numerateur){
        m_numerateur=1;
        m_denominateur=1;
    }
}

Rationnel* Rationnel::to_rationnel(Complexe *c){
    if(EstUnEntier(c->Afficher()))
        return new Rationnel(c->GetPartieReelle());
    return 0;
}

Rationnel* Rationnel::Facto()const{
    int fact = 1;

    for(int i = 1; i<= m_numerateur; i++){
        fact = fact* i;
    }
    return new Rationnel(fact);
}


Rationnel* Rationnel::Modulo(Rationnel* r)const{
    int res = m_numerateur%r->GetNumerateur();
    return new Rationnel(res);
}

QDataStream & operator << (QDataStream & out, const Rationnel& Valeur){

    out<<int(Valeur.GetNumerateur())
       <<int(Valeur.GetDenominateur());
    return out;
}

QDataStream & operator >> (QDataStream & in, Rationnel& Valeur){
    int n;
    int d;
    in>>n;
    in>>d;
    Valeur.SetNumerateur(n);
    Valeur.SetDenominateur(d);
    return in;

}
