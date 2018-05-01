/******************************************************
* \file UcAjouter.cpp
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <UcAjouter.h>

void UcAjouter::doIt(EclairageUnicolore & eclairage, cgicc::Cgicc & cgi)
{
    SqlitePersiBny persi("/var/eclairage/bdd.db");
    SqlitePersiBny::Resultat resultat;

    cgicc::form_iterator nom = cgi.getElement("nom");
    cgicc::form_iterator couleur = cgi.getElement("couleur");
    cgicc::form_iterator id = cgi.getElement("id");

    // Si le nom et la couleur sont donnés
    if(nom != cgi.getElements().end() && couleur != cgi.getElements().end() && id != cgi.getElements().end())
    {     
        // Insertion de l'éclairage dans la BDD, si non existant   
        try
        {
            persi.executerSql("INSERT INTO eclairages(id, nom, couleur) VALUES(" + **id + ", \"" + **nom + "\", " + **couleur + ");");
        }catch(...)
        {
        }
        // Si un numero de prise est présent
        cgicc::form_iterator numeroPrise = cgi.getElement("numeroPrise");
        if(numeroPrise != cgi.getElements().end())
        {
            // Insertion de l'éclairage unicolore dans la BDD
            persi.executerSql("INSERT INTO unicolores(id,numeroPrise) VALUES(" + **id + ", " + **numeroPrise + ");");
            std::cout << "<p>Creation terminee !</p>";
            std::cout << "<meta http-equiv='refresh' content='2; URL=/cgi-bin/index.cgi'> ";
        }
        else
        {
            // Si le nom et la couleur sont présents
            // Affichage du formulaire unicolore
            eclairage.EclairageUnicolore::controleur.ihmFormulaire.set(eclairage.controleur.ent, **nom, **couleur, **id);
        }
    }
    else
    {
        // Si aucune info n'est donnée
        // Création de l'ID en fonction du dernier ID et affichage du formulaire eclairage
        try
        {
            persi.executerSql("select seq from sqlite_sequence;", resultat);   
            eclairage.controleur.ent.setID(atoi(resultat.at(0).at(0).second.c_str())+1);
        }
        catch(...)
        {
            eclairage.controleur.ent.setID(0);
        }        
        
        eclairage.Eclairage::controleur.ihmFormulaire.set(eclairage.controleur.ent, "unicolore");
    }
}

void UcAjouter::doIt(EclairageMulticolore & eclairage, cgicc::Cgicc & cgi)
{
    SqlitePersiBny persi("/var/eclairage/bdd.db");
    SqlitePersiBny::Resultat resultat;

    cgicc::form_iterator nom = cgi.getElement("nom");
    cgicc::form_iterator couleur = cgi.getElement("couleur");
    cgicc::form_iterator id = cgi.getElement("id");

    // Si le nom et la couleur sont donnés
    if(nom != cgi.getElements().end() && couleur != cgi.getElements().end() && id != cgi.getElements().end())
    {     
        // Insertion de l'éclairage dans la BDD, si non existant   
        try
        {
            persi.executerSql("INSERT INTO eclairages(id, nom, couleur) VALUES(" + **id + ", \"" + **nom + "\", " + **couleur + ");");
        }catch(...)
        {
        }
        // Si un numero de prise est présent
        cgicc::form_iterator adresseIP = cgi.getElement("adresseIP");
        if(adresseIP != cgi.getElements().end())
        {
            // Insertion de l'éclairage multicolore dans la BDD
            persi.executerSql("INSERT INTO multicolores(id,adresseIP) VALUES(" + **id + ", \"" + **adresseIP + "\");");
            std::cout << "<p>Creation terminee !</p>";
            std::cout << "<meta http-equiv='refresh' content='2; URL=/cgi-bin/index.cgi'> ";
        }
        else
        {
            // Si le nom et la couleur sont présents
            // Affichage du formulaire multicolore
            eclairage.EclairageMulticolore::controleur.ihmFormulaire.set(eclairage.controleur.ent, **nom, **couleur, **id);
        }
    }
    else
    {
        // Si aucune info n'est donnée
        // Création de l'ID en fonction du dernier ID et affichage du formulaire eclairage
        try
        {
            persi.executerSql("select seq from sqlite_sequence;", resultat);   
            eclairage.controleur.ent.setID(atoi(resultat.at(0).at(0).second.c_str())+1);
        }
        catch(...)
        {
            eclairage.controleur.ent.setID(0);
        }        
        
        eclairage.Eclairage::controleur.ihmFormulaire.set(eclairage.controleur.ent, "multicolore");
    }
}


#ifdef _UT_UcAjouter_
int main()
{
	UcAjouter ucAjouter;
    cgicc::Cgicc cgi;

    // Envoi des headers HTTP
    std::cout << cgicc::HTTPHTMLHeader() << std::endl;

    // Début du document HTML
    std::cout << cgicc::html() << cgicc::head(cgicc::title("Ajouter un eclairage")) << std::endl;
    std::cout << cgicc::body() << std::endl;

    // Récupération du type d'éclairage dans l'url (GET)
    cgicc::form_iterator type = cgi.getElement("type");

    if(type != cgi.getElements().end())
    {
        if(**type == "unicolore")
        {
            EclairageUnicolore eclairage;
            ucAjouter.doIt(eclairage, cgi);
        }
        else if(**type == "multicolore")
        {
            EclairageMulticolore eclairage;
            ucAjouter.doIt(eclairage, cgi);
        }
    }

    // Fermeture du document
    std::cout << cgicc::body() << cgicc::html();

	return 0;
}
#endif

//g++ -o /usr/lib/cgi-bin/UcAjouter.cgi UcAjouter.cpp Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcAjouter_