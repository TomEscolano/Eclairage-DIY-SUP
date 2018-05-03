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
	std::cout << "<div class='w3-panel w3-green'><h3>Succes !</h3><p>Suppression terminee !</p>  </div>";
    std::cout << "<meta http-equiv='refresh' content='2; URL=/cgi-bin/index.cgi'> ";
}


#ifdef _UT_UcSupprimer_
int main()
{

	UcSupprimer ucSupprimer;
	cgicc::Cgicc cgi;

    // Envoi des headers HTTP
    std::cout << cgicc::HTTPHTMLHeader() << std::endl;

    // Début du document HTML
    std::cout << cgicc::html() << cgicc::head() << "<title>Supprimer un eclairage</title><link rel='stylesheet' href='https://www.w3schools.com/w3css/4/w3.css'>" << std::endl;
    std::cout << cgicc::body() << std::endl;

    // Supression de l'eclairage soumis au document
    cgicc::form_iterator id = cgi.getElement("id");
    if(id != cgi.getElements().end())
    {
    	// Eclairage temporaire pour récupérer l'entité de l'eclairage selectionné
		Eclairage tmp;
		SqlitePersiBny::Resultat resultat;
		
		std::string tmpId = **id;
		tmp.controleur.ent.setID(atoi(tmpId.c_str()));

		//Supression de l'éclairage
		ucSupprimer.doIt(tmp.controleur.ent);
        }

      // Fin du document HTML
      std::cout << cgicc::body() << cgicc::html();
   
	return 0;
}
#endif

//g++ -o UcSupprimer Eclairage.cpp UcSupprimer.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcSupprimer_