/**
* \file SUP.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include <SUP.h>

void SUP::suivreConsoElectricite() {
}

int SUP::main() {
}


#ifdef _UT_SUP_

int main(int argc, char const *argv[])
{
	SUP sup;
	
	return 0;
}

#endif

 // g++ -o Eclairage Eclairage.cpp SqlitePersiBny.cpp UcCommander.cpp Utility.cpp  -I . -lsqlite3 -D NDEBUG -std=c++11 -w && rm Eclairage