/**
* \file UcCommander.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <string>
#include "Eclairage.h"
#include "UcCommander.h"
#include "Utility.h"

/*void UcCommander::getSelection() {
}

void UcCommander::afficherMenuSelection() {
}

void UcCommander::getAction() {
}

void UcCommander::execAction() {
}

void UcCommander::enregistrer() {
}*/

void UcCommander::allumer(Eclairage::Ent & ent, bool etat)
{
	ent.setAllume(etat);
	Utility::log_action(ent.getID(), "Allumer", etat ? "true":"false");
}

void UcCommander::activer(Eclairage::Ent & ent, bool etat)
{
	ent.setActive(etat);
	Utility::log_action(ent.getID(), "Activer", etat ? "true":"false");
}


#ifdef _UT_UCCOMMANDER_

int main(int argc, char const *argv[])
{
	UcCommander ucCommander;
	return 0;
}

//g++ -o UcCommander UcCommander.cpp Eclairage.cpp Utility.cpp SqlitePersiBny.cpp -I . -lsqlite3 -D _UT_UCCOMMANDER_ -std=c++11 -w

#endif