#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H
#include "logmessage.h"
#include <QDate>
#include <iostream>
#include <fstream>
#include <QDebug>

class LogSystem
{
   QString m_date;
   QString m_time;

public:
    LogSystem();

    void Logger(LogMessage* lm);

};

#endif // LOGSYSTEM_H
