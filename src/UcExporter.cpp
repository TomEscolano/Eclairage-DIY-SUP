/******************************************************
* \file UcExporter.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "UcExporter.h"
#include <iostream>

void UcExporter::doIt()
{
	system("sqlite3 -header -csv /var/eclairage/bdd.db \"select * from eclairages, multicolores, unicolores;\" > eclairages_save.csv");
	std::cout <<  "<a href='eclairages_save.csv' download>Fichier de sauvegarde</a>" << std::endl;
}


#ifdef _UT_UcExporter_
int main()
{
	return 0;
}
#endif
