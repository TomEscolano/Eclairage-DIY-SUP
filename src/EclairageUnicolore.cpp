/**
* \file EclairageUnicolore.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <EclairageUnicolore.h>
#include <string.h>
#include <iostream>
#include <unistd.h>

//****************** CONTROLEUR *****************
//==================== MUTATEURS ===================
void EclairageUnicolore::Controleur::setID(unsigned int id)
{
	this->ent.setID(id);
}

void EclairageUnicolore::Controleur::setAllume(bool etat)
{
	this->ent.setAllume(etat);
}
void EclairageUnicolore::Controleur::setActive(bool etat)
{
	this->ent.setActive(etat);
}
void EclairageUnicolore::Controleur::setNom(std::string nom)
{
	this->ent.setNom(nom);
}
void EclairageUnicolore::Controleur::setConsommation(unsigned int conso)
{
	this->ent.setConsommation(conso);
}

void EclairageUnicolore::Controleur::setCouleur( Couleur couleur)
{
	this->ent.setCouleur(couleur);
}

//==================== ASSESSEURS ===================
unsigned int EclairageUnicolore::Controleur::getID()
{
	return this->ent.getID();
}

bool EclairageUnicolore::Controleur::getAllume()
{
	return this->ent.getAllume();
}

bool EclairageUnicolore::Controleur::getActive()
{
	return this->ent.getActive();
}

std::string EclairageUnicolore::Controleur::getNom()
{
	return this->ent.getNom();
}

unsigned int EclairageUnicolore::Controleur::getConsommation()
{
	return this->ent.getConsommation();
}

Couleur EclairageUnicolore::Controleur::getCouleur()
{
	return this->ent.getCouleur();
}

//********************    ENT    *******************
//==================== MUTATEURS ===================
void EclairageUnicolore::Ent::setID(unsigned int id)
{
	this->Eclairage::Ent::setID(id);	
}

void EclairageUnicolore::Ent::setAllume(bool etat)
{
	this->Eclairage::Ent::setAllume(etat);
	Utility::log_action(this->Eclairage::Ent::getID(), "Allume", etat == true ? "true" : "false");
}

void EclairageUnicolore::Ent::setActive(bool etat)
{
	this->Eclairage::Ent::setActive(etat);
	Utility::log_action(this->Eclairage::Ent::getID(), "Active", etat == true ? "true" : "false");
}

void EclairageUnicolore::Ent::setNom(std::string nom)
{
	this->Eclairage::Ent::setNom(nom);
	Utility::log_action(this->Eclairage::Ent::getID(), "Nom", nom);
}

void EclairageUnicolore::Ent::setConsommation(unsigned int conso)
{
	this->Eclairage::Ent::setConsommation(conso);
	Utility::log_action(this->Eclairage::Ent::getID(), "Conso", std::to_string(conso));
}

void EclairageUnicolore::Ent::setCouleur( Couleur couleur)
{
	this->couleur = couleur;
	Utility::log_action(this->Eclairage::Ent::getID(), "Couleur", std::to_string(couleur));
}

//==================== ASSESSEURS ===================
unsigned int EclairageUnicolore::Ent::getID()
{
	return this->Eclairage::Ent::getID();
}

bool EclairageUnicolore::Ent::getAllume()
{
	return this->Eclairage::Ent::getAllume();
}

bool EclairageUnicolore::Ent::getActive()
{
	return this->Eclairage::Ent::getActive();
}

std::string EclairageUnicolore::Ent::getNom()
{
	return this->Eclairage::Ent::getNom();
}

unsigned int EclairageUnicolore::Ent::getConsommation()
{
	return this->Eclairage::Ent::getConsommation();
}

Couleur EclairageUnicolore::Ent::getCouleur()
{
	return this->couleur;
}

//****************** PERSI **********************
void EclairageUnicolore::PersiBny::set(EclairageUnicolore::Ent & ent)
{

	//Insère dans la table eclairages les propriétés
	//Utilisation du set de la classe mère
	this->Eclairage::PersiBny::set(ent);

	//Délai de traitement
	usleep(100);

	//Insère dans la table unicolores les propriétés
	this->executerSql("INSERT INTO unicolores(id,couleur) VALUES(" + std::to_string(ent.getID()) + ", \"" + std::to_string(ent.getCouleur()) + "\");");
}

void EclairageUnicolore::PersiBny::get(Ent & ent)
{

} 

#ifdef _UT_UNICOLORE_

int main(int argc, char const *argv[])
{

	EclairageUnicolore eclairage;

	eclairage.controleur.setCouleur(Bleu);
	eclairage.controleur.setID(10);
	eclairage.controleur.setNom("Eclairage1");
	eclairage.controleur.setConsommation(40);
	eclairage.controleur.setAllume(false);
	eclairage.controleur.setActive(true);

	eclairage.controleur.persiBny.set(eclairage.controleur.ent);

	return 0;
}

//g++ -o EclairageUnicolore EclairageUnicolore.cpp SqlitePersiBny.cpp Utility.cpp Eclairage.cpp -I . -lsqlite3 -D _UT_UNICOLORE_ -std=c++11 -w && clear && ./EclairageUnicolore && rm EclairageUnicolore

#endif