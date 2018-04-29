/******************************************************
* \file UcCommander.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcCommander.h>

void UcCommander::doIt(Eclairage::Ent & eclairage, bool etat)
{
	eclairage.setAllume(etat);
	/*SqlitePersiBny persiBny(this->DB);
	persiBny.executerSql("UPDATE  eclairages SET allume = " + std::to_string(etat) + " WHERE id = " + std::to_string(eclairage.controleur.ent.getID()) + ";");*/
}


#ifdef _UT_UcCommander_
int main()
{
	UcCommander ucCommander;
	cgicc::Cgicc cgi;

	std::cout << cgicc::HTTPHTMLHeader() << std::endl;

    // Début du document HTML
    std::cout << cgicc::html() << cgicc::head(cgicc::title("Allumer un eclairage")) << std::endl;
    std::cout << cgicc::body() << std::endl;

    // Modification de l'eclairage soumis au document
    cgicc::form_iterator id = cgi.getElement("id");
    cgicc::form_iterator action = cgi.getElement("action");

    if(id != cgi.getElements().end() && action != cgi.getElements().end())
    {
    	// Eclairage temporaire pour récupérer l'entité de l'eclairage selectionné
		Eclairage tmp;
		SqlitePersiBny::Resultat resultat;
		bool etat = (**action == "allumer") ? true : false;
		
		// Selection de l'ID de l'eclairage
		std::string idd = **id;
		tmp.controleur.ent.setID(atoi(idd.c_str()));

		//Récupération de l'entité de l'éclairage
		//tmp.controleur.get(tmp.controleur.ent);

		//Modification de l'éclairage
		ucCommander.doIt(tmp.controleur.ent, etat);
    
		std::cout << "<p>Modification terminee !</p>";
		std::cout << " <meta http-equiv='refresh' content='2; URL=/cgi-bin/index.cgi'> ";
    }

      // Fin du document HTML
      std::cout << cgicc::body() << cgicc::html();
	
	return 0;
}
#endif

//g++ -o UcCommander UcCommander.cpp Eclairage.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcCommander_