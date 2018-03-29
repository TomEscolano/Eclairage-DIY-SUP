/**
* \file UcImporter.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcImporter.h>
#include <UcGerer.h>
#include <Eclairage.h>
#include <Utility.h>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <FichierTextePersiBny.h>

void UcImporter::doIt(std::ifstream & fichierCSV, const UcGerer & ucGerer)
{

	Json::Value root;
	Json::Reader reader;

	// Création de la structure XML
	fichierCSV >> root;

	// Parse du fichier dans la structure XML
	reader.parse(fichierCSV, root);

	// Création d'une entity temporaire
	Eclairage::Ent ent;

	//Assignation des valeurs d'eclairage
	ent.setID((unsigned int)root.get("id", 0).asInt());
	ent.setAllume(root.get("allume", 0).asBool());
	ent.setActive(root.get("active", 0).asBool());
	ent.setNom(root.get("nom", "").asString());
	ent.setConsommation((unsigned int)root.get("consommation", 0).asInt());

	std::cout << ent.getID() << ", " << ent.getAllume() << ", " << ent.getActive() << ", " << ent.getNom() << ", " << ent.getConsommation() << std::endl;

	//ucGerer.modifierConfiguration();

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

	std::ifstream fichier("eclairage.json");
	ucimporter.doIt(fichier, ucgerer);

	return 0;
}

#endif