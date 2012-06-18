#include "calculatrice.h"




bool Calculatrice::OperationBinaire(char operation){
    /*! Traitement d'un opérateur binaire: les opérandes sont dépilées puis l'opération est calculée
      En fonction du type d'opération envoyé en paramètre.
      */
    if(m_pStock.size()>1){
        Constante* op1 = m_pStock.pop();
        Constante* op2 =m_pStock.pop();


        QString type;
        Complexe* c1;
        Complexe* c2;
        Rationnel* r1;
        Rationnel* r2;


        /*! type Permettra de stocker le type de constante:
          cc pour 2 complexes
          rr pour 2 rationnels
          rc ou cr pour cpx et rationnel
          pour une expression => Il faudra gérer concaténation en fonction du type
          */

        //! Détermination du type de constante

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
            r2=Rationnel::to_rationnel(c2);

            r1=dynamic_cast<Rationnel*>(op1);

            if(r2) type="rr";
            else{
                c1=r1->to_complexe();

                type="cc";}
        }
        else if(op1->GetType()=="complexe"&& op2->GetType()=="rationnel"){
            c1=dynamic_cast<Complexe*>(op1);
            r1=Rationnel::to_rationnel(c1);
            r2=dynamic_cast<Rationnel*>(op2);

            if(r1) type="rr";
            else{
                c2=r2->to_complexe();

                type="cc";
            }
        }

        switch(operation){
        case '+':
            if (type=="cc") //! somme cpx cpx
            {
                m_pStock.push(c1->Somme(c2));
                return true;
            }

            if(type=="rr"){ //! somme rat rat

                m_pStock.push(r1->Somme(r2));
                return true;
            }
            break;

            //! Soustraction
        case '-':
            if (type=="cc") //! <soustraction cpx cpx
            {

                m_pStock.push(c1->Difference(c2));
                return true;
            }

            if(type=="rr"){ //! <soustraction rat rat
                m_pStock.push(r1->Difference(r2));
                return true;
            }

            break;

            //! Produit:
        case '*':
            if (type=="cc") //! produit cpx cpx
            {
                m_pStock.push(c1->Produit(c2));
                return true;
            }

            if(type=="rr"){ //! produit rat rat
                m_pStock.push(r1->Produit(r2));
                return true;
            }

            break;
            //! Division:
        case '/':
            //! Dans le cas de la division réelle sur des complexes, on réalise la division et on retourne un complexe
            if (m_type==REEL){
                if (type=="cc") //! Division cpx cpx
                {
                    m_pStock.push(c1->Quotient(c2));
                    return true;
                }
                if(type=="rr"){
                    m_pStock.push(r1->to_complexe()->Quotient(r2->to_complexe()));
                    return true;
                }

            }


            else if(m_type==RATIONNEL){
                if(type=="rr"){ //! Division rat rat
                    m_pStock.push(r1->Quotient(r2));
                    return true;
                }
                else if(EstUnEntier(c1->Afficher())&& EstUnEntier(c2->Afficher())){
                    r1=new Rationnel((int)c1->GetPartieReelle());
                    r2=new Rationnel((int)c2->GetPartieReelle());
                    m_pStock.push(r1->Quotient(r2));
                    return true;
                }

                else{
                    m_pStock.push(op2);
                    m_pStock.push(op1);
                    std::cout<<"Une des operandes n'est pas un rationnel\n";//remplacer par une erreur
                    return true;

                }
            }

            else if(m_type==ENTIER){
                if(type=="cc"){
                    if(!c1->GetPartieImaginaire() &&!c2->GetPartieImaginaire()){
                        // Alors division tronqu�e
                        Rationnel* res = new Rationnel((int)c1->GetPartieReelle()/(int)c2->GetPartieImaginaire());
                        m_pStock.push(res);
                        return true;

                    }
                    else{

                        m_pStock.push(op2);
                        m_pStock.push(op1);
                        std::cout<<"Division entiere impossible entre 2 complexes\n";//remplacer par une erreur
                        return true;
                    }
                }
                else{
                    Rationnel* res= r1->Quotient(r2);
                    Rationnel* res1= new Rationnel((int)res->GetFloat());
                    m_pStock.push(res1);
                    return true;
                }

            }

            break;

            m_pStock.push(op2);
            m_pStock.push(op1);
            std::cout<<"Une des op�randes n'est pas un rationnel\n";//remplacer par une erreur
            return true;
        default:
            break;
        }
    }
    else std::cout<<"La pile ne contient pas assez d'éléments";
    return false;//envoyer une exception


}


bool Calculatrice::Signe(){
    Constante *c= m_pStock.top();
    if(c->GetType()=="expression") return false;

        c=m_pStock.pop();
        c->Signe();
        m_pStock.push(c);
        return true;

}

bool Calculatrice::Inverse(){
    Constante *c= m_pStock.top();
    if(c->GetType()=="expression") return false;

        c=m_pStock.pop();
        c->Inverse();
        m_pStock.push(c);
        return true;

}



/* Algorithme opération binaire
  1. Récupérer les 2 opérandes. DOnc checker qu'il y en a au moins 2. Sinon envoyer erreur
  et réempiler la donnée.
  2. Vérifier le type.
Si ce sont des nb alors on peut faire l'opération.
Si c'est une expression alors il faut la concaténer.

  3. Appeler la méthode correspondante
  Division: vérifier le mode pour voir l'opération effectuée
  Mode Complexe On/Of: checker avant l'affichage du résultat si on est en mode On.
  Sinon choisir traitement.

  */

/*! Cette fonction �value une expression.
Si c'est une expression entr�e en ligne de commande,
  alors on transmet l'expression construite et sa pile transform�e � la fonction.
  Sinon, eval d�pile une constante expression*/
bool Calculatrice::EvalExpression(QStack<QString> pileExpr, Expression* expr){
    if(expr==0 && pileExpr.isEmpty()){ // Si on cherche � �valuer une expression qui est dans la pile
        Constante* tmp= m_pStock.pop();
        if(tmp->GetType()=="expression") expr= dynamic_cast<Expression*>(tmp);
        else{
            m_pStock.push(tmp); // Si la constante n'est pas une expression on la remet dans la pile
            return false;
        }
            //pileExpr=expr->TransformerExpression(); modifie !!!!!!!!!!!
//            QString s=pileExpr.pop();
//            if(s=="Erreur") return false;
//            else pileExpr.push(s);
    }

    QString elem;
    for(int i=0; i<pileExpr.size()+2;i++){

        elem=pileExpr.pop();

        std::cout<<elem.toStdString()<<"\n";

//        if(elem=="+"){

//            OperationBinaire('+'); // On teste d'abord si on a une fonction. Sinon c'est qu'on a une constante

//        }
//        else MajPileS(elem);

    }
    return true;

}

bool Calculatrice::MajPileS(QString s){
    Constante* c;

    /*! Cas 1: On a entr� une expression: elle est construite
      La v�rification se fera seulement si on appelle EVAL */
if(s.startsWith("'")){
    if(s.endsWith("'")) c= new Expression(s);

    else  return false;

}

/*! Cas 2: on entre une constante complexe.
      Rappel: On ne peut pas rentrer un rationnel directement. Un rationnel est construit slmt si on d�pile
      2 op�randes et que l'on est en mode rationnel
      */

//! Complexe "classique" seulement si le mode complexe est activ�. sinon renvoyer une erreur.
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
    if(EstUnEntier(num)&& EstUnEntier(den)){
        //try{
        c= new Rationnel(num.toInt(), den.toInt());
    }
    else return false;
}
else if(EstUnEntier(s)) c= new Rationnel(s.toInt());
else if(EstUnNombre(s)) c= new Complexe(s.toFloat());
else return false;

//Si size d�passe la taille: traitement.
m_pStock.push(c);
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
        Constante * yInt = m_pStock.pop(); //y intermediaire
        if(yInt->GetType() == "rationnel"){
            c1 = dynamic_cast<Rationnel*>(yInt);
            if(c1->GetDenominateur() == 1){
                y = c1->GetNumerateur();
            }
            else{
                m_pStock.push(c1);
                return false; //faire exception ou afficher erreur ce n'est pas un entier
            }
        }
        else{
            m_pStock.push(yInt);
            return false;// faire une exception ou afficher une erreur, ce n'est pas un entier
        }

        Constante * xInt = m_pStock.pop(); //x intermediaire
        if(xInt->GetType() == "rationnel"){
            c2 = dynamic_cast<Rationnel*>(xInt);
            if(c2->GetDenominateur() == 1){
                x =c2->GetNumerateur();
            }
            else{
                m_pStock.push(c2);
                m_pStock.push(c1);
                return false; //faire exception ou afficher erreur ce n'est pas un entier
            }
        }
        else{
            m_pStock.push(xInt);
            m_pStock.push(c1);
            return false;// faire une exception ou afficher une erreur, ce n'est pas un entier
        }

        int max = qMax(x-1, y-1);
        if(m_pStock.size() <= max){
            m_pStock.push(c2);
            m_pStock.push(c1);
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
    m_pStock = QStack<Constante*>(); //je ne sais pas si c'est necessaire
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
        a = m_pStock.first();
        if(a->GetType() == "complexe"){
            c2 = dynamic_cast <Complexe *>(a);
            c = new Complexe(c2->GetPartieReelle(), c2->GetPartieImaginaire());
            m_pStock.push(c);
            return true;
        }
        else if(a->GetType() == "rationnel"){
            r2 = dynamic_cast <Rationnel *>(a);
            r = new Rationnel(r2->GetNumerateur(),r2->GetDenominateur());
            m_pStock.push(r);
            return true;
        }
        else{
            e2 = dynamic_cast <Expression *>(a);
            e2 = dynamic_cast <Expression *>(a);
            e = new Expression(e2->GetExpression());
            m_pStock.push(r);
            return true;
        }
    }
}

/*! Fonction qui supprime le premier element de la pile
     et retourne true si la duplication s'est faite correctement
    false dans le cas contraire
*/
bool Calculatrice::Drop(){
    if(m_pStock.isEmpty())
        return false;

    else{
        m_pStock.remove(0);
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
        Constante * xInt = m_pStock.pop(); //x intermediaire
        if(xInt->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(xInt);
            if(r->GetDenominateur() == 1){
                int x = r->GetNumerateur();

                 if(m_pStock.size() < x){
                    m_pStock.push(r);
                    return false; //faire exception ou afficher erreur taille de la pile inferieure
                 }

                 else{
                    for(int i = 0; i < x; i++){
                        if(m_pStock.at(i)->GetType() == "expression")
                            return false;
                    }

                    for(int i=0; i< x; i++){
                        c = m_pStock.front();
                        m_pStock.push(c);
                        m_pStock.remove(0);
                    }

                    for(int i=0; i< x-1; i++){
                        OperationBinaire('+');
                    }
                    return true;
                 }


            }
            else{
                m_pStock.push(r);
                return false; //faire exception ou afficher erreur ce n'est pas un entier
            }
        }
        else{
            m_pStock.push(xInt);
            return false; //faire exception ou afficher erreur ce n'est pas un entier
        }
    }
}

bool Calculatrice::Mean(){
    Rationnel* r;
    Constante* c;
    int x;

    if(m_pStock.isEmpty()){
        return false;
    }

    else{
        Constante * xInt = m_pStock.pop(); //x intermediaire
        if(xInt->GetType() == "rationnel"){
            r = dynamic_cast<Rationnel*>(xInt);
            if(r->GetDenominateur() == 1){
                x = r->GetNumerateur();

                 if(m_pStock.size() < x){
                    m_pStock.push(r);
                    return false; //faire exception ou afficher erreur taille de la pile inferieure
                 }

                 else{
                    for(int i = 0; i < x; i++){
                        if(m_pStock.at(i)->GetType() == "expression")
                            return false;
                    }

                    for(int i=0; i< x; i++){
                        c = m_pStock.front();
                        m_pStock.push(c);
                        m_pStock.remove(0);
                    }

                    for(int i=0; i< x-1; i++){
                        OperationBinaire('+');
                    }
                    Complexe* c1 = new Complexe(float(x));
                    Constante* c2 = m_pStock.pop();
                    m_pStock.push(c1);
                    m_pStock.push(c2);
                    OperationBinaire('/');
                    return true;
                 }


            }
            else{
                m_pStock.push(r);
                return false; //faire exception ou afficher erreur ce n'est pas un entier
            }
        }
        else{
            m_pStock.push(xInt);
            return false; //faire exception ou afficher erreur ce n'est pas un entier
        }
    }

}

