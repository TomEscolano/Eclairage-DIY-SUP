/******************************************************
* \file Eclairage.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "Eclairage.h"

void Eclairage::IHMFormulaire::set(const Eclairage::Ent & ent){
}

void Eclairage::IHMFormulaire::get(Eclairage::Ent & ent) {
}

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

void Eclairage::Controleur::set(const Eclairage::Ent & ent) {
}

void Eclairage::Controleur::get(Eclairage::Ent & ent) {
}

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

void Eclairage::Ent::setCouleur(Couleur couleur)
{
	this->couleur = couleur;
}

void Eclairage::Ent::setConsommation(const unsigned int & conso)
{
	this->consommation = conso;
}

void Eclairage::Ent::setX(int x)
{
	this->x = x;
}

void Eclairage::Ent::setY(int y)
{
	this->y = y;
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

Couleur Eclairage::Ent::getCouleur()
{
	return this->couleur;
}

unsigned int Eclairage::Ent::getConsommation()
{
	return this->consommation;
}

int Eclairage::Ent::getX()
{
	return this->x;
}

int Eclairage::Ent::getY()
{
	return this->y;
}

void Eclairage::PersiBny::set(Ent & ent)
{
	this->executerSql("UPDATE eclairages SET allume = " + std::to_string(ent.getAllume()) + ", active = " + std::to_string(ent.getActive()) + ", nom = \"" + ent.getNom() + "\", consommation = " + std::to_string(ent.getConsommation()) + " WHERE id = " + std::to_string(ent.getID()) + ";");

}

void Eclairage::PersiBny::get(Ent & ent)
{
	SqlitePersiBny::Resultat resultat;
	this->executerSql("SELECT * FROM eclairages WHERE id = " + std::to_string(ent.getID()) + ";", resultat);

	ent.setAllume(atoi(resultat.at(0).at(1).second.c_str()));
	ent.setActive(atoi(resultat.at(0).at(2).second.c_str()));
	ent.setNom(resultat.at(0).at(3).second);
	ent.setConsommation((unsigned int)atoi(resultat.at(0).at(4).second.c_str()));
	if(resultat.at(0).at(5).second == "Bleu")
			ent.setCouleur(Bleu);
		if(resultat.at(0).at(5).second == "Rouge")
			ent.setCouleur(Rouge);
		if(resultat.at(0).at(5).second == "Blanc")
			ent.setCouleur(Blanc);

	ent.setX(atoi(resultat.at(0).at(6).second.c_str()));
	ent.setY(atoi(resultat.at(0).at(7).second.c_str()));
}

void Eclairage::IHMJardin::set(const Eclairage::Ent & ent) {
}


#ifdef _UT_Eclairage_
int main()
{
	Eclairage eclairage;
	eclairage.controleur.persiBny.set(eclairage.controleur.ent);
	//eclairage.controleur.persiBny.get(eclairage.controleur.ent);

	return 0;
}
#endif

//g++ -o Eclairage Eclairage.cpp SqlitePersiBny.cpp -lsqlite3 -I . -D _UT_Eclairage_