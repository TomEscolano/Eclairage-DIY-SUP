/******************************************************
* \file UcAjouter.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <UcAjouter.h>

void UcAjouter::doIt(EclairageUnicolore::Ent & ent)
{
	SqlitePersiBny persiBny(this->DB);
	persiBny.executerSql("INSERT INTO eclairages (id, nom, allume, active, consommation, couleur, x, y) VALUES (" + std::to_string(ent.getID()) + ",\"" + ent.getNom() + "\", " + std::to_string(ent.getAllume()) + ", " + std::to_string(ent.getActive()) + ", " + std::to_string(ent.getConsommation()) + ", " + std::to_string(ent.getCouleur()) + ", " + std::to_string(ent.getX()) + ", " + std::to_string(ent.getY()) + "); INSERT INTO unicolores(id,numeroPrise) VALUES(" + std::to_string(ent.getID()) + ", " + std::to_string(ent.getNumeroPrise()) + ");");
}

void UcAjouter::doIt(EclairageMulticolore::Ent & ent)
{
	SqlitePersiBny persiBny(this->DB);
	persiBny.executerSql("INSERT INTO eclairages (id, nom, allume, active, consommation, couleur, x, y) VALUES (" + std::to_string(ent.getID()) + ",\"" + ent.getNom() + "\", " + std::to_string(ent.getAllume()) + ", " + std::to_string(ent.getActive()) + ", " + std::to_string(ent.getConsommation()) + ", " + std::to_string(ent.getCouleur()) + ", " + std::to_string(ent.getX()) + ", " + std::to_string(ent.getY()) + "); INSERT INTO multicolores(id, adresseMac, adresseIP, versionFirmware, luminosite, niveauBatterie) VALUES(" + std::to_string(ent.getID()) + ", \"" + ent.getAdresseMac() + "\", \"" + ent.getAdresseIP() + "\", " + std::to_string(ent.getVersionFirmware()) + ", " + std::to_string(ent.getLuminosite()) + ", " + std::to_string(ent.getNiveauBatterie()) + ");"); 
}


#ifdef _UT_UcAjouter_
int main()
{
	UcAjouter ucAjouter;

	EclairageMulticolore tmp;
	tmp.controleur.ent.setID(9);
	tmp.controleur.ent.setCouleur(Rouge);
	tmp.controleur.ent.setConsommation(66);
	tmp.controleur.ent.setActive(true);
	tmp.controleur.ent.setAllume(false);
	tmp.controleur.ent.setVersionFirmware(1.2);
	tmp.controleur.ent.setAdresseIP("127.0.0.1");
	tmp.controleur.ent.setAdresseMac("FF:FF:FF:FF");
	tmp.controleur.ent.setLuminosite(50);

	ucAjouter.doIt(tmp.controleur.ent);

	return 0;
}
#endif

//g++ -o UcAjouter UcAjouter.cpp Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp SqlitePersiBny.cpp -I . -lsqlite3 -D _UT_UcAjouter_