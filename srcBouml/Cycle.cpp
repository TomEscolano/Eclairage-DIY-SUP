/**
* \file Cycle.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "Cycle.h"

//******************* CONTROLEUR ******************
void Cycle::Controleur::activer(bool actif)
{
	this->ent.setActif(actif);
}

void Cycle::Controleur::setHoraires(const std::string & heureDebut, const std::string & heureFin) 
{
	this->ent.setHeureDebut(heureDebut);
	this->ent.setHeureFin(heureFin);
}

void Cycle::Controleur::setJours(const std::array<bool, 7> & jours)
{
	this->ent.setJours(jours);
}

void Cycle::Controleur::getHoraires(std::string & heureDebut, std::string & heureFin)
{
	heureDebut = this->ent.getHeureDebut();
	heureFin = this->ent.getHeureFin();
}

std::array<bool, 7> Cycle::Controleur::getJours()
{
	return this->ent.getJours();
}

//******************* ENT ****************
void Cycle::Ent::setHeureDebut(std::string heure)
{
	this->heureDebut = heure;
}
void Cycle::Ent::setHeureFin(std::string heure)
{
	this->heureFin = heure;
}
void Cycle::Ent::setJours(std::array<bool, 7> jours)
{
	this->jours = jours;
}
void Cycle::Ent::setActif(bool actif)
{
	this->actif = actif;
}
std::string Cycle::Ent::getHeureDebut()
{
	return this->heureDebut;
}
std::string Cycle::Ent::getHeureFin()
{
	return this->heureFin;
}
std::array<bool, 7> Cycle::Ent::getJours()
{
	return this->jours;
}
bool Cycle::Ent::getActif()
{
	return this->actif;
}

#ifdef NDEBUG

#endif