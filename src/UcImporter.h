/**
* \file UcImporter.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCIMPORTER_H
#define _UCIMPORTER_H

#include "Eclairage.h"

class UcGerer;

class UcImporter {
  public:
	void doIt(std::string fichierCSV, const UcGerer & ucGerer);


  private:
    void getFile();


  public:
    void ajouter(const Eclairage::Ent & eclairage, const UcGerer & ucGerer);


};
#endif
