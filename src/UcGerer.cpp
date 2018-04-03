/**
* \file UcGerer.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcGerer.h>
#include <Eclairage.h>
#include <UcCommander.h>
#include <SqlitePersiBny.h>

#define DB "eclairagediy.db"

void UcGerer::emettreConfiguration(const Eclairage::Ent & eclairage) {
}

void UcGerer::desactiverEclairage(Eclairage::Ent & eclairage)
{
	eclairage.setActive(false);
}

void UcGerer::supprimerEclairage( Eclairage::Ent & eclairage, const sqlite3 & bd)
{
	SqlitePersiBny persi(DB);
	std::string requete = "DELETE FROM eclairages WHERE id = " + std::to_string(eclairage.getID()) + ";";

	persi.executerSql(requete);
}

void UcGerer::activerEclairage(Eclairage::Ent & eclairage)
{
	eclairage.setActive(true);
}

void UcGerer::ajouterEclairage(Eclairage::Ent & eclairage, const sqlite3 & bd)
{
	SqlitePersiBny persi(DB);

	std::string requete = "INSERT INTO eclairages (nom, allume, active, consommation) VALUES (" + eclairage.getNom() + ", " + std::to_string(eclairage.getAllume()) + ", " + std::to_string(eclairage.getActive()) + ", " + std::to_string(eclairage.getConsommation()) + ");";

	persi.executerSql(requete);
}

void UcGerer::recevoirEclairage() {
}

void UcGerer::modifierConfiguration( Eclairage::Ent & eclairage)
{
    SqlitePersiBny persi(DB);
	
	std::string requete = "UPDATE eclairages SET nom = " + eclairage.getNom() + "allume = " + std::to_string(eclairage.getAllume()) + "active = " + std::to_string(eclairage.getActive()) + "consommation =" + std::to_string(eclairage.getConsommation()) + " WHERE id = " + std::to_string(eclairage.getID()) + ";";

	persi.executerSql(requete);
}

void UcGerer::extraireEclairage(const sqlite3 & bd)
{

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

//g++ -o UcGerer Eclairage.cpp UcGerer.cpp Utility.cpp SqlitePersiBny.cpp -I . -lsqlite3 -D _UT_UCGERER_ -std=c++11 -w

#endif
