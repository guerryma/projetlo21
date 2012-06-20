#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H
#include <QString>

enum Priorite {HAUTE, NORMALE, BASSE};


class LogMessage
{
    /*! Classe servant à générer des messages de log avec un degre
        d'importance
    */

    QString m_message; //! <message du log
    Priorite m_priorite; //! <priorite du message

public:

    LogMessage(): m_priorite(BASSE){}
    /* ! Constructeur de LogMessage : construit un LogMessage n'ayant aucun message
        et ayant une priorite basse
    */

    LogMessage(QString m, Priorite prio=BASSE): m_message(m), m_priorite(prio){}
    /*! Constructeur de LogMessage : construit une LogMessage avec un message
        et une priorite passes en parametres
    */

    QString GetMessage()const{return m_message;}
    //! Accesseur en lecture qui retourne le message d'un LogMessage

    QString GetPriorite()const{if(m_priorite == HAUTE) return "HAUTE"; else if(m_priorite == NORMALE) return "NORMALE"; else return "BASSE";}
    //! Accesseur en lecture qui retourne la priorite d'un LogMessage

    void SetMessage(QString m){m_message = m;}
    //! Accesseur en ecriture qui initialise un message

    void SetPriorite(Priorite p){m_priorite = p;}
    //! Accesseur en ecriture qui initialise une priorite

};

#endif // LOGMESSAGE_H
