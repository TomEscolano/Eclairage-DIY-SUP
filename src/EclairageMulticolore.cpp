/******************************************************
* \file EclairageMulticolore.cpp
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <EclairageMulticolore.h>

void EclairageMulticolore::IHMFormulaire::set(EclairageMulticolore::Ent & ent)
{
	this->Eclairage::IHMFormulaire::set(ent);
	FichierTextePersiBny fichier("html/formulaireMulticolore.html");
	std::cout << fichier.getContenu();
}

void EclairageMulticolore::IHMFormulaire::get(EclairageMulticolore::Ent & ent) {
}

void EclairageMulticolore::IHMJardin::set(EclairageMulticolore::Ent & ent) {
	std::cout << "<img src='/eclairage.svg' onclick='toggleMenu(\"menu-box" + std::to_string(ent.getID()) + "\")'/><ul id='menu-box" + std::to_string(ent.getID()) + "' style='display: none'>";

	if(ent.getActive() == true)
		std::cout << "<li><a href='UcGerer.cgi?id=" + std::to_string(ent.getID()) + "&action=desactiver'>Desactiver</a></li>" << std::endl;
	else
		std::cout << "<li><a href='UcGerer.cgi?id=" + std::to_string(ent.getID()) + "&action=activer'>Activer</a></li>" << std::endl;

	if(ent.getAllume() == true)
		std::cout << "<li><a href='UcCommander.cgi?id=" + std::to_string(ent.getID()) + "&action=eteindre'>Eteindre</a></li>" << std::endl;
	else
		std::cout << "<li><a href='UcCommander.cgi?id=" + std::to_string(ent.getID()) + "&action=allumer'>Allumer</a></li>" << std::endl;
	
	std::cout << "<li><a href='UcModifier.cgi?id=" + std::to_string(ent.getID()) + "&action=parametrer'>Parametrer</a></li>" << std::endl;
	std::cout << "</ul>" << std::endl;
}

void EclairageMulticolore::Ent::setAdresseIP(std::string adresseIP)
{
	this->adresseIP = adresseIP;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE multicolores SET adresseIP = \"" + adresseIP + "\" WHERE id = " + std::to_string(this->getID()) + ";");
}

void EclairageMulticolore::Ent::setAdresseMac(std::string adresseMac)
{
	this->adresseMac = adresseMac;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE multicolores SET adresseMac = \"" + adresseMac + "\" WHERE id = " + std::to_string(this->getID()) + ";");
}

void EclairageMulticolore::Ent::setNiveauBatterie(unsigned int niveauBatterie)
{
	this->niveauBatterie = niveauBatterie;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE multicolores SET niveauBatterie = " + std::to_string(niveauBatterie) + " WHERE id = " + std::to_string(this->getID()) + ";");
}

void EclairageMulticolore::Ent::setVersionFirmware(float version)
{
	this->versionFirmware = version;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE multicolores SET versionFirmware = " + std::to_string(versionFirmware) + " WHERE id = " + std::to_string(this->getID()) + ";");
}

void EclairageMulticolore::Ent::setLuminosite(int luminosite)
{
	this->luminosite = luminosite;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE multicolores SET luminosite = " + std::to_string(luminosite) + " WHERE id = " + std::to_string(this->getID()) + ";");
}

std::string EclairageMulticolore::Ent::getAdresseIP()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT adresseIP FROM multicolores WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->adresseIP = resultat.at(0).at(0).second;
	return this->adresseIP;
}

std::string EclairageMulticolore::Ent::getAdresseMac()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT adresseMac FROM multicolores WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->adresseMac = resultat.at(0).at(0).second;
	return this->adresseMac;
}

unsigned int EclairageMulticolore::Ent::getNiveauBatterie()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT niveauBatterie FROM multicolores WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->niveauBatterie = atoi(resultat.at(0).at(0).second.c_str());
	return this->niveauBatterie;
}

float EclairageMulticolore::Ent::getVersionFirmware()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT versionFirmware FROM multicolores WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->versionFirmware = atof(resultat.at(0).at(0).second.c_str());
	return this->versionFirmware;
}

int EclairageMulticolore::Ent::getLuminosite()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT luminosite FROM multicolores WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->luminosite = atoi(resultat.at(0).at(0).second.c_str());
	return this->luminosite;
}

void EclairageMulticolore::Controleur::getIHMJardin()
{
	this->ihmJardin.set(this->ent);
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
	ent.setLuminosite(atoi(resultat.at(0).at(4).second.c_str()));
	ent.setNiveauBatterie(atoi(resultat.at(0).at(5).second.c_str()));
}

#ifdef _UT_EclairageMulticolore_
#include <iostream>

int main()
{
	EclairageMulticolore eclairage;
	eclairage.controleur.ent.setID(2);
	eclairage.controleur.ent.setAdresseMac("FF:FF:FF:FF");
	eclairage.controleur.ihmFormulaire.set(eclairage.controleur.ent);
	//eclairage.controleur.persiBny.set(eclairage.controleur.ent);
	return 0;
}
#endif

//g++ -o EclairageMulticolore EclairageMulticolore.cpp Eclairage.cpp SqlitePersiBny.cpp -lsqlite3 -I . -D _UT_EclairageMulticolore_
