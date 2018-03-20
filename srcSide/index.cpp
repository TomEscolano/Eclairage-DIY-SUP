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
      //cgicc::Cgicc cgi;

      // Envoi du header HTTP
      std::cout << cgicc::HTTPHTMLHeader() << std::endl;

      // Generation du document HTML
      std::cout << cgicc::html() << std::endl << cgicc::head() << std::endl <<
         cgicc::title("Superviseur") << std::endl <<
         cgicc::link().set("rel","stylesheet").set("href", "http://localhost/css/w3.css") << std::endl <<
         cgicc::link().set("rel","stylesheet").set("href", "https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css") << std::endl <<
         cgicc::link().set("rel","stylesheet").set("href", "http://localhost/css/style.css") << std::endl <<
      cgicc::head() << std::endl;

      std::cout << cgicc::body() << std::endl;

      // Contenu du body
      // Bar de navigation
      std::cout << cgicc::div().set("class", "w3-bar w3-bar-grey") << std::endl <<
         cgicc::a().set("class", "w3-bar-item w3-button w3-mobile w3-blue").set("style", "width:50%;") << 
            cgicc::i().set("class", "fa fa-home").set("style", "font-size:35px;") << cgicc::i() << 
         cgicc::a() << std::endl <<
         cgicc::a().set("class", "w3-bar-item w3-button w3-mobile").set("style", "width:50%;") << 
            cgicc::i().set("class", "fa fa-bars").set("style", "font-size:35px;") << cgicc::i() << 
         cgicc::a() << std::endl <<
      cgicc::div() << std::endl;

      // Image de la maison
      std::cout << cgicc::img().set("src", "http://localhost/img/t.png") << cgicc::img() << std::endl;

      // Fermeture du document HTML
      std::cout << cgicc::body() << cgicc::html();
   }
   catch(std::exception& e) {
      // Gestion des erreurs
   }
}