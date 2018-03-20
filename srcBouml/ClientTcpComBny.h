#ifndef _CLIENTTCPCOMBNY_H
#define _CLIENTTCPCOMBNY_H

#include <string>
#include <cstdarg>
#include <TcpIpComBnyException.h>

class TcpComBny;
class ClientTcpComBny {
  public:
    ClientTcpComBny();
    ~ClientTcpComBny();
    void connecter(std::string ip, unsigned short int port) throw(TcpIpComBnyException);
    void recevoir(char*  buffer, std::size_t  size, std::size_t & count) throw(TcpIpComBnyException);
    void fscanf(const char* format, ...);
    void envoyer(const char*  buffer,  std::size_t  size) throw(TcpIpComBnyException);
    void fprintf(const char* format, ...);
    void deconnecter(void);

  private:
    TcpComBny* tcpComBny;
};
#endif

