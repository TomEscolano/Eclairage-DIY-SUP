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

	persi.executerSql("INSERT INTO eclairages (nom, allume, active, consommation) VALUES (\"" + ent.getNom() + "\", " + std::to_string(ent.getAllume()) + ", " + std::to_string(ent.getActive()) + ", " + std::to_string(ent.getConsommation()) + ");");

	persi.executerSql("INSERT INTO multicolores(id,adresseBluetooth,adresseIP,versionFirmware, couleur) VALUES(" + std::to_string(ent.getID()) + ", \"" + ent.getAdresseMac() + "\", \"" + ent.getAdresseIP() + "\", " + std::to_string(ent.getVersionFirmware()) + ", \"" + ent.getCouleur() + "\");");

}

void UcGerer::ajouterEclairageUnicolore(EclairageUnicolore::Ent & ent)
{
	SqlitePersiBny persi(DB);

	persi.executerSql("INSERT INTO eclairages (nom, allume, active, consommation) VALUES (\"" + ent.getNom() + "\", " + std::to_string(ent.getAllume()) + ", " + std::to_string(ent.getActive()) + ", " + std::to_string(ent.getConsommation()) + ");");

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
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT * FROM multicolores;", resultat);

	std::vector<EclairageMulticolore> eclairages;
	for(int i = 0; i < resultat.size(); i++)
	{
		EclairageMulticolore tmp;
		tmp.controleur.setID(atoi(resultat.at(i).at(0).second.c_str()));
		tmp.controleur.setAdresseMac(resultat.at(i).at(1).second);
		tmp.controleur.setAdresseIP(resultat.at(i).at(2).second);
		tmp.controleur.setVersionFirmware(atof(resultat.at(i).at(3).second.c_str()));
		tmp.controleur.setCouleur(resultat.at(i).at(4).second);
		eclairages.push_back(tmp);
	}
	return eclairages;
}

std::vector<EclairageUnicolore> UcGerer::extraireEclairagesUnicolores()
{
	SqlitePersiBny persi(DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT * FROM unicolores;", resultat);

	std::vector<EclairageUnicolore> eclairages;
	for(int i = 0; i < resultat.size(); i++)
	{
		EclairageUnicolore tmp;
		tmp.controleur.setID(atoi(resultat.at(i).at(0).second.c_str()));
		Couleur couleur;
		if(resultat.at(i).at(1).second == "Bleu")
			couleur = Bleu;
		if(resultat.at(i).at(1).second == "Rouge")
			couleur = Rouge;
		if(resultat.at(i).at(1).second == "Blanc")
			couleur = Blanc;
		tmp.controleur.setCouleur(couleur);
		eclairages.push_back(tmp);
	}
	return eclairages;
}

void UcGerer::recevoirInfo(const Eclairage::Ent & eclairage) {
}

void UcGerer::visualiserInfo(const Eclairage::Ent & eclairage) {
}


#ifdef _UT_UCGERER_

int main(int argc, char const *argv[])
{
	UcGerer ucGerer;

	return 0;
}

//g++ -o UcGerer Eclairage.cpp UcGerer.cpp Utility.cpp SqlitePersiBny.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp UcCommander.cpp -I . -lsqlite3 -D _UT_UCGERER_ -std=c++11 -w


#endif
