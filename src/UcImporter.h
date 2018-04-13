/**
* \file UcImporter.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCIMPORTER_H
#define _UCIMPORTER_H

#include <Eclairage.h>
#include <UcGerer.h>

class UcGerer;

class UcImporter {
  public:
	void doIt(std::string fichierCSV, const UcGerer & ucGerer);


  private:
    void getFile();
    UcGerer ucGerer;


  public:
    void ajouter(Eclairage::Ent & eclairage, UcGerer & ucGerer);


};
#endif
