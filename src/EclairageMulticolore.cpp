/******************************************************
* \file EclairageMulticolore.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "EclairageMulticolore.h"
#include <unistd.h> // Pour le usleep

void EclairageMulticolore::Ent::setAdresseIP(const std::string & adresseIP)
{
	this->adresseIP = adresseIP;
}

void EclairageMulticolore::Ent::setAdresseMac(const std::string & adresseMac)
{
	this->adresseMac = adresseMac;
}

void EclairageMulticolore::Ent::setNiveauBatterie(const unsigned int & niveauBatterie)
{
	this->niveauBatterie = niveauBatterie;
}

void EclairageMulticolore::Ent::setVersionFirmware(float version)
{
	this->versionFirmware = version;
}

void EclairageMulticolore::Ent::setLuminosite(int luminosite)
{
	this->luminosite = luminosite;
}

std::string EclairageMulticolore::Ent::getAdresseIP()
{
	return this->adresseIP;
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

int EclairageMulticolore::Ent::getLuminosite()
{
	return this->luminosite;
}

void EclairageMulticolore::Controleur::recevoir() {
}

void EclairageMulticolore::Controleur::envoyer() {
}

void EclairageMulticolore::PersiBny::set(Ent & ent)
{
	//Màj dans la table eclairages les popriétés
	//Utilisation du set de la classe mère
	this->Eclairage::PersiBny::set(ent);

	//Délai de traitement
	usleep(1000);

	//Màj dans la table multicolores les propriétés
	this->executerSql("UPDATE multicolores SET adresseMac = \"" + ent.getAdresseMac() + "\", adresseIP = \"" + ent.getAdresseIP() + "\", versionFirmware = " + std::to_string(ent.getVersionFirmware()) + ", couleur = \"" + std::to_string(ent.getCouleur()) + "\" WHERE id = " + std::to_string(ent.getID()) + ";");
}

void EclairageMulticolore::PersiBny::get(Ent & ent)
{
	//On update l'ent grâce à la classe mère
	this->Eclairage::PersiBny::get(ent);

	SqlitePersiBny::Resultat resultat;
	this->executerSql("SELECT * FROM multicolores WHERE id = " + std::to_string(ent.getID()) + ";", resultat);

	ent.setAdresseMac(resultat.at(0).at(1).second);
	ent.setAdresseIP(resultat.at(0).at(2).second);
	ent.setVersionFirmware((unsigned int) atoi(resultat.at(0).at(3).second.c_str()));
	if(resultat.at(0).at(3).second == "0")
		ent.setCouleur(Bleu);
	if(resultat.at(0).at(3).second == "1")
		ent.setCouleur(Rouge);
	if(resultat.at(0).at(3).second == "2")
		ent.setCouleur(Blanc);
	ent.setLuminosite(atoi(resultat.at(0).at(5).second.c_str()));
	ent.setNiveauBatterie(atoi(resultat.at(0).at(6).second.c_str()));
}

#ifdef _UT_EclairageMulticolore_
#include <iostream>

int main()
{
	EclairageMulticolore eclairage;
	eclairage.controleur.ent.setID(2);
	eclairage.controleur.ent.setAdresseMac("FF:FF:FF:FF");
	eclairage.controleur.persiBny.set(eclairage.controleur.ent);
	return 0;
}
#endif

//g++ -o EclairageMulticolore EclairageMulticolore.cpp Eclairage.cpp SqlitePersiBny.cpp -lsqlite3 -I . -D _UT_EclairageMulticolore_
