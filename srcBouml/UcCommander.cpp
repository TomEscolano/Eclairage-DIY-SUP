/**
* \file UcCommander.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <string>
#include <Eclairage.h>
#include <UcCommander.h>
#include <Utility.h>

void UcCommander::allumer(Eclairage::Ent & ent, bool etat)
{
	ent.setAllume(etat);
}

void UcCommander::activer(Eclairage::Ent & ent, bool etat)
{
	ent.setActive(etat);
}


#ifdef _UT_UCCOMMANDER_

int main(int argc, char const *argv[])
{
	UcCommander ucCommander;
	return 0;
}

//g++ -o UcCommander UcCommander.cpp Eclairage.cpp Utility.cpp SqlitePersiBny.cpp -I . -lsqlite3 -D _UT_UCCOMMANDER_ -std=c++11 -w

#endif