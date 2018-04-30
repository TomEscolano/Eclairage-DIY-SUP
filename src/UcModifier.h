/*******************************************************
* \file UcModifier.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCMODIFIER_H
#define _UCMODIFIER_H


#include <SqlitePersiBny.h>
#include <Eclairage.h>
#include <EclairageMulticolore.h>
#include <EclairageUnicolore.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTMLClasses.h>
#include <cgicc/HTTPHTMLHeader.h>

class UcModifier {
  public:
    /**
     * M�thode permettant de modifier la configuration un �clairage multicolore.
     */
    void doIt(EclairageMulticolore & eclairage, cgicc::Cgicc & cgi);

    /**
     * M�thode permettant de modifier la configuration d'un �clairage unicolore.
     */
    void doIt(EclairageUnicolore & eclairage, cgicc::Cgicc & cgi);

private:
    const char * DB = "/var/eclairage/bdd.db";

};
#endif
