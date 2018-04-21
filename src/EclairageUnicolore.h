/*******************************************************
* \file EclairageUnicolore.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGEUNICOLORE_H
#define _ECLAIRAGEUNICOLORE_H


#include "Eclairage.h"
#include "Couleur.h"

class EclairageUnicolore : public Eclairage {
  public:
    class Ent : public Eclairage::Ent {
      private:
        Controleur controleur;

        int numeroPrise;


      public:
        /**
         * M�thode permettant de modifier le numero de la prise associ� � l'�clairage.
         */
        void setNumeroPrise(int num);

        /**
         * M�thode permettant de r�cup�rer le num�ro de la prise associ� � l'�clairage.
         */
        int getNumeroPrise();

    };
    
    class Controleur : public Eclairage::Controleur {
      private:
        Ent ent;

    };
    
    class PersiBny : public Eclairage::PersiBny {
    };
    
};
#endif
