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
         * Méthode permettant de modifier le numero de la prise associé à l'éclairage.
         */
        void setNumeroPrise(int num);

        /**
         * Méthode permettant de récupérer le numéro de la prise associé à l'éclairage.
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
