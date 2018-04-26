/*******************************************************
* \file SUP.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _SUP_H
#define _SUP_H


#include <vector>
#include <EclairageUnicolore.h>
#include <EclairageMulticolore.h>
#include <FichierTextePersiBny.h>
#include <Eclairage.h>
#include <SqlitePersiBny.h>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <Utility.h>

class SUP {
  private:
    
    class PersiBny : public SqlitePersiBny{
      public:
        /**
         * Constructeur de la persistance lui indiquant le fichier de base de donnée.
         */

        PersiBny(): SqlitePersiBny("/var/eclairage/bdd.db"){};
    };
   
    PersiBny persiBny;

    /**
     * Méthode permettant d'afficher les informations d'un éclairage Unicolore :
     * - Nom
     * - Etat (allumé/activé)
     * - Consommation
     */
    void visualiserInfo(EclairageUnicolore::Ent eclairage);

    /**
     * Méthode permettant d'afficher les informations d'un éclairage Multicolore :
     * - Nom
     * - Etat (allumé/activé)
     * - Consommation
     * - Luminosité
     * - Batterie
     */
    void visualiserInfo(EclairageMulticolore::Ent eclairage);

    /**
     * Méthode permettant d'extraire la liste des eclairages unicolores et multicolores.
     */
    void extraireEclairages(std::vector<EclairageUnicolore> & eclairagesUnicolores, std::vector<EclairageMulticolore> & eclairagesMulticolores);

    /**
     * Méthode permettant de suivre la consommation électrique d'un éclairage.
     */
    void suivreConsoElectricite();

  public:
    void doIt();

};
#endif
