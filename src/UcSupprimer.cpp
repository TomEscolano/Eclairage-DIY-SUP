/******************************************************
* \file UcSupprimer.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "UcSupprimer.h"

void UcSupprimer::doIt(Eclairage::Ent eclairage)
{
	SqlitePersiBny persi(this->DB);
	persi.executerSql("DELETE FROM eclairages WHERE id = " + std::to_string(eclairage.getID()) + "; DELETE FROM multicolores WHERE id = " + std::to_string(eclairage.getID()) + "; DELETE FROM unicolores WHERE id = " + std::to_string(eclairage.getID()) + ";");
}


#ifdef _UT_UcSupprimer_
int main()
{
	UcSupprimer ucSupprimer;
	
	return 0;
}
#endif

//g++ -o UcSupprimer Eclairage.cpp UcSupprimer.cpp SqlitePersiBny.cpp -I . -lsqlite3 -D _UT_UcSupprimer_