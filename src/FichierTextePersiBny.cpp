#include "FichierTextePersiBny.h"
#ifndef NDEBUG
#ifdef FichierTextePersiBny_Ut_
#include <cassert>
#include <string>
/*
 g++ -o FichierTextePersiBnyUt  FichierTextePersiBny.cpp -D FichierTextePersiBny_Ut_ -g3  -std=c++14 && ./FichierTextePersiBnyUt;rm FichierTextePersiBnyUt.*;
 g++ -c FichierTextePersiBny.cpp -DNDEBUG
 */
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#define NOM_FICHIER "FichierTextePersiBnyUt.txt"  
#define INT_ECRIT 10
#define FLOAT_ECRIT (float)2.77
#define CHAR_ECRIT 'e'
#define STRING_ECRIT "nom"
int main(int argc, char** argv) {
	int intLu=0;
	float floatLu=0.0;
	char charLu='\0';
	std::string stringLu="";
	system("rm " NOM_FICHIER "> /dev/null");
	system("touch " NOM_FICHIER);
	/**/
	{
		//FichierTextePersiBny fichierTextePersiBny(NOM_FICHIER);
		FichierTextePersiBny fichierTextePersiBny;
		fichierTextePersiBny.open(NOM_FICHIER);
		fichierTextePersiBny << INT_ECRIT << FLOAT_ECRIT << CHAR_ECRIT << STRING_ECRIT;
	}
	/**/
	/**/
	FichierTextePersiBny fichierTextePersiBny;
	fichierTextePersiBny.open(NOM_FICHIER);
	fichierTextePersiBny >> intLu >> floatLu >> charLu >> stringLu;
	//std::cout << intLu << " *** "  << floatLu << " *** " << charLu << " *** " << stringLu <<  std::endl;
	/**/
	assert(intLu == INT_ECRIT);
	assert(floatLu == FLOAT_ECRIT);
	assert(charLu == CHAR_ECRIT);
	assert(stringLu == STRING_ECRIT);
	/**/
	return 0;
}
#endif
#endif

