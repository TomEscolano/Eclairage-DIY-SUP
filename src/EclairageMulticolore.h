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
  
    EclairageMulticolore():Eclairage(),controleur(){};
    
    class Ent : public Eclairage::Ent {
      private:
        std::string couleur;

        std::string adresseMac;

        unsigned int niveauBatterie;

        float versionFirmware;

        int socket;

        std::string adresseIP;

        public:
            Ent():Eclairage::Ent(),couleur("undefined"), adresseMac("undefined"), niveauBatterie(0), versionFirmware(0.0F), socket(-1), adresseIP("undefined"){};

            void setCouleur(const std::string & couleur);

            void setAdresseMac(const std::string & adresseMac);
        
            void setNiveauBatterie(const unsigned int & niveauBatterie);
        
            void setVersionFirmware(float version);
        
            void setAdresseIP(const std::string & adresseIP);

            unsigned int getID();
        
            std::string getCouleur();
        
            std::string getAdresseMac();
        
            unsigned int getNiveauBatterie();


    };

    class PersiBny : public Eclairage::PersiBny {
        public:
            PersiBny():Eclairage::PersiBny(){};

            void set(const Ent & ent);

            void get(Ent & ent);
    };
    
    class Controleur : public Eclairage::Controleur{
      private:
        Ent ent;
        PersiBny persiBny;

      public:
        Controleur():Eclairage::Controleur(), ent(), persiBny(){};
        
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
    
    Controleur controleur;

};
#endif
