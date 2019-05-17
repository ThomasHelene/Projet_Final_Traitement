#pragma once
#include <string>
#include "Modem.h"
#include "PDF.h"
class Notifier
{
public:
	Notifier(std::string Rapport,std::wstring ImageAcq,std::string Numero, std::string codeSim);

	~Notifier();
	bool GetEtatRapports();

private:
	void GenererPDF(std::wstring ImageAcq);
	void EnvoiSms(std::string Rapport,std::string Numero, std::string codeSim);
	PDF * pdf;
	Modem* modem;
	bool Etat;
	bool EtatPdf, EtatSms;
};

