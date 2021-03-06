/*******************************************************
* \file UcImporter.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCIMPORTER_H
#define _UCIMPORTER_H

#include <UcModifier.h>
#include <UcAjouter.h>
#include <SqlitePersiBny.h>
#include <Eclairage.h>
#include <csv.h> //https://github.com/banjocat/csv-cpp/
#include <new>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

using namespace cgicc;


class UcModifier;
class UcAjouter;
class SqlitePersiBny;

class UcImporter {
  public:
    /**
     * M�thode permettant d'importer dans la base de donn�es les configurations d'�clairages depuis un fichier au format CSV.
     */
    void doIt(UcModifier & ucModifier);


  private:
    /**
     * M�thode permettant de r�cup�rer le fichier � importer dans le syst�me
     */
    void getFile(const Cgicc& cgi);

    UcAjouter ucAjouter;

    public: UcModifier ucModifier;
};
#endif
