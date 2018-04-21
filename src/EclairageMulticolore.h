/*******************************************************
* \file EclairageMulticolore.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGEMULTICOLORE_H
#define _ECLAIRAGEMULTICOLORE_H


#include "Eclairage.h"
#include <string>


class EclairageMulticolore : public Eclairage {
  public:
    class Ent : public Eclairage::Ent {
      private:
        std::string adresseIP;

        std::string adresseMac;

        unsigned int niveauBatterie;

        float versionFirmware;


      public:
        void setAdresseIP(const std::string & adresseIP);

        void setAdresseMac(const std::string & adresseMac);

        void setNiveauBatterie(const unsigned int & niveauBatterie);

        void setVersionFirmware(float version);

        std::string getAdresseIP();

        std::string getAdresseMac();

        unsigned int getNiveauBatterie();

        float getVersionFirmware();


      private:
        Controleur controleur;

    };
    
    class Controleur : public Eclairage::Controleur {
      private:
        Ent ent;


      public:
        /**
         * Méthode permettant de recevoir une configuration d'éclairage via le réseau.
         */
        void recevoir();

        /**
         * Méthode permettant d'envoyer une configuration d'eclairage via le réseau.
         */
        void envoyer();

    };
    
    class PersiBny : public Eclairage::PersiBny {
    };
    
};
#endif
