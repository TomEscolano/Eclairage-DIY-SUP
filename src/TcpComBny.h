#ifndef _TCPCOMBNY_H
#define _TCPCOMBNY_H

#include <cstdarg>

#include <TcpIpComBnyException.h>

class TcpComBny {
  public:
    TcpComBny(const int) throw(TcpIpComBnyException);
    ~TcpComBny();
    void recevoir(char*  buffer, std::size_t  size, std::size_t & count) throw(TcpIpComBnyException);
    void fscanf(const char* format, ...);
    void fscanf(const char* format, va_list args);
    void envoyer(const char*  buffer,  std::size_t  size) throw(TcpIpComBnyException);
    void fprintf(const char* format, ...);
    void fprintf(const char* format, va_list args);
    void fermer();
  private:
    int socketDesc;
    FILE * socketDescFile;
};

#endif

