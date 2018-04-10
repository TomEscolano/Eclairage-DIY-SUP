/**
* \file EclairageMulticolore.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <EclairageMulticolore.h>
#include <fstream>
#include <string>
#include <Utility.h>
#include <unistd.h>
#include <iostream>

//****************** CONTROLEUR **********************
void EclairageMulticolore::Controleur::recevoir() {
}

void EclairageMulticolore::Controleur::envoyer() {
}

void EclairageMulticolore::Controleur::setCouleur(const std::string & couleur)
{
	this->ent.setCouleur(couleur);
}

void EclairageMulticolore::Controleur::setAdresseMac(const std::string & adresseMac)
{
	this->ent.setAdresseMac(adresseMac);
}

void EclairageMulticolore::Controleur::setNiveauBatterie(const unsigned int & niveauBatterie)
{
	this->ent.setNiveauBatterie(niveauBatterie);
}

void EclairageMulticolore::Controleur::setVersionFirmware(float version)
{
	this->ent.setVersionFirmware(version);
}

void EclairageMulticolore::Controleur::setAdresseIP(const std::string & adresseIP)
{
	this->ent.setAdresseIP(adresseIP);
}

unsigned int EclairageMulticolore::Controleur::getID()
{
	return this->ent.getID();
}

bool EclairageMulticolore::Controleur::getAllume()
{
	return this->ent.getAllume();
}

bool EclairageMulticolore::Controleur::getActive()
{
	return this->ent.getActive();
}

std::string EclairageMulticolore::Controleur::getNom()
{
	return this->ent.getNom();
}

unsigned int EclairageMulticolore::Controleur::getConsommation()
{
	return this->ent.getConsommation();
}

std::string EclairageMulticolore::Controleur::getCouleur()
{
	return this->ent.getCouleur();
}

std::string EclairageMulticolore::Controleur::getAdresseMac()
{
	return this->ent.getAdresseMac();
}

unsigned int EclairageMulticolore::Controleur::getNiveauBatterie()
{
	return this->ent.getNiveauBatterie();
}

float EclairageMulticolore::Controleur::getVersionFirmware()
{
	return this->ent.getVersionFirmware();
}

std::string EclairageMulticolore::Controleur::getAdresseIP()
{
	return this->ent.getAdresseIP();
}

//Surcharge des méthodes de la classe mère
void EclairageMulticolore::Controleur::setID(unsigned int id)
{
	this->ent.setID(id);
}

void EclairageMulticolore::Controleur::setAllume(bool etat)
{
	this->ent.setAllume(etat);
}
void EclairageMulticolore::Controleur::setActive(bool etat)
{
	this->ent.setActive(etat);
}
void EclairageMulticolore::Controleur::setNom(std::string nom)
{
	this->ent.setNom(nom);
}
void EclairageMulticolore::Controleur::setConsommation(unsigned int conso)
{
	this->ent.setConsommation(conso);
}

//******************** ENT **********************
void EclairageMulticolore::Ent::setCouleur(const std::string & couleur)
{
	this->couleur = couleur;
	//Utility::log_action(this->getID(), "Couleur", couleur);
}

void EclairageMulticolore::Ent::setAdresseMac(const std::string & adresseMac)
{
	this->adresseMac = adresseMac;
	//Utility::log_action(this->getID(), "AdresseMAC", adresseMac);
}

void EclairageMulticolore::Ent::setNiveauBatterie(const unsigned int & niveauBatterie)
{
	this->niveauBatterie = niveauBatterie;
	//Utility::log_action(this->getID(), "NiveauBatterie", std::to_string(niveauBatterie));
}

void EclairageMulticolore::Ent::setVersionFirmware(float version)
{
	this->versionFirmware = version;
	//Utility::log_action(this->getID(), "VersionFirmware", std::to_string(version));
}

void EclairageMulticolore::Ent::setAdresseIP(const std::string & adresseIP)
{
	this->adresseIP = adresseIP;
	//Utility::log_action(this->getID(), "AdresseIP", adresseIP);
}

unsigned int EclairageMulticolore::Ent::getID()
{
	return this->Eclairage::Ent::getID();
}

bool EclairageMulticolore::Ent::getAllume()
{
	return this->Eclairage::Ent::getAllume();
}

bool EclairageMulticolore::Ent::getActive()
{
	return this->Eclairage::Ent::getActive();
}

std::string EclairageMulticolore::Ent::getNom()
{
	return this->Eclairage::Ent::getNom();
}

unsigned int EclairageMulticolore::Ent::getConsommation()
{
	return this->Eclairage::Ent::getConsommation();
}


std::string EclairageMulticolore::Ent::getCouleur()
{
	return this->couleur;
}

std::string EclairageMulticolore::Ent::getAdresseMac()
{
	return this->adresseMac;
}

unsigned int EclairageMulticolore::Ent::getNiveauBatterie()
{
	return this->niveauBatterie;
}

float EclairageMulticolore::Ent::getVersionFirmware()
{
	return this->versionFirmware;
}

std::string EclairageMulticolore::Ent::getAdresseIP()
{
	return this->adresseIP;
}

//Surcharge des méthodes de la classe mère
void EclairageMulticolore::Ent::setID(unsigned int id)
{
	this->Eclairage::Ent::setID(id);
}

void EclairageMulticolore::Ent::setAllume(bool etat)
{
	this->Eclairage::Ent::setAllume(etat);
}

void EclairageMulticolore::Ent::setActive(bool etat)
{
	this->Eclairage::Ent::setActive(etat);
}

void EclairageMulticolore::Ent::setNom(std::string nom)
{
	this->Eclairage::Ent::setNom(nom);
}

void EclairageMulticolore::Ent::setConsommation(unsigned int conso)
{
	this->Eclairage::Ent::setConsommation(conso);
}

//********************* PERSI ********************
void EclairageMulticolore::PersiBny::set(EclairageMulticolore::Ent & ent)
{
	//Insère dans la table eclairages les popriétés
	this->executerSql("INSERT INTO eclairages(id,allume,active,nom) VALUES(" + std::to_string(ent.getID()) + ", " + std::to_string(ent.getAllume()) + ", " + std::to_string(ent.getActive()) + ", \"" + ent.getNom() + "\");");

	usleep(1000);

	//Insère dans la table multicolores les propriétés
	this->executerSql("INSERT INTO multicolores(id,adresseBluetooth,adresseIP,versionFirmware) VALUES(" + std::to_string(ent.getID()) + ", \"" + ent.getAdresseMac() + "\", \"" + ent.getAdresseIP() + "\", " + std::to_string(ent.getVersionFirmware()) + ");");
}
void EclairageMulticolore::PersiBny::get(Ent & ent)
{

}

#ifdef _UT_MULTICOLORE_

int main(int argc, char const *argv[])
{

	EclairageMulticolore eclairageMulticolore;

	eclairageMulticolore.controleur.setID(1);
	eclairageMulticolore.controleur.setNom("Eclairage1");
	eclairageMulticolore.controleur.setConsommation(40);
	eclairageMulticolore.controleur.setAllume(false);
	eclairageMulticolore.controleur.setActive(true);
	eclairageMulticolore.controleur.setCouleur("Bleu");
	eclairageMulticolore.controleur.setAdresseMac("FF:FF:FF:FF");
	eclairageMulticolore.controleur.setNiveauBatterie(85);
	eclairageMulticolore.controleur.setVersionFirmware(1.2);
	eclairageMulticolore.controleur.setAdresseIP("127.0.0.1");

	eclairageMulticolore.controleur.persiBny.set(eclairageMulticolore.controleur.ent);


	std::cout << "ID : " << eclairageMulticolore.controleur.getID() << std::endl;
	std::cout << "Allume : " << eclairageMulticolore.controleur.getAllume() << std::endl;
	std::cout << "Active : " << eclairageMulticolore.controleur.getActive() << std::endl;
	std::cout << "Conso : " << eclairageMulticolore.controleur.getConsommation() << "mah" << std::endl;
	std::cout << "Couleur : " << eclairageMulticolore.controleur.getCouleur() << std::endl;
	std::cout << "Adresse MAC : " << eclairageMulticolore.controleur.getAdresseMac() << std::endl;
	std::cout << "Niveau de batterie: " << eclairageMulticolore.controleur.getNiveauBatterie() << "%" <<std::endl;
	std::cout << "Version du firmware : " << eclairageMulticolore.controleur.getVersionFirmware() << std::endl;
	std::cout << "AdresseIP : " << eclairageMulticolore.controleur.getAdresseIP() << std::endl;
	
	return 0;
}

// g++ -o EclairageMulticolore EclairageMulticolore.cpp SqlitePersiBny.cpp Eclairage.cpp Utility.cpp -I . -lsqlite3 -D _UT_MULTICOLORE_ -std=c++11 -w && clear && ./EclairageMulticolore && rm EclairageMulticolore

#endif