/**
* \file Eclairage.cpp
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "Eclairage.h"

//*************** CONTROLEUR ****************
void Eclairage::Controleur::activer(bool etat)
{
	this->ent.setActive(etat);
}

void Eclairage::Controleur::allumer(bool etat)
{
	this->ent.setAllume(etat);
}

void Eclairage::Controleur::getIHMJardin() {
}

void Eclairage::Controleur::getIHMFormulaire() {
}

void Eclairage::Controleur::set( Eclairage::Ent & ent)
{
	this->ent.setID(ent.getID());
	this->ent.setAllume(ent.getAllume());
	this->ent.setActive(ent.getActive());
	this->ent.setNom(ent.getNom());
	this->ent.setConsommation(ent.getConsommation());
}

void Eclairage::Controleur::get(Eclairage::Ent & ent)
{
	ent.setID(this->ent.getID());
	ent.setAllume(this->ent.getAllume());
	ent.setActive(this->ent.getActive());
	ent.setNom(this->ent.getNom());
	ent.setConsommation(this->ent.getConsommation());
}


//*************** ENTITY ****************
void Eclairage::Ent::setID(const unsigned int & id)
{
	this->id = id;
}

void Eclairage::Ent::setAllume(bool etat)
{
	this->allume = etat;
}

void Eclairage::Ent::setActive(bool etat)
{
	this->active = etat;
}

void Eclairage::Ent::setNom(const std::string & nom)
{
	this->nom = nom;
}

void Eclairage::Ent::setConsommation(const unsigned int & conso)
{
	this->consommation = conso;
}

unsigned int Eclairage::Ent::getID()
{
	return this->id;
}

bool Eclairage::Ent::getAllume()
{
	return this->allume;
}

bool Eclairage::Ent::getActive()
{
	return this->active;
}

std::string Eclairage::Ent::getNom()
{
	return this->nom;
}

unsigned int Eclairage::Ent::getConsommation()
{
	return this->consommation;
}


//*************** PERSIBNY ****************
void Eclairage::PersiBny::set(const Eclairage::Ent & ent) {
}

void Eclairage::PersiBny::get(Eclairage::Ent & ent) {
}

//*************** IHM JARDIN ****************
void Eclairage::IHMJardin::set(const Eclairage::Ent & ent) {
}


#ifdef NDEBUG

#include <iostream>

int main(int argc, char const *argv[])
{

	Eclairage eclairage;

	return 0;
}
#endif