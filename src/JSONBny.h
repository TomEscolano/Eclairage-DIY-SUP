#ifndef _JSONSERIALIZE_H_
#define _JSONSERIALIZE_H_
/*!
 * \file JSONBny.h
 * \brief Projet EclairageDIY
 * \author Haro Nathan
 * \date 03 mai 2018
 */
#include <string>
#include <sstream>

/*! \class JSONBny
 * \brief classe gérant le format json
 *
 *  Classe permettant de serialiser et déserialiser des informations sous le format json
 */
class JSONBny{
  private:

  public:
  
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe JSONBny
     */  
    JSONBny();
  
    std::string serialiserUnicolore(int etat, int id);

};
#endif


