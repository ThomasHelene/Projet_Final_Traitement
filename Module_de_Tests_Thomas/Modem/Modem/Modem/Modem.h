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
	bool Rapport(std::string Rapport);
public:
	Modem();
	~Modem();
};

