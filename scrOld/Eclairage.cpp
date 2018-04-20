/**
* \file Eclairage.cpp
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <Eclairage.h>
#include <vector>
#include <Utility.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>


//**************** IHM FORMULAIRE ********************
void Eclairage::IHMFormulaire::set(Ent & ent)
{
	std::vector<std::pair<std::string, std::string> > contenu = {{"_nom", ent.getNom()}, {"_unicolore", ""}, {"_multicolore", "selected"}};
	std::cout << Utility::remplacer("formulaire.html",  contenu);
}

void Eclairage::IHMFormulaire::get(Ent & ent)
{

}

//*************** CONTROLEUR ****************
void Eclairage::Controleur::activer(bool etat)
{
	this->ent.setActive(etat);
}

void Eclairage::Controleur::allumer(bool etat)
{
	this->ent.setAllume(etat);
}

void Eclairage::Controleur::getIHMJardin(){

}

void Eclairage::Controleur::setID(const unsigned int & id)
{
	this->ent.setID(id);
	Utility::log_action(this->getID(), "ID", std::to_string(id));
}

void Eclairage::Controleur::setAllume(bool etat)
{
	this->ent.setAllume(etat);
	Utility::log_action(this->getID(), "Allumer", etat ? "true":"false");

}

void Eclairage::Controleur::setActive(bool etat)
{
	this->ent.setActive(etat);
	Utility::log_action(this->getID(), "Activer", etat ? "true":"false");
}

void Eclairage::Controleur::setNom(const std::string & nom)
{
	this->ent.setNom(nom);
	Utility::log_action(this->getID(), "Nom", nom);

}

void Eclairage::Controleur::setConsommation(const unsigned int & conso)
{
	this->ent.setConsommation(conso);
	Utility::log_action(this->getID(), "Consommation", std::to_string(conso));
}

void Eclairage::Controleur::setX(int valeur)
{
	this->ent.setX(valeur);
}

void Eclairage::Controleur::setY(int valeur)
{
	this->ent.setY(valeur);
}

unsigned int Eclairage::Controleur::getID()
{
	return this->ent.getID();
}

bool Eclairage::Controleur::getAllume()
{
	return this->ent.getAllume();
}

bool Eclairage::Controleur::getActive()
{
	return this->ent.getActive();
}

std::string Eclairage::Controleur::getNom()
{
	return this->ent.getNom();
}

unsigned int Eclairage::Controleur::getConsommation()
{
	return this->ent.getConsommation();
}

int Eclairage::Controleur::getX()
{
	return this->ent.getX();
}

int Eclairage::Controleur::getY()
{
	return this->ent.getY();
}

void Eclairage::Controleur::getIHMFormulaire() {
}

//*************** ENTITY ****************
void Eclairage::Ent::setID(const unsigned int & id)
{
	this->id = id;

}

void Eclairage::Ent::setAllume(bool etat)
{
	this->allume = etat;
}

void Eclairage::Ent::setActive(bool etat)
{
	this->active = etat;
}

void Eclairage::Ent::setNom(const std::string & nom)
{
	this->nom = nom;

}

void Eclairage::Ent::setConsommation(const unsigned int & conso)
{
	this->consommation = conso;
}

void Eclairage::Ent::setX(int valeur)
{
	this->x = valeur;
}

void Eclairage::Ent::setY(int valeur)
{
	this->y = valeur;
}

unsigned int Eclairage::Ent::getID()
{
	return this->id;
}

bool Eclairage::Ent::getAllume()
{
	return this->allume;
}

bool Eclairage::Ent::getActive()
{
	return this->active;
}

std::string Eclairage::Ent::getNom()
{
	return this->nom;
}

unsigned int Eclairage::Ent::getConsommation()
{
	return this->consommation;
}

int Eclairage::Ent::getX()
{
	return this->x;
}

int Eclairage::Ent::getY()
{
	return this->y;
}


//*************** PERSIBNY ****************
void Eclairage::PersiBny::set(Eclairage::Ent & ent)
{
	this->executerSql("UPDATE eclairages SET allume = " + std::to_string(ent.getAllume()) + ", active = " + std::to_string(ent.getActive()) + ", nom = \"" + ent.getNom() + "\", consommation = " + std::to_string(ent.getConsommation()) + " WHERE id = " + std::to_string(ent.getID()) + ";");
}

void Eclairage::PersiBny::get(Eclairage::Ent & ent)
{
	SqlitePersiBny::Resultat resultat;
	this->executerSql("SELECT * FROM eclairages WHERE id = " + std::to_string(ent.getID()) + ";", resultat);

	ent.setAllume(resultat.at(0).at(1).second == "1" ? true : false);
	ent.setActive(resultat.at(0).at(2).second == "1" ? true : false);
	ent.setNom(resultat.at(0).at(3).second);
	ent.setConsommation((unsigned int)atoi(resultat.at(0).at(4).second.c_str()));
}

//*************** IHM JARDIN ****************
void Eclairage::IHMJardin::set(Ent & ent){

}


#ifdef _UT_ECLAIRAGE_

#include <iostream>

int main(int argc, char const *argv[])
{

	Eclairage eclairage;

	/*eclairage.controleur.setID(9);
	eclairage.controleur.persiBny.set(eclairage.controleur.ent);
	eclairage.controleur.persiBny.get(eclairage.controleur.ent);*/

	return 0;
}

//g++ -o Eclairage Eclairage.cpp SqlitePersiBny.cpp Utility.cpp -I . -lsqlite3 -D _UT_ECLAIRAGE_ -std=c++11 -w

#endif