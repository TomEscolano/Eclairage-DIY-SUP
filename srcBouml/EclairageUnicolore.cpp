/**
* \file EclairageUnicolore.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "EclairageUnicolore.h"

//****************** CONTROLEUR *****************
void EclairageUnicolore::Controleur::setCouleur( Couleur couleur)
{
	this->ent.setCouleur(couleur);
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

	EclairageUnicolore monUnicolore;
	EclairageUnicolore::Ent ent;
	EclairageUnicolore::Controleur controleur;

	return 0;
}

//g++ -o EclairageUnicolore EclairageUnicolore.cpp -I . -lsqlite3 -D _UT_UNICOLORE_ -std=c++11 -w

#endif