/**
* \file UcGerer.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcGerer.h>
#include <Eclairage.h>
#include <EclairageUnicolore.h>
#include <EclairageMulticolore.h>
#include <UcCommander.h>
#include <SqlitePersiBny.h>
#include <vector>
#include <iostream>

#define DB "/var/eclairage/bdd.db"

void UcGerer::emettreConfiguration(const Eclairage::Ent & eclairage) {
}

void UcGerer::desactiverEclairage(Eclairage::Ent & eclairage)
{
	eclairage.setActive(false);
}

void UcGerer::supprimerEclairage( Eclairage::Ent & eclairage)
{
	SqlitePersiBny persi(DB);
	std::string requete = "DELETE FROM eclairages WHERE id = " + std::to_string(eclairage.getID()) + "; DELETE FROM multicolores WHERE id = " + std::to_string(eclairage.getID()) + "; DELETE FROM unicolores WHERE id = " + std::to_string(eclairage.getID()) + ";";
	persi.executerSql(requete);
}

void UcGerer::activerEclairage(Eclairage::Ent & eclairage)
{
	eclairage.setActive(true);
}

void UcGerer::ajouterEclairageMulticolore(EclairageMulticolore::Ent & ent)
{

	SqlitePersiBny persi(DB);

	persi.executerSql("INSERT INTO eclairages (id, nom, allume, active, consommation) VALUES (" + std::to_string(ent.getID()) + ",\"" + ent.getNom() + "\", " + std::to_string(ent.getAllume()) + ", " + std::to_string(ent.getActive()) + ", " + std::to_string(ent.getConsommation()) + ");");

	persi.executerSql("INSERT INTO multicolores(id,adresseBluetooth,adresseIP,versionFirmware, couleur, luminosite, niveauBatterie) VALUES(" + std::to_string(ent.getID()) + ", \"" + ent.getAdresseMac() + "\", \"" + ent.getAdresseIP() + "\", " + std::to_string(ent.getVersionFirmware()) + ", \"" + ent.getCouleur() + "\", " + std::to_string(ent.getLuminosite()) + ", " + std::to_string(ent.getNiveauBatterie()) + ");");

}

void UcGerer::ajouterEclairageUnicolore(EclairageUnicolore::Ent & ent)
{
	SqlitePersiBny persi(DB);

	persi.executerSql("INSERT INTO eclairages (id, nom, allume, active, consommation) VALUES (" + std::to_string(ent.getID()) + ",\"" + ent.getNom() + "\", " + std::to_string(ent.getAllume()) + ", " + std::to_string(ent.getActive()) + ", " + std::to_string(ent.getConsommation()) + ");");

	persi.executerSql("INSERT INTO unicolores(id,couleur) VALUES(" + std::to_string(ent.getID()) + ", \"" + std::to_string(ent.getCouleur()) + "\");");
}

void UcGerer::recevoirEclairage(){
}

void UcGerer::modifierConfigurationUnicolore(EclairageUnicolore::Controleur & eclairage)
{
    SqlitePersiBny::Resultat resultat;
    std::string requete;


    this->persi.executerSql("SELECT * FROM unicolores WHERE id = " + std::to_string(eclairage.getID()) + ";", resultat);
    if(resultat.size() == 0)
    {
		this->ajouterEclairageUnicolore(eclairage.ent);
    }
    else
    {
    	this->persi.executerSql("UPDATE eclairages SET nom = \"" + eclairage.getNom() + "\" allume = " + std::to_string(eclairage.getAllume()) + " active = " + std::to_string(eclairage.getActive()) + " consommation = " + std::to_string(eclairage.getConsommation()) + " WHERE id = " + std::to_string(eclairage.getID()) + ";");
    }
}

void UcGerer::modifierConfigurationMulticolore(EclairageMulticolore::Controleur & eclairage)
{
    SqlitePersiBny persi(DB);
    SqlitePersiBny::Resultat resultat;
    std::string requete;

    persi.executerSql("SELECT * FROM multicolores WHERE id = " + std::to_string(eclairage.getID()) + ";", resultat);
    if(resultat.size() == 0)
    {
		this->ajouterEclairageMulticolore(eclairage.ent);
    }
    else
    {
    	persi.executerSql("UPDATE eclairages SET nom = " + eclairage.getNom() + " allume = " + std::to_string(eclairage.getAllume()) + " active = " + std::to_string(eclairage.getActive()) + " consommation =" + std::to_string(eclairage.getConsommation()) + " WHERE id = " + std::to_string(eclairage.getID()) + ";");
	}
}

std::vector<EclairageMulticolore> UcGerer::extraireEclairagesMulticolores()
{
	SqlitePersiBny persi(DB);
	SqlitePersiBny::Resultat resultat, subRes;
	persi.executerSql("SELECT * FROM multicolores;", resultat);

	std::vector<EclairageMulticolore> eclairages;
	for(int i = 0; i < resultat.size(); i++)
	{
		EclairageMulticolore tmp;
		
		//Propriétés spécifiques
		tmp.controleur.ent.setID(atoi(resultat.at(i).at(0).second.c_str()));
		tmp.controleur.ent.setAdresseMac(resultat.at(i).at(1).second.c_str());
		tmp.controleur.ent.setAdresseIP(resultat.at(i).at(2).second.c_str());
		tmp.controleur.ent.setVersionFirmware(atof(resultat.at(i).at(3).second.c_str()));
		tmp.controleur.ent.setCouleur(resultat.at(i).at(4).second);
		tmp.controleur.ent.setNiveauBatterie(atoi(resultat.at(i).at(5).second.c_str()));

		//Propriétés génériques
		persi.executerSql("SELECT * FROM eclairages WHERE id = " + std::to_string(tmp.controleur.getID()) + ";", subRes);
		tmp.controleur.ent.setAllume(subRes.at(i).at(1).second.c_str());
		tmp.controleur.ent.setActive(subRes.at(i).at(2).second.c_str());
		tmp.controleur.ent.setNom(subRes.at(i).at(3).second.c_str());
		tmp.controleur.ent.setConsommation(atoi(subRes.at(i).at(4).second.c_str()));

		eclairages.push_back(tmp);
	}
	return eclairages;
}

std::vector<EclairageUnicolore> UcGerer::extraireEclairagesUnicolores()
{
	SqlitePersiBny persi(DB);
	SqlitePersiBny::Resultat resultat, subRes;
	persi.executerSql("SELECT * FROM unicolores;", resultat);

	std::vector<EclairageUnicolore> eclairages;
	for(int i = 0; i < resultat.size(); i++)
	{
		EclairageUnicolore tmp;

		//Propriétés spécifiques
		tmp.controleur.ent.setID(atoi(resultat.at(i).at(0).second.c_str()));
		Couleur couleur;
		if(resultat.at(i).at(1).second == "Bleu")
			couleur = Bleu;
		if(resultat.at(i).at(1).second == "Rouge")
			couleur = Rouge;
		if(resultat.at(i).at(1).second == "Blanc")
			couleur = Blanc;
		tmp.controleur.ent.setCouleur(couleur);

		//Propriétés génériques
		persi.executerSql("SELECT * FROM eclairages WHERE id = " + std::to_string(tmp.controleur.getID()) + ";", subRes);
		tmp.controleur.ent.setAllume(subRes.at(i).at(1).second.c_str());
		tmp.controleur.ent.setActive(subRes.at(i).at(2).second.c_str());
		tmp.controleur.ent.setNom(subRes.at(i).at(3).second.c_str());
		tmp.controleur.ent.setConsommation(atoi(subRes.at(i).at(4).second.c_str()));

		eclairages.push_back(tmp);
	}
	return eclairages;
}

void UcGerer::recevoirInfo(const Eclairage::Ent & eclairage) {
}

void UcGerer::visualiserInfo(const Eclairage::Ent & eclairage) {
}

void UcGerer::afficherEclairages(std::vector<EclairageMulticolore> eclairagesMulticolores, std::vector<EclairageUnicolore> eclairagesUnicolores)
{
	for(int i = 0; i < eclairagesMulticolores.size(); i++)
	{
		std::cout << "<img src='/eclairage.svg' onclick='toggleMenu(\"menu-box" + std::to_string(eclairagesMulticolores.at(i).controleur.getID()) + "\")'/><ul id='menu-box" + std::to_string(eclairagesMulticolores.at(i).controleur.getID()) + "' style='display: none'>";

		if(eclairagesMulticolores.at(i).controleur.getActive())
			std::cout << "<li><a href='UcGerer.cgi?id= " + std::to_string(eclairagesMulticolores.at(i).controleur.getID()) + "&action=desactiver'>Desactiver</a></li>" << std::endl;
		else
			std::cout << "<li><a href='UcGerer.cgi?id= " + std::to_string(eclairagesMulticolores.at(i).controleur.getID()) + "&action=activer'>Activer</a></li>" << std::endl;

		if(eclairagesMulticolores.at(i).controleur.getAllume())
			std::cout << "<li><a href='UcGerer.cgi?id= " + std::to_string(eclairagesMulticolores.at(i).controleur.getID()) + "&action=eteindre'>Eteindre</a></li>" << std::endl;
		else
			std::cout << "<li><a href='UcGerer.cgi?id= " + std::to_string(eclairagesMulticolores.at(i).controleur.getID()) + "&action=allumer'>Allumer</a></li>" << std::endl;
		
		std::cout << "<li><a href='UcGerer.cgi?id= " + std::to_string(eclairagesMulticolores.at(i).controleur.getID()) + "&action=parametrer'>Parametrer</a></li>" << std::endl;
		std::cout << "</ul>" << std::endl;
	}

	for(int i = 0; i < eclairagesUnicolores.size(); i++)
	{
		std::cout << "<img src='eclairagesUnicolores.png' onclick='toggleMenu(\"menu-box " + std::to_string(eclairagesUnicolores.at(i).controleur.getID()) + "\")'/><ul id='menu-box' style='display: none'>";

		if(eclairagesUnicolores.at(i).controleur.getActive())
			std::cout << "<li><a href='UcGerer.cgi?id= " + std::to_string(eclairagesUnicolores.at(i).controleur.getID()) + "&action=desactiver'>Desactiver</a></li>" << std::endl;
		else
			std::cout << "<li><a href='UcGerer.cgi?id= " + std::to_string(eclairagesUnicolores.at(i).controleur.getID()) + "&action=activer'>Activer</a></li>" << std::endl;

		if(eclairagesUnicolores.at(i).controleur.getAllume())
			std::cout << "<li><a href='UcGerer.cgi?id= " + std::to_string(eclairagesUnicolores.at(i).controleur.getID()) + "&action=eteindre'>Eteindre</a></li>" << std::endl;
		else
			std::cout << "<li><a href='UcGerer.cgi?id= " + std::to_string(eclairagesUnicolores.at(i).controleur.getID()) + "&action=allumer'>Allumer</a></li>" << std::endl;
		
		std::cout << "<li><a href='UcGerer.cgi?id= " + std::to_string(eclairagesUnicolores.at(i).controleur.getID()) + "&action=parametrer'>Parametrer</a></li>" << std::endl;
		std::cout << "</ul>" << std::endl;
	}

}



#ifdef _UT_UCGERER_

int main(int argc, char const *argv[])
{
	UcGerer ucGerer;
	EclairageMulticolore tmp;
	tmp.controleur.ent.setID(9);

	ucGerer.ajouterEclairageMulticolore(tmp.controleur.ent);

	return 0;
}

//g++ -o UcGerer Eclairage.cpp UcGerer.cpp Utility.cpp SqlitePersiBny.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp UcCommander.cpp -I . -lsqlite3 -D _UT_UCGERER_ -std=c++11 -w


#endif
