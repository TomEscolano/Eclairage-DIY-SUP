/*******************************************************
* \file UcSupprimer.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCSUPPRIMER_H
#define _UCSUPPRIMER_H


#include <SqlitePersiBny.h>
#include <Eclairage.h>
#include <iostream>
#include <vector>
#include <string>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

class UcSupprimer {
  private:
	const char * DB = "/var/eclairage/bdd.db";

  public:
    /**
     * Méthode permettant de supprimer un éclairage.
     */
    void doIt(Eclairage::Ent eclairage);

};
#endif
