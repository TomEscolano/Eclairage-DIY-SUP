/**
* \file UcGerer.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcGerer.h>
#include <Eclairage.h>
#include <UcCommander.h>

void UcGerer::emettreConfiguration(const Eclairage::Ent & eclairage) {
}

void UcGerer::desactiverEclairage(Eclairage::Ent & eclairage)
{
	eclairage.setActive(false);
}

void UcGerer::supprimerEclairage(const Eclairage::Ent & eclairage, const sqlite3 & bd) {
}

void UcGerer::activerEclairage(Eclairage::Ent & eclairage)
{
	eclairage.setActive(true);
}

void UcGerer::ajouterEclairage(const Eclairage::Ent & eclairage, const sqlite3 & bd) {
}

void UcGerer::recevoirEclairage() {
}

void UcGerer::modifierConfiguration(const Eclairage::Ent & eclairage) {
}

void UcGerer::extraireEclairage(const sqlite3 & bd) {
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
