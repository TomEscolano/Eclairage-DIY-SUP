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
      cgicc::form_iterator type = cgi.getElement("type");
      cgicc::form_iterator nom = cgi.getElement("nom");



      // Envoi du header HTTP
      std::cout << cgicc::HTTPHTMLHeader() << std::endl;

      // Generation du document HTML
      std::cout << cgicc::html() << std::endl << cgicc::head() << std::endl <<
         cgicc::title("Veuillez patienter...") << std::endl <<
         cgicc::link().set("rel","stylesheet").set("href", "http://localhost/css/w3.css") << std::endl <<
         cgicc::link().set("rel","stylesheet").set("href", "https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css") << std::endl <<
         //cgicc::link().set("rel","stylesheet").set("href", "http://localhost/css/style.css") << std::endl <<
         //cgicc::style(".w3-card-4{text-align:center;width:75%;margin: auto; margin-top:5%;}") << std::endl <<
      cgicc::head() << std::endl;

      std::cout << cgicc::body() << std::endl;

      // Contenu du body
      std::cout << "Nom de l'aclairage: " << **nom;
      std::cout << "Type de l'aclairage: " << **type;
      std::cout << "x: " << **x;
      std::cout << "y: " << **y;

      

      // Fermeture du document HTML
      std::cout << cgicc::body() << cgicc::html();
   }
   catch(std::exception& e) {
      // Gestion des erreurs
   }
}