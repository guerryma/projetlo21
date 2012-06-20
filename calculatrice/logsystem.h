#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H
#include "logmessage.h"
#include <QDate>
#include <iostream>
#include <fstream>
#include <QDebug>

class LogSystem
{
    /*! Classe traitant les LogMessage en ecrivant le contenu des messages et
        de leur priorite dans la console dans un fichier log dedie

    */

   QString m_date; //! <une date
   QString m_time; //! <une heure

public:
    LogSystem();
    /* ! Constructeur LogSystem : cree ou ouvre un fichier log et y applique
       la date et l'heure actuelle. Il en fait de meme dans la console

    */

    void Logger(LogMessage* lm);
    /* ! Fonction qui prend en parametre un LogMessage et ecrit son message
       et sa priorite sur la console et dans le fichier log ouvert precedemment
    */

};

#endif // LOGSYSTEM_H
