/**
* \file EclairageMulticolore.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGEMULTICOLORE_H
#define _ECLAIRAGEMULTICOLORE_H


#include <Eclairage.h>
#include <string>


class EclairageMulticolore : public Eclairage {
  public:
  
	EclairageMulticolore():Eclairage(),controleur(){};
	
	class Ent : public Eclairage::Ent {
	  private:
		std::string couleur;

		std::string adresseMac;

		unsigned int niveauBatterie;

		float versionFirmware;

		int socket;

		std::string adresseIP;

		public:
			Ent():Eclairage::Ent(),couleur("undefined"), adresseMac("undefined"), niveauBatterie(0), versionFirmware(0.0F), socket(-1), adresseIP("undefined"){};

			void setCouleur(const std::string & couleur);

			void setAdresseMac(const std::string & adresseMac);
		
			void setNiveauBatterie(const unsigned int & niveauBatterie);
		
			void setVersionFirmware(float version);
		
			void setAdresseIP(const std::string & adresseIP);

			void setID(unsigned int id);

			void setAllume(bool etat);

			void setActive(bool etat);

			void setNom(std::string nom);

			void setConsommation(unsigned int conso);
		
			unsigned int getID();

			bool getAllume();

			bool getActive();

			std::string getNom();

			unsigned int getConsommation();

			std::string getCouleur();
		
			std::string getAdresseMac();
		
			unsigned int getNiveauBatterie();

			float getVersionFirmware();

			std::string getAdresseIP();


	};

	class PersiBny : public Eclairage::PersiBny {
		public:
			PersiBny():Eclairage::PersiBny(){};

			void set(EclairageMulticolore::Ent & ent);

			void get(Ent & ent);
	};
	
	class Controleur : public Eclairage::Controleur{
	  public:
		Ent ent;

		PersiBny persiBny;

		Controleur():Eclairage::Controleur(), ent(), persiBny(){};
		
		void recevoir();

		void envoyer();

		void setCouleur(const std::string & couleur);

		void setAdresseMac(const std::string & adresseMac);

		void setNiveauBatterie(const unsigned int & niveauBatterie);

		void setVersionFirmware(float version);

		void setAdresseIP(const std::string & adresseIP);

		void setID(unsigned int id);

		void setAllume(bool etat);

		void setActive(bool etat);

		void setNom(std::string nom);

		unsigned int getID();

		bool getAllume();

		bool getActive();

		std::string getNom();

		unsigned int getConsommation();

		void setConsommation(unsigned int conso);

		std::string getCouleur();

		std::string getAdresseMac();

		unsigned int getNiveauBatterie();

		float getVersionFirmware();

		std::string getAdresseIP();

	  private:
		IHMFormulaire ihmAjouter;

	};
	
	Controleur controleur;

};
#endif
