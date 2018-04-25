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
     * Méthode permettant d'activer/desactiver un éclairage passé en paramètre.
     */
    void doIt(Eclairage::Ent & eclairage, bool etat);

};
#endif
