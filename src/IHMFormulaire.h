/*****************************************************
* \file IHMFormulaire.h
* \Author Tom ESCOLANO


\brief Projet : Eclairage DIY
*******************************************************/

#ifndef ECLAIRAGE_IHMFORMULAIRE_H
#define ECLAIRAGE_IHMFORMULAIRE_H


namespace Eclairage { class Ent; } 

namespace Eclairage {

class IHMFormulaire {
  public:
    void set(const Ent & ent);

    void get(Ent & ent);

};

} // namespace Eclairage
#endif
