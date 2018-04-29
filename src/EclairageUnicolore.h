/*******************************************************
* \file EclairageUnicolore.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGEUNICOLORE_H
#define _ECLAIRAGEUNICOLORE_H


#include <Eclairage.h>

/**
 * Classe fille (de eclairage) représentant un éclairage unicolore comportant:
 * - Un controleur
 * - Une entité comportant:
 *    - le numéro de prise associé à l'éclairage
 * - Une persistance (polymorphée)
 */
class EclairageUnicolore : public Eclairage {
	public:
		class Ent : public Eclairage::Ent {
			private:
				int numeroPrise;

				const char * DB = "/var/eclairage/bdd.db";

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
		
		/**
		 * Classe de persistance de l'éclairage dérivant de la classe mère Eclairage::PersiBny. Permet de set et de get la configuration de l'éclairage dans la base de données.
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
		 * IHM présentant au propriétaire un forulaire de création d'éclairage unicolore.
		 */
		class IHMFormulaire : public Eclairage::IHMFormulaire {
			 public:
			 /**
			  * Méthde permettant d'afficher le formulaire de création d'éclairage unicolore
			  */
			 void set(EclairageUnicolore::Ent & ent, std::string nom, std::string couleur);

			 /**
			  * Méthode permettant de récupérer les données entrées par l'utilisateur lors de la création d'éclairage unicolore.
			  */
			 void get(EclairageUnicolore::Ent & ent);

		 };
		 
		 class IHMJardin : public Eclairage::IHMJardin {
		 	public:
				/**
				 * Méthode permettant de mettre à jour l'icone représentant l'éclairage dans l'IHM de supervision.
				 */
				void set(EclairageUnicolore::Ent & ent);
		 };

		/**
		 * Classe controleur contenant une entité, une persistance et une IHMFormulaire de création.
		 */
		class Controleur : public Eclairage::Controleur {
			public:
				Controleur():Eclairage::Controleur(), ent(), persiBny(){};

				Ent ent;

				PersiBny persiBny;

				IHMFormulaire ihmFormulaire;

				IHMJardin ihmJardin;

				void getIHMJardin();

		};

		Controleur controleur;
		
};
#endif
