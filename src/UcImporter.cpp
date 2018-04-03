/**
* \file UcImporter.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#include "csvReader.h"
//https://github.com/ben-strasser/fast-cpp-csv-parser
#include <UcImporter.h>
#include <UcGerer.h>
#include <Eclairage.h>
#include <EclairageUnicolore.h>
#include <EclairageMulticolore.h>
#include <Utility.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <FichierTextePersiBny.h>

void UcImporter::doIt(std::string fichierCSV, const UcGerer & ucGerer)
{

	io::CSVReader<11> in(fichierCSV);

	in.read_header(io::ignore_extra_column, "type", "id", "nom", "consommation","allume", "active", "couleur", "adresseMac", "niveauBatterie", "versionFirmware", "adresseIP");
	
	//Proprietes
	std::string type;
	int id;
	std::string nom;
	std::string couleur;
	std::string allume;
	std::string active;
	std::string adresseMac;
	int niveauBatterie;
	int consommation;
	float versionFirmware;
	std::string adresseIP;

	while(in.read_row(type, id, nom, consommation, allume, active, couleur, adresseMac, niveauBatterie, versionFirmware, adresseIP))
	{

		if(type == "Unicolore"){
				std::string couleur;
		}else{
		
			//Creation d'un eclairage temporaire
			EclairageMulticolore eclairage;

			//Assignation des valeurs d'eclairage générique
			eclairage.controleur.setID(id);
			eclairage.controleur.setAllume((allume == "true")? true: false);
			eclairage.controleur.setActive((active == "true")? true: false);
			eclairage.controleur.setNom(nom);
			eclairage.controleur.setConsommation(consommation);
			//Creation de l'eclairage
			//ucGerer.modifierConfiguration(eclairage);
		}
	}
}

void UcImporter::getFile() {
}

void UcImporter::ajouter(const Eclairage::Ent & eclairage, const UcGerer & ucGerer) {
}


#ifdef _UT_UCIMPORTER_

int main(int argc, char const *argv[])
{
	UcImporter ucimporter;
	UcGerer ucgerer;

	ucimporter.doIt("eclairages_save.csv", ucgerer);

	return 0;
}

#endif

//g++ -o UcImporter UcImporter.cpp UcGerer.cpp Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp Utility.cpp FichierTextePersiBny.cpp SqlitePersiBny.cpp -I . -lsqlite3 -D _UT_UCIMPORTER_ -std=c++11 -w -pthread