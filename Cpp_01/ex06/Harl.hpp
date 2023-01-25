#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>

enum Level {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Harl {
   public:
    Harl(void);
    ~Harl(void);

    void (Harl::*functionPointers[4])();
    void complain(std::string level);

   private:
    /* "DEBUG" : Les messages de débug contiennent des informations
    contextuelles. On les utilise principalement pour établir des diagnostics.*/
    void debug(void);

    /* "INFO" : Ces messages contiennent des informations détaillées.
    On les utilise pour tracer l’exécution d’un programme en production.*/
    void info(void);

    /* "WARNING" : Les messages d’avertissement indiquent un problème potentiel
    dans le système. Toutefois, on est en mesure de le gérer ou de l’ignorer.*/
    void warning(void);

    /* "ERROR" : Ces messages indiquent qu’une erreur irrécupérable s’est
    produite. Il s’agit généralement d’un problème critique qui nécessite
    une intervention manuelle.*/
    void error(void);
};

#endif
