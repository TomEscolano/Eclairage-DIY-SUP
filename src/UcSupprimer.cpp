/******************************************************
* \file UcSupprimer.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcSupprimer.h>

void UcSupprimer::doIt(Eclairage::Ent eclairage)
{
	SqlitePersiBny persi(this->DB);
	persi.executerSql("DELETE FROM eclairages WHERE id = " + std::to_string(eclairage.getID()) + "; DELETE FROM multicolores WHERE id = " + std::to_string(eclairage.getID()) + "; DELETE FROM unicolores WHERE id = " + std::to_string(eclairage.getID()) + ";");
}


#ifdef _UT_UcSupprimer_
int main()
{

	UcSupprimer ucSupprimer;
	cgicc::Cgicc cgi;

    // Envoi des headers HTTP
    std::cout << cgicc::HTTPHTMLHeader() << std::endl;

    // Début du document HTML
    std::cout << cgicc::html() << cgicc::head(cgicc::title("Supprimer un eclairage")) << std::endl;
    std::cout << cgicc::body() << std::endl;

	SqlitePersiBny persi("/var/eclairage/bdd.db");
	SqlitePersiBny::Resultat resultat;

	persi.executerSql("SELECT nom FROM eclairages;", resultat);

	std::cout << "<h1>Supprimer un eclairage:</h1>";

	std::cout << "<form action='/cgi-bin/UcSupprimer.cgi' method='get'><select name=\"name\">" << std::endl;

	for(int i = 0; i < resultat.size(); i++)
	{
		std::cout << "<option name='" + resultat.at(i).at(0).second + "' value='" + resultat.at(i).at(0).second + "'>" + resultat.at(i).at(0).second + "</option>" << std::endl;
	}
	std::cout << "</select><input type='submit' value='Supprimer'></input></form>" << std::endl;


    // Supression de l'eclairage soumis au document
    cgicc::form_iterator name = cgi.getElement("name");
    if(name != cgi.getElements().end())
    {
    	// Eclairage temporaire pour récupérer l'entité de l'eclairage selectionné
		Eclairage tmp;
		SqlitePersiBny::Resultat resultat;
		
		// Selection de l'ID de l'eclairage
		persi.executerSql("SELECT id FROM eclairages WHERE nom = \"" + **name + "\";", resultat);
		tmp.controleur.ent.setID(atoi(resultat.at(0).at(0).second.c_str()));

		//Récupération de l'entité de l'éclairage
		tmp.controleur.get(tmp.controleur.ent);

		//Supression de l'éclairage
		ucSupprimer.doIt(tmp.controleur.ent);
    
		std::cout << "<p>Suppression terminee !</p>";
    }

      // Fin du document HTML
      std::cout << cgicc::body() << cgicc::html();
   
	return 0;
}
#endif

//g++ -o UcSupprimer Eclairage.cpp UcSupprimer.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcSupprimer_