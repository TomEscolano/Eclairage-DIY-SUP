/**
* \file UcGerer.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCGERER_H
#define _UCGERER_H

#include <vector>
#include <Eclairage.h>
#include <EclairageUnicolore.h>
#include <EclairageMulticolore.h>
#include <UcMettreAJour.h>
#include <UcCommander.h>
#include <sqlite3.h>
#include <SqlitePersiBny.h>

class Eclairage;
class UcCommander;

class UcGerer {

    class PersiBny : public SqlitePersiBny {
      public:

        PersiBny(): SqlitePersiBny("/var/eclairage/bdd.db"){};
    };

  public:

    void emettreConfiguration(const Eclairage::Ent & eclairage);

    void desactiverEclairage(Eclairage::Ent & eclairage);

    void supprimerEclairage(Eclairage::Ent & eclairage);

    void activerEclairage(Eclairage::Ent & eclairage);

    void ajouterEclairageUnicolore(EclairageUnicolore::Ent & ent);

    void ajouterEclairageMulticolore(EclairageMulticolore::Ent & ent);

    void recevoirEclairage();

    void modifierConfigurationUnicolore(EclairageUnicolore::Controleur & eclairage);

    void modifierConfigurationMulticolore(EclairageMulticolore::Controleur & eclairage);

    std::vector<EclairageMulticolore> extraireEclairagesMulticolores();
    
    std::vector<EclairageUnicolore> extraireEclairagesUnicolores();

    void recevoirInfo(const Eclairage::Ent & eclairage);

    void visualiserInfo(const Eclairage::Ent & eclairage);

    void afficherEclairages(std::vector<EclairageMulticolore> eclairagesMulticolores, std::vector<EclairageUnicolore> eclairagesUnicolores);


  private:

    Eclairage * eclairages;

    UcMettreAJour ucMettreAJour;

    UcCommander ucCommander;

    PersiBny persi;

};
#endif
