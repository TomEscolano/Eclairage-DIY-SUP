/*******************************************************
* \file EclairageUnicolore.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGEUNICOLORE_H
#define _ECLAIRAGEUNICOLORE_H


#include <Eclairage.h>

/**
 * Classe fille (de eclairage) repr�sentant un �clairage unicolore comportant:
 * - Un controleur
 * - Une entit� comportant:
 *    - le num�ro de prise associ� � l'�clairage
 * - Une persistance (polymorph�e)
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
				 * M�thode permettant de modifier le numero de la prise associ� � l'�clairage.
				 */
				void setNumeroPrise(int num);

				/**
				 * M�thode permettant de r�cup�rer le num�ro de la prise associ� � l'�clairage.
				 */
				int getNumeroPrise();

		};
		
		/**
		 * Classe de persistance de l'�clairage d�rivant de la classe m�re Eclairage::PersiBny. Permet de set et de get la configuration de l'�clairage dans la base de donn�es.
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
		 * IHM pr�sentant au propri�taire un forulaire de cr�ation d'�clairage unicolore.
		 */
		class IHMFormulaire : public Eclairage::IHMFormulaire {
			 public:
			 /**
			  * M�thde permettant d'afficher le formulaire de cr�ation d'�clairage unicolore
			  */
			 void set(EclairageUnicolore::Ent & ent, std::string nom, std::string couleur);

			 /**
			  * M�thode permettant de r�cup�rer les donn�es entr�es par l'utilisateur lors de la cr�ation d'�clairage unicolore.
			  */
			 void get(EclairageUnicolore::Ent & ent);

		 };
		 
		 class IHMJardin : public Eclairage::IHMJardin {
		 	public:
				/**
				 * M�thode permettant de mettre � jour l'icone repr�sentant l'�clairage dans l'IHM de supervision.
				 */
				void set(EclairageUnicolore::Ent & ent);
		 };

		/**
		 * Classe controleur contenant une entit�, une persistance et une IHMFormulaire de cr�ation.
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
