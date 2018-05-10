/*******************************************************
* \file SUP.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _SUP_H
#define _SUP_H


#include <vector>
#include <Eclairage.h>
#include <SqlitePersiBny.h>
#include <EclairageUnicolore.h>
#include <EclairageMulticolore.h>
#include <FichierTextePersiBny.h>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <Utility.h>

// Classe de supervision du projet. (index.cgi sur le serveur WEB)
class SUP {
  private:
    
    /**
     * Classe de persistance, permet l'interraction avec la BDD
     */
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
     * - Etat (activé/désactivé)
     * - Consommation
     */
    void visualiserInfo(EclairageUnicolore::Ent eclairage);

    /**
     * Méthode permettant d'afficher les informations d'un éclairage Multicolore :
     * - Nom
     * - Etat (activé/désactivé)
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

    /**
     * Méthode permettant d'afficher les éclairages en apellant leur IHMJardin
     */
    void afficherEclairages(std::vector<EclairageUnicolore> & eclairagesUnicolores, std::vector<EclairageMulticolore> & eclairagesMulticolores);

  public:
    /**
     * Méthode qui:
     * - Extrait les éclairages de la BDD
     * - Les affiche (avec leurs infos)
     */
    void doIt();

};
#endif
