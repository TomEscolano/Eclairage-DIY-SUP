/******************************************************
* \file UcAjouter.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <UcAjouter.h>
#define DB "/var/eclairage/bdd.db"

void UcAjouter::doIt(EclairageUnicolore::Ent & ent)
{
	SqlitePersiBny persiBny(DB);
	persiBny.executerSql("INSERT INTO eclairages (id, nom, allume, active, consommation, x, y) VALUES (" + std::to_string(ent.getID()) + ",\"" + ent.getNom() + "\", " + std::to_string(ent.getAllume()) + ", " + std::to_string(ent.getActive()) + ", " + std::to_string(ent.getConsommation()) + ", " + std::to_string(ent.getX()) + ", " + std::to_string(ent.getY()) + "); INSERT INTO unicolores(id,couleur,numeroPrise) VALUES(" + std::to_string(ent.getID()) + ", \"" + std::to_string(ent.getCouleur()) + "\", " + std::to_string(ent.getNumeroPrise()) + ");");
}

void UcAjouter::doIt(EclairageMulticolore::Ent & ent)
{
	SqlitePersiBny persiBny(DB);
	persiBny.executerSql("INSERT INTO eclairages (id, nom, allume, active, consommation, x, y) VALUES (" + std::to_string(ent.getID()) + ",\"" + ent.getNom() + "\", " + std::to_string(ent.getAllume()) + ", " + std::to_string(ent.getActive()) + ", " + std::to_string(ent.getConsommation()) + ", " + std::to_string(ent.getX()) + ", " + std::to_string(ent.getY()) + "); INSERT INTO multicolores(id, adresseBluetooth, adresseIP, versionFirmware, couleur, luminosite, niveauBatterie) VALUES(" + std::to_string(ent.getID()) + ", \"" + ent.getAdresseMac() + "\", \"" + ent.getAdresseIP() + "\", " + std::to_string(ent.getVersionFirmware()) + ", \"" + std::to_string(ent.getCouleur()) + "\", " + std::to_string(ent.getLuminosite()) + ", " + std::to_string(ent.getNiveauBatterie()) + ");"); 
}


#ifdef _UT_UcAjouter_
int main()
{
	UcAjouter ucAjouter;

	return 0;
}
#endif

//g++ -o UcAjouter UcAjouter.cpp Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp SqlitePersiBny.cpp -I . -lsqlite3 -D _UT_UcAjouter_