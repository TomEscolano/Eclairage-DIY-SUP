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
     * M�thode permettant d'ajouter un �clairage unicolore dans la base de donn�es
     */
    void doIt(EclairageUnicolore::Ent & ent);

    /**
     * M�thode permettant d'ajouter un �clairage multicolore dans la base de donn�es.
     */
    void doIt(EclairageMulticolore::Ent & ent);

};
#endif
