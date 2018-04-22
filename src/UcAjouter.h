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
     * Méthode permettant d'ajouter un éclairage unicolore dans la base de données
     */
    void doIt(const EclairageUnicolore::Ent & eclairage, const sqlite3 & bd);

    /**
     * Méthode permettant d'ajouter un éclairage multicolore dans la base de données.
     */
    void doIt(const EclairageMulticolore::Ent & eclairage, const sqlite3 & bdd);


  private:
    SqlitePersiBny persiBny;

};
#endif
