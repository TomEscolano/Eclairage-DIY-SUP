/******************************************************
* \file UcCommander.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "UcCommander.h"
#include "Eclairage.h"
#define DB "/var/eclairage/bdd.db"

void UcCommander::doIt(Eclairage & eclairage, bool etat)
{
	eclairage.controleur.ent.setAllume(etat);
	SqlitePersiBny persiBny(DB);
	persiBny.executerSql("UPDATE  eclairages SET allume = " + std::to_string(etat) + " WHERE id = " + std::to_string(eclairage.controleur.ent.getID()) + ";");
}


#ifdef _UT_UcCommander_
int main()
{
	return 0;
}
#endif

//g++ -o UcCommander UcCommander.cpp Eclairage.cpp SqlitePersiBny.cpp -I . -lsqlite3 -D _UT_UcCommander_