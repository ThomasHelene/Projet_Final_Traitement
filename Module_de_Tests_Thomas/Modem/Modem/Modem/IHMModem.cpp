/*******************************************************
Nom ......... : IHMModem.h
Role ........ : Appelle la Classe Modem et l'utilise .
Auteur ...... : Thomas Hélène


********************************************************/

#include "pch.h"
#include <iostream>
#include "Modem.h"

int main()
{
	Modem test("exemple","648579166");
	if (test.GetEtatRapport() == true)
	{
		printf("Rapport Envoyé . Vous pouvez fermer cette fenêtre \n\r");
	}
	else
	{
		MessageBox(NULL, L"Rapport Non envoyé, relancez", L"Erreur Modem", 0x00000000L);
	}

	
	
  
}
