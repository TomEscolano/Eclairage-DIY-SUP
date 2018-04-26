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
         * Constructeur de la persistance lui indiquant le fichier de base de donn�e.
         */

        PersiBny(): SqlitePersiBny("/var/eclairage/bdd.db"){};
    };
   
    PersiBny persiBny;

    /**
     * M�thode permettant d'afficher les informations d'un �clairage Unicolore :
     * - Nom
     * - Etat (allum�/activ�)
     * - Consommation
     */
    void visualiserInfo(EclairageUnicolore::Ent eclairage);

    /**
     * M�thode permettant d'afficher les informations d'un �clairage Multicolore :
     * - Nom
     * - Etat (allum�/activ�)
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

  public:
    void doIt();

};
#endif
