/**
* \file EclairageUnicolore.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "EclairageUnicolore.h"

void EclairageUnicolore::Controleur::setCouleur( Couleur couleur)
{
	this->ent.setCouleur(couleur);
}

Couleur EclairageUnicolore::Controleur::getCouleur()
{
	return this->ent.getCouleur();
}

void EclairageUnicolore::Ent::setCouleur( Couleur couleur)
{
	this->couleur = couleur;
}

Couleur EclairageUnicolore::Ent::getCouleur()
{
	return this->couleur;
}

#ifndef NDEBUG

#endif