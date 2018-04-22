/******************************************************
* \file SUP.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "SUP.h"
#include "EclairageUnicolore.h"
#include "EclairageMulticolore.h"
#include "Eclairage.h"

void SUP::visualiserInfo(const Ent & eclairage) {
}

void SUP::extraireEclairages(const sqlite3 & bdd, std::vector<EclairageUnicolore> & eclairagesUnicolores, std::vector<EclairageMulticolore> & eclairagesMulticolores) {
}

void SUP::suivreConsoElectricite() {
}

void SUP::doIt() {
}


#ifdef _UT_SUP_
int main()
{
	return 0;
}
#endif
