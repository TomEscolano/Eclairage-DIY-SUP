/******************************************************
* \file UcAjouter.cpp
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <UcAjouter.h>

void UcAjouter::doIt(EclairageUnicolore & eclairage, cgicc::Cgicc & cgi)
{
    cgicc::form_iterator nom = cgi.getElement("nom");
    cgicc::form_iterator couleur = cgi.getElement("couleur");

    // Si le nom et la couleur sont donnés
    if(nom != cgi.getElements().end() && couleur != cgi.getElements().end())
    {
        SqlitePersiBny persi("/var/eclairage/bdd.db");
     
        // Insertion de l'éclairage dans la BDD, si non existant   
        try
        {
            persi.executerSql("INSERT INTO eclairages(nom, couleur) VALUES(\"" + **nom + "\", " + **couleur + ");");
        }catch(...)
        {
        }
        // Si un numero de prise est présent
        cgicc::form_iterator numeroPrise = cgi.getElement("numeroPrise");
        if(numeroPrise != cgi.getElements().end())
        {
            // Récuperation de l'ID
            SqlitePersiBny::Resultat res;
            persi.executerSql("SELECT id FROM eclairages WHERE nom = \"" + **nom + "\";", res);

            // Insertion de l'éclairage unicolore dans la BDD
            persi.executerSql("INSERT INTO unicolores(id,numeroPrise) VALUES(" + res.at(0).at(0).second + ", " + **numeroPrise + ");");
            std::cout << "<p>Creation terminee !</p>";
            std::cout << "<meta http-equiv='refresh' content='2; URL=/cgi-bin/index.cgi'> ";
        }
        else
        {
            // Si le nom et la couleur sont présents
            // Affichage du formulaire unicolore
            eclairage.EclairageUnicolore::controleur.ihmFormulaire.set(eclairage.controleur.ent, **nom, **couleur);
        }
    }
    else
    {
        // Si aucune info n'est donnée
        // Affichage du formulaire eclairage
        eclairage.Eclairage::controleur.ihmFormulaire.set(eclairage.controleur.ent, "unicolore");
    }
}

void UcAjouter::doIt(EclairageMulticolore::Ent & ent, cgicc::Cgicc & cgi)
{
    /*
	SqlitePersiBny persiBny(this->DB);
	persiBny.executerSql("INSERT INTO multicolores(id, adresseMac, adresseIP, versionFirmware, luminosite, niveauBatterie) VALUES(" + std::to_string(ent.getID()) + ", \"" + ent.getAdresseMac() + "\", \"" + ent.getAdresseIP() + "\", " + std::to_string(ent.getVersionFirmware()) + ", " + std::to_string(ent.getLuminosite()) + ", " + std::to_string(ent.getNiveauBatterie()) + ");"); 
    */
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
            ucAjouter.doIt(eclairage, cgi)
        }
    }

    // Fermeture du document
    std::cout << cgicc::body() << cgicc::html();

	return 0;
}
#endif

//g++ -o /usr/lib/cgi-bin/UcAjouter.cgi UcAjouter.cpp Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcAjouter_