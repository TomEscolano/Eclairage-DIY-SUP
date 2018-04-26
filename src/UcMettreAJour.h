/*******************************************************
* \file UcMettreAJour.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCMETTREAJOUR_H
#define _UCMETTREAJOUR_H


#include <string>
#include <ClientTcpComBny.h>

class UcMettreAJour {
  private:
    FILE firmware;

  public:
    /**
     * Méthode permettant de mettre à jour le micrologiciel d'un éclairage multicolore.
     */
    void doIt(const std::string & adresseIP, const unsigned int & port);


  private:
    ClientTCPComBny clientTcp;

};
#endif
