/**
* \file EclairageMulticolore.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGEMULTICOLORE_H
#define _ECLAIRAGEMULTICOLORE_H


#include <Eclairage.h>
#include <string>


class EclairageMulticolore : public Eclairage {
  public:
    
    class Ent {
      private:
        std::string couleur;

        std::string adresseMac;

        unsigned int niveauBatterie;

        float versionFirmware;

        int socket;

        std::string adresseIP;

        Controleur controleur;

        public:
            void setCouleur(const std::string & couleur);

            void setAdresseMac(const std::string & adresseMac);
        
            void setNiveauBatterie(const unsigned int & niveauBatterie);
        
            void setVersionFirmware(float version);
        
            void setAdresseIP(const std::string & adresseIP);
        
            std::string getCouleur();
        
            std::string getAdresseMac();
        
            unsigned int getNiveauBatterie();


    };
    
    class Controleur {
      private:
        Ent ent;


      public:
        void recevoir();

        void envoyer();

        void setCouleur(const std::string & couleur);

        void setAdresseMac(const std::string & adresseMac);

        void setNiveauBatterie(const unsigned int & niveauBatterie);

        void setVersionFirmware(float version);

        void setAdresseIP(const std::string & adresseIP);

        std::string getCouleur();

        std::string getAdresseMac();

        unsigned int getNiveauBatterie();


      private:
        IHMFormulaire ihmAjouter;

    };
    
};
#endif
