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
		 * 	- Le niveau de batterie du RapsberryPi controlant l'�clairage
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
			void set(EclairageMulticolore::Ent & ent, std::string nom, std::string couleur, std::string id, std::string x, std::string y);

			/**
			 * M�thode permettant de r�cup�rer les donn�es entr�es par l'utilisateur lors de la cr�ation d'�clairage multicolore.
			 */
			void get(EclairageMulticolore::Ent & ent);

		 };

		 /**
		  * Classe permettant d'afficher l'IHM de l'�clairage dans le jardin
		  */
		 class IHMJardin : public Eclairage::IHMJardin {
		 	public:
				/**
				 * M�thode permettant de mettre � jour l'icone repr�sentant l'�clairage dans l'IHM de supervision.
				 */
				void set(EclairageMulticolore::Ent & ent);
		 };

		 /**
		  * Classe permettant d'afficher l'IHM de configuration de l'�clairage
		  */
		class IHMParametre{
		 	public:
		 		/**
		 		 * M�thode permettant d'afficher la page de param�trage de l'�clairage
		 		 */
				void set(EclairageMulticolore::Ent & ent);
		 };

		 /**
		  * Classe permettant de communiquer par r�seau avec l'�clairage
		  */
		 class EclairageComBny{
		 	private:
		 		ClientTcpComBny clientTcpComBny;

		 	public:
		 	   /**
		  		* M�thode permettant d'allumer un �clairage distant par le r�seau
		  		*/
		 		void allumer(EclairageMulticolore::Ent & ent, bool etat);
		 	   /**
		  		* M�thode permettant de changer la couleur un �clairage distant par le r�seau
		  		*/
		 		void changerCouleur(EclairageMulticolore::Ent & ent, std::string couleur);
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

				EclairageComBny eclairageComBny;

				Controleur():Eclairage::Controleur(), ent(), persiBny(){};

				/**
				 * M�thode permettant d'afficher l'IHM Jardin dans le superviseur.
				 */
				void getIHMJardin();

		};

		Controleur controleur;
};
#endif
