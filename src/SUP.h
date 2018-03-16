/**
* \file SUP.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _SUP_H
#define _SUP_H


#include "UcGerer.h"
#include "UcExporter.h"
#include "UcImporter.h"

class UcExporter;
class UcImporter;

class SUP {
  public:
    void suivreConsoElectricite();

    int main();


  private:
    UcExporter ucExporter;

    UcImporter ucImporter;

    UcGerer ucGerer;

};
#endif
