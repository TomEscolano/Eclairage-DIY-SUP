/*******************************************************
* \file UcGerer.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCGERER_H
#define _UCGERER_H


#include "SqlitePersiBny.h"
#include "Eclairage.h"

class Eclairage;

class UcGerer {
  private:
  	const char * DB = "/var/eclairage/bdd.db";

  public:
    /**
     * M�thode permettant d'activer/desactiver un �clairage pass� en param�tre.
     */
    void doIt(Eclairage::Ent & eclairage, bool etat);

};
#endif
