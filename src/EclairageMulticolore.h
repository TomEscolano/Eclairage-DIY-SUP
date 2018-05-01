/*******************************************************
* \file EclairageMulticolore.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGEMULTICOLORE_H
#define _ECLAIRAGEMULTICOLORE_H


#include <Eclairage.h>

/**
 * Classe fille (de eclairage) repr�sentant un �clairage multicolore comportant:
 * - Un controleur
 * - Une entit� comportant:
 *    - l'adresse IP de l'eclairage
 *    - son adresse MAC bluetooth
 *    - le niveau de sa batterie
 *    - sa version de firmware
 *    - le taux de luminosit� actuel
 * - Une persistance (polymorph�e)
 */
class EclairageMulticolore : public Eclairage {

	//Instanciation de la classe m�re de l'�clairage et de son controleur.
	public:
		EclairageMulticolore():Eclairage(),controleur(){};

		/**
		 * Classe entit� de l'�clairage comportant:
		 * 	- Une adresse IP
		 *  - Un adresse MAC
		 * 	- Le iveau de batterie du RapsberryPi controlant l'�clairage
		 * 	- La version du firmware
		 * 	- La lminosit� venant du capteur sur le RPI
		 */
		class Ent : public Eclairage::Ent {
			private:
				std::string adresseIP;

				std::string adresseMac;

				unsigned int niveauBatterie;

				float versionFirmware;

				int luminosite;

				const char * DB = "/var/eclairage/bdd.db";

				SqlitePersiBny::Resultat resultat;


			public:
				Ent():Eclairage::Ent(),adresseIP("undefined"), adresseMac("undefined"), niveauBatterie(0), versionFirmware(0.0F), luminosite(0){};

				void setAdresseIP(std::string adresseIP);

				void setAdresseMac(std::string adresseMac);

				void setNiveauBatterie(unsigned int niveauBatterie);

				void setVersionFirmware(float version);

				void setLuminosite(int luminosite);

				std::string getAdresseIP();

				std::string getAdresseMac();

				unsigned int getNiveauBatterie();

				float getVersionFirmware();

				int getLuminosite();

		};
		
		/**
		 * Classe de persistance d�rivant de la classe Eclairage::PersiBny, permet de set et get la configuration de l'�clairage dans la base de donn�es.
		 */
		class PersiBny : public Eclairage::PersiBny {
		 public:
			PersiBny():Eclairage::PersiBny(){};
				
				/**
				 * M�thode permettant de set la configuration de l'�clairage dans la base de donn�es.
				 */
				void set(Ent & ent);

				/**
				 * M�thode permettant de get la configuration de l'�clairage dans la base de donn�es.
				 */
				void get(Ent & ent);

		};

		/**
		 * IHM pr�sentant au propri�taire un forulaire de cr�ation d'�clairage multicolore.
		 */
		class IHMFormulaire : public Eclairage::IHMFormulaire {
			public:
			/**
			 * M�thde permettant d'afficher le formulaire de cr�ation d'�clairage multicolore
			 */
			void set(EclairageMulticolore::Ent & ent, std::string nom, std::string couleur, std::string id);

			/**
			 * M�thode permettant de r�cup�rer les donn�es entr�es par l'utilisateur lors de la cr�ation d'�clairage multicolore.
			 */
			void get(EclairageMulticolore::Ent & ent);

		 };

		 class IHMJardin : public Eclairage::IHMJardin {
		 	public:
				/**
				 * M�thode permettant de mettre � jour l'icone repr�sentant l'�clairage dans l'IHM de supervision.
				 */
				void set(EclairageMulticolore::Ent & ent);
		 };

		class IHMParametre{
		 	public:

				void set(EclairageMulticolore::Ent & ent);
		 };

		/**
		 * Controleur de l'eclairage multicolore compos� d'une entit�, une persistance et une IHM de cr�ation.
		 */		
		class Controleur : public Eclairage::Controleur {
			public:
				Ent ent;

				PersiBny persiBny;

				IHMFormulaire ihmFormulaire;

				IHMJardin ihmJardin;

				IHMParametre ihmParametre;

				Controleur():Eclairage::Controleur(), ent(), persiBny(){};

				/**
				 * M�thode permettant de recevoir une configuration d'�clairage via le r�seau.
				 */
				void recevoir();

				/**
				 * M�thode permettant d'envoyer une configuration d'eclairage via le r�seau.
				 */
				void envoyer();

				/**
				 * M�thode permettant d'afficher l'IHM Jardin dans le superviseur.
				 */
				void getIHMJardin();

		};

		Controleur controleur;
};
#endif
