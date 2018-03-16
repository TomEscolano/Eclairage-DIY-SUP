/*****************************************************
* \file Controleur.h
* \Author Tom ESCOLANO


\brief Projet : Eclairage DIY
*******************************************************/

#ifndef _CONTROLEUR_H
#define _CONTROLEUR_H


#include "Ent.h"
#include "PersiBny.h"
#include <string>

#include <vector>


class Controleur {
  private:
    Ent ent;

    PersiBny persiBny;


  public:
    void activer(bool etat);

    void setHeureDebut(const std::string & heureDebut);

    std::string getHeureDebut();

    void setHeureFin(const std::string & heureFin);

    std::string getHeureFin();

    void setJours(const std::vector<bool> & jours);

    std::vector<bool> getJours();

};
#endif
