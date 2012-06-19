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
    Complexe* expP = new Complexe(exp(m_reelle),0); //e(x)
    Complexe* expM = new Complexe(exp(-m_reelle),0); //e(-x)
    Complexe* shInt = expP->Difference(expM); //sh intermediaire
    Complexe* Deux = new Complexe(2, 0);
    return shInt->Quotient(Deux); //sh = (e(x)-e(-x))/2
}

Complexe* Complexe::CosinusH() const{
    Complexe* expP = new Complexe(exp(m_reelle),0); //e(x)
    Complexe* expM = new Complexe(exp(-m_reelle),0); //e(-x)
    Complexe* chInt = expP->Somme(expM); //ch intermediaire
    Complexe* Deux = new Complexe(2, 0);
    return chInt->Quotient(Deux);//ch = (e(x)+e(-x))/2
}

Complexe* Complexe::TangH() const{
    Complexe* sh = SinusH();
    Complexe* ch = CosinusH();

    return sh->Quotient(ch);
}

Complexe* Complexe::LnC()const{
    return new Complexe(qLn(m_reelle), 0);
}
Complexe* Complexe::LogC()const{
    Complexe* ln = LnC();
    Complexe* ln10 = new Complexe(qLn(10));
    return ln->Quotient(ln10);
}


Complexe* Complexe::RacineC()const{
    return new Complexe(qSqrt(m_reelle), 0);
}

Complexe* Complexe::Carre()const{
    float a2, b2; //un complexe c'est a+ib
    float res_re, res_im;

    a2 = qPow(m_reelle, 2); //a au carre
    b2 = qPow(m_imaginaire, 2); //b au carre

    res_re = a2 - b2;
    res_im = 2*m_reelle*m_imaginaire;

    return new Complexe(res_re, res_im);
}

Complexe* Complexe::CubeC()const{
    float a2, b2, a3, b3; //un complexe c'est a+ib
    float res_re, res_im;


    a3 = qPow(m_reelle, 3); //a au cube
    b3 = qPow(m_imaginaire, 3); //b au cube
    
    a2 = qPow(m_reelle, 2); //a au carre
    b2 = qPow(m_imaginaire, 2); //b au carre
    
    res_re = a3-(2*m_reelle*b2)-(b2*m_reelle);
    res_im = (a2*m_imaginaire)+(2*a2*m_imaginaire)-b3;

    return new Complexe(res_re, res_im);
}


