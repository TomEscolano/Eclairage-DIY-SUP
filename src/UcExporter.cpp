/**
* \file UcExporter.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcExporter.h>
#include <SqlitePersiBny.h>
#include <iostream>
#include <fstream>
#include <vector>

void UcExporter::doIt()
{
	//Créer fichier CSV avec header
	std::ofstream fichier;
	fichier.open("eclairages_export.csv");
	fichier << "type, id, nom, consommation, allume, active, couleur, adresseMac, niveauBatterie, versionFirmware, adresseIP" << std::endl;

	// Extraire la liste des eclairages unicolores
	std::vector<EclairageUnicolore> eclairagesUnicolore = this->ucgerer.extraireEclairagesUnicolores();

	// Extraires la liste des eclairages multicolores
	std::vector<EclairageMulticolore> eclairagesMulticolore = this->ucgerer.extraireEclairagesMulticolores();

	// Pour chaque eclairage unicolore
	for(int i = 0; i < eclairagesUnicolore.size(); i++)
	{
		//Insérer dans le fichier
		fichier << "unicolore" << "," << eclairagesUnicolore.at(i).controleur.getID() << "," << eclairagesUnicolore.at(i).controleur.getNom() << "," << eclairagesUnicolore.at(i).controleur.getConsommation() << "," << eclairagesUnicolore.at(i).controleur.getAllume() << "," << eclairagesUnicolore.at(i).controleur.getActive() << ","<< eclairagesUnicolore.at(i).controleur.getCouleur() << ",\"\",\"\",\"\",\"\"" << std::endl;
	}

	// Pour chaque eclairage multicolore
	for(int i = 0; i < eclairagesMulticolore.size(); i++)
	{
		//Insérer dans le fichier
		fichier << "multicolore" << "," << eclairagesMulticolore.at(i).controleur.getID() << "," << eclairagesMulticolore.at(i).controleur.getNom() << "," << eclairagesMulticolore.at(i).controleur.getConsommation() << "," << eclairagesMulticolore.at(i).controleur.getAllume() << "," << eclairagesMulticolore.at(i).controleur.getActive() << "," << eclairagesMulticolore.at(i).controleur.getCouleur() << "," << eclairagesMulticolore.at(i).controleur.getAdresseMac() << "," << eclairagesMulticolore.at(i).controleur.getNiveauBatterie() << "," << eclairagesMulticolore.at(i).controleur.getVersionFirmware() << "," << eclairagesMulticolore.at(i).controleur.getAdresseIP() << std::endl;
	}

	//Faire télécharger le fichier (balise html)
	std::cout << "<a href='eclairages_export.csv' download></a>" << std::endl;
}


#ifdef _UT_UCEXPORTER_

int main(int argc, char const *argv[])
{
	UcExporter ucExporter;

	ucExporter.doIt();

	return 0;
}

//g++ -o UcExporter UcExporter.cpp UcGerer.cpp SqlitePersiBny.cpp Eclairage.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp Utility.cpp -I . -lsqlite3 -D _UT_UCEXPORTER_ -std=c++11 -w

#endif