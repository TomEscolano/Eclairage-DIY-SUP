/**
* \file EclairageUnicolore.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _ECLAIRAGEUNICOLORE_H
#define _ECLAIRAGEUNICOLORE_H


#include <Eclairage.h>
#include <Couleur.h>
#include <string>


class EclairageUnicolore : public Eclairage {
	public:
		class Ent : public Eclairage::Ent {
			public:

				Ent():Eclairage::Ent(), couleur(Bleu){};

				void setCouleur(Couleur couleur);

				void setID(unsigned int id);

				void setAllume(bool etat);

				void setActive(bool etat);

				void setNom(std::string nom);

				void setConsommation(unsigned int conso);

				Couleur getCouleur();

				unsigned int getID();

				bool getAllume();

				bool getActive();

				std::string getNom();

				unsigned int getConsommation();

			private:
				Couleur couleur;

		};
		
		class PersiBny : public Eclairage::PersiBny {
		public:

			PersiBny():Eclairage::PersiBny(){};

			void set(EclairageUnicolore::Ent & ent);

			void get(Ent & ent);

	};

	class Controleur : public Eclairage::Controleur{

			public:
				Ent ent;

				PersiBny persiBny;

				Controleur():Eclairage::Controleur(), ent(), persiBny(){this->ent.setID(this->persiBny.getDernierId("unicolores")+1);};

				void setCouleur(Couleur couleur);

				void setID(unsigned int id);

				void setAllume(bool etat);

				void setActive(bool etat);

				void setNom(std::string nom);

				void setConsommation(unsigned int conso);

				Couleur getCouleur();
				
				unsigned int getID();

				bool getAllume();

				bool getActive();

				std::string getNom();

				unsigned int getConsommation();

		};
	
	Controleur controleur;

};
#endif
