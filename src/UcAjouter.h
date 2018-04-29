/*******************************************************
* \file UcAjouter.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCAJOUTER_H
#define _UCAJOUTER_H

#include <vector>
#include <string>
#include <iostream>
#include <cgicc/Cgicc.h>
#include <SqlitePersiBny.h>
#include <cgicc/HTMLClasses.h>
#include <EclairageUnicolore.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <EclairageMulticolore.h>


class UcAjouter {
  private:
	const char * DB = "/var/eclairage/bdd.db";
	
  public:
    /**
     * M�thode permettant d'ajouter un �clairage unicolore dans la base de donn�es
     */
    void doIt(EclairageUnicolore & eclairage, cgicc::Cgicc & cgi);

    /**
     * M�thode permettant d'ajouter un �clairage multicolore dans la base de donn�es.
     */
    void doIt(EclairageMulticolore & eclairage, cgicc::Cgicc & cgi);

};
#endif
