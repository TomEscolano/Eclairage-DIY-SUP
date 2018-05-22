/*******************************************************
* \file Utility.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/


#ifndef _UTILITY_H
#define _UTILITY_H

#include <vector>

class Utility
{
	public : 
		/**
		 * Méthode permettant de loguer les actions d'un eclairage dans la table "logs" en lui indiquant l'ID de l'eclairage, son action et sa valeur
		 */
		static void log_action(unsigned int id, std::string, std::string);
};

#endif