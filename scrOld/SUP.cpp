/**
* \file SUP.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <SUP.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <FichierTextePersiBny.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

void SUP::suivreConsoElectricite() {
}

int SUP::main()
{

	std::string html;

	std::cout << cgicc::HTTPHTMLHeader() << std::endl;

	try
	{

		//Recuperation du template de la page
		FichierTextePersiBny fichier("html/index.html");

		//Debut de la page HTML
		std::cout << fichier.getContenu();

		//Extractions des eclairages/infos
		std::pair<std::string, std::string> infos;
		
		this->ucGerer.afficherEclairages(this->ucGerer.extraireEclairagesMulticolores(), this->ucGerer.extraireEclairagesUnicolores());

		//Remplacement des données dans le fichier
		//Utility::Remplacer(html, infos);

		//Fin de la page HTML
		std::cout << "</body></html>";


	}catch(std::exception &e)
	{
		std::cout << "Erreur dans la lecture de l'index";
	}
	
}


#ifdef _UT_SUP_

int main(int argc, char const *argv[])
{
	SUP sup;
	sup.main();

	return 0;
}

#endif

//g++ -o SUP SUP.cpp SqlitePersiBny.cpp FichierTextePersiBny.cpp UcGerer.cpp Utility.cpp -lsqlite3 Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp -lcgicc -I . -D _UT_SUP_ -std=c++11 -w