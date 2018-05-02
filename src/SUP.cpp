/******************************************************
* \file SUP.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <SUP.h>

void SUP::visualiserInfo(EclairageUnicolore::Ent eclairage)
{
	/**
	 * Variables contenant:
	 * 	- Resultat de la requete SQL
	 *  - Vecteur de pairs mettant en relation les champs à remplacer et les informations de l'eclairage
	 *  - Nom du fichier HTML qui va acceuillir les infos de l'eclairage
	 */
	SqlitePersiBny::Resultat resultat;
	std::vector<std::pair<std::string, std::string>> infosUni;
	std::string html = "html/infoPanelUnicolore.html";

	// Requete SQL selectionnant le nom, l'etat et la consommation de l'eclairage
	this->persiBny.executerSql("SELECT nom,active,consommation FROM eclairages WHERE id = " + std::to_string(eclairage.getID()) + ";", resultat);

	// Insertion des données dans le vecteur
	infosUni.at(0) = std::make_pair("_nom", resultat.at(0).at(0).second);
	infosUni.at(1) = std::make_pair("_active", resultat.at(0).at(1).second);
	infosUni.at(2) = std::make_pair("_consommation", resultat.at(0).at(2).second);
	infosUni.at(3) = std::make_pair("_idClass", "infos_"+std::to_string(eclairage.getID()));

	// Remplacement des données dans le fichier HTML
	std::cout << Utility::remplacer(html, infosUni);
}

void SUP::visualiserInfo(EclairageMulticolore::Ent eclairage)
{
	/**
	 * Variables contenant:
	 * 	- Resultat de la requete SQL
	 *  - Vecteur de pairs mettant en relation les champs à remplacer et les informations de l'eclairage
	 *  - Nom du fichier HTML qui va acceuillir les infos de l'eclairage
	 */
	SqlitePersiBny::Resultat resultat;
	std::string fichier = "html/infoPanelMulticolore.html";

	FichierTextePersiBny file(fichier);
	std::string html = file.getContenu();

	this->persiBny.executerSql("SELECT nom,active,consommation,luminosite,niveauBatterie FROM eclairages e INNER JOIN multicolores m ON m.id = e.id WHERE e.id = " + std::to_string(eclairage.getID()) + ";", resultat);

	// Remplacement des données dans le fichier HTML
	html.replace(html.find("_nom"), sizeof("_nom")-1, resultat.at(0).at(0).second);
	html.replace(html.find("_active"), sizeof("_active")-1, resultat.at(0).at(1).second);
	html.replace(html.find("_consommation"), sizeof("_consommation")-1, resultat.at(0).at(2).second);
	html.replace(html.find("_luminosite"), sizeof("_luminosite")-1, resultat.at(0).at(3).second);
	html.replace(html.find("_niveauBatterie"), sizeof("_niveauBatterie")-1, resultat.at(0).at(4).second);
	html.replace(html.find("_idClass"), sizeof("_idClass")-1, "menu-box"+std::to_string(eclairage.getID()) + "_infos");

	std::cout << html;

}

void SUP::extraireEclairages(std::vector<EclairageUnicolore> & eclairagesUnicolores, std::vector<EclairageMulticolore> & eclairagesMulticolores)
{
	// Unicolore
	SqlitePersiBny::Resultat resultat, subRes;

	this->persiBny.executerSql("SELECT id, numeroPrise FROM unicolores;", resultat);

	for(int i = 0; i < resultat.size(); i++)
	{
		EclairageUnicolore tmp;

		//Propriétés spécifiques
		tmp.controleur.ent.setID(atoi(resultat.at(i).at(0).second.c_str()));
		tmp.controleur.ent.setNumeroPrise(atoi(resultat.at(i).at(1).second.c_str()));

		//Propriétés génériques
		this->persiBny.executerSql("SELECT allume, active, nom, consommation, couleur FROM eclairages WHERE id = " + std::to_string(tmp.controleur.ent.getID()) + ";", subRes);
		tmp.controleur.ent.setAllume(subRes.at(0).at(0).second == "1" ? true : false);
		tmp.controleur.ent.setActive(subRes.at(0).at(1).second == "1" ? true : false);
		tmp.controleur.ent.setNom(subRes.at(0).at(2).second.c_str());
		tmp.controleur.ent.setConsommation(atoi(subRes.at(0).at(3).second.c_str()));
		if(subRes.at(i).at(4).second == "0")
			tmp.controleur.ent.setCouleur(Bleu);
		if(subRes.at(i).at(4).second == "1")
			tmp.controleur.ent.setCouleur(Blanc);
		if(subRes.at(i).at(4).second == "2")
			tmp.controleur.ent.setCouleur(Rouge);

		eclairagesUnicolores.push_back(tmp);
		subRes.clear();
	}

	resultat.clear();
	subRes.clear();

	// Multicolore
	this->persiBny.executerSql("SELECT id, adresseMAc, adresseIP, versionFirmware, luminosite, niveauBatterie FROM multicolores;", resultat);

	for(int i = 0; i < resultat.size(); i++)
	{
		EclairageMulticolore tmp;
		
		//Propriétés spécifiques
		tmp.controleur.ent.setID(atoi(resultat.at(i).at(0).second.c_str()));
		tmp.controleur.ent.setAdresseMac(resultat.at(i).at(1).second);
		tmp.controleur.ent.setAdresseIP(resultat.at(i).at(2).second);
		tmp.controleur.ent.setVersionFirmware(atof(resultat.at(i).at(3).second.c_str()));
		tmp.controleur.ent.setLuminosite(atoi(resultat.at(i).at(4).second.c_str()));
		tmp.controleur.ent.setNiveauBatterie(atoi(resultat.at(i).at(5).second.c_str()));

		//Propriétés génériques
		this->persiBny.executerSql("SELECT allume, active, nom, consommation, couleur FROM eclairages WHERE id = " + std::to_string(tmp.controleur.ent.getID()) + ";", subRes);
		tmp.controleur.ent.setAllume(subRes.at(0).at(0).second == "1" ? true : false);
		tmp.controleur.ent.setActive(subRes.at(0).at(1).second == "1" ? true : false);
		tmp.controleur.ent.setNom(subRes.at(0).at(2).second);
		tmp.controleur.ent.setConsommation(atoi(subRes.at(0).at(3).second.c_str()));
		if(subRes.at(0).at(4).second == "0")
			tmp.controleur.ent.setCouleur(Bleu);
		if(subRes.at(0).at(4).second == "1")
			tmp.controleur.ent.setCouleur(Blanc);
		if(subRes.at(0).at(4).second == "2")
			tmp.controleur.ent.setCouleur(Rouge);
		
		eclairagesMulticolores.push_back(tmp);
		subRes.clear();
	}
	resultat.clear();

}

void SUP::suivreConsoElectricite() {
}

void SUP::afficherEclairages(std::vector<EclairageUnicolore> & eclairagesUnicolores, std::vector<EclairageMulticolore> & eclairagesMulticolores)
{
	for(int i = 0; i < eclairagesMulticolores.size(); i++)
	{
		eclairagesMulticolores.at(i).controleur.getIHMJardin();
		this->visualiserInfo(eclairagesMulticolores.at(i).controleur.ent);
	}eclairagesMulticolores.clear();

	for(int i = 0; i < eclairagesUnicolores.size(); i++)
	{
		eclairagesUnicolores.at(i).controleur.getIHMJardin();
		this->visualiserInfo(eclairagesUnicolores.at(i).controleur.ent);

	}eclairagesUnicolores.clear();
}

void SUP::doIt()
{
	std::string html;

	std::cout << cgicc::HTTPHTMLHeader() << std::endl;

	//Recuperation du template de la page
	FichierTextePersiBny fichier("html/index.html");

	//Debut de la page HTML
	std::cout << fichier.getContenu();

	//Extractions des eclairages
	std::vector<EclairageMulticolore> eclairagesMulticolores;
	std::vector<EclairageUnicolore> eclairagesUnicolores;
	this->extraireEclairages(eclairagesUnicolores, eclairagesMulticolores);

	//Affichage des éclairages/infos
	this->afficherEclairages(eclairagesUnicolores, eclairagesMulticolores);

	//Fin de la page HTML
	std::cout << "</body></html>";



}


#ifdef _UT_SUP_
int main()
{
	SUP sup;
	sup.doIt();

	return 0;
}
#endif

//g++ -o /usr/lib/cgi-bin/index.cgi SUP.cpp Eclairage.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp SqlitePersiBny.cpp Utility.cpp -I . -lsqlite3 -pthread -lcgicc -D _UT_SUP_
