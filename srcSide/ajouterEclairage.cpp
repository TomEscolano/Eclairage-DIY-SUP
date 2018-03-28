#include <iostream>
#include <vector>
#include <string>

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

int main(int argc, char **argv)
{
   try
   {
      cgicc::Cgicc cgi;

      cgicc::form_iterator x = cgi.getElement("x");
      cgicc::form_iterator y = cgi.getElement("y");


      // Envoi du header HTTP
      std::cout << cgicc::HTTPHTMLHeader() << std::endl;

      // Generation du document HTML
      std::cout << cgicc::html() << std::endl << cgicc::head() << std::endl <<
         cgicc::title("Ajouter eclairage") << std::endl <<
         cgicc::link().set("rel","stylesheet").set("href", "http://localhost/css/w3.css") << std::endl <<
         cgicc::link().set("rel","stylesheet").set("href", "https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css") << std::endl <<
         //cgicc::link().set("rel","stylesheet").set("href", "http://localhost/css/style.css") << std::endl <<
         cgicc::style(".w3-card-4{text-align:center;width:75%;margin: auto; margin-top:5%;}") << std::endl <<
      cgicc::head() << std::endl;

      std::cout << cgicc::body() << std::endl;

      // Contenu du body
      // Formulaire d'ajout
      std::cout << cgicc::div().set("class", "w3-card-4") << std::endl <<
         cgicc::header().set("class", "w3-container w3-blue") << std::endl <<
            cgicc::h1("Ajouter un eclairage") << std::endl <<
         cgicc::header() << std::endl <<
         "<div class='w3-container'>" <<
            cgicc::form().set("action", "process.cgi").set("method", "post") << std::endl <<
            cgicc::br() << std::endl <<
               cgicc::h2("Type:") << std::endl <<
               cgicc::select().set("name", "typeEclairage") << std::endl <<
               cgicc::option().set("value", "unicolore") << "Unicolore" << cgicc::option() << std::endl <<
               cgicc::option().set("value", "multicolore") << "Multicolore" << cgicc::option() << std::endl <<
            cgicc::select() << std::endl <<
            cgicc::h2("Nom:") << std::endl <<
            cgicc::input().set("name", "nom").set("value", "") << std::endl <<

            cgicc::input().set("type", "hidden").set("name", "x").set("value", **x) << std::endl <<
            cgicc::input().set("type", "hidden").set("name", "y").set("value", **y) << std::endl <<

            cgicc::form() << std::endl <<
            cgicc::br() << std::endl <<
         "</div>" << std::endl <<
         cgicc::footer().set("class", "w3-container w3-blue") << std::endl <<
            cgicc::input().set("type", "submit").set("style", "background-color:transparent;border:none;padding:10px;color:white;") << std::endl <<
         cgicc::footer() << std::endl <<
         cgicc::div();

      // Fermeture du document HTML
      std::cout << cgicc::body() << cgicc::html();
   }
   catch(std::exception& e) {
      // Gestion des erreurs
   }
}