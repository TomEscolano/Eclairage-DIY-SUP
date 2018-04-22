/******************************************************
* \file EclairageUnicolore.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#include "EclairageUnicolore.h"

void EclairageUnicolore::Ent::setNumeroPrise(int num)
{
	this->numeroPrise = num;
}

int EclairageUnicolore::Ent::getNumeroPrise()
{
	return this->numeroPrise;
}


#ifdef _UT_EclairageUnicolore_
int main()
{
	EclairageUnicolore eclairage;


	return 0;
}
#endif
