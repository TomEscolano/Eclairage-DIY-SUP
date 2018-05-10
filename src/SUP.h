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
         * Constructeur de la persistance lui indiquant le fichier de base de donn�e.
         */
        PersiBny(): SqlitePersiBny("/var/eclairage/bdd.db"){};
    };
   
    PersiBny persiBny;

    /**
     * M�thode permettant d'afficher les informations d'un �clairage Unicolore :
     * - Nom
     * - Etat (activ�/d�sactiv�)
     * - Consommation
     */
    void visualiserInfo(EclairageUnicolore::Ent eclairage);

    /**
     * M�thode permettant d'afficher les informations d'un �clairage Multicolore :
     * - Nom
     * - Etat (activ�/d�sactiv�)
     * - Consommation
     * - Luminosit�
     * - Batterie
     */
    void visualiserInfo(EclairageMulticolore::Ent eclairage);

    /**
     * M�thode permettant d'extraire la liste des eclairages unicolores et multicolores.
     */
    void extraireEclairages(std::vector<EclairageUnicolore> & eclairagesUnicolores, std::vector<EclairageMulticolore> & eclairagesMulticolores);

    /**
     * M�thode permettant de suivre la consommation �lectrique d'un �clairage.
     */
    void suivreConsoElectricite();

    /**
     * M�thode permettant d'afficher les �clairages en apellant leur IHMJardin
     */
    void afficherEclairages(std::vector<EclairageUnicolore> & eclairagesUnicolores, std::vector<EclairageMulticolore> & eclairagesMulticolores);

  public:
    /**
     * M�thode qui:
     * - Extrait les �clairages de la BDD
     * - Les affiche (avec leurs infos)
     */
    void doIt();

};
#endif
