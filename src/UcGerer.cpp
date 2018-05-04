/******************************************************
* \file UcGerer.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcGerer.h>

void UcGerer::doIt(Eclairage::Ent & eclairage, bool etat)
{
	eclairage.setActive(etat);
}


#ifdef _UT_UcGerer_
int main()
{
	UcGerer ucGerer;
	cgicc::Cgicc cgi;

	std::cout << cgicc::HTTPHTMLHeader() << std::endl;

    // Début du document HTML
    std::cout << cgicc::html() << cgicc::head() << "<title>Activer un eclairage</title><link rel='stylesheet' href='https://www.w3schools.com/w3css/4/w3.css'>" << std::endl;
    std::cout << cgicc::body() << std::endl;

    // Modification de l'eclairage soumis au document
    cgicc::form_iterator id = cgi.getElement("id");
    cgicc::form_iterator action = cgi.getElement("action");

    if(id != cgi.getElements().end() && action != cgi.getElements().end())
    {
    	// Eclairage temporaire, etat
		Eclairage tmp;
		bool etat = (**action == "activer") ? true : false;
		
		// Selection de l'ID de l'eclairage
		std::string idd = **id;
		tmp.controleur.ent.setID(atoi(idd.c_str()));

		//Modification de l'éclairage
		ucGerer.doIt(tmp.controleur.ent, etat);
    
    	if(etat)
			std::cout << "<div class='w3-panel w3-green'><h3>Succes !</h3><p>Activation terminee !</p>  </div>";
		else
			std::cout << "<div class='w3-panel w3-green'><h3>Succes !</h3><p>Desactivation terminee !</p>  </div>";
		std::cout << " <meta http-equiv='refresh'content='2; URL=/cgi-bin/index.cgi'> " << std::endl;

    }

      // Fin du document HTML
      std::cout << cgicc::body() << cgicc::html();
	
	return 0;
}
#endif

//g++ -o /usr/lib/cgi-bin/UcGerer.cgi UcGerer.cpp Eclairage.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcGerer_