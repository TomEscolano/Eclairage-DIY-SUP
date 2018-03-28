/**
* \file Utility.h
* \author Tom ESCOLANO

\brief Projet : Eclairage DIY - SUP
*******************************************************/


#ifndef _UTILITY_H
#define _UTILITY_H

class Utility
{
	public : 
		static std::string remplacer(std::string, std::vector<std::pair<std::string, std::string> >& );
		static void log_action(unsigned int id, std::string, std::string);
};

#endif