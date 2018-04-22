/*******************************************************
* \file UcAjouter.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCAJOUTER_H
#define _UCAJOUTER_H


#include "SqlitePersiBny.h"

class UcAjouter {
  public:
    /**
     * M�thode permettant d'ajouter un �clairage unicolore dans la base de donn�es
     */
    void doIt(const EclairageUnicolore::Ent & eclairage, const sqlite3 & bd);

    /**
     * M�thode permettant d'ajouter un �clairage multicolore dans la base de donn�es.
     */
    void doIt(const EclairageMulticolore::Ent & eclairage, const sqlite3 & bdd);


  private:
    SqlitePersiBny persiBny;

};
#endif
