/*******************************************************
Nom ......... : Modem.cpp
Role ........ : Permet l'envoi d'un Rapport via un SMS
Auteur ...... : Thomas Hélène


********************************************************/

#include "pch.h"
#include "Modem.h"

// Execute l'Intégralité de la Fonctionnalité
Modem::Modem(std::string Texte,std::string Numero)
{
	// Préparation du Handle pour la communication avec le Modem GSM
	hComm = CreateFile(L"COM1",
		GENERIC_READ | GENERIC_WRITE,
		0,
		0,
		OPEN_EXISTING,
		FILE_FLAG_NO_BUFFERING,
		0);

	GetCommState(hComm, &serie);
	serie.BaudRate = 9600;
	serie.ByteSize = 8;
	serie.Parity = NOPARITY;
	serie.StopBits = ONESTOPBIT;
	SetCommState(hComm, &serie);


	// On Insère le Code Pin
	bool etatInitialisation=Initialisation("0000");

	
	if (etatInitialisation == true)
	{
		printf("Code Pin inséré ! Emission du Rapport.\n\r");
		
		// On envoie le Rapport au numéro souhaité
		Rapport(Texte, Numero);
	

			

	
	}
	else
	{
		MessageBox(NULL, L" Mauvais Code Pin ou Modem non Connecté",L"Erreur Modem", 0x00000000L);
	}
	


}

// Arrete la Communication Avec le Modem
Modem::~Modem()
{
	CloseHandle(hComm);
}

// Prépare la carte Sim pour le Modem GSM
bool Modem::Initialisation(std::string CodeSim)
{

	// Préparation Commande AT pour rentrer le Code PIN
	std::string commandePin;
	commandePin = "AT+CPIN=";
	commandePin += CodeSim;
	commandePin += "\r\n";
	DWORD dNoOFBytestoWrite = commandePin.length();         
	DWORD dNoOfBytesWritten = 0;

	// Envoi en RS232 de la Commande
	WriteFile(hComm,      
		commandePin.c_str(),     
		dNoOFBytestoWrite, 
		&dNoOfBytesWritten, 
		NULL);



	// Préparation Commande AT pour bloquer le Code PIN afin de pouvoir réaliser les prochaines commandes
	std::string commande;
	commande = "AT+CLCK=";
	commande += '"';
	commande += "SC";
	commande += '"';
	commande += ",";
	commande += "0";
	commande += ",";
	commande += CodeSim;
	commande += "\r\n";


	// Envoi en RS232 de la Commande
	 dNoOFBytestoWrite = commande.length();         
	 dNoOfBytesWritten = 0;

	if(WriteFile(hComm,       
		commande.c_str(),     
		dNoOFBytestoWrite,  
		&dNoOfBytesWritten, 
		NULL))

	{
		return true;
	}
	else
	{
		return false;
	}

}

void Modem::Rapport(std::string Texte,std::string Numero)
{
	// Prépare la Commande AT pour l'envoi d'un SMS avec le numéro voulu et le texte voulu
	std::string commande;
	commande = " AT + CMGS =";
	commande += '"'; 
	commande += "+33";
	commande += Numero;
	commande += '"';
	commande+= ";\r\n";
	commande += Texte;
	commande += 0x1A;
	
	// Envoi en RS232 de la Commande
	DWORD dNoOFBytestoWrite = commande.length();         // No of bytes to write into the port
	DWORD dNoOfBytesWritten = 0;

	WriteFile(hComm,        // Handle to the Serial port
		commande.c_str(),     // Data to be written to the port
		dNoOFBytestoWrite,  //No of bytes to write
		&dNoOfBytesWritten, //Bytes written
		NULL);
	
	EtatRapport = true;
	


	



	

}

bool Modem::GetEtatRapport()
{
	return EtatRapport;
}