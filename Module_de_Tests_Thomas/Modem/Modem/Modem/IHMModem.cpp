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
	char numero[100];
	int i;

	printf("Entrez un numero valide \n ", numero);
	scanf_s("%s", &numero);
	char numero1[100];
	for (i = 1; i < strlen(numero); i++)
	numero1[i-1] = numero[i];
	numero1[i-1] = '\0'; numero1[i] = '\0';
	printf("%s \n", numero1);
	
	// Appels de ma Classe
	Modem test("exemple",numero1,"0000");
	if (test.GetEtatRapport() == true)
	{
		printf("Message Envoyé . Vous pouvez fermer cette fenêtre \n\r");
	}
	else
	{
		MessageBox(NULL, L"Rapport Non envoyé, relancez"
			, L"Erreur Modem", 0x00000000L);
	}
}
