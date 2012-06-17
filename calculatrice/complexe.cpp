#include "complexe.h"


Complexe* Complexe:: Somme(const Complexe* c)const{

    // return Complexe(m_reelle+c.m_reelle, m_reelle+c.m_imaginaire);
    return new Complexe(m_reelle+c->GetPartieReelle(), m_imaginaire+c->GetPartieImaginaire());
}

Complexe* Complexe::Oppose(){
    SetPartieReelle(-m_reelle);
    SetPartieImaginaire(-m_imaginaire);
    return this;
}
void Complexe::Signe(){
    Oppose();
}

Complexe* Complexe::Difference( Complexe *c) const{
    c->Oppose();
    return Somme(c);
}

Complexe* Complexe::Produit(const Complexe* c) const{
    float r, i;
    r=m_reelle*c->m_reelle - m_imaginaire*c->m_imaginaire;
    i=m_reelle*c->m_imaginaire + m_imaginaire*c->m_reelle;
    return new Complexe(r,i);

}

Complexe* Complexe::InversePrive(){
    float d=(pow(m_reelle,2)+pow(m_imaginaire,2));
    SetPartieReelle(m_reelle/d);
    SetPartieImaginaire(-m_imaginaire/d);

    return this;
}

void Complexe::Inverse(){
   InversePrive();
}

Complexe* Complexe::Quotient(Complexe* c) const{

    Complexe* y=c->InversePrive();
    return Produit(y) ;
}

QString Complexe::Afficher()const{

    return QString(QString::number(m_reelle)+"$"+QString::number(m_imaginaire));
}

Complexe* Complexe::Sinus() const{
   return new Complexe(qSin(m_reelle),0);
}

Complexe* Complexe::Cosinus() const{
    return new Complexe(qCos(m_reelle),0);
}
Complexe* Complexe::Tang() const{
    Complexe* sin = Sinus();
    Complexe* cos = Cosinus();

    return sin->Quotient(cos);
}

Complexe* Complexe::SinusH() const{
    Complexe* cos = Cosinus();
    Complexe* sin = Sinus();

    Complexe* expP = cos->Somme(sin); //e(x) = cos(x) + sin(x)
    Complexe* expM = cos->Difference(sin); //e(-x) = cos(x) - sin(x)

    Complexe* shInt = expP->Difference(expM); //sh intermediaire
    Complexe* Deux = new Complexe(2, 0);

    return shInt->Quotient(Deux); //sh = (e(x)-e(-x))/2
}

Complexe* Complexe::CosinusH() const{
    Complexe* cos = Cosinus();
    Complexe* sin = Sinus();

    Complexe* expP = cos->Somme(sin); //e(x) = cos(x) + sin(x)
    Complexe* expM = cos->Difference(sin); //e(-x) = cos(x) - sin(x)

    Complexe* chInt = expP->Difference(expM); //ch intermediaire
    Complexe* Deux = new Complexe(2, 0);

    return chInt->Quotient(Deux); //ch = (e(x)+e(-x))/2
}

Complexe* Complexe::TangH() const{
    Complexe* sh = SinusH();
    Complexe* ch = CosinusH();

    return sh->Quotient(ch);
}

Complexe* Complexe::Ln()const{
    return new Complexe(qLn(m_reelle), 0);
}
Complexe* Complexe::Log()const{
    Complexe* ln = Ln();
    Complexe* ln10 = new Complexe(qLn(10));
    return ln->Quotient(ln10);
}


Complexe* Complexe::RacineC()const{
    return new Complexe(qSqrt(m_reelle), 0);
    //Ajouter cas nombre négatif
}

Complexe* Complexe::Carre()const{
    return new Complexe(qPow(m_reelle, 2), 0);
    //ajouter pour le cas d'un vrai complexe
}

Complexe* Complexe::Cube()const{
    return new Complexe(qPow(m_reelle, 3), 0);
    //ajouter pour le cas d'un vrai complexe
}

Complexe* Complexe::Fact()const{
    float fac = 1;
    int i;

    for(i = 1; i < m_reelle+1; i++){
        fac = fac*i;
    }

    return new Complexe(fac, 0);
}
