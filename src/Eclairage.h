/*******************************************************
* \file Eclairage.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGE_H
#define _ECLAIRAGE_H


#include <string>

#include <Couleur.h>
#include <SqlitePersiBny.h>

/**
 * Classe mère représentant un éclairage générique comportant:
 * - Une IHM Formulaire (Forumaire de création d'éclairage)
 * - Une IHM Jardin (Icone de l'eclairage dans l'IHM de supervision)
 * - Un controleur
 * - Une entité
 * - Une persistance
 */
class Eclairage {
  public:
	
	class Ent {
	  private:

		unsigned int id;

		bool allume;

		bool active;

		std::string nom;

		unsigned int consommation;

		Couleur couleur;

		int x;

		int y;


	  public:
	
		virtual void setID(const unsigned int & id);
	
		virtual void setAllume(bool etat);
	
		virtual void setActive(bool etat);
	
		virtual void setNom(const std::string & nom);
	
		virtual void setCouleur(Couleur couleur);
	
		virtual void setConsommation(const unsigned int & conso);
	
		virtual void setX(int x);
	
		virtual void setY(int y);
	
		virtual unsigned int getID();
	
		virtual bool getAllume();
	
		virtual bool getActive();
	
		virtual std::string getNom();
	
		virtual Couleur getCouleur();
	
		virtual unsigned int getConsommation();
	
		virtual int getX();
	
		virtual int getY();

	};

	/**
	 * IHM présentant au propriétaire un forulaire de création d'éclairage.
	 */
	class IHMFormulaire {
	  public:
		/**
		 * Méthde permettant d'afficher le formulaire de création d'éclairage
		 */
		void set(const Eclairage::Ent & ent);

		/**
		 * Méthode permettant de récupérer les données entrées par l'utilisateur lors de la création d'éclairage.
		 */
		void get(Eclairage::Ent & ent);

	};

	class PersiBny : public SqlitePersiBny{
	  public:
	  	/**
		 * Constructeur de la persistance lui indiquant le fichier de base de donnée.
	  	 **/

	  	PersiBny(): SqlitePersiBny("/var/eclairage/bdd.db"){};

		/**
		 * Méthode permettant de modifier la configuration de l'éclairage dans la persistance.
		 */
		void set(const Eclairage::Ent & ent);

		/**
		 * Méthode permettant de récupérer l'entité de l'éclairage depuis la persistance.
		 */
		void get(Eclairage::Ent & ent);

	};
	
	class IHMJardin {
	  public:
		/**
		 * Méthode permettant de mettre à jour l'icone représentant l'éclairage dans l'IHM de supervision.
		 */
		void set(const Eclairage::Ent & ent);

	};
	
	/**
	 * Controleur de la classe eclairage.
	 */
	class Controleur {
	  private:
		PersiBny persiBny;

		Ent ent;

		IHMJardin ihmJardin;


	  public:
		/**
		 * Méthode permettant d'activer/désactiver l'éclairage en fonction d'un booléen passé en paramètres.
		 */
		void activer(bool etat);

		/**
		 * Méthode permettant d'allumer/éteindre un éclairage grâce à un booléen passé en paramètre.
		 */
		void allumer(bool etat);

		/**
		 * Méthode permettant de récupérer l'état de l'IHMJardin (Icone représentant l'éclairage dans l'IHM de supervision)
		 */
		void getIHMJardin();

		/**
		 * Méthode permettant de récupérer les informations entrées par le propriétaire lors de la création de l'éclairage.
		 */
		void getIHMFormulaire();

		/**
		 * Méthode permettant de modifier intégralement la configuration de l'éclairage en lui passant une entité en paramètres.
		 */
		void set(const Eclairage::Ent & ent);

		/**
		 * Méthode permettant de récupérer l'entité de l'éclairage.
		 */
		void get(Eclairage::Ent & ent);


	  private:
		IHMFormulaire ihmFormulaire;

	};
	
	Controleur controleur;

};
#endif
