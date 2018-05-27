/******************************************************
* \file EclairageMulticolore.cpp
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <EclairageMulticolore.h>

void EclairageMulticolore::IHMFormulaire::set(EclairageMulticolore::Ent & ent, std::string nom, std::string couleur, std::string id, std::string x, std::string y)
{
	// Affichage du formulaire de création d'éclairage multicolore
	FichierTextePersiBny fichier("html/formulaireMulticolore.html");
	std::string html = fichier.getContenu();

	html.replace(html.find("_nomEclairage"), sizeof("_nomEclairage")-1, nom);
	html.replace(html.find("_couleurEclairage"), sizeof("_couleurEclairage")-1, couleur);
	html.replace(html.find("_idEclairage"), sizeof("_idEclairage")-1, id);
	html.replace(html.find("_xEclairage"), sizeof("_xEclairage")-1, x);
	html.replace(html.find("_yEclairage"), sizeof("_yEclairage")-1, y);

	std::cout << html;
}

void EclairageMulticolore::IHMFormulaire::get(EclairageMulticolore::Ent & ent) {
}

void EclairageMulticolore::IHMJardin::set(EclairageMulticolore::Ent & ent) {
	std::string logo;

	if(ent.getActive())
	{
		std::string couleurTmp = ent.getCouleur();

		if(ent.getAllume() == true && couleurTmp.find("bleu") != std::string::npos)
			logo = "multicoloreBleu.png";
		if(ent.getAllume() == true && couleurTmp.find("blanc") != std::string::npos)
			logo = "multicoloreBlanc.png" ;
		if(ent.getAllume() == true && couleurTmp.find("rouge") != std::string::npos)
			logo = "multicoloreRouge.png";
		else if(ent.getAllume() == false)
			logo = "multicoloreDesactive.png";
	}
	else
		logo = "multicoloreDesactive.png";

	std::cout << "<img style='width:75px;height:175x;position:absolute;z-index:2;margin-left:" + std::to_string(ent.getX()-60)+ "px;margin-top:"+ std::to_string(ent.getY()-130)+"px;' src='/" + logo + "' onclick='toggleMenu(\"menu-box" + std::to_string(ent.getID()) + "\")'/><ul id='menu-box" + std::to_string(ent.getID()) + "' style='display:none; z-index:2;margin-left:" + std::to_string(ent.getX())+ "px;margin-top:"+ std::to_string(ent.getY()-130)+"px;positon:absolute;'>";

	if(ent.getActive())
		std::cout << "<li><a href='UcGerer.cgi?id=" + std::to_string(ent.getID()) + "&action=desactiver'>Desactiver</a></li>" << std::endl;
	else
		std::cout << "<li><a href='UcGerer.cgi?id=" + std::to_string(ent.getID()) + "&action=activer'>Activer</a></li>" << std::endl;

	if(ent.getAllume())
		std::cout << "<li><a href='UcCommander.cgi?id=" + std::to_string(ent.getID()) + "&action=eteindre&type=multicolore'>Eteindre</a></li>" << std::endl;
	else
		std::cout << "<li><a href='UcCommander.cgi?id=" + std::to_string(ent.getID()) + "&action=allumer&type=multicolore'>Allumer</a></li>" << std::endl;
	
	std::cout << "<li><a href='UcModifier.cgi?id=" + std::to_string(ent.getID()) + "&type=multicolore'>Parametrer</a></li>" << std::endl;
	std::cout << "</ul>" << std::endl;
}

void EclairageMulticolore::IHMParametre::set(EclairageMulticolore::Ent & ent)
{
	//Récupération du nom de l'éclairage
	SqlitePersiBny persi("/var/eclairage/bdd.db");
	SqlitePersiBny::Resultat resultat;

	// Affichage du formulaire de création d'éclairage unicolore
	FichierTextePersiBny fichier("html/formulaireParametreMulticolore.html");
	std::string html = fichier.getContenu();

	html.replace(html.find("_idEclairage"), sizeof("_idEclairage")-1, std::to_string(ent.getID()));
	persi.executerSql("SELECT nom FROM eclairages WHERE id = " + std::to_string(ent.getID()) + ";", resultat);
	html.replace(html.find("_nomEclairage"), sizeof("_nomEclairage")-1, resultat.at(0).at(0).second);
	html.replace(html.find("_idSuppr"), sizeof("_idSuppr")-1, std::to_string(ent.getID()));

	resultat.clear();

	persi.executerSql("SELECT adresseIP FROM multicolores WHERE id = " + std::to_string(ent.getID()) + ";", resultat);
	html.replace(html.find("_addr"), sizeof("_addr")-1, resultat.at(0).at(0).second);

	std::cout << html;

}

void EclairageMulticolore::Ent::setAdresseIP(std::string adresseIP)
{
	this->adresseIP = adresseIP;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE multicolores SET adresseIP = \"" + adresseIP + "\" WHERE id = " + std::to_string(this->getID()) + ";");
	Utility::log_action(this->getID(), "Adresse IP", this->adresseIP);
}

void EclairageMulticolore::Ent::setAdresseMac(std::string adresseMac)
{
	this->adresseMac = adresseMac;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE multicolores SET adresseMac = \"" + adresseMac + "\" WHERE id = " + std::to_string(this->getID()) + ";");
	Utility::log_action(this->getID(), "Adresse Mac", this->adresseMac);
}

void EclairageMulticolore::Ent::setNiveauBatterie(unsigned int niveauBatterie)
{
	this->niveauBatterie = niveauBatterie;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE multicolores SET niveauBatterie = " + std::to_string(niveauBatterie) + " WHERE id = " + std::to_string(this->getID()) + ";");
	Utility::log_action(this->getID(), "Niveau Batterie", std::to_string(this->niveauBatterie));
}

void EclairageMulticolore::Ent::setVersionFirmware(float version)
{
	this->versionFirmware = version;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE multicolores SET versionFirmware = " + std::to_string(versionFirmware) + " WHERE id = " + std::to_string(this->getID()) + ";");
	Utility::log_action(this->getID(), "Version Firmware", std::to_string(this->versionFirmware));
}

void EclairageMulticolore::Ent::setLuminosite(int luminosite)
{
	this->luminosite = luminosite;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE multicolores SET luminosite = " + std::to_string(luminosite) + " WHERE id = " + std::to_string(this->getID()) + ";");
	Utility::log_action(this->getID(), "luminosite", std::to_string(this->luminosite));
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


void EclairageMulticolore::PersiBny::set(Ent & ent)
{
	//Màj dans la table eclairages les popriétés
	//Utilisation du set de la classe mère
	this->Eclairage::PersiBny::set(ent);

	//Délai de traitement
	usleep(1000);

	//Màj dans la table multicolores les propriétés
	this->executerSql("UPDATE multicolores SET adresseMac = \"" + ent.getAdresseMac() + "\", adresseIP = \"" + ent.getAdresseIP() + "\", versionFirmware = " + std::to_string(ent.getVersionFirmware()) + ", couleur = \"" + ent.getCouleur() + "\" WHERE id = " + std::to_string(ent.getID()) + ";");
}

void EclairageMulticolore::PersiBny::get(Ent & ent)
{
	//On update l'ent grâce à la classe mère
	this->Eclairage::PersiBny::get(ent);

	SqlitePersiBny::Resultat resultat;
	this->executerSql("SELECT adresseMac, adresseIP, versionFirmware, luminosite, niveauBatterie FROM multicolores WHERE id = " + std::to_string(ent.getID()) + ";", resultat);

	ent.setAdresseMac(resultat.at(0).at(0).second);
	ent.setAdresseIP(resultat.at(0).at(1).second);
	ent.setVersionFirmware((unsigned int) atoi(resultat.at(0).at(2).second.c_str()));
	ent.setLuminosite(atoi(resultat.at(0).at(3).second.c_str()));
	ent.setNiveauBatterie(atoi(resultat.at(0).at(4).second.c_str()));
}

void EclairageMulticolore::EclairageComBny::allumer(EclairageMulticolore::Ent & ent, bool etat)
{
	this->clientTcpComBny.connecter(ent.getAdresseIP(), 55554);
	std::string message = "{\"demande\":\"fe\", \"etat\":" + std::to_string(etat) + ",\"id\":"+ std::to_string(ent.getID())+"}";

	this->clientTcpComBny.fprintf(message.c_str());

	this->clientTcpComBny.deconnecter();
}

void EclairageMulticolore::EclairageComBny::changerCouleur(EclairageMulticolore::Ent & ent, std::string couleur)
{
	this->clientTcpComBny.connecter(ent.getAdresseIP(), 55554);
	std::string message = "{\"demande\":\"cc\", \"couleur\":" + couleur + ",\"id\":"+ std::to_string(ent.getID())+"}";

	this->clientTcpComBny.fprintf(message.c_str());

	this->clientTcpComBny.deconnecter();
}


#ifdef _UT_EclairageMulticolore_
#include <iostream>

int main()
{
	EclairageMulticolore eclairage;
	eclairage.controleur.ent.setID(2);
	eclairage.controleur.ent.setAdresseMac("FF:FF:FF:FF");

	return 0;
}
#endif

//g++ -o EclairageMulticolore EclairageMulticolore.cpp Eclairage.cpp SqlitePersiBny.cpp -lsqlite3 -lcgicc -I . -D _UT_EclairageMulticolore_
