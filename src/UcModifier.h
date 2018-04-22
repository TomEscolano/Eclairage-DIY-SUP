/*******************************************************
* \file UcModifier.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCMODIFIER_H
#define _UCMODIFIER_H


#include "SqlitePersiBny.h"

class UcModifier {
  public:
    /**
     * M�thode permettant de modifier la configuration un �clairage multicolore.
     */
    void doIt(const EclairageMulticolore::Ent & eclairage);

    /**
     * M�thode permettant de modifier la configuration d'un �clairage unicolore.
     */
    void doIt(const EclairageUnicolore::Ent & eclairage);


  private:
    SqlitePersiBny persiBny;

};
#endif
