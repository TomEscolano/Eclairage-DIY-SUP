/**
* \file UcMettreAJour.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCMETTREAJOUR_H
#define _UCMETTREAJOUR_H


#include <string>

class UcMettreAJour {
  private:
    FILE firmware;

  public:
    void doIt(const std::string & adresseIP, const unsigned int & port);

};
#endif
