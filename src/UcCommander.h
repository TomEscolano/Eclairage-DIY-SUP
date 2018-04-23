/*******************************************************
* \file UcCommander.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCCOMMANDER_H
#define _UCCOMMANDER_H


#include "SqlitePersiBny.h"

class Eclairage;

class UcCommander {
  public:
    /**
     * Méthode permettant d'allumer/éteindre un éclairage passé en paramètres.
     */
    void doIt(Eclairage & eclairage, bool etat);

};
#endif
