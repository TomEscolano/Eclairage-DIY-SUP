/******************************************************
* \file UcModifier.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "UcModifier.h"
#define DB "/var/eclairage/bdd.db"

void UcModifier::doIt(EclairageMulticolore::Ent eclairage)
{
	SqlitePersiBny persi(DB);

	persi.executerSql("SELECT * FROM unicolores WHERE id = " + std::to_string(eclairage.getID()) + ";");
   	persi.executerSql("UPDATE eclairages SET nom = \"" + eclairage.getNom() + "\" allume = " + std::to_string(eclairage.getAllume()) + " active = " + std::to_string(eclairage.getActive()) + " consommation = " + std::to_string(eclairage.getConsommation()) + " x = " + std::to_string(eclairage.getX()) + " y = " + std::to_string(eclairage.getY()) + " WHERE id = " + std::to_string(eclairage.getID()) + ";");
    

}

void UcModifier::doIt(EclairageUnicolore::Ent eclairage)
{
	SqlitePersiBny persi(DB);

    persi.executerSql("SELECT * FROM multicolores WHERE id = " + std::to_string(eclairage.getID()) + ";");
   	persi.executerSql("UPDATE eclairages SET nom = " + eclairage.getNom() + " allume = " + std::to_string(eclairage.getAllume()) + " active = " + std::to_string(eclairage.getActive()) + " consommation =" + std::to_string(eclairage.getConsommation()) + " x = " + std::to_string(eclairage.getX()) + " y = " + std::to_string(eclairage.getY()) + " WHERE id = " + std::to_string(eclairage.getID()) + ";");

}


#ifdef _UT_UcModifier_
int main()
{
	UcModifier ucModifier;
	
	return 0;
}
#endif
