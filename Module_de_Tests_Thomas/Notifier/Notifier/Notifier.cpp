#include "pch.h"
#include "Notifier.h"


Notifier::Notifier(std::string Rapport, std::wstring ImageAcq, std::string Numero, std::string codeSim)
{
	_putws(L"Génération du PDF");
	GenererPDF(ImageAcq);
	_putws(L"Envoi du Sms au Client");
	EnvoiSms(Rapport, Numero, codeSim);

}


Notifier::~Notifier()
{
}

void Notifier::GenererPDF(std::wstring ImageAcq)
{
	pdf = new PDF(ImageAcq);
	
	EtatPdf= pdf->getEtat();
}
void Notifier::EnvoiSms(std::string Rapport, std::string Numero, std::string codeSim)
{
	modem = new Modem(Rapport, Numero, codeSim);

	EtatSms= modem->GetEtatRapport();

}
bool Notifier::GetEtatRapports()
{
	if (EtatPdf == true && EtatSms == true)
	{
		Etat = true;
	}
	else
	{
		Etat = false;
	}
	return Etat;
}