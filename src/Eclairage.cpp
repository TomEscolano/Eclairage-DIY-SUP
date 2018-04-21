/******************************************************
* \file Eclairage.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "Eclairage.h"
#include "UcGerer.h"

void Eclairage::IHMFormulaire::set(const Eclairage::Ent & ent) {
}

void Eclairage::IHMFormulaire::get(Eclairage::Ent & ent) {
}

void Eclairage::Controleur::activer(bool etat) {
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

void Eclairage::Ent::setCouleur(Couleur couleur) {
}

void Eclairage::Ent::setConsommation(const unsigned int & conso) {
}

void Eclairage::Ent::setX(const valeur & x) {
}

void Eclairage::Ent::setY(int y) {
}

unsigned int Eclairage::Ent::getID() {
}

bool Eclairage::Ent::getAllume() {
}

bool Eclairage::Ent::getActive() {
}

std::string Eclairage::Ent::getNom() {
}

Couleur Eclairage::Ent::getCouleur() {
}

unsigned int Eclairage::Ent::getConsommation() {
}

int Eclairage::Ent::getX() {
}

int Eclairage::Ent::getY() {
}

void Eclairage::PersiBny::set(const Eclairage::Ent & ent) {
}

void Eclairage::PersiBny::get(Eclairage::Ent & ent) {
}

void Eclairage::IHMJardin::set(const Eclairage::Ent & ent) {
}


#ifdef _UT_Eclairage_
int main()
{
	return 0;
}
#endif
