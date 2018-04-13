/**
* \file UcImporter.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#include "csvReader.h"
//https://github.com/ben-strasser/fast-cpp-csv-parser
#include <UcImporter.h>
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
	std::string type, nom, couleur, allume, active, adresseMac, adresseIP;
	int id, niveauBatterie, consommation;
	float versionFirmware;

	while(in.read_row(type, id, nom, consommation, allume, active, couleur, adresseMac, niveauBatterie, versionFirmware, adresseIP))
	{

		if(type == "unicolore"){

			std::cout << "ptn dunicolore : " << niveauBatterie << std::endl;

			//Création d'un eclairage temporaire
			EclairageUnicolore eclairage;

			//Assignation des valeurs d'éclairage générique
			eclairage.controleur.ent.setID(id);
			eclairage.controleur.ent.setAllume((allume == "true")? true: false);
			eclairage.controleur.ent.setActive((active == "true")? true: false);
			eclairage.controleur.ent.setNom(nom);
			eclairage.controleur.ent.setConsommation(consommation);
			
			//Assignation des valeurs d'éclairage spécifique
			if(couleur == "Bleu")
				eclairage.controleur.ent.setCouleur(Bleu);
			if(couleur == "Rouge")
				eclairage.controleur.ent.setCouleur(Rouge);
			if(couleur == "Blanc")
				eclairage.controleur.ent.setCouleur(Blanc);

			//Creation de l'eclairage ou modification
			this->ucGerer.modifierConfigurationUnicolore(eclairage.controleur);

		}else{
					std::cout << "ptn dmulticolore : " << niveauBatterie << std::endl;

			//Creation d'un eclairage temporaire
			EclairageMulticolore eclairage;

			//Assignation des valeurs d'eclairage générique
			eclairage.controleur.ent.setID(id);
			eclairage.controleur.ent.setAllume((allume == "true")? true: false);
			eclairage.controleur.ent.setActive((active == "true")? true: false);
			eclairage.controleur.ent.setNom(nom);
			eclairage.controleur.ent.setConsommation(consommation);

			//Assignation des valeurs d'éclairage spécifique
			eclairage.controleur.ent.setAdresseMac(adresseMac);
			eclairage.controleur.ent.setNiveauBatterie(niveauBatterie);
			eclairage.controleur.ent.setVersionFirmware(versionFirmware);
			eclairage.controleur.ent.setAdresseIP(adresseIP);
			eclairage.controleur.ent.setCouleur(couleur);
			
			//Creation de l'eclairage ou modification
			this->ucGerer.modifierConfigurationMulticolore(eclairage.controleur);
		}
	}
}

void UcImporter::getFile() {
}

void UcImporter::ajouter(Eclairage::Ent & eclairage, UcGerer & ucGerer)
{
	ucGerer.activerEclairage(eclairage);
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