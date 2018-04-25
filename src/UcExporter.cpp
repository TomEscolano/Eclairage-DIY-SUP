/******************************************************
* \file UcExporter.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "UcExporter.h"
#include <iostream>

void UcExporter::doIt()
{
	std::cout << cgicc::HTTPHTMLHeader() << cgicc::HTMLDoctype(cgicc::HTMLDoctype::eStrict) << std::endl;
	
	system("sqlite3 -header -csv /var/eclairage/bdd.db \"SELECT e.id,allume,active,nom,consommation,x,y,couleur,numeroPrise FROM eclairages e INNER JOIN unicolores u ON u.id = e.id;\" > /var/www/html/eclairages_unicolores_save.csv");
	system("sqlite3 -header -csv /var/eclairage/bdd.db \"SELECT e.id,allume,active,nom,consommation,x,y,adresseMac,adresseIP, versionFirmware, couleur,luminosite,niveauBatterie FROM eclairages e INNER JOIN multicolores m ON m.id = e.id;\" >  /var/www/html/eclairages_multicolores_save.csv");

	std::cout <<  "<iframe width='1' height='1' frameborder='0' src='/eclairages_multicolores_save.csv'></iframe>" << std::endl;
	std::cout <<  "<iframe width='1' height='1' frameborder='0' src='/eclairages_unicolores_save.csv'></iframe>" << std::endl;
	std::cout << " <meta http-equiv='refresh'content='2; URL=/cgi-bin/'> " << std::endl;

	system("rm *.csv");
}


#ifdef _UT_UcExporter_
int main()
{
	UcExporter ucExporter;
	ucExporter.doIt();

	return 0;
}
#endif

//g++ -o UcExporter.cgi UcExporter.cpp -I . -D _UT_UcExporter_