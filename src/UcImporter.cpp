/******************************************************
* \file UcImporter.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcImporter.h>

using namespace cgicc;

void UcImporter::doIt(UcModifier & ucModifier)
{
	// Création d'un nouvel objet Cgicc contenant toutes les données du CGI
    Cgicc cgi;

    // Headers HTTP
    std::cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << std::endl;
    std::cout << html().set("lang", "fr").set("dir", "ltr") << std::endl;

    // Head & title 
    std::cout << head() << std::endl;
    std::cout << title() << "Importer Configuration" << title() << std::endl;
    std::cout << head() << std::endl;
    
    // Début du body
    std::cout << body() << std::endl;

    // Récupère un pointeur vers l'environnement
    const CgiEnvironment& env = cgi.getEnvironment();
    
    // Process du fichier
    const_file_iterator file;
    file = cgi.getFile("userfile");
                                
    if(file != cgi.getFiles().end()) {

    	//Ecriture des données dans le fichier
		std::ofstream fichier;
		fichier.open(file->getFilename());
		file->writeToStream(fichier);
		fichier.close();

		//Lecture du fichier
        std::ifstream ifs(file->getFilename());
  		std::string contenu( (std::istreambuf_iterator<char>(ifs)),
                       (std::istreambuf_iterator<char>()));

		if(contenu.find("id,allume,active,nom,consommation,x,y,couleur,numeroPrise") != std::string::npos)
		{
			//Unicolore
			//Création du lecteur CSV
			CSV csv;
			csv.open(file->getFilename());

			std::vector<std::vector<std::string>> donnees = csv.get_vector();

			for(int i = 1; i < donnees.size(); i++)
			{
					//Création d'un eclairage unicolore temporaire
					EclairageUnicolore eclairage;

					//Assignation des valeurs d'éclairage générique
					eclairage.controleur.ent.setID(donnees[i][0]);
					eclairage.controleur.ent.setAllume(donnees[i][1]);
					eclairage.controleur.ent.setActive(donnees[i][2]);
					eclairage.controleur.ent.setNom(donnees[i][3]);
					eclairage.controleur.ent.setConsommation(donnees[i][4]);
					
					//Assignation des valeurs d'éclairage spécifique
					eclairage.controleur.ent.setCouleur(donnees[i][5]);

					//Creation de l'eclairage ou modification
					//ucModifier.doIt(eclairage,cgi);
			}
		}

		else if(contenu.find("id,allume,active,nom,consommation,couleur,x,y,adresseMac,adresseIP,versionFirmware,luminosite,niveauBatterie") != std::string::npos)
		{
	
			//Ecriture des données dans le fichier
			std::ofstream fichier;
			fichier.open(file->getFilename());
			file->writeToStream(fichier);
			fichier.close();

			//Lecture du fichier
	        std::ifstream ifs(file->getFilename());
	  		std::string contenu( (std::istreambuf_iterator<char>(ifs)),
	                       (std::istreambuf_iterator<char>()));

			for(int i = 1; i < donnees.size(); i++)
			{
					EclairageMulticolore eclairage;

					//Assignation des valeurs d'eclairage générique
					eclairage.controleur.ent.setID(donnees[i][0]);
					eclairage.controleur.ent.setAllume(donnees[i][1]);
					eclairage.controleur.ent.setActive(donnees[i][2]);
					eclairage.controleur.ent.setNom(donnees[i][3]);
					eclairage.controleur.ent.setConsommation(donnees[i][4]);
					eclairage.controleur.ent.setX(donnees[i][5]);
					eclairage.controleur.ent.setY(donnees[i][6]);
					eclairage.controleur.ent.setCouleur(donnees[i][10]);
	
					//Assignation des valeurs d'éclairage spécifique
					eclairage.controleur.ent.setAdresseMac(donnees[i][7]);
					eclairage.controleur.ent.setAdresseIP(donnees[i][8]);
					eclairage.controleur.ent.setVersionFirmware(donnees[i][9]);
					eclairage.controleur.ent.setLuminosite(donnees[i][11]);
					eclairage.controleur.ent.setNiveauBatterie(donnees[i][12]);
	
					//Creation de l'eclairage ou modification
					//ucModifier.doIt(eclairage,cgi);
			}			
		}
		else
		{
			// Erreur
			std::cout << ":(";
		}

		// Suppression du fichier et confirmation
		remove(file->getFilename().c_str());
		std::cout << "<p>Importation terminee !</p>" << std::endl;

    }

    // Affichage de la form pour recommencer
    std::cout << br() << std::endl;
    this->getFile(cgi);
    std::cout << hr().set("class", "half") << std::endl;

    // Fin du document
    std::cout << cgicc::div() << std::endl;
    std::cout << body() << html() << std::endl;
}

void UcImporter::getFile(const Cgicc & cgi)
{
std::cout << "<form method=\"post\" action=\"" 
       << cgi.getEnvironment().getScriptName() 
       << "\" enctype=\"multipart/form-data\">" << std::endl;
    
  std::cout << "<table>" << std::endl;

  std::cout << "<tr><td class=\"title\">Selectionner un fichier: </td>"
       << "<td class=\"form\">"
       << "<input type=\"file\" name=\"userfile\" accept=\"text/csv\" />"
       << "</td></tr>" << std::endl;

  std::cout << "</table>" << std::endl;

  std::cout << "<div class=\"center\"><p>"
       << "<input type=\"submit\" name=\"submit\" value=\"Envoyer le fichier\" />"
       << "</p></div></form>" << std::endl;
}


#ifdef _UT_UcImporter_
int main()
{
	UcImporter ucImporter;
	ucImporter.doIt(ucImporter.ucModifier);
	return 0;
}
#endif

//g++ -o /usr/lib/cgi-bin/UcImporter.cgi UcImporter.cpp UcAjouter.cpp UcModifier.cpp SqlitePersiBny.cpp Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp -lcgicc -lsqlite3 -I . -D _UT_UcImporter_ -pthread
