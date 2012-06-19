#include "constante.h"

QDataStream & operator << (QDataStream & out, const Constante* & Valeur){
    out<<Valeur;

    return out;
}

QDataStream & operator >> (QDataStream & in, Constante* & Valeur){
    in>>Valeur;
    return in;

}
