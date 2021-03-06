/******************************************************
* \file Eclairage.cpp
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <Eclairage.h>

void Eclairage::IHMFormulaire::set(Eclairage::Ent & ent, std::string type, std::string x, std::string y)
{
	// Affichage du formulaire et remplacement du type d'éclairage
	FichierTextePersiBny fichier("html/formulaire.html");
	std::string html = fichier.getContenu();
	
	html.replace(html.find("_typeEclairage"), sizeof("_typeEclairage")-1, type);
	html.replace(html.find("_idEclairage"), sizeof("_idEclairage")-1, std::to_string(ent.getID()));
	html.replace(html.find("_xEclairage"), sizeof("_xEclairage")-1, x);
	html.replace(html.find("_yEclairage"), sizeof("_yEclairage")-1, y);

	std::cout << html;
}

void Eclairage::IHMFormulaire::get(Eclairage::Ent & ent)
{

	cgicc::Cgicc cgi;

    // Récupération des paramètres pour le script
    cgicc::form_iterator nom = cgi.getElement("nom");
    cgicc::form_iterator couleur = cgi.getElement("couleur");

    if(nom != cgi.getElements().end() && couleur != cgi.getElements().end())
    {
    	ent.setNom(**nom);
    	ent.setCouleur(**couleur);
    }	
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

void Eclairage::Controleur::get(Eclairage::Ent & ent) 
{
	SqlitePersiBny::Resultat resultat;
	this->persiBny.executerSql("SELECT allume, active, nom, consommation, couleur FROM eclairages WHERE id = " + std::to_string(ent.getID()) + ";", resultat);

	ent.setAllume(resultat.at(0).at(0).second == "1" ? true : false);
	ent.setActive(resultat.at(0).at(1).second == "1" ? true : false);
	ent.setNom(resultat.at(0).at(2).second);
	ent.setConsommation((unsigned int)atoi(resultat.at(0).at(3).second.c_str()));
	ent.setCouleur(resultat.at(0).at(4).second);

}

void Eclairage::Ent::setID(const unsigned int & id)
{
	this->id = id;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE eclairages SET id =  " + std::to_string(this->getID()) + " WHERE id = " + std::to_string(this->getID()) + ";");
}

void Eclairage::Ent::setAllume(bool etat)
{
	this->allume = etat;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE eclairages SET allume = " + std::to_string(this->allume) + " WHERE id = " + std::to_string(this->getID()) + ";");
	Utility::log_action(this->getID(), "Allumer", std::to_string(this->allume));
}

void Eclairage::Ent::setActive(bool etat)
{
	this->active = etat;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE eclairages SET active = " + std::to_string(this->active) + " WHERE id = " + std::to_string(this->getID()) + ";");
	Utility::log_action(this->getID(), "Activer", std::to_string(this->active));
}

void Eclairage::Ent::setNom(const std::string & nom)
{
	this->nom = nom;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE eclairages SET nom = \"" + this->nom + "\" WHERE id = " + std::to_string(this->getID()) + ";");
	Utility::log_action(this->getID(), "Nom", this->nom);
}

void Eclairage::Ent::setCouleur(std::string couleur)
{
	this->couleur = couleur;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE eclairages SET couleur =  \"" + this->couleur + "\" WHERE id = " + std::to_string(this->getID()) + ";");
	Utility::log_action(this->getID(), "Couleur", this->couleur);
}

void Eclairage::Ent::setConsommation(const unsigned int & conso)
{
	this->consommation = conso;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE eclairages SET consommation =  " + std::to_string(this->consommation) + " WHERE id = " + std::to_string(this->getID()) + ";");
	Utility::log_action(this->getID(), "Consommation", std::to_string(this->consommation));
}

void Eclairage::Ent::setX(int x)
{
	this->x = x;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE eclairages SET x =  " + std::to_string(this->x) + " WHERE id = " + std::to_string(this->getID()) + ";");
}

void Eclairage::Ent::setY(int y)
{
	this->y = y;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE eclairages SET y =  " + std::to_string(this->y) + " WHERE id = " + std::to_string(this->getID()) + ";");
}

unsigned int Eclairage::Ent::getID()
{
	return this->id;
}

bool Eclairage::Ent::getAllume()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT allume FROM eclairages WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->allume = resultat.at(0).at(0).second == "1" ? true : false; 
	return this->allume;
}

bool Eclairage::Ent::getActive()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT active FROM eclairages WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->active = resultat.at(0).at(0).second == "1" ? true : false;
	return this->active;
}

std::string Eclairage::Ent::getNom()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT nom FROM eclairages WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->nom = resultat.at(0).at(0).second;
	return this->nom;
}

std::string Eclairage::Ent::getCouleur()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT couleur FROM eclairages WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->couleur = resultat.at(0).at(0).second;

	return this->couleur;
}

unsigned int Eclairage::Ent::getConsommation()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT consommation FROM eclairages WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->consommation = atoi(resultat.at(0).at(0).second.c_str());
	return this->consommation;
}

int Eclairage::Ent::getX()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT x FROM eclairages WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->x = atoi(resultat.at(0).at(0).second.c_str());
	return this->x;
}

int Eclairage::Ent::getY()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT y FROM eclairages WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->y = atoi(resultat.at(0).at(0).second.c_str());
	return this->y;
}

void Eclairage::PersiBny::set(Ent & ent)
{
	this->executerSql("UPDATE eclairages SET allume = " + std::to_string(ent.getAllume()) + ", active = " + std::to_string(ent.getActive()) + ", nom = \"" + ent.getNom() + "\", consommation = " + std::to_string(ent.getConsommation()) + " WHERE id = " + std::to_string(ent.getID()) + ";");

}

void Eclairage::PersiBny::get(Ent & ent)
{
	SqlitePersiBny::Resultat resultat;
	this->executerSql("SELECT allume, active, nom, consommation, couleur, x, y FROM eclairages WHERE id = " + std::to_string(ent.getID()) + ";", resultat);

	ent.setAllume(atoi(resultat.at(0).at(0).second.c_str()));
	ent.setActive(atoi(resultat.at(0).at(1).second.c_str()));
	ent.setNom(resultat.at(0).at(2).second);
	ent.setConsommation((unsigned int)atoi(resultat.at(0).at(3).second.c_str()));
	ent.setCouleur(resultat.at(0).at(4).second);
	ent.setX(atoi(resultat.at(0).at(5).second.c_str()));
	ent.setY(atoi(resultat.at(0).at(6).second.c_str()));
}

void Eclairage::IHMJardin::set(const Eclairage::Ent & ent) {
}


#ifdef _UT_Eclairage_
int main()
{
	Eclairage eclairage;
	//eclairage.controleur.persiBny.set(eclairage.controleur.ent);
	//eclairage.controleur.persiBny.get(eclairage.controleur.ent);

	return 0;
}
#endif

//g++ -o Eclairage Eclairage.cpp SqlitePersiBny.cpp -lsqlite3 -I . -D _UT_Eclairage_