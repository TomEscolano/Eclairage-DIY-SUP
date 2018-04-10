/**
* \file Utility.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <regex>
#include <vector>
#include <FichierTextePersiBny.h>
#include <SqlitePersiBny.h>
#include <Utility.h>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>

#define DB "/var/eclairage/bdd.db"

std::string Utility::remplacer(std::string nomFichier, std::vector<std::pair<std::string, std::string> >& conversion)
{
		FichierTextePersiBny fichier(nomFichier);
		std::string html = fichier.getContenu();
		for(auto p:conversion)
		{
			std::regex_replace (std::back_inserter(html), html.begin(), html.end(),std::regex (p.first),p.second);
		}
		return html;
}

void Utility::log_action(unsigned int id, std::string action, std::string value)
{
	SqlitePersiBny persi("/var/eclairage/bdd.db");
	persi.executerSql("INSERT INTO logs VALUES(" + std::to_string(id) + ", \"" + action + "\", \"" + value + "\");");

}

#ifdef _UT_UTILITY_

int main(int argc, char const *argv[])
{
	
	return 0;
}

#endif


//Lire données JSON
/*
	Json::Value root;
	Json::Reader reader;

	// Création de la structure XML
	fichierCSV >> root;

	// Parse du fichier dans la structure XML
	reader.parse(fichierCSV, root);

	for(int i = 1; i < root.size()+1; i++)
	{
		// Création d'une entity temporaire
		Eclairage::Ent ent;

		//Assignation des valeurs d'eclairage
		ent.setID((unsigned int)root[std::to_string(i)].get("id", 0).asInt());
		ent.setAllume(root[std::to_string(i)].get("allume", 0).asBool());
		ent.setActive(root[std::to_string(i)].get("active", 0).asBool());
		ent.setNom(root[std::to_string(i)].get("nom", "").asString());
		ent.setConsommation((unsigned int)root[std::to_string(i)].get("consommation", 0).asInt());

		ucGerer.modifierConfiguration(ent);
	}
*/