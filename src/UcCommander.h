/*******************************************************
* \file UcCommander.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCCOMMANDER_H
#define _UCCOMMANDER_H

#include <Eclairage.h>
#include <EclairageMulticolore.h>
#include <EclairageUnicolore.h>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

class UcCommander {
  public:
    /**
     * Méthode permettant d'allumer/éteindre un éclairage multicolore passé en paramètres.
     */
    void doIt(EclairageMulticolore & eclairage, bool etat);
	
	/**
     * Méthode permettant d'allumer/éteindre un éclairage unicolore passé en paramètres.
     */
    void doIt(EclairageUnicolore & eclairage, bool etat);

};
#endif
