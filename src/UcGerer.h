/*******************************************************
* \file UcGerer.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCGERER_H
#define _UCGERER_H

#include <Eclairage.h>
#include <iostream>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

class UcGerer {
  public:
    /**
     * M�thode permettant d'activer/desactiver un �clairage pass� en param�tre.
     */
    void doIt(Eclairage::Ent & eclairage, bool etat);

};
#endif
