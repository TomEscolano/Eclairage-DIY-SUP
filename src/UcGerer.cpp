/******************************************************
* \file UcGerer.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcGerer.h>

void UcGerer::doIt(Eclairage::Ent & eclairage, bool etat)
{
	eclairage.setActive(etat);
	SqlitePersiBny persiBny(this->DB);
	persiBny.executerSql("UPDATE eclairage SET active = " + std::to_string(etat)  + " WHERE id = " + std::to_string(eclairage.getID()) + ";");
}


#ifdef _UT_UcGerer_
int main()
{
	UcGerer ucGerer;
	
	return 0;
}
#endif

//g++ -o /usr/lib/cgi-bin/UcGerer.cgi UcGerer.cpp Eclairage.cpp SqlitePersiBny.cpp -I . -lsqlite3 -D _UT_UcGerer_