/*******************************************************
* \file SUP.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _SUP_H
#define _SUP_H


#include <vector>

#include "UcExporter.h"
#include "UcImporter.h"
#include "UcGerer.h"
#include "UcCommander.h"
#include "UcMettreAJour.h"

class EclairageUnicolore;
class EclairageMulticolore;
class UcModifier;
class UcAjouter;
class UcSupprimer;

class SUP {
  public:
    /**
     * Méthode permettant d'afficher les informations d'un éclairage :
     * - ID
     * - Etat (allumé/activé)
     * - Consommation
     * - Luminosité
     * - Batterie
     */
    void visualiserInfo(const Ent & eclairage);

    /**
     * Méthode permettant d'extraire la liste des eclairages unicolores et multicolores.
     */
    void extraireEclairages(const sqlite3 & bdd, std::vector<EclairageUnicolore> & eclairagesUnicolores, std::vector<EclairageMulticolore> & eclairagesMulticolores);

    /**
     * Méthode permettant de suivre la consommation électrique d'un éclairage.
     */
    void suivreConsoElectricite();

    void doIt();


  private:
    UcExporter ucExporter;

    UcImporter ucImporter;

    UcGerer ucGerer;

    <UcModifier> ucModifier;

    <UcAjouter> ucAjouter;

    <UcSupprimer> ucSupprimer;

    UcCommander ucCommander;

    UcMettreAJour ucMettreAJour;

};
#endif
