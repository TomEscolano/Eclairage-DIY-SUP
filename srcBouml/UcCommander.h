/**
* \file UcCommander.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCCOMMANDER_H
#define _UCCOMMANDER_H


class UcCommander {
  public:

    void allumer(Eclairage::Ent & ent, bool etat);

	void activer(Eclairage::Ent & ent, bool etat);

};
#endif
