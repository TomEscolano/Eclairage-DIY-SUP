/*******************************************************
* \file UcRecevoirInfo.cpp.cpp
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <UcRecevoirInfo.h>


int main(int argc, char const *argv[])
{

    ServeurTcpComBny serveurTcpComBny;
    serveurTcpComBny.associer("192.168.140.61", 55555);
    serveurTcpComBny.ouvrir(50);

    while(true)
    {
	    TcpComBny tcpComBny(serveurTcpComBny.attendreClient());

	    char buf;
	    std::string message = "";
	    std::size_t nbRecu;

	    do{
	    	tcpComBny.recevoir(&buf, 1, nbRecu);
	    	message += buf;
		}while(buf != '\n');

		
	 	SqlitePersiBny persi("/var/eclairage/bdd.db");

	    Json::Value root;
	  	Json::Reader reader;
	  	reader.parse(message, root);

	  	std::string demande = root.get("demande","").asString();
		std::string valeur = root.get("valeur","").asString();
		std::string id = root.get("id","").asString();

	  	if(demande == "fe")
	  	{
	  		persi.executerSql("UPDATE eclairages SET allume = " + valeur + " WHERE id = " + id + ";");
	  		std::cout << id << valeur;
	  	}
	  	else if(demande == "fc")
	  	{
			persi.executerSql("UPDATE eclairages SET couleur = \"" + valeur + "\" WHERE id = " + id + ";");
	  	}
	 
	    tcpComBny.fermer();
	}
    serveurTcpComBny.fermer();

    return 0;
}

//{"demande":"fe","valeur":"1","id":"1"}
//g++ -o test UcRecevoirInfo.cpp ServeurTcpComBny.cpp TcpComBny.cpp  SqlitePersiBny.cpp -ljsoncpp -I . -std=c++11 -lsqlite3 -g