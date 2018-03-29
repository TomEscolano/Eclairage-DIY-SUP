/**
* \file EclairageMulticolore.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <EclairageMulticolore.h>
#include <fstream>

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

//******************** ENT **********************
void EclairageMulticolore::Ent::setCouleur(const std::string & couleur)
{
	this->couleur = couleur;
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

void EclairageMulticolore::Ent::setAdresseIP(const std::string & adresseIP)
{
	this->adresseIP = adresseIP;
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

#ifdef _UT_MULTICOLORE_

int main(int argc, char const *argv[])
{
	EclairageMulticolore monEclairageMulticolore;
	EclairageMulticolore::Ent ent;
	EclairageMulticolore::Controleur controleur;

	return 0;
}

//g++ -o EclairageMulticolore EclairageMulticolore.cpp -I . -lsqlite3 -D _UT_MULTICOLORE_ -std=c++11 -w

#endif