/*******************************************************
* \file UcCommander.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCCOMMANDER_H
#define _UCCOMMANDER_H


#include <SqlitePersiBny.h>

class Eclairage;

class UcCommander {
private:
	const char * DB = "/var/eclairage/bdd.db";

  public:
    /**
     * M�thode permettant d'allumer/�teindre un �clairage pass� en param�tres.
     */
    void doIt(Eclairage & eclairage, bool etat);

};
#endif
