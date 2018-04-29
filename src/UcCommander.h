/*******************************************************
* \file UcCommander.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCCOMMANDER_H
#define _UCCOMMANDER_H

#include <Eclairage.h>
#include <SqlitePersiBny.h>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

class Eclairage;

class UcCommander {
private:
	const char * DB = "/var/eclairage/bdd.db";

  public:
    /**
     * Méthode permettant d'allumer/éteindre un éclairage passé en paramètres.
     */
    void doIt(Eclairage::Ent & eclairage, bool etat);

};
#endif
