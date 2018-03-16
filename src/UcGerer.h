/**
* \file UcGerer.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCGERER_H
#define _UCGERER_H


#include "UcMettreAJour.h"
#include "UcCommander.h"
#include <sqlite3.h>

class Eclairage;
class UcCommander;

class UcGerer {
  public:
    void emettreConfiguration(const Eclairage::Ent & eclairage);

    void desactiverEclairage(const Eclairage::Ent & eclairage);

    void supprimerEclairage(const Eclairage::Ent & eclairage);

    void activerEclairage(const Eclairage::Ent & eclairage);

    void ajouterEclairage(const Eclairage::Ent & eclairage, const sqlite3 & bd);

    void recevoirEclairage();

    void modifierConfiguration(const Eclairage::Ent & eclairage);

    void extraireEclairage(const sqlite3 & bd);

    void recevoirInfo(const Eclairage::Ent & eclairage);

    void visualiserInfo(const Eclairage::Ent & eclairage);


  private:

    Eclairage * eclairages;

    UcMettreAJour ucMettreAJour;

    UcCommander ucCommander;

};
#endif
