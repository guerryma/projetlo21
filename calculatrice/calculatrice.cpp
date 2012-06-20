#include "calculatrice.h"


void Calculatrice::EmpilerPileS(Constante *c){
    m_memoAnnul.push(m_pStock);
    m_pStock.push(c);
    if(m_pStock.size()==m_taille){
        DropTete(); //!< Si la pile dÈpasse la taille parametree, on efface le dernier ÈlÈment
    }

}

Constante*::Calculatrice::DepilerPileS(){
    if(!m_pStock.isEmpty()) m_memoAnnul.push(m_pStock);
    return m_pStock.pop();
}

void Calculatrice::EnregistrerParametres(){
    m_param.setValue ("taille",m_taille);
    m_param.setValue ("type",m_type);
    m_param.setValue ("angle",m_angle);
    m_param.setValue("complexe",m_modeComplexe);


}
void Calculatrice::ChargerOptions(){

    m_taille=m_param.value("taille",10).toInt();
    m_type=(Type)m_param.value("type", RADIAN).toInt();
    m_angle=(Angle)m_param.value("angle",REEL).toInt();
    m_modeComplexe=m_param.value("complexe",true).toBool();
}

void Calculatrice::ChargerPile(){
    QFile pile("../pile.dat");
    pile.open(QIODevice::ReadOnly);
    QDataStream in(&pile);

    in>>m_pStock;
    pile.close();

}

void Calculatrice::SauvegarderPile(){
    QFile pile("../pile.dat");
    pile.open(QIODevice::WriteOnly);
    QDataStream out(&pile);


    out<<m_pStock;
    pile.close();

}

bool Calculatrice::Annuler(){
    if(!m_memoAnnul.isEmpty()){
        m_memoRetab.push(m_pStock);
        m_pStock=m_memoAnnul.pop();
        return true;
    }

    return false;
}

bool Calculatrice::Retablir(){
    if(!m_memoRetab.isEmpty()){
        m_memoAnnul.push(m_pStock);
        m_pStock=m_memoRetab.pop();

        return true;
    }
    return false;

}

bool Calculatrice::OperationBinaire(char operation){
    /*! Traitement d'un op√©rateur binaire: les op√©randes sont d√©pil√©es puis l'op√©ration est calcul√©e
      En fonction du type d'op√©ration envoy√© en param√®tre.
      */
    if(m_pStock.size()>1){
        Constante* op1 = DepilerPileS();
        Constante* op2 =DepilerPileS();


        QString type;
        Complexe* c1;
        Complexe* c2;
        Rationnel* r1;
        Rationnel* r2;
        Expression* e1;
        Expression *e2;


        /*! type Permettra de stocker le type de constante:
          cc pour 2 complexes
          rr pour 2 rationnels
          Si on a un complexe et un rationnel, le rationnel est toujours transformÈ en complexe
          pour une expression => Il faudra g√©rer concat√©nation en fonction du type
          */

        //! D√©termination du type de constante

        if (op1->GetType()=="complexe" && op2->GetType()=="complexe")
        {
            c1=dynamic_cast<Complexe*>(op1);
            c2=dynamic_cast<Complexe*>(op2);

            type="cc";
        }
        else if (op1->GetType()=="rationnel"&& op2->GetType()=="rationnel"){
            r1=dynamic_cast<Rationnel*>(op1);
            r2=dynamic_cast<Rationnel*>(op2);

            type="rr";
        }
        else if(op1->GetType()=="rationnel"&& op2->GetType()=="complexe"){
            c2=dynamic_cast<Complexe*>(op2);
            r2=Rationnel::to_rationnel(c2); //!< On vÈrifie si l'on a un complexe entier.

            r1=dynamic_cast<Rationnel*>(op1);

            if(r2) type="rr";
            else{
                c1=r1->to_complexe();
                type="cc";}
        }
        else if(op1->GetType()=="complexe"&& op2->GetType()=="rationnel"){
            c1=dynamic_cast<Complexe*>(op1);
            r1=Rationnel::to_rationnel(c1); //!< On vÈrifie si l'on a un complexe entier.
            r2=dynamic_cast<Rationnel*>(op2);

            if(r1) type="rr";
            else{
                c2=r2->to_complexe();

                type="cc";
            }
        }
        else if(op1->GetType()=="expression"){
            e1=dynamic_cast<Expression*>(op1);
            e2=e1->ConcatenerDevant(QString(operation),op2);
            EmpilerPileS(e2);
            return true;
        }
        else if(op2->GetType()=="expression"){
            e2=dynamic_cast<Expression*>(op2);
            e1=e2->ConcatenerDerriere(QString(operation),op1);
            EmpilerPileS(e1);
            return true;

        }

        switch(operation){
        case '+':
            if (type=="cc") //! somme cpx cpx
            {
                EmpilerPileS(c1->Somme(c2));
                return true;
            }

            if(type=="rr"){ //! somme rat rat

                EmpilerPileS(r1->Somme(r2));
                return true;
            }

            break;

            //! Soustraction
        case '-':
            if (type=="cc") //! <soustraction cpx cpx
            {

                EmpilerPileS(c1->Difference(c2));
                return true;
            }

            if(type=="rr"){ //! <soustraction rat rat
                EmpilerPileS(r1->Difference(r2));
                return true;
            }

            break;

            //! Produit:
        case '*':
            if (type=="cc") //! produit cpx cpx
            {
                EmpilerPileS(c1->Produit(c2));
                return true;
            }

            if(type=="rr"){ //! produit rat rat
                EmpilerPileS(r1->Produit(r2));
                return true;
            }

            break;
            //! Division:
        case '/':
            //! Dans le cas de la division r√©elle sur des rationnels, on r√©alise la division et on retourne un complexe
            if(op2->IsNul() )throw RationnelException("Division par zero non autorisee");
            else{
                if (m_type==REEL){
                    if (type=="cc") //! Division cpx cpx
                    {
                        EmpilerPileS(c1->Quotient(c2));
                        return true;
                    }
                    if(type=="rr"){
                        EmpilerPileS(r1->to_complexe()->Quotient(r2->to_complexe()));
                        return true;
                    }

                }


                else if(m_type==RATIONNEL){
                    if(type=="rr"){ //! Division rat rat
                        EmpilerPileS(r1->Quotient(r2));
                        return true;
                    }
                    else if(EstUnEntier(c1->Afficher())&& EstUnEntier(c2->Afficher())){
                        r1=new Rationnel((int)c1->GetPartieReelle());
                        r2=new Rationnel((int)c2->GetPartieReelle());
                        EmpilerPileS(r1->Quotient(r2));
                        return true;
                    }

                    else{
                        EmpilerPileS(op2);
                        EmpilerPileS(op1);
                        throw(CalculatriceException("Une des operandes n'est pas un rationnel"));
                        return true;

                    }
                }

                else if(m_type==ENTIER){
                    if(type=="cc"){
                        if(!c1->GetPartieImaginaire() &&!c2->GetPartieImaginaire()){
                            // Alors division tronquÈe
                            Rationnel* res = new Rationnel((int)c1->GetPartieReelle()/(int)c2->GetPartieImaginaire());
                            EmpilerPileS(res);
                            return true;

                        }
                        else{

                            EmpilerPileS(op2);
                            EmpilerPileS(op1);
                            throw(CalculatriceException("Division entiere impossible entre 2 complexes"));
                            return true;
                        }
                    }
                    else{
                        Rationnel* res= r1->Quotient(r2);
                        Rationnel* res1= new Rationnel((int)res->GetFloat());
                        EmpilerPileS(res1);
                        return true;
                    }

                }

                break;
            }

            EmpilerPileS(op2);
            EmpilerPileS(op1);
            throw(CalculatriceException("Une des operandes n'est pas un rationnel"));
            return true;
        default:
            break;
        }
    }
    else throw(RationnelException("La calculatrice ne contient pas assez d'elements"));
    return false;


}


bool Calculatrice::Signe(){
    if(!m_pStock.isEmpty()){
        Constante *c= m_pStock.top();
        if(c->GetType()=="expression") return false;

        c=DepilerPileS();
        c->Signe();
        EmpilerPileS(c);
        return true;
    }

    return false;
}

bool Calculatrice::Inverse(){
    if(!m_pStock.isEmpty()){
        Constante *c= m_pStock.top();
        //if(c->GetType()=="expression") return false;

        c=DepilerPileS();
        c->Inverse();
        EmpilerPileS(c);
        return true;
    }
    return false;

}



/* Algorithme op√©ration binaire
  1. R√©cup√©rer les 2 op√©randes. DOnc checker qu'il y en a au moins 2. Sinon envoyer erreur
  et r√©empiler la donn√©e.
  2. V√©rifier le type.
Si ce sont des nb alors on peut faire l'op√©ration.
Si c'est une expression alors il faut la concat√©ner.

  3. Appeler la m√©thode correspondante
  Division: v√©rifier le mode pour voir l'op√©ration effectu√©e
  Mode Complexe On/Of: checker avant l'affichage du r√©sultat si on est en mode On.
  Sinon choisir traitement.

  */

/*! Cette fonction Èvalue une expression.
Si c'est une expression entrÈe en ligne de commande,
  alors on transmet l'expression construite et sa pile transformÈe ‡ la fonction.
  Sinon, eval dÈpile une constante expression*/
bool Calculatrice::EvalExpression(QQueue<QString> pileExpr, Expression* expr){
    if(expr==0 && pileExpr.isEmpty()){ // Si on cherche ‡ Èvaluer une expression qui est dans la pile
        Constante* tmp= DepilerPileS();
        if(tmp->GetType()=="expression") expr= dynamic_cast<Expression*>(tmp);
        else{
            EmpilerPileS(tmp); // Si la constante n'est pas une expression on la remet dans la pile
            return false;
        }
        pileExpr=expr->TransformerExpression();
        QString s=pileExpr.first();
        if(s=="Erreur") return false;

    }

    QString elem;
    for(QQueue<QString>::iterator i=pileExpr.begin();i!=pileExpr.end();i++){

        elem=pileExpr.dequeue();

        if((elem=="+")||(elem=="+")||(elem=="*")||(elem=="/"))
            OperationBinaire(elem[0].toLatin1()); // On teste d'abord si on a une fonction. Sinon c'est qu'on a une constante
        else if(elem=="INV") Inverse();

        else MajPileS(elem);

    }
    return true;

}

bool Calculatrice::MajPileS(QString s){
    Constante* c;


    /*! Cas 1: On a entrÈ une expression: elle est construite
      La vÈrification se fera seulement si on appelle EVAL */
    if(s.startsWith("'")){
        if(s.endsWith("'")) c= new Expression(s);

        else  return false;

    }

    /*! Cas 2: on entre une constante complexe.
      Rappel: On ne peut pas rentrer un rationnel directement. Un rationnel est construit slmt si on dÈpile
      2 opÈrandes et que l'on est en mode rationnel
      */

    //! Complexe "classique" seulement si le mode complexe est activÈ. sinon renvoyer une erreur.
    else if(s.contains("$")&& m_modeComplexe ){
        int n=s.indexOf('$');
        QString re=s.left(n);
        QString im=s.right(s.size()-n-1);
        if(EstUnEntier(re)&& !im.toFloat()) c= new Rationnel(re.toInt());
        if(EstUnNombre(re)&& EstUnNombre(im))
            c= new Complexe(re.toFloat(), im.toFloat());
        else return false;
    }
    //! Rationnel
    else if(s.contains("/")){
        int n=s.indexOf('/');
        QString num=s.left(n);
        QString den=s.right(s.size()-n-1);
        if(EstUnEntier(num)&& EstUnEntier(den))

            c= new Rationnel(num.toInt(), den.toInt());

        else return false;
    }
    else if(EstUnEntier(s)) c= new Rationnel(s.toInt());
    else if(EstUnNombre(s)) c= new Complexe(s.toFloat());
    else return false;

    //Si size dÈpasse la taille: traitement.
    EmpilerPileS(c);

    //m_calc.EmpilerPileA(s); Gestion  historique
    return true;

}


/*! Inversion de deux elements a la position x et y
     et retourne true si l'inversion s'est faite correctement
    false dans le cas contraire
*/
bool Calculatrice::Swap(){
    int x, y;
    Rationnel * c1, *c2;

    if(m_taille >= 2){
        Constante * yInt = DepilerPileS(); //y intermediaire
        if(yInt->GetType() == "rationnel"){
            c1 = dynamic_cast<Rationnel*>(yInt);
            if(c1->GetDenominateur() == 1){
                y = c1->GetNumerateur();
            }
            else{
                EmpilerPileS(c1);
                return false; //faire exception ou afficher erreur ce n'est pas un entier
            }
        }
        else{
            EmpilerPileS(yInt);
            return false;// faire une exception ou afficher une erreur, ce n'est pas un entier
        }

        Constante * xInt = DepilerPileS(); //x intermediaire
        if(xInt->GetType() == "rationnel"){
            c2 = dynamic_cast<Rationnel*>(xInt);
            if(c2->GetDenominateur() == 1){
                x =c2->GetNumerateur();
            }
            else{
                EmpilerPileS(c2);
                EmpilerPileS(c1);
                return false; //faire exception ou afficher erreur ce n'est pas un entier
            }
        }
        else{
            EmpilerPileS(xInt);
            EmpilerPileS(c1);
            return false;// faire une exception ou afficher une erreur, ce n'est pas un entier
        }

        int max = qMax(x-1, y-1);
        if(m_pStock.size() <= max){
            EmpilerPileS(c2);
            EmpilerPileS(c1);
            return false; //pas assez d'elemts dans la pile
        }

        else{
            Constante* valeurX = m_pStock.at(x-1);
            Constante* valeurY = m_pStock.at(y-1);

            m_pStock.replace(x-1, valeurY);
            m_pStock.replace(y-1, valeurX);

            return true;

        }
    }
    else{
        return false;// pas assez d'elmts ds la pile
    }
}

/*! Fonction qui vide la pile */
void Calculatrice::Clear(){
    m_pStock.clear();
    // m_pStock = QStack<Constante*>(); //je ne sais pas si c'est necessaire. en effet :)
}

/*! Fonction qui duplique le premier element de la pile
    et retourne true si la duplication s'est faite correctement
    false dans le cas contraire
*/
bool Calculatrice::Dup(){
    Constante * a;
    Complexe* c2, *c;
    Rationnel* r2, *r;
    Expression* e, *e2;

    if(m_pStock.isEmpty())
        return false;
    else{
        a = m_pStock.top();
        if(a->GetType() == "complexe"){
            c2 = dynamic_cast <Complexe *>(a);
            c = new Complexe(c2->GetPartieReelle(), c2->GetPartieImaginaire());
            EmpilerPileS(c);
            return true;
        }
        else if(a->GetType() == "rationnel"){
            r2 = dynamic_cast <Rationnel *>(a);
            r = new Rationnel(r2->GetNumerateur(),r2->GetDenominateur());
            EmpilerPileS(r);
            return true;
        }
        else{
            e2 = dynamic_cast <Expression *>(a);
            e = new Expression(e2->GetExpression());
            EmpilerPileS(e);
            return true;
        }
    }
}

/*! Fonction qui supprime le premier element de la pile
     et retourne true si la suppression s'est faite correctement
    false dans le cas contraire
*/
bool Calculatrice::DropTete(){

    if(m_pStock.isEmpty())
        return false;

    else{
        m_pStock.remove(0);
        return true;
    }
}
bool Calculatrice::Drop(){
    if(m_pStock.isEmpty())
        return false;

    else{
        DepilerPileS();
        return true;
    }
}

bool Calculatrice::Sum(){
    Rationnel* r;
    Constante* c;

    if(m_pStock.isEmpty()){
        return false;
    }

    else{ 
        Constante * xInt = DepilerPileS(); //x intermediaire
        if(xInt->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(xInt);
            if(r->GetDenominateur() == 1){
                int x = r->GetNumerateur();

                if(m_pStock.size() < x){
                    EmpilerPileS(r);
                    return false; //faire exception ou afficher erreur taille de la pile inferieure
                }

                else{
                    for(int i = 0; i < x; i++){
                        if(m_pStock.at(m_pStock.size()-1-i)->GetType() == "expression"){
                            EmpilerPileS(r);
                            return false;
                        }
                    }

                    for(int i=0; i< x-1; i++){
                        OperationBinaire('+');
                    }
                    return true;
                }


            }
            else{
                EmpilerPileS(r);
                return false; //faire exception ou afficher erreur ce n'est pas un entier
            }
        }
        else{
            EmpilerPileS(xInt);
            return false; //faire exception ou afficher erreur ce n'est pas un entier
        }
    }
}

bool Calculatrice::Mean(){
    Rationnel* r, *r2;
    Constante* c;
    Complexe* c3;
    int x;

    if(m_pStock.isEmpty()){
        return false;
    }

    else{
        Constante * xInt = DepilerPileS(); //x intermediaire
        if(xInt->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(xInt);
            if(r->GetDenominateur() == 1){
                x = r->GetNumerateur();

                if(m_pStock.size() < x){
                    EmpilerPileS(r);
                    return false; //faire exception ou afficher erreur taille de la pile inferieure
                }

                else{
                    for(int i = 0; i < x; i++){
                        if(m_pStock.at(m_pStock.size()-1-i)->GetType() == "expression"){
                            EmpilerPileS(r);
                            return false;
                        }
                    }

                    for(int i=0; i< x-1; i++){
                        OperationBinaire('+');
                    }
                    Complexe* c1 = r->to_complexe();
                    Constante* c2 = DepilerPileS();
                    if(c2->GetType() == "rationnel"){
                        r2 = dynamic_cast<Rationnel*>(c2);
                        c3 = r2->to_complexe();
                    }
                    else{
                        c3 = dynamic_cast<Complexe*>(c2);
                    }
                    EmpilerPileS(c3->Quotient(c1));
                    return true;
                }


            }
            else{
                EmpilerPileS(r);
                return false; //faire exception ou afficher erreur ce n'est pas un entier
            }
        }
        else{
            EmpilerPileS(xInt);
            return false; //faire exception ou afficher erreur ce n'est pas un entier
        }
    }

}

bool Calculatrice::Sin(){
    Constante * x;
    Rationnel* r;
    Complexe* c, *c2, *c3;
    if(m_pStock.isEmpty())
        return false;

    else{
        x = DepilerPileS();

        if(x->GetType() == "complexe"){
            c = dynamic_cast<Complexe*>(x);
            if(c->GetPartieImaginaire() != 0){
                EmpilerPileS(x);
                return false;
            }
            else{
                if(m_angle == DEGRE){
                    c2 = c->to_degre();
                    EmpilerPileS(c2->Sinus());
                    return true;
                }

                c2 = c->Sinus();
                EmpilerPileS(c2);
                return true;
            }

        }

        else if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            c2 = r->to_complexe();
            if(m_angle == DEGRE){
                c3 = c2->to_degre();
                EmpilerPileS(c3->Sinus());
                return true;
            }

            EmpilerPileS(c2->Sinus());
            return true;
        }

        else{
            EmpilerPileS(x);
            return false;
        }

    }

}

bool Calculatrice::Cos(){

    Constante * x;
    Rationnel* r;
    Complexe* c, *c2, *c3;
    if(m_pStock.isEmpty())
        return false;

    else{
        x = DepilerPileS();

        if(x->GetType() == "complexe"){
            c = dynamic_cast<Complexe*>(x);
            if(c->GetPartieImaginaire() != 0){
                EmpilerPileS(x);
                return false;
            }
            else{
                if(m_angle == DEGRE){
                    c2 = c->to_degre();
                    EmpilerPileS(c2->Cosinus());
                    return true;
                }

                c2 = c->Cosinus();
                EmpilerPileS(c2);
                return true;
            }

        }

        else if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            c2 = r->to_complexe();
            if(m_angle == DEGRE){
                c3 = c2->to_degre();
                EmpilerPileS(c3->Cosinus());
                return true;
            }

            EmpilerPileS(c2->Cosinus());
            return true;
        }

        else{
            EmpilerPileS(x);
            return false;
        }

    }

}

bool Calculatrice::Tan(){

    Constante * x;
    Rationnel* r;
    Complexe* c, *c2, *c3;
    if(m_pStock.isEmpty())
        return false;

    else{
        x = DepilerPileS();

        if(x->GetType() == "complexe"){
            c = dynamic_cast<Complexe*>(x);
            if(c->GetPartieImaginaire() != 0){
                EmpilerPileS(x);
                return false;
            }
            else{
                if(m_angle == DEGRE){
                    c2 = c->to_degre();
                    EmpilerPileS(c2->Tang());
                    return true;
                }

                c2 = c->Tang();
                EmpilerPileS(c2);
                return true;
            }

        }

        else if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            c2 = r->to_complexe();
            if(m_angle == DEGRE){
                c3 = c2->to_degre();
                EmpilerPileS(c3->Tang());
                return true;
            }

            EmpilerPileS(c2->Tang());
            return true;
        }

        else{
            EmpilerPileS(x);
            return false;
        }

    }

}

bool Calculatrice::SinH(){

    Constante * x;
    Rationnel* r;
    Complexe* c, *c2;
    if(m_pStock.isEmpty())
        return false;

    else{
        x = DepilerPileS();

        if(x->GetType() == "complexe"){
            c = dynamic_cast<Complexe*>(x);
            if(c->GetPartieImaginaire() != 0){
                EmpilerPileS(x);
                return false;
            }
            else{

                c2 = c->SinusH();
                EmpilerPileS(c2);
                return true;
            }

        }

        else if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            c2 = r->to_complexe();
            EmpilerPileS(c2->SinusH());
            return true;
        }

        else{
            EmpilerPileS(x);
            return false;
        }

    }
}

bool Calculatrice::CosH(){

    Constante * x;
    Rationnel* r;
    Complexe* c, *c2;
    if(m_pStock.isEmpty())
        return false;

    else{
        x = DepilerPileS();

        if(x->GetType() == "complexe"){
            c = dynamic_cast<Complexe*>(x);
            if(c->GetPartieImaginaire() != 0){
                EmpilerPileS(x);
                return false;
            }
            else{

                c2 = c->CosinusH();
                EmpilerPileS(c2);
                return true;
            }

        }

        else if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            c2 = r->to_complexe();
            EmpilerPileS(c2->CosinusH());
            return true;
        }

        else{
            EmpilerPileS(x);
            return false;
        }

    }
}

bool Calculatrice::TanH(){

    Constante * x;
    Rationnel* r;
    Complexe* c, *c2;
    if(m_pStock.isEmpty())
        return false;

    else{
        x = DepilerPileS();

        if(x->GetType() == "complexe"){
            c = dynamic_cast<Complexe*>(x);
            if(c->GetPartieImaginaire() != 0){
                EmpilerPileS(x);
                return false;
            }
            else{

                c2 = c->TangH();
                EmpilerPileS(c2);
                return true;
            }

        }

        else if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            c2 = r->to_complexe();
            EmpilerPileS(c2->TangH());
            return true;
        }

        else{
            EmpilerPileS(x);
            return false;
        }

    }
}

bool Calculatrice::Ln(){

    Constante * x;
    Rationnel* r;
    Complexe* c, *c2;
    if(m_pStock.isEmpty())
        return false;

    else{
        x = DepilerPileS();

        if(x->GetType() == "complexe"){
            c = dynamic_cast<Complexe*>(x);
            if(c->GetPartieImaginaire() != 0){
                EmpilerPileS(c);
                return false;

            }

            else{
                if(c->GetPartieReelle() > 0){
                    EmpilerPileS(c->LnC());
                    return true;
                }
                else{
                    EmpilerPileS(c);
                    return false;
                }
            }

        }

        else if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            c2 = r->to_complexe();

            if(c2->GetPartieImaginaire() != 0){
                EmpilerPileS(c2);
                return false;

            }

            else{
                if(c2->GetPartieReelle() > 0){
                    EmpilerPileS(c2->LnC());
                    return true;
                }
                else{
                    EmpilerPileS(c2);
                    return false;
                }
            }
        }
    }
    return false;
}

bool Calculatrice::Log(){

    Constante * x;
    Rationnel* r;
    Complexe* c, *c2;
    if(m_pStock.isEmpty())
        return false;

    else{
        x = DepilerPileS();

        if(x->GetType() == "complexe"){
            c = dynamic_cast<Complexe*>(x);
            if(c->GetPartieImaginaire() != 0){
                EmpilerPileS(c);
                return false;

            }

            else{
                if(c->GetPartieReelle() > 0){
                    EmpilerPileS(c->LogC());
                    return true;
                }
                else{
                    EmpilerPileS(c);
                    return false;
                }
            }

        }

        else if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            c2 = r->to_complexe();

            if(c2->GetPartieImaginaire() != 0){
                EmpilerPileS(c2);
                return false;

            }

            else{
                if(c2->GetPartieReelle() > 0){
                    EmpilerPileS(c2->LogC());
                    return true;
                }
                else{
                    EmpilerPileS(c2);
                    return false;
                }
            }
        }
    }
    return false;
}

bool Calculatrice::Sqrt(){

    Constante * x;
    Rationnel* r;
    Complexe* c, *c2;
    if(m_pStock.isEmpty())
        return false;

    else{
        x = DepilerPileS();

        if(x->GetType() == "complexe"){
            c = dynamic_cast<Complexe*>(x);
            if(c->GetPartieImaginaire() != 0){
                EmpilerPileS(x);
                return false;
            }
            else{
                if(c->GetPartieReelle()< 0){
                    EmpilerPileS(c);
                    return false;
                }
                else{
                    c2 = c->RacineC();
                    EmpilerPileS(c2);
                    return true;
                }
            }

        }

        else if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            c2 = r->to_complexe();

            if(c2->GetPartieReelle()< 0){
                EmpilerPileS(c2);
                return false;
            }
            else{
                EmpilerPileS(c2->RacineC());
                return true;
            }
        }

        else{
            EmpilerPileS(x);
            return false;
        }

    }
}

bool Calculatrice::Sqr(){

    Constante * x;
    Rationnel* r;
    Complexe* c;
    if(m_pStock.isEmpty())
        return false;

    else{
        x = DepilerPileS();

        if(x->GetType() == "complexe"){
            c = dynamic_cast<Complexe*>(x);
            EmpilerPileS(c->Carre());
            return true;
        }

        else if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            c = r->to_complexe();
            EmpilerPileS(c->Carre());
            return true;
        }

        else{
            EmpilerPileS(x);
            return false;
        }

    }
}

bool Calculatrice::Cube(){

    Constante * x;
    Rationnel* r;
    Complexe* c;
    if(m_pStock.isEmpty())
        return false;

    else{
        x = DepilerPileS();

        if(x->GetType() == "complexe"){
            c = dynamic_cast<Complexe*>(x);
            EmpilerPileS(c->CubeC());
            return true;
        }

        else if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            c = r->to_complexe();
            EmpilerPileS(c->CubeC());
            return true;
        }

        else{
            EmpilerPileS(x);
            return false;
        }

    }
}

bool Calculatrice::Fact(){
    Constante* x;
    Rationnel* r;

    if(m_pStock.isEmpty())
        return false;

    else{
        x = DepilerPileS();

        if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            if(r->GetNumerateur() >= 0 && r->GetDenominateur() == 1){
                EmpilerPileS(r->Facto());
                return true;
            }
            else{
                EmpilerPileS(r);
                return false;
            }
        }
        else{
            EmpilerPileS(x);
            return false;
        }
    }
}

bool Calculatrice::Mod(){
    Constante* x, *y;
    Rationnel* r1, *r2;

    if(m_pStock.size() >= 2){
        y = m_pStock.pop();
        if(y->GetType() == "rationnel"){
            r1 = dynamic_cast<Rationnel*>(y);
            if(r1->GetDenominateur() != 1){
                m_pStock.push(r1);
                return false;
            }
            else{
                x = m_pStock.pop();
                if(x->GetType() == "rationnel"){
                    r2 = dynamic_cast<Rationnel*>(x);
                    if(r2->GetNumerateur() == 0 || r2->GetDenominateur() != 1){
                        m_pStock.push(r2);
                        m_pStock.push(r1);
                        return false;
                    }
                    else{
                        m_pStock.push(r1->Modulo(r2));
                        return true;
                    }
                }
                else{
                    m_pStock.push(r1);
                    m_pStock.push(x);
                    return false;
                }
            }
        }
        else{
            m_pStock.push(y);
            return false;
        }
    }
    else{
        return false;
    }

    return false;
}

bool Calculatrice::Pow(){
    Constante*x, *y; //on veut faire x pow y
    Complexe* c, *c2;
    Rationnel* r, *r2;

    if(m_pStock.size() >= 2){
        y = DepilerPileS();

        if(y->GetType() == "complexe"){
            c = dynamic_cast<Complexe*>(y);
            if(c->GetPartieImaginaire() != 0){
                EmpilerPileS(c);
                return false;
            }
        }

        else if(y->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(y);
            c = r->to_complexe();
            if(c->GetPartieImaginaire() != 0){
                EmpilerPileS(r);
                return false;
            }
        }

        else{
            EmpilerPileS(y);
            return false;
        }

        x = DepilerPileS();

        if(x->GetType() == "complexe"){
            c2 = dynamic_cast<Complexe*>(x);
            if(c2->GetPartieImaginaire() != 0){
                EmpilerPileS(c2);
                EmpilerPileS(c);
                return false;
            }
        }

        else if(x->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(x);
            c2 = r->to_complexe();
            if(c2->GetPartieImaginaire() != 0){
                EmpilerPileS(r);
                EmpilerPileS(c);
                return false;
            }
        }

        else{
            EmpilerPileS(x);
            EmpilerPileS(y);
            return false;
        }

        EmpilerPileS(c2->PowC(c));

        EmpilerPileS(c->PowC(c2));
        return true;

    }
    else{
        return false;
    }
}


QDataStream & operator << (QDataStream & out, Constante* & Valeur){
    out<<Valeur->GetType();

    if(Valeur->GetType()=="complexe"){
        Complexe *c= dynamic_cast<Complexe*>(Valeur);
        out<<*c;
    }
    else if(Valeur->GetType()=="rationnel"){
        Rationnel *c= dynamic_cast<Rationnel*>(Valeur);
        out<<*c;
    }
    else if(Valeur->GetType()=="expression"){
        Expression *c= dynamic_cast<Expression*>(Valeur);
        out<<*c;
    }
    return out;
}

QDataStream & operator >> (QDataStream & in, Constante* & Valeur){
    in>>Valeur->m_type;

    if(Valeur->GetType()=="complexe"){
        Complexe *c= dynamic_cast<Complexe*>(Valeur);
        in>>*c;
    }
    else if(Valeur->GetType()=="rationnel"){
        Rationnel *c= dynamic_cast<Rationnel*>(Valeur);
        in>>*c;
    }
    else if(Valeur->GetType()=="expression"){
        Expression *c= dynamic_cast<Expression*>(Valeur);
        in>>*c;
    }


    return in;

}
