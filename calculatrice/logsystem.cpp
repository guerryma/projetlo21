#include "logsystem.h"


    LogSystem::LogSystem(){
        m_date = QDate::currentDate().toString();
        m_time = QTime::currentTime().toString();

        std::ofstream fic("log.txt", std::ios::out| std::ios::app);

        if(fic){
            fic<<"Date: "<<m_date.toStdString()<<" Heure: "<<m_time.toStdString()<<std::endl;
            fic.close();
            qDebug()<<"Date: "<<m_date<<" Heure: "<<m_time;
        }

        else
            std::cerr<< "Impossible d'ouvrir le fichier!"<<std::endl;
    }

    void LogSystem::Logger(LogMessage* lm){
        std::ofstream fic("log.txt", std::ios::out| std::ios::app);
        fic<<"Priorité :"<<lm->GetPriorite().toStdString()<<" Message: "<<lm->GetMessage().toStdString()<<std::endl;
        fic.close();
        qDebug()<<"Priorité :"<<lm->GetPriorite()<<" Message: "<<lm->GetMessage();
    }


