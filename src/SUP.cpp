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

void SUP::suivreConsoElectricite() {
}

int SUP::main()
{
	try
	{
		FichierTextePersiBny fichier("html/index.html");
		std::cout << fichier.getContenu();
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

//g++ -o SUP SUP.cpp -I . -D _UT_SUP_ -std=c++11 -w && rm SUP