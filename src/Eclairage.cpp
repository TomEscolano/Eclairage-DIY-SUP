/**
* \file Eclairage.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "Eclairage.h"
#include "UcGerer.h"

void Eclairage::Controleur::activer(bool etat)
{
	//Eclairage::Ent->setActive(etat);
}

void Eclairage::Controleur::allumer(bool etat) {
}

void Eclairage::Controleur::getIHMJardin() {
}

void Eclairage::Controleur::getIHMFormulaire() {
}

void Eclairage::Controleur::set(const Eclairage::Ent & ent) {
}

void Eclairage::Controleur::get(Eclairage::Ent & ent) {
}

void Eclairage::Ent::setID(const unsigned int & id) {
}

void Eclairage::Ent::setAllume(bool etat) {
}

void Eclairage::Ent::setActive(bool etat) {
}

void Eclairage::Ent::setNom(const std::string & nom) {
}

void Eclairage::Ent::setConsommation(const unsigned int & conso) {
}

unsigned int Eclairage::Ent::getID() {
}

bool Eclairage::Ent::getAllume() {
}

bool Eclairage::Ent::getActive() {
}

std::string Eclairage::Ent::getNom() {
}

unsigned int Eclairage::Ent::getConsommation() {
}

void Eclairage::PersiBny::set(const Eclairage::Ent & ent) {
}

void Eclairage::PersiBny::get(Eclairage::Ent & ent) {
}

void Eclairage::IHMJardin::set(const Eclairage::Ent & ent) {
}


#ifndef NDEBUG
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
#endif