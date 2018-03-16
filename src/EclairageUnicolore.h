/**
* \file EclairageUnicolore.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGEUNICOLORE_H
#define _ECLAIRAGEUNICOLORE_H


#include "Eclairage.h"
#include "Couleur.h"
#include <string>


class EclairageUnicolore : public Eclairage {
  public:
    class Ent {
      private:
        Couleur couleur;

        Controleur controleur;

    };
    
    class Controleur {
      private:
        Ent ent;


      public:
        void setCouleur(const std::string & couleur);

        std::string getCouleur();

    };
    
};
#endif
