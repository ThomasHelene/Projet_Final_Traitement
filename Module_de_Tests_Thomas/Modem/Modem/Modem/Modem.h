
/*******************************************************
Nom ......... : Modem.h
Role ........ : Permet l'envoi d'un Rapport via un SMS
Auteur ...... : Thomas H�l�ne


********************************************************/

#pragma once
#include <string>
#include <stdlib.h>
#include <windows.h>


class Modem
{
private:
	HANDLE hComm;
	DCB serie;
	OVERLAPPED over;

	bool Initialisation(std::string CodeSim);
	bool Rapport(std::string Rapport,std::string Numero);
public:
	Modem(std::string Texte,std::string Numero);
	~Modem();
};

