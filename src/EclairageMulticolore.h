/*******************************************************
* \file EclairageMulticolore.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGEMULTICOLORE_H
#define _ECLAIRAGEMULTICOLORE_H


#include <Eclairage.h>

/**
 * Classe fille (de eclairage) représentant un éclairage multicolore comportant:
 * - Un controleur
 * - Une entité comportant:
 *    - l'adresse IP de l'eclairage
 *    - son adresse MAC bluetooth
 *    - le niveau de sa batterie
 *    - sa version de firmware
 *    - le taux de luminosité actuel
 * - Une persistance (polymorphée)
 */
class EclairageMulticolore : public Eclairage {

	//Instanciation de la classe mère de l'éclairage et de son controleur.
	public:
		EclairageMulticolore():Eclairage(),controleur(){};

		/**
		 * Classe entité de l'éclairage comportant:
		 * 	- Une adresse IP
		 *  - Un adresse MAC
		 * 	- Le iveau de batterie du RapsberryPi controlant l'éclairage
		 * 	- La version du firmware
		 * 	- La lminosité venant du capteur sur le RPI
		 */
		class Ent : public Eclairage::Ent {
			private:
				std::string adresseIP;

				std::string adresseMac;

				unsigned int niveauBatterie;

				float versionFirmware;

				int luminosite;

			public:
				Ent():Eclairage::Ent(),adresseIP("undefined"), adresseMac("undefined"), niveauBatterie(0), versionFirmware(0.0F), luminosite(0){};

				void setAdresseIP(const std::string & adresseIP);

				void setAdresseMac(const std::string & adresseMac);

				void setNiveauBatterie(const unsigned int & niveauBatterie);

				void setVersionFirmware(float version);

				void setLuminosite(int luminosite);

				std::string getAdresseIP();

				std::string getAdresseMac();

				unsigned int getNiveauBatterie();

				float getVersionFirmware();

				int getLuminosite();

		};
		
		/**
		 * Classe de persistance dérivant de la classe Eclairage::PersiBny, permet de set et get la configuration de l'éclairage dans la base de données.
		 */
		class PersiBny : public Eclairage::PersiBny {
		 public:
			PersiBny():Eclairage::PersiBny(){};
				
				/**
				 * Méthode permettant de set la configuration de l'éclairage dans la base de données.
				 */
				void set(Ent & ent);

				/**
				 * Méthode permettant de get la configuration de l'éclairage dans la base de données.
				 */
				void get(Ent & ent);

		};

		/**
		 * IHM présentant au propriétaire un forulaire de création d'éclairage multicolore.
		 */
		class IHMFormulaire : public Eclairage::IHMFormulaire {
			 public:
			 /**
				* Méthde permettant d'afficher le formulaire de création d'éclairage multicolore
				*/
			 void set(EclairageMulticolore::Ent & ent);

			 /**
				* Méthode permettant de récupérer les données entrées par l'utilisateur lors de la création d'éclairage multicolore.
				*/
			 void get(EclairageMulticolore::Ent & ent);

		 };

		/**
		 * Controleur de l'eclairage multicolore composé d'une entité, une persistance et une IHM de création.
		 */		
		class Controleur : public Eclairage::Controleur {
			public:
				Ent ent;

				PersiBny persiBny;

				IHMFormulaire ihmFormulaire;

				Controleur():Eclairage::Controleur(), ent(), persiBny(){};

				/**
				 * Méthode permettant de recevoir une configuration d'éclairage via le réseau.
				 */
				void recevoir();

				/**
				 * Méthode permettant d'envoyer une configuration d'eclairage via le réseau.
				 */
				void envoyer();

		};

		Controleur controleur;
};
#endif
