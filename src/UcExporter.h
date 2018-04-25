/*******************************************************
* \file UcExporter.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCEXPORTER_H
#define _UCEXPORTER_H

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

class UcExporter {
  public:
    /**
     * Méthode permettant d'exporter toutes les configurations d'éclairages vers un fichier CSV et de le faire télécharger au propriétaire depuis son navigateur WEB.
     */
    void doIt();


};
#endif
