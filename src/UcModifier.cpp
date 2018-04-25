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
	SqlitePersiBny::Resultat resultat;
	
	try
	{
		persi.executerSql("SELECT * FROM multicolores WHERE id = " + std::to_string(eclairage.getID()) + ";", resultat);
		resultat.at(0).at(0).second;

   		persi.executerSql("UPDATE eclairages SET nom = \"" + eclairage.getNom() + "\" allume = " + std::to_string(eclairage.getAllume()) + " active = " + std::to_string(eclairage.getActive()) + " consommation = " + std::to_string(eclairage.getConsommation()) + " x = " + std::to_string(eclairage.getX()) + " y = " + std::to_string(eclairage.getY()) + " WHERE id = " + std::to_string(eclairage.getID()) + ";");
	
   		persi.executerSql("UPDATE multicolores SET id = " + std::to_string(eclairage.getID())+ " adresseMac = " + eclairage.getAdresseMac()+ " adresseIP = " + eclairage.getAdresseIP()+ " versionFirmware = " + std::to_string(eclairage.getVersionFirmware())+ " couleur = " + std::to_string(eclairage.getCouleur())+ " luminosite = " + std::to_string(eclairage.getLuminosite())+ " niveauBatterie = " + std::to_string(eclairage.getNiveauBatterie())+ " WHERE id = " + std::to_string(eclairage.getID())+ ";");
	}
	catch(...)
	{
		this->ucAjouter.doIt(eclairage);
	}
	
    

}

void UcModifier::doIt(EclairageUnicolore::Ent eclairage)
{
	SqlitePersiBny persi(DB);
	SqlitePersiBny::Resultat resultat;

	try
	{
		persi.executerSql("SELECT * FROM unicolores WHERE id = " + std::to_string(eclairage.getID()) + ";", resultat);
		resultat.at(0).at(0).second;

   		persi.executerSql("UPDATE eclairages SET nom = " + eclairage.getNom() + " allume = " + std::to_string(eclairage.getAllume()) + " active = " + std::to_string(eclairage.getActive()) + " consommation =" + std::to_string(eclairage.getConsommation()) + " x = " + std::to_string(eclairage.getX()) + " y = " + std::to_string(eclairage.getY()) + " WHERE id = " + std::to_string(eclairage.getID()) + ";");
	}
	catch(...)
	{
		this->ucAjouter.doIt(eclairage);
	}
}


#ifdef _UT_UcModifier_
int main()
{
	UcModifier ucModifier;
	
	return 0;
}

#endif

//g++ -o /usr/lib/cgi-bin/UcModifier UcModifier.cpp Eclairage.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp SqlitePersiBny.cpp UcAjouter.cpp -lsqlite3 -I . -D _UT_UcModifier_