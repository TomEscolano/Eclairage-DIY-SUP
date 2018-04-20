/**
* \file UcMettreAJour.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <UcMettreAJour.h>
#include <ClientTcpComBny.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void UcMettreAJour::doIt(const std::string & adresseIP, const unsigned int & port)
{

	//ClientTcpComBny clientTCP;

	/*clientTCP.connecter(adresseIP, port);
	clientTCP.fprintf(this->firmware);
	clientTCP.deconnecter();*/

}


#ifdef NDEBUG
#endif