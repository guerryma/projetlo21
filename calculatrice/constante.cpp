#include "constante.h"

QDataStream & operator << (QDataStream & out, const Constante* & Valeur){
    out<<Valeur->GetType();

    return out;
}

QDataStream & operator >> (QDataStream & in, Constante* & Valeur){
    in>>Valeur->m_type;
    return in;

}
