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

    };

    class Controleur : public Eclairage::Controleur {
      private:
        Controleur():Eclairage::Controleur(), ent(), persiBny(){};

        EclairageUnicolore::Ent ent;

        EclairageUnicolore::PersiBny persiBny;


    };
    
};
#endif
