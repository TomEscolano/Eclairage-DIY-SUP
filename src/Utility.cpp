/*******************************************************
* \file Utility.cpp
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <FichierTextePersiBny.h>
#include <SqlitePersiBny.h>
#include <Utility.h>
#include <iostream>

void Utility::log_action(unsigned int id, std::string action, std::string value)
{
	SqlitePersiBny persi("/var/eclairage/bdd.db");
	persi.executerSql("INSERT INTO logs VALUES(" + std::to_string(id) + ", \"" + action + "\", \"" + value + "\");");

}

#ifdef _UT_UTILITY_

int main(int argc, char const *argv[])
{
	
	return 0;
}

#endif