/*******************************************************
* \file UcSupprimer.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCSUPPRIMER_H
#define _UCSUPPRIMER_H


#include "SqlitePersiBny.h"

class UcSupprimer {
  public:
    /**
     * M�thode permettant de supprimer un �clairage.
     */
    void doIt(const Ent & eclairage);


  private:
    SqlitePersiBny persiBny;

};
#endif
