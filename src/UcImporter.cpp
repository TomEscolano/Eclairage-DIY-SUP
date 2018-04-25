/******************************************************
* \file UcImporter.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "UcImporter.h"
#include <cstdio>


using namespace cgicc;

void UcImporter::doIt(UcModifier & ucModifier)
{
	// Create a new Cgicc object containing all the CGI data
    Cgicc cgi;

    // Output the HTTP headers for an HTML document, and the HTML 4.0 DTD info
    std::cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << std::endl;
    std::cout << html().set("lang", "fr").set("dir", "ltr") << std::endl;

    // Set up the page's header and title.
    // I will put in lfs to ease reading of the produced HTML. 
    std::cout << head() << std::endl;

    std::cout << title() << "Importer Configuration" << title() << std::endl;

    std::cout << head() << std::endl;
    
    // Start the HTML body
    std::cout << body() << std::endl;

    // Get a pointer to the environment
    const CgiEnvironment& env = cgi.getEnvironment();
    
    // Process the uploaded file
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
			//Initialisation du lecteur CSV
			io::CSVReader<9> in(file->getFilename());
			in.read_header(io::ignore_extra_column, "id","allume","active","nom","consommation","x","y","couleur","numeroPrise");

			//Propriétés
			std::string nom;
			int id, consommation, x, y, numeroPrise, couleur, allume, active;

			while(in.read_row(id,allume,active,nom,consommation,x,y,couleur,numeroPrise))
			{
				//Création d'un eclairage unicolore temporaire
				EclairageUnicolore eclairage;

				//Assignation des valeurs d'éclairage générique
				eclairage.controleur.ent.setID(id);
				eclairage.controleur.ent.setAllume(allume);
				eclairage.controleur.ent.setActive(active);
				eclairage.controleur.ent.setNom(nom);
				eclairage.controleur.ent.setConsommation(consommation);
				
				//Assignation des valeurs d'éclairage spécifique
				if(couleur == 0)
					eclairage.controleur.ent.setCouleur(Bleu);
				if(couleur == 1)
					eclairage.controleur.ent.setCouleur(Rouge);
				if(couleur == 2)
					eclairage.controleur.ent.setCouleur(Blanc);

				//Creation de l'eclairage ou modification
				ucModifier.doIt(eclairage.controleur.ent);
			}

			
		}
		else if(contenu.find("id,allume,active,nom,consommation,x,y,adresseMac,adresseIP,versionFirmware,couleur,luminosite,niveauBatterie") != std::string::npos)
		{
	
			//Multicolore
			//Initialisation du lecteur CSV
			io::CSVReader<13> in(file->getFilename());
			in.read_header(io::ignore_extra_column, "id","allume","active","nom","consommation","x","y","adresseMac","adresseIP","versionFirmware","couleur","luminosite","niveauBatterie");

			//Propriétés
			std::string nom, adresseMac, adresseIP;
			int id, consommation, x, y, numeroPrise, couleur, allume, active, luminosite, niveauBatterie;
			float versionFirmware;

			while(in.read_row(id,allume,active,nom,consommation,x,y,adresseMac,adresseIP,versionFirmware,couleur,luminosite,niveauBatterie))
			{
				//Creation d'un eclairage multicolore temporaire
				EclairageMulticolore eclairage;

				//Assignation des valeurs d'eclairage générique
				eclairage.controleur.ent.setID(id);
				eclairage.controleur.ent.setAllume(allume);
				eclairage.controleur.ent.setActive(active);
				eclairage.controleur.ent.setNom(nom);
				eclairage.controleur.ent.setConsommation(consommation);
				eclairage.controleur.ent.setX(x);
				eclairage.controleur.ent.setY(y);

				//Assignation des valeurs d'éclairage spécifique
				eclairage.controleur.ent.setAdresseMac(adresseMac);
				eclairage.controleur.ent.setAdresseIP(adresseIP);
				eclairage.controleur.ent.setVersionFirmware(versionFirmware);
				if(couleur == 0)
					eclairage.controleur.ent.setCouleur(Bleu);
				if(couleur == 1)
					eclairage.controleur.ent.setCouleur(Rouge);
				if(couleur == 2)
					eclairage.controleur.ent.setCouleur(Blanc);
				eclairage.controleur.ent.setLuminosite(luminosite);
				eclairage.controleur.ent.setNiveauBatterie(niveauBatterie);

				//Creation de l'eclairage ou modification
				ucModifier.doIt(eclairage.controleur.ent);
			}
			
		}
		else{
			std::cout << ":(";
		}



		remove(file->getFilename().c_str());

    }

    // Print out the form to do it again
    std::cout << br() << std::endl;
    this->getFile(cgi);
    std::cout << hr().set("class", "half") << std::endl;

    // End of document
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
