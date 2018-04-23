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
 * Classe fille (de eclairage) repr�sentant un �clairage unicolore comportant:
 * - Un controleur
 * - Une entit� comportant:
 *    - le num�ro de prise associ� � l'�clairage
 * - Une persistance (polymorph�e)
 */
class EclairageUnicolore : public Eclairage {
  public:
    class Ent : public Eclairage::Ent {
      private:
        int numeroPrise;

      public:
        Ent():Eclairage::Ent(), numeroPrise(-1){};
        /**
         * M�thode permettant de modifier le numero de la prise associ� � l'�clairage.
         */
        void setNumeroPrise(int num);

        /**
         * M�thode permettant de r�cup�rer le num�ro de la prise associ� � l'�clairage.
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
