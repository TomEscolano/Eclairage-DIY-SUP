/**
* \file UcCommander.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#ifndef _UCCOMMANDER_H
#define _UCCOMMANDER_H


class UcCommander {
  public:
    /*void getSelection();

    void afficherMenuSelection();

    void getAction();

    void execAction();

    void enregistrer();*/
    void allumer(Eclairage::Ent & ent, bool etat);

	void activer(Eclairage::Ent & ent, bool etat);

};
#endif
