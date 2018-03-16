/*****************************************************
* \file Ent.h
* \Author Tom ESCOLANO


\brief Projet : Eclairage DIY
*******************************************************/

#ifndef _ENT_H
#define _ENT_H


#include <string>

#include <vector>


class Ent {
  private:
    bool etat = false;

    std::string heureFin;

    std::string heureDebut;

    std::vector<bool> jours;

};
#endif
