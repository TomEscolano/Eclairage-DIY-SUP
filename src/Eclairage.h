/*******************************************************
* \file Eclairage.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGE_H
#define _ECLAIRAGE_H


#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <Utility.h>
#include <cgicc/Cgicc.h>
#include <SqlitePersiBny.h>
#include <ClientTcpComBny.h>
#include <cgicc/HTMLClasses.h>
#include <FichierTextePersiBny.h>
#include <cgicc/HTTPHTMLHeader.h>

/**
 * Classe m�re repr�sentant un �clairage g�n�rique comportant:
 * - Une IHM Formulaire (Forumaire de cr�ation d'�clairage)
 * - Une IHM Jardin (Icone de l'eclairage dans l'IHM de supervision)
 * - Un controleur
 * - Une entit�
 * - Une persistance
 */
class Eclairage {
  public:
	
	Eclairage():controleur(){};

	class Ent {
	  private:

		unsigned int id;

		bool allume;

		bool active;

		std::string nom;

		unsigned int consommation;

		/**
		 * Couleurs possibles:
		 * 	- rouge
		 * 	- rougeOrange
		 * 	- orange
		 * 	- jauneOrange
		 * 	- jaune
		 * 	- vert
		 * 	- turquoise
		 * 	- vertBleu
		 * 	- bleuClair
		 * 	- bleuVert
		 * 	- bleu
		 * 	- bleuSombre
		 * 	- roseClair
		 * 	- rose
		 * 	- roseSombre
		 * 	- blanc
		 */
		std::string couleur;

		int x;

		int y;

		const char * DB = "/var/eclairage/bdd.db";

	  public:

	  	Ent():id(0), allume(false), active(false), nom("undefined"), consommation(0), couleur("blanc"), x(0), y(0){}
	
		virtual void setID(const unsigned int & id);
	
		virtual void setAllume(bool etat);
	
		virtual void setActive(bool etat);
	
		virtual void setNom(const std::string & nom);
	
		virtual void setCouleur(std::string couleur);
	
		virtual void setConsommation(const unsigned int & conso);
	
		virtual void setX(int x);
	
		virtual void setY(int y);
	
		virtual unsigned int getID();
	
		virtual bool getAllume();
	
		virtual bool getActive();
	
		virtual std::string getNom();
	
		virtual std::string getCouleur();
	
		virtual unsigned int getConsommation();
	
		virtual int getX();
	
		virtual int getY();

	};

	/**
	 * IHM pr�sentant au propri�taire un forulaire de cr�ation d'�clairage.
	 */
	class IHMFormulaire {
	  public:
		/**
		 * M�thde permettant d'afficher le formulaire de cr�ation d'�clairage
		 */
		void set(Eclairage::Ent & ent, std::string type, std::string x, std::string y);

		/**
		 * M�thode permettant de r�cup�rer les donn�es entr�es par l'utilisateur lors de la cr�ation d'�clairage.
		 */
		void get(Eclairage::Ent & ent);

	};

   /**
	* Classe permettant la persistance de l'�clairage dans la BDD
	*/
	class PersiBny : public SqlitePersiBny{
	  public:
	  	/**
		 * Constructeur de la persistance lui indiquant le fichier de base de donn�e.
	  	 **/
	  	PersiBny(): SqlitePersiBny("/var/eclairage/bdd.db"){};

		/**
		 * M�thode permettant de modifier la configuration de l'�clairage dans la persistance.
		 */
		void set(Ent & ent);

		/**
		 * M�thode permettant de r�cup�rer l'entit� de l'�clairage depuis la persistance.
		 */
		void get(Ent & ent);

	};
	
	class IHMJardin {
	  public:
		/**
		 * M�thode permettant de mettre � jour l'icone repr�sentant l'�clairage dans l'IHM de supervision.
		 */
		void set(const Eclairage::Ent & ent);

	};
	
	/**
	 * Controleur de la classe eclairage.
	 */
	class Controleur {
	  public:
		PersiBny persiBny;

		Ent ent;

		IHMJardin ihmJardin;

		IHMFormulaire ihmFormulaire;

		/**
		 * Constructeur du controleur de l'eclairage. Instancie l'entit� et la persistance.
		 */
	  	Controleur():ent(),persiBny(){};

		/**
		 * M�thode permettant d'activer/d�sactiver l'�clairage en fonction d'un bool�en pass� en param�tres.
		 */
		void activer(bool etat);

		/**
		 * M�thode permettant d'allumer/�teindre un �clairage gr�ce � un bool�en pass� en param�tre.
		 */
		void allumer(bool etat);

		/**
		 * M�thode permettant de r�cup�rer l'�tat de l'IHMJardin (Icone repr�sentant l'�clairage dans l'IHM de supervision)
		 */
		void getIHMJardin();

		/**
		 * M�thode permettant de r�cup�rer les informations entr�es par le propri�taire lors de la cr�ation de l'�clairage.
		 */
		void getIHMFormulaire();

		/**
		 * M�thode permettant de modifier int�gralement la configuration de l'�clairage en lui passant une entit� en param�tres.
		 */
		void set(const Eclairage::Ent & ent);

		/**
		 * M�thode permettant de r�cup�rer l'entit� de l'�clairage.
		 */
		void get(Eclairage::Ent & ent);

	};
	
	/**
	 * L'�clairage n'a qu'un controleur, accessible en public, qui controle l'eclairage dans sa totalit�.
	 */
	Controleur controleur;

};
#endif
