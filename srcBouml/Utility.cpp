/**
* \file Utility.cpp
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/

#include <regex>
#include <vector>
#include <fichierTextePersiBny.h>
#include <SqlitePersiBny.h>
#include <Utility.h>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>

#define DB "eclairage-DIY.db"

std::string Utility::remplacer(std::string nomFichier, std::vector<std::pair<std::string, std::string> >& conversion)
{
		FichierTextePersiBny fichier(nomFichier);
		std::string html = fichier.getContenu();
		for(auto p:conversion)
		{
			std::regex_replace (std::back_inserter(html), html.begin(), html.end(),std::regex (p.first),p.second);
		}
		return html;
}

void Utility::log_action(unsigned int id, std::string action, std::string value)
{
	SqlitePersiBny persi(DB);
	persi.executerSql("INSERT INTO logs VALUES(" + std::to_string(id) + ", " + action + ", " + value + ");");


}

void replaceAll(std::string& str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

Json::Value decodeJson(std::string toDecode)
{
	Json::Value root;   
    Json::Reader reader;
    bool parsingSuccessful = reader.parse( toDecode.c_str(), root );
    //std::cout << root.get("mykey", "A Default Value if not exists" ).asString() << std::endl;
}

#ifdef _UT_UTILITY_

int main(int argc, char const *argv[])
{
	
	return 0;
}

#endif