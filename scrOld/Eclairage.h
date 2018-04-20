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
#include <Utility.h>

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

		int x;

		int y;


	  public:
	  	Ent():id(0),allume(false), active(false),nom("undefined"), consommation(0), x(0), y(0){}

		void setID(const unsigned int & id);

		void setAllume(bool etat);

		void setActive(bool etat);

		void setNom(const std::string & nom);

		void setConsommation(const unsigned int & conso);

		void setX(int valeur);

		void setY(int valeur);

		unsigned int getID();

		bool getAllume();

		bool getActive();

		std::string getNom();

		unsigned int getConsommation();

		int getX();
		
		int getY();


	};

	class PersiBny : public SqlitePersiBny {
	  public:

	  	PersiBny(): SqlitePersiBny("/var/eclairage/bdd.db"){};

		void set(Ent & ent);

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
			Ent ent;

			PersiBny persiBny;

		public:
			Controleur():ent(),persiBny(){};

			void doIt();
		
			void activer(bool etat);

			void allumer(bool etat);

			void getIHMJardin();

			void getIHMFormulaire();

			void setID(const unsigned int & id);

			void setAllume(bool etat);

			void setActive(bool etat);

			void setNom(const std::string & nom);

			void setConsommation(const unsigned int & conso);

			void setX(int valeur);
			
			void setY(int valeur);

			unsigned int getID();

			bool getAllume();

			bool getActive();

			std::string getNom();

			unsigned int getConsommation();

			int getX();
			
			int getY();

	};
	
private:
	Cycle cycle;

public:
	Controleur controleur;

};
#endif
