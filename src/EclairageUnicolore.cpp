/**
* \file EclairageUnicolore.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <EclairageUnicolore.h>
#include <string.h>
#include <iostream>

//****************** CONTROLEUR *****************
void EclairageUnicolore::Controleur::setCouleur( Couleur couleur)
{
	this->ent.setCouleur(couleur);
	Utility::log_action(this->getID(), "Couleur", std::to_string(couleur));

}

Couleur EclairageUnicolore::Controleur::getCouleur()
{
	return this->ent.getCouleur();
}

//******************** ENT ***********************
void EclairageUnicolore::Ent::setCouleur( Couleur couleur)
{
	this->couleur = couleur;
}

Couleur EclairageUnicolore::Ent::getCouleur()
{
	return this->couleur;
}

#ifdef _UT_UNICOLORE_

int main(int argc, char const *argv[])
{

	EclairageUnicolore eclairage;

	eclairage.controleur.setCouleur(Rouge);
	std::cout << eclairage.controleur.getCouleur() << std::endl;

	return 0;
}

//g++ -o EclairageUnicolore EclairageUnicolore.cpp SqlitePersiBny.cpp Utility.cpp Eclairage.cpp -I . -lsqlite3 -D _UT_UNICOLORE_ -std=c++11 -w && clear && ./EclairageUnicolore && rm EclairageUnicolore

#endif