/*******************************************************
* \file UcExporter.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCEXPORTER_H
#define _UCEXPORTER_H


#include "SqlitePersiBny.h"

class UcExporter {
  public:
    /**
     * M�thode permettant d'exporter toutes les configurations d'�clairages vers un fichier CSV et de le faire t�l�charger au propri�taire depuis son navigateur WEB.
     */
    void doIt();


  private:
    SqlitePersiBny persiBny;

};
#endif
