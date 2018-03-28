/**
* \file UcExporter.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "UcExporter.h"
#include "SqlitePersiBny.h"

FILE UcExporter::doIt()
{
	std::string requete = "INSERT * from eclairages";
	SqlitePersiBny::resultat resultat;
	
	int code_retour = persiBny.executerSql(requete, resultat&);

}


#ifdef NDEBUG

#endif
#endif