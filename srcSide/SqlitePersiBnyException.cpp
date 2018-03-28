#include <SqlitePersiBnyException.h>

#ifndef NDEBUG
#ifdef SqlitePersiBnyException_Ut_
#include <cassert>
#include <iostream>
/*
g++ -o SqlitePersiBnyExceptionUt -I. -g -D SqlitePersiBnyException_Ut_ SqlitePersiBnyException.cpp -l sqlite3 \
&& ./SqlitePersiBnyExceptionUt;rm SqlitePersiBnyExceptionUt

g++ -c  SqlitePersiBnyException.cpp -I. -DNDEBUG 
   */
int main(int argc, char **argv) {

  try { 
    throw SqlitePersiBnyException("sqlite3_prepare_v2",SQLITE_OPEN_CREATE);
  } catch (std::exception& e) {
    std::string resultat(std::string("SqlitePersiBnyException\n\tsqlite3_prepare_v2 : ")+sqlite3_errstr(SQLITE_OPEN_CREATE));
    //std::cout << e.what() << std::endl;
    //std::cout << resultat << std::endl;
    assert(std::string(e.what()) ==resultat);
  }
}
#endif
#endif

