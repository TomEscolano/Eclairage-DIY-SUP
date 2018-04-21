#ifndef _TCPIPCOMBNYEXCEPTION_H_
#define _TCPIPCOMBNYEXCEPTION_H_
#include <string>
#include <exception>

class TcpIpComBnyException : public std::exception{
  private:
    std::string message;
 public:
    TcpIpComBnyException( const std::string description) : std::exception(){
      this->message="TcpIpComBnyException\n\t"+description+"\n";
    }
    const char* what() const throw() {
      return this->message.c_str();
    }
    virtual ~TcpIpComBnyException() throw() {}
};
#endif
