/*****************************************************
 * Nom :JSONBny.cpp
 * AUteur : Haro Nathan
 * Date : 13/04/2018
 *******************************************************/
#include <jsoncpp/json/json.h>
#include "JSONBny.h"

JSONBny::JSONBny(){}

std::string JSONBny::serialiserUnicolore(int etat, int id){
  Json::Value root;
  root["demande"] = "fe";
  root["etat"] = etat;
  root["id"] = id;
  Json::Writer* writer;
  writer= new Json::StyledWriter();
  return writer->write(root);
}
