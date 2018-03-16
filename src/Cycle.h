/**
* \file Cycle.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _CYCLE_H
#define _CYCLE_H

#include <iostream>
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

    };
    
    class Controleur {
      public:
        void activer(bool actif);

        void setHoraires(const std::string & heureDebut, const std::string & heureFin);

        void setJours(const std::array<bool, 7> & jours);

        void getHoraires(std::string & heureDebut, const std::string & heureFin);

        std::array<bool, 7> getJours();

    };
    
};
#endif
