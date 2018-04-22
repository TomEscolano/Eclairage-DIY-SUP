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
     * Méthode permettant de modifier la configuration un éclairage multicolore.
     */
    void doIt(const EclairageMulticolore::Ent & eclairage);

    /**
     * Méthode permettant de modifier la configuration d'un éclairage unicolore.
     */
    void doIt(const EclairageUnicolore::Ent & eclairage);


  private:
    SqlitePersiBny persiBny;

};
#endif
