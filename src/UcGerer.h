/*******************************************************
* \file UcGerer.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCGERER_H
#define _UCGERER_H


#include "SqlitePersiBny.h"

class Eclairage;

class UcGerer {
  public:
    /**
     * Méthode permettant d'activer/desactiver un éclairage passé en paramètre.
     */
    void doIt(const Ent & eclairage, bool etat);


  private:
    <Eclairage *> eclairages;

    SqlitePersiBny persiBny;

};
#endif
