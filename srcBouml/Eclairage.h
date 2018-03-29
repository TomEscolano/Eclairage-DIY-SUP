/**
* \file Eclairage.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGE_H
#define _ECLAIRAGE_H


#include <string>
#include <Cycle.h>
#include <SqlitePersiBny.h>

class Eclairage {

  public:
  
	Eclairage():controleur(){};

	//~Eclairage();

	class Ent {
	  private:

		unsigned int id;

		bool allume;

		bool active;

		std::string nom;

		unsigned int consommation;


	  public:
		void setID(const unsigned int & id);

		void setAllume(bool etat);

		void setActive(bool etat);

		void setNom(const std::string & nom);

		void setConsommation(const unsigned int & conso);

		unsigned int getID();

		bool getAllume();

		bool getActive();

		std::string getNom();

		unsigned int getConsommation();

	};

	class PersiBny {
	  public:
		void set(const Ent & ent);

		void get(Ent & ent);

	};
	
	class IHMJardin {
	  public:
		void set( Ent & ent);

	};

	class IHMFormulaire {
      public:
        void set( Ent & ent);

        void get(Ent & ent);

    };
	
	class Controleur {

		public:
			Controleur():ent(),persiBny(){};

			void doIt();
		
			Ent ent;

			PersiBny persiBny;

			Controleur controleur;

			enum Etat {id, active, allume, nom, conso};

			void activer(bool etat);

			void allumer(bool etat);

			void getIHMJardin();

			void getIHMFormulaire();

			void set( Ent & ent);

			void get(Ent & ent);

			void reguler(Cycle& cycle);

	};
	
private:
	Cycle cycle;

};
#endif
