/*******************************************************
* \file EclairageUnicolore.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGEUNICOLORE_H
#define _ECLAIRAGEUNICOLORE_H


#include "Eclairage.h"
#include "Couleur.h"

/**
 * Classe fille (de eclairage) représentant un éclairage unicolore comportant:
 * - Un controleur
 * - Une entité comportant:
 *    - le numéro de prise associé à l'éclairage
 * - Une persistance (polymorphée)
 */
class EclairageUnicolore : public Eclairage {
  public:
    class Ent : public Eclairage::Ent {
      private:
        int numeroPrise;

      public:
        Ent():Eclairage::Ent(), numeroPrise(-1){};
        /**
         * Méthode permettant de modifier le numero de la prise associé à l'éclairage.
         */
        void setNumeroPrise(int num);

        /**
         * Méthode permettant de récupérer le numéro de la prise associé à l'éclairage.
         */
        int getNumeroPrise();

    };
    
    class PersiBny : public Eclairage::PersiBny {
    public:
      PersiBny():Eclairage::PersiBny(){};

      void set(Ent & ent);

      void get(Ent & ent);

    };

    class Controleur : public Eclairage::Controleur {
      public:
        Controleur():Eclairage::Controleur(), ent(), persiBny(){};

        Ent ent;

        PersiBny persiBny;


    };

    Controleur controleur;
    
};
#endif
