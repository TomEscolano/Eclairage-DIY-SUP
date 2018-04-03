#include <TcpComBny.h>
#include <string>
#include <cstddef>
#include <cstdio>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

TcpComBny::TcpComBny(const int socketDesc) throw(TcpIpComBnyException): socketDesc(socketDesc) {
  if(this->socketDesc < 0) throw TcpIpComBnyException("no established connection");
  this->socketDescFile=fdopen(this->socketDesc,"a+");
  if(this->socketDescFile == nullptr) throw TcpIpComBnyException("no established connection");
}

TcpComBny::~TcpComBny() {
  this->fermer();
}

void TcpComBny::fermer() {
  if(this->socketDescFile != nullptr) {
	  fclose(this->socketDescFile);
	  this->socketDescFile=nullptr;
	  this->socketDesc = -1;
  }
  if(this->socketDesc != -1) {
    close(this->socketDesc);
    this->socketDesc = -1;
	this->socketDescFile=nullptr;
  }
}

void TcpComBny::recevoir(char* buffer, std::size_t size, std::size_t & count) throw(TcpIpComBnyException) {
  if (this->socketDesc == -1) throw TcpIpComBnyException("socket does not exist");
  count = recv(this->socketDesc , buffer , size , MSG_WAITALL);
  if (count == -1) throw TcpIpComBnyException("recv");
}

void TcpComBny::envoyer(const char* buffer, std::size_t size) throw(TcpIpComBnyException) {
  if (this->socketDesc == -1) throw TcpIpComBnyException("socket does not exist");
  int ctrl;
  ctrl = send(this->socketDesc , buffer , size , 0);
  if(ctrl != size) throw TcpIpComBnyException("send");
}

void TcpComBny::fscanf(const char* format, ...) {
	va_list args;
	va_start( args, format );
	this->fscanf(format, args);
	va_end( args );
}
void TcpComBny::fscanf(const char* format, va_list args) {
	if (this->socketDescFile == nullptr) throw TcpIpComBnyException("socket does not exist");
	::vfscanf(this->socketDescFile, format, args);
}


void TcpComBny::fprintf(const char* format, ...) {
	va_list args;
	va_start(args, format );
	this->fprintf(format, args);
	va_end( args );
}
void TcpComBny::fprintf(const char* format, va_list args) {
	if (this->socketDescFile == nullptr) throw TcpIpComBnyException("socket does not exist");
	::vfprintf(this->socketDescFile, format, args);
}