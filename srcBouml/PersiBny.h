/*****************************************************
* \file PersiBny.h
* \Author Tom ESCOLANO


\brief Projet : Eclairage DIY
*******************************************************/

#ifndef _PERSIBNY_H
#define _PERSIBNY_H


class Cycle;

class PersiBny {
  private:
    sqlite3 db;


  public:
    void set(const Cycle & cycle);

    void get(Cycle & cycle);

};
#endif
