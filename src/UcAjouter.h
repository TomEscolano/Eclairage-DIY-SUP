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
     * Méthode permettant d'ajouter un éclairage unicolore dans la base de données
     */
    void doIt(EclairageUnicolore & eclairage, cgicc::Cgicc & cgi);

    /**
     * Méthode permettant d'ajouter un éclairage multicolore dans la base de données.
     */
    void doIt(EclairageMulticolore & eclairage, cgicc::Cgicc & cgi);

};
#endif
