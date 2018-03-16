/**
* \file Eclairage.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGE_H
#define _ECLAIRAGE_H


#include <string>
#include "Cycle.h"

class UcGerer;

class Eclairage {



  public:
  
    Eclairage():controleur(),ent(),persiBny(){};
    ~Eclairage();
    
    class Ent {
      private:

        unsigned int id;

        bool allume;

        bool active;

        std::string nom;

        unsigned int consommation;


      public:
        void setID(const unsigned int & id);

        void setAllume(bool etat);

        void setActive(bool etat);

        void setNom(const std::string & nom);

        void setConsommation(const unsigned int & conso);

        unsigned int getID();

        bool getAllume();

        bool getActive();

        std::string getNom();

        unsigned int getConsommation();

    };

    class Controleur {
      public:
        void activer(bool etat);

        void allumer(bool etat);

        void getIHMJardin();

        void getIHMFormulaire();

        void set(const Ent & ent);

        void get(Ent & ent);

    };
    
    
    class PersiBny {
      public:
        void set(const Ent & ent);

        void get(Ent & ent);

    };
    
    class IHMJardin {
      public:
        void set(const Ent & ent);

    };
    

  private:
    UcGerer * ucGerer;
    Cycle cycle;

private:

    Controleur controleur;
    Ent ent;
    PersiBny persiBny;

};
#endif
