#ifndef _FICHIERTEXTEPERSIBNY_H
#define _FICHIERTEXTEPERSIBNY_H

#include <fstream>
#include <sstream>
#include <iostream>
class FichierTextePersiBny: public std::fstream {
	private:
		std::string nomFichier;
		std::string contenu;
	public:
		FichierTextePersiBny(const char* nomFichier): 
			std::fstream(nomFichier),nomFichier(nomFichier) { }
		FichierTextePersiBny(const std::string nomFichier): 
			std::fstream(nomFichier.c_str()),nomFichier(nomFichier) { }
		FichierTextePersiBny(): std::fstream(){}
		~FichierTextePersiBny(){this->close();}

		//void open(const char* fileName){std::fstream::open(fileName);}
		template <typename T> FichierTextePersiBny& operator<<(const T& data){
			*(std::fstream*)this << data << ' ';
			return *this;
		}
		template <typename T>FichierTextePersiBny& operator>>(T&  data){ 
			*(std::fstream*)this >> data ; 
			return *this; 
		}
		std::string getNomFichier() const{ 
			return this-> nomFichier;
		}
		std::string getContenu() {
			std::stringstream buffer;
			buffer << this->rdbuf();
			return buffer.str(); 
		}
};
#endif
