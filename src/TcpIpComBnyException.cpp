/******************************************************************
 * Auteurs:
 *   Frédéric Sutre (Frederic-Albert.Sutre@ac-nice.fr)
 *   Eric Valade (Eric.Valade@ac-nice.fr)
 * LGT Les Eucalyptus - Nice
 * Section de technicien supérieur
 * Systèmes Numériques option Informatique et réseau (SN-IR)
 * $Id: TcpIpComBnyException.cpp 133 2016-03-03 17:21:00Z eric $
 * $HeadURL: svn://buffalo500/IrisDesignPattern/trunk/Model/ComBnyBase/sansHeritageNiCatalogue/TcpIpComBnyException.cpp $
 ******************************************************************/
#include "TcpIpComBnyException.h"

#ifndef NDEBUG
#ifdef TcpIpComBnyException_Ut_
#include <cassert>
#include <iostream>
/*
g++ -o TcpIpComBnyExceptionUt -g -D TcpIpComBnyException_Ut_ TcpIpComBnyException.cpp \
&& ./TcpIpComBnyExceptionUt;rm TcpIpComBnyExceptionUt
g++ -c  TcpIpComBnyException.cpp -DNDEBUG 
   */
int main(int argc, char **argv) {

  try {
    throw TcpIpComBnyException("sendto");
  } catch (std::exception& e) {
    std::string resultat("TcpIpComBnyException\n\tsendto\n");
    assert(std::string(e.what()) ==resultat);
  }
}
#endif
#endif
