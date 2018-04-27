/*******************************************************
* \file UcAjouter.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCAJOUTER_H
#define _UCAJOUTER_H

#include <SqlitePersiBny.h>
#include <EclairageUnicolore.h>
#include <EclairageMulticolore.h>
#include <iostream>
#include <vector>
#include <string>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>


class UcAjouter {
  private:
	const char * DB = "/var/eclairage/bdd.db";
	
  public:
    /**
     * Méthode permettant d'ajouter un éclairage unicolore dans la base de données
     */
    void doIt(EclairageUnicolore::Ent & ent);

    /**
     * Méthode permettant d'ajouter un éclairage multicolore dans la base de données.
     */
    void doIt(EclairageMulticolore::Ent & ent);

};
#endif
