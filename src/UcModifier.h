/*******************************************************
* \file UcModifier.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCMODIFIER_H
#define _UCMODIFIER_H


#include "SqlitePersiBny.h"
#include <Eclairage.h>
#include <EclairageMulticolore.h>
#include <EclairageUnicolore.h>
#include <UcAjouter.h>

class UcModifier {
  public:
    /**
     * M�thode permettant de modifier la configuration un �clairage multicolore.
     */
    void doIt(EclairageMulticolore::Ent eclairage);

    /**
     * M�thode permettant de modifier la configuration d'un �clairage unicolore.
     */
    void doIt(EclairageUnicolore::Ent eclairage);

private:
    const char * DB = "/var/eclairage/bdd.db";
	UcAjouter ucAjouter;

};
#endif
