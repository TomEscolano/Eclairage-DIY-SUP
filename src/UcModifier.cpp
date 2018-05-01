/******************************************************
* \file UcModifier.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcModifier.h>

void UcModifier::doIt(EclairageMulticolore & eclairage, cgicc::Cgicc & cgi)
{
    cgicc::form_iterator id = cgi.getElement("id");
    cgicc::form_iterator nom = cgi.getElement("nom");
    cgicc::form_iterator couleur = cgi.getElement("couleur");
    cgicc::form_iterator adresseIP = cgi.getElement("adresseIP");

    if(nom != cgi.getElements().end() && couleur != cgi.getElements().end() && adresseIP != cgi.getElements().end() && id != cgi.getElements().end())
    {
            SqlitePersiBny persi("/var/eclairage/bdd.db");
            persi.executerSql("UPDATE eclairages SET nom =\"" + **nom + "\", couleur = " + **couleur + " WHERE id = " + **id + ";");
            persi.executerSql("UPDATE multicolores SET adresseIP = \"" + **adresseIP + "\" WHERE id = " + **id + ";");
            std::cout << "<p>Configuration mise à jour !<p>";
            std::cout << "<meta http-equiv='refresh' content='2; URL=/cgi-bin/index.cgi'> ";

    }
    else
    {
        eclairage.EclairageMulticolore::controleur.ihmParametre.set(eclairage.controleur.ent);
    }
}

void UcModifier::doIt(EclairageUnicolore & eclairage, cgicc::Cgicc & cgi)
{
	cgicc::form_iterator id = cgi.getElement("id");
	cgicc::form_iterator nom = cgi.getElement("nom");
    cgicc::form_iterator couleur = cgi.getElement("couleur");
    cgicc::form_iterator numeroPrise = cgi.getElement("numeroPrise");

    if(nom != cgi.getElements().end() && couleur != cgi.getElements().end() && numeroPrise != cgi.getElements().end() && id != cgi.getElements().end())
    {
    		SqlitePersiBny persi("/var/eclairage/bdd.db");
    		persi.executerSql("UPDATE eclairages SET nom =\"" + **nom + "\", couleur = " + **couleur + " WHERE id = " + **id + ";");
    		persi.executerSql("UPDATE unicolores SET numeroPrise = " + **numeroPrise + " WHERE id = " + **id + ";");
    		std::cout << "<p>Configuration mise à jour !<p>";
            std::cout << "<meta http-equiv='refresh' content='2; URL=/cgi-bin/index.cgi'> ";

    }
	else
	{
		eclairage.EclairageUnicolore::controleur.ihmParametre.set(eclairage.controleur.ent);
	}
	
}


#ifdef _UT_UcModifier_
int main()
{
	UcModifier ucModifier;
	cgicc::Cgicc cgi;

    // Envoi des headers HTTP
    std::cout << cgicc::HTTPHTMLHeader() << std::endl;

    // Début du document HTML
    std::cout << cgicc::html() << cgicc::head(cgicc::title("Modifier un eclairage")) << std::endl;
    std::cout << cgicc::body() << std::endl;

    // Récupération du type d'éclairage dans l'url (GET)
    cgicc::form_iterator type = cgi.getElement("type");
    cgicc::form_iterator id = cgi.getElement("id");

    if(type != cgi.getElements().end() && id != cgi.getElements().end())
    {
        std::string idd = **id;
        if(**type == "unicolore")
        {
            EclairageUnicolore eclairage;
            eclairage.controleur.ent.setID(atoi(idd.c_str()));
            ucModifier.doIt(eclairage, cgi);
        }
        else if(**type == "multicolore")
        {
            EclairageMulticolore eclairage;
            eclairage.controleur.ent.setID(atoi(idd.c_str()));
            ucModifier.doIt(eclairage, cgi);
        }
    }

    // Fermeture du document
    std::cout << cgicc::body() << cgicc::html();
	
	return 0;
}

#endif

//g++ -o /usr/lib/cgi-bin/UcModifier.cgi UcModifier.cpp Eclairage.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp SqlitePersiBny.cpp UcAjouter.cpp -lsqlite3 -lcgicc -I . -D _UT_UcModifier_