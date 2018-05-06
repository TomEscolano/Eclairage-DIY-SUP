#include <TcpIpComBnyException.h>

#ifdef NDEBUG
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
