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
    EclairageMulticolore():Eclairage(),controleur(){};

    class Ent : public Eclairage::Ent {
      private:
        std::string adresseIP;

        std::string adresseMac;

        unsigned int niveauBatterie;

        float versionFirmware;

        int luminosite;


      public:
        Ent():Eclairage::Ent(),adresseIP("undefined"), adresseMac("undefined"), niveauBatterie(0), versionFirmware(0.0F), luminosite(0){};

        void setAdresseIP(const std::string & adresseIP);

        void setAdresseMac(const std::string & adresseMac);

        void setNiveauBatterie(const unsigned int & niveauBatterie);

        void setVersionFirmware(float version);

        void setLuminosite(int luminosite);

        std::string getAdresseIP();

        std::string getAdresseMac();

        unsigned int getNiveauBatterie();

        float getVersionFirmware();

        int getLuminosite();

    };
    
    class Controleur : public Eclairage::Controleur {
      private:
        Ent ent;

        PersiBny persiBny;

      public:
        Controleur():Eclairage::Controleur(), ent(), persiBny(){};


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
    public:
      PersiBny():Eclairage::PersiBny(){};

    };

    Controleur controleur;
};
#endif
