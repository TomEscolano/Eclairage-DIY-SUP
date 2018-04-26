/*******************************************************
* \file Utility.h
* \author Tom ESCOLANO

* \brief Projet : Eclairage DIY - SUP
*******************************************************/


#ifndef _UTILITY_H
#define _UTILITY_H

class Utility
{
	public : 
		/**
		 * Méthode permettant de remplacer des éléments HTML par une pair de données (utilisé pour les infos d'éclairages)
		 */
		static std::string remplacer(std::string, std::vector<std::pair<std::string, std::string> >& );
		
		/**
		 * Méthode permettant de loguer les actions d'un eclairage dans la table "logs" en lui indiquant l'ID de l'eclairage, son action et sa valeur
		 */
		static void log_action(unsigned int id, std::string, std::string);
};

#endif