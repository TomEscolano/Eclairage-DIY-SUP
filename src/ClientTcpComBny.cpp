#include <cstdarg>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <ClientTcpComBny.h>
#include <TcpComBny.h>


ClientTcpComBny::ClientTcpComBny(): tcpComBny(NULL) {
}
ClientTcpComBny::~ClientTcpComBny() {
  this->deconnecter();
}
void ClientTcpComBny::connecter(std::string ip, unsigned short int port) throw(TcpIpComBnyException) {
  if(this->tcpComBny != NULL) this->tcpComBny->fermer();
  int socketDesc = socket(AF_INET , SOCK_STREAM , 0) ;
  if(socketDesc == -1) throw TcpIpComBnyException("socket");
  struct sockaddr_in adresseServeur ;
  int ctrl;
  bzero((char*) &adresseServeur, sizeof(adresseServeur));
  adresseServeur.sin_family = AF_INET;
  adresseServeur.sin_port = htons(port);
  ctrl = inet_aton (ip.c_str() , &adresseServeur.sin_addr);
  if(ctrl == 0 ) throw TcpIpComBnyException("inet_aton");
  ctrl = connect( socketDesc , (struct sockaddr*) &adresseServeur , sizeof(adresseServeur));
  if(ctrl != 0) throw TcpIpComBnyException("connect");
  this->tcpComBny = new TcpComBny(socketDesc);
}
void ClientTcpComBny::deconnecter(void) {
  if(this->tcpComBny != NULL) {
    delete this->tcpComBny;
    this->tcpComBny = NULL;
  }
}
void ClientTcpComBny::recevoir(char* buffer, std::size_t size, std::size_t & count) throw(TcpIpComBnyException) {
  if(this->tcpComBny == NULL)  throw TcpIpComBnyException("no established connection");
  this->tcpComBny->recevoir( buffer,  size, count);
}
void ClientTcpComBny::envoyer(const char* buffer, std::size_t size) throw(TcpIpComBnyException) {
  if(this->tcpComBny == NULL) throw TcpIpComBnyException("no established connection");
  this->tcpComBny->envoyer(buffer, size);
}
void ClientTcpComBny::fscanf(const char* format, ...) {
	if(this->tcpComBny == NULL)  throw TcpIpComBnyException("no established connection");
	va_list args;
	va_start(args,format);
	this->tcpComBny->fscanf(format,args);
	va_end(args);
}
void ClientTcpComBny::fprintf(const char* format, ...) {
	if(this->tcpComBny == NULL)  throw TcpIpComBnyException("no established connection");
	va_list args;
	va_start(args,format);
	this->tcpComBny->fprintf(format,args);
	va_end(args);
}