/******************************************************
* \file EclairageUnicolore.cpp
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <EclairageUnicolore.h>

void EclairageUnicolore::IHMFormulaire::set(EclairageUnicolore::Ent & ent, std::string nom, std::string couleur, std::string id)
{
	// Affichage du formulaire de création d'éclairage unicolore
	FichierTextePersiBny fichier("html/formulaireUnicolore.html");
	std::string html = fichier.getContenu();

	html.replace(html.find("_nomEclairage"), sizeof("_nomEclairage")-1, nom);
	html.replace(html.find("_couleurEclairage"), sizeof("_couleurEclairage")-1, couleur);
	html.replace(html.find("_idEclairage"), sizeof("_idEclairage")-1, id);

	std::cout << html;
}

void EclairageUnicolore::IHMFormulaire::get(EclairageUnicolore::Ent & ent) {
}

void EclairageUnicolore::IHMJardin::set(EclairageUnicolore::Ent & ent)
{
	std::string logo;

	if(ent.getActive())
	{
		if(ent.getAllume() == true && ent.getCouleur() == 0)
			logo = "unicoloreBleu.png";
		if(ent.getAllume() == true && ent.getCouleur() == 1)
			logo = "unicoloreBlanc.png" ;
		if(ent.getAllume() == true && ent.getCouleur() == 2)
			logo = "unicoloreRouge.png";
		else if(ent.getAllume() == false)
			logo = "unicoloreDesactive.png";
	}
	else
		logo = "unicoloreDesactive.png";
	

	std::cout << "<img style='width=100px;height:100px;' src='/" + logo + "' onclick='toggleMenu(\"menu-box" + std::to_string(ent.getID()) + "\")'/><ul id='menu-box" + std::to_string(ent.getID()) + "' style='display: none'>";

	if(ent.getActive())
		std::cout << "<li><a href='UcGerer.cgi?id=" + std::to_string(ent.getID()) + "&action=desactiver'>Desactiver</a></li>" << std::endl;
	else
		std::cout << "<li><a href='UcGerer.cgi?id=" + std::to_string(ent.getID()) + "&action=activer'>Activer</a></li>" << std::endl;

	if(ent.getAllume())
		std::cout << "<li><a href='UcCommander.cgi?id=" + std::to_string(ent.getID()) + "&action=eteindre'>Eteindre</a></li>" << std::endl;
	else
		std::cout << "<li><a href='UcCommander.cgi?id=" + std::to_string(ent.getID()) + "&action=allumer'>Allumer</a></li>" << std::endl;
	
	std::cout << "<li><a href='UcModifier.cgi?id=" + std::to_string(ent.getID()) + "&type=unicolore'>Parametrer</a></li>" << std::endl;
	std::cout << "</ul>" << std::endl;
}

void EclairageUnicolore::IHMParametre::set(EclairageUnicolore::Ent & ent)
{
	//Récupération du nom de l'éclairage
	SqlitePersiBny persi("/var/eclairage/bdd.db");
	SqlitePersiBny::Resultat resultat;

	persi.executerSql("SELECT nom FROM eclairages WHERE id = " + std::to_string(ent.getID()) + ";", resultat);

	// Affichage du formulaire de création d'éclairage unicolore
	FichierTextePersiBny fichier("html/formulaireParametreUnicolore.html");
	std::string html = fichier.getContenu();

	html.replace(html.find("_idEclairage"), sizeof("_idEclairage")-1, std::to_string(ent.getID()));
	html.replace(html.find("_nomEclairage"), sizeof("_nomEclairage")-1, resultat.at(0).at(0).second);

	std::cout << html;

}

void EclairageUnicolore::Controleur::getIHMJardin()
{
	this->ihmJardin.set(this->ent);
}

void EclairageUnicolore::Ent::setNumeroPrise(int num)
{
	this->numeroPrise = num;
	SqlitePersiBny persi(this->DB);
	persi.executerSql("UPDATE unicolores SET numeroPrise = " + std::to_string(numeroPrise) + " WHERE id = " + std::to_string(this->getID()) + ";");
}

int EclairageUnicolore::Ent::getNumeroPrise()
{
	SqlitePersiBny persi(this->DB);
	SqlitePersiBny::Resultat resultat;
	persi.executerSql("SELECT numeroPrise FROM unicolores WHERE id = " + std::to_string(this->getID()) + ";", resultat);
	this->numeroPrise = atoi(resultat.at(0).at(0).second.c_str());
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
	//eclairage.controleur.persiBny.set(eclairage.controleur.ent);
	eclairage.controleur.ihmFormulaire.set(eclairage.controleur.ent);

	return 0;
}
#endif

//g++ -o EclairageUnicolore EclairageUnicolore.cpp Eclairage.cpp SqlitePersiBny.cpp -lsqlite3 -I . -D _UT_EclairageUnicolore_