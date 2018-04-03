#ifndef _SQLITEPERSIBNYEXCEPTION_H_
#define _SQLITEPERSIBNYEXCEPTION_H_
#include <string>
#include <exception>
#include <sqlite3.h>//sqlite3
class SqlitePersiBnyException :  public std::exception  {
  private:
    int code;
    std::string message;
  public:
    SqlitePersiBnyException(const std::string  description, int code) : std::exception(){
      this->message="SqlitePersiBnyException\n\t"+description+" : "+sqlite3_errstr(code);
    }
    const char* what() const throw() {
      return this->message.c_str();
    }
    virtual ~SqlitePersiBnyException() throw() {}
};
#endif /* SQLITEPERSIBNYEXCEPTION_H_ */
