/**
* \file EclairageUnicolore.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGEUNICOLORE_H
#define _ECLAIRAGEUNICOLORE_H


#include <Eclairage.h>
#include <Couleur.h>
#include <string>


class EclairageUnicolore : public Eclairage {
  public:
    class Ent : public Eclairage::Ent {
      public:
        void setCouleur(Couleur couleur);
        
        Couleur getCouleur();

      private:
        Couleur couleur;

    };
    
    class Controleur : public Eclairage::Controleur{
      private:
        Ent ent;

      public:
        void setCouleur(Couleur couleur);

        Couleur getCouleur();

    };
  
  Controleur controleur;

};
#endif
