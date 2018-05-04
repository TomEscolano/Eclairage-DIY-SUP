/******************************************************
* \file UcCommander.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcCommander.h>

void UcCommander::doIt(Eclairage::Ent & eclairage, bool etat)
{
	eclairage.setAllume(etat);
}


#ifdef _UT_UcCommander_
int main()
{
	UcCommander ucCommander;
	cgicc::Cgicc cgi;

	std::cout << cgicc::HTTPHTMLHeader() << std::endl;

    // Début du document HTML
    std::cout << cgicc::html() << cgicc::head() << "<title>Allumer un eclairage</title><link rel='stylesheet' href='https://www.w3schools.com/w3css/4/w3.css'>" << std::endl;
    std::cout << cgicc::body() << std::endl;

    // Récupération des paramètres pour le script
    cgicc::form_iterator id = cgi.getElement("id");
    cgicc::form_iterator action = cgi.getElement("action");

    if(id != cgi.getElements().end() && action != cgi.getElements().end())
    {
    	// Eclairage temporaire et etat
		Eclairage tmp;
		bool etat = (**action == "allumer") ? true : false;
		
		// Selection de l'ID de l'eclairage
		std::string idd = **id;
		tmp.controleur.ent.setID(atoi(idd.c_str()));

		//Modification de l'éclairage
		ucCommander.doIt(tmp.controleur.ent, etat);
    
    	if(etat)
			std::cout << "<div class='w3-panel w3-green'><h3>Succes !</h3><p>Allumage termine !</p>  </div>";
		else
			std::cout << "<div class='w3-panel w3-green'><h3>Succes !</h3><p>Extinction terminee !</p>  </div>";
		std::cout << "<meta http-equiv='refresh' content='2; URL=/cgi-bin/index.cgi'> ";
    }

      // Fin du document HTML
      std::cout << cgicc::body() << cgicc::html();
	
	return 0;
}
#endif

//g++ -o UcCommander UcCommander.cpp Eclairage.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcCommander_