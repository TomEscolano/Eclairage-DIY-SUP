/*******************************************************
* \file UcImporter.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCIMPORTER_H
#define _UCIMPORTER_H


class UcGerer;
class UcAjouter;
class SqlitePersiBny;

class UcImporter {
  public:
    /**
     * Méthode permettant d'importer dans la base de données les configurations d'éclairages depuis un fichier au format CSV.
     */
    void doIt(const FILE & fichierCSV, const UcGerer & ucGerer);


  private:
    void getFile();

    <UcAjouter> ucAjouter;

    <SqlitePersiBny> persiBny;

};
#endif
