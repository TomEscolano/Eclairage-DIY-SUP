/**
* \file Cycle.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _CYCLE_H
#define _CYCLE_H

#include <array>
#include <string>

class Cycle {
  public:
    class Ent {
      private:
        std::string heureDebut;

        std::string heureFin;

        std::array<bool, 7> jours;

        bool actif;

      public:
       void setHeureDebut(std::string heure);

       void setHeureFin(std::string heure);

       void setJours(std::array<bool, 7> jours);

       void setActif(bool actif);

       std::string getHeureDebut();

       std::string getHeureFin();

       std::array<bool, 7> getJours();

       bool getActif();


    };
    
    class Controleur {
    
    private:
      Ent ent;

      public:
        void activer(bool actif);

        void setHoraires(const std::string & heureDebut, const std::string & heureFin);

        void setJours(const std::array<bool, 7> & jours);

        void getHoraires(std::string & heureDebut, std::string & heureFin);

        std::array<bool, 7> getJours();

    };
    
};
#endif
