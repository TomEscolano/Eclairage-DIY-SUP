/******************************************************
* \file EclairageUnicolore.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "EclairageUnicolore.h"
#include <unistd.h>

void EclairageUnicolore::Ent::setNumeroPrise(int num)
{
	this->numeroPrise = num;
}

int EclairageUnicolore::Ent::getNumeroPrise()
{
	return this->numeroPrise;
}

void EclairageUnicolore::PersiBny::set(Ent & ent)
{
	//Insère dans la table eclairages les propriétés
	//Utilisation du set de la classe mère
	this->Eclairage::PersiBny::set(ent);

	//Délai de traitement
	usleep(100);

	//Insère dans la table unicolores les propriétés
	this->executerSql("UPDATE unicolores SET couleur = " + std::to_string(ent.getCouleur()) + ", numeroPrise = " + std::to_string(ent.getNumeroPrise()) + " WHERE id = " + std::to_string(ent.getID()) + ";");
}

void EclairageUnicolore::PersiBny::get(Ent & ent)
{
	//On update l'ent grâce à la classe mère
	this->Eclairage::PersiBny::get(ent);

	SqlitePersiBny::Resultat resultat;
	this->executerSql("SELECT * FROM unicolores WHERE id = " + std::to_string(ent.getID()) + ";", resultat);

	ent.setNumeroPrise(atoi(resultat.at(0).at(1).second.c_str()));
}

#ifdef _UT_EclairageUnicolore_
#include <iostream>

int main()
{
	EclairageUnicolore eclairage;
	eclairage.controleur.ent.setNumeroPrise(1);
	eclairage.controleur.ent.setCouleur(Rouge);
	eclairage.controleur.ent.setID(9);
	eclairage.controleur.persiBny.set(eclairage.controleur.ent);

	return 0;
}
#endif

//g++ -o EclairageUnicolore EclairageUnicolore.cpp Eclairage.cpp SqlitePersiBny.cpp -lsqlite3 -I . -D _UT_EclairageUnicolore_