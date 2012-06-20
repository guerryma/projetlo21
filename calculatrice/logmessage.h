#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H
#include <QString>

enum Priorite {HAUTE, NORMALE, BASSE};

class LogMessage
{
    QString m_message;
    Priorite m_priorite;

public:
    LogMessage(): m_priorite(BASSE){}
    LogMessage(QString m, Priorite prio=BASSE): m_message(m), m_priorite(prio){}

    QString GetMessage()const{return m_message;}
    QString GetPriorite()const{if(m_priorite == HAUTE) return "HAUTE"; else if(m_priorite == NORMALE) return "NORMALE"; else return "BASSE";}

    void SetMessage(QString m){m_message = m;}
    void SetPriorite(Priorite p){m_priorite = p;}

};

#endif // LOGMESSAGE_H
