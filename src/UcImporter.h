/*******************************************************
* \file UcImporter.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCIMPORTER_H
#define _UCIMPORTER_H

#include "UcModifier.h"
#include "UcAjouter.h"
#include "SqlitePersiBny.h"
#include "Eclairage.h"
#include "csvReader.h"
//https://github.com/ben-strasser/fast-cpp-csv-parser
#include <new>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

using namespace cgicc;


class UcModifier;
class UcAjouter;
class SqlitePersiBny;

class UcImporter {
  public:
    /**
     * Méthode permettant d'importer dans la base de données les configurations d'éclairages depuis un fichier au format CSV.
     */
    void doIt(UcModifier & ucModifier);


  private:
    void getFile(const Cgicc& cgi);

    UcAjouter ucAjouter;

    public: UcModifier ucModifier;
};
#endif
