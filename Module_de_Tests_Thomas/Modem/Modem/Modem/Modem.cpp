/*******************************************************
Nom ......... : Modem.cpp
Role ........ : Permet l'envoi d'un Rapport via un SMS
Auteur ...... : Thomas H�l�ne


********************************************************/

#include "pch.h"
#include "Modem.h"

// Execute l'Int�gralit� de la Fonctionnalit�
Modem::Modem(std::string Texte,std::string Numero)
{
	// Pr�paration du Handle pour la communication avec le Modem GSM
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


	// On Ins�re le Code Pin
	bool etatInitialisation=Initialisation("0000");
	int i;
	
	if (etatInitialisation == true)
	{
		printf("Code Pin ins�r� ! Emission du Rapport.\n\r");
		
		// On envoie le Rapport au num�ro souhait�
		bool EtatRapport = Rapport(Texte, Numero);
		
		if (EtatRapport == true)
		{
			printf("Rapport Envoy� . Vous pouvez fermer cette fen�tre \n\r");

		}
	}
	


}

// Arrete la Communication Avec le Modem
Modem::~Modem()
{
	CloseHandle(hComm);
}

// Pr�pare la carte Sim pour le Modem GSM
bool Modem::Initialisation(std::string CodeSim)
{

	// Pr�paration Commande AT pour rentrer le Code PIN
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



	// Pr�paration Commande AT pour bloquer le Code PIN afin de pouvoir r�aliser les prochaines commandes
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

bool Modem::Rapport(std::string Texte,std::string Numero)
{
	// Pr�pare la Commande AT pour l'envoi d'un SMS avec le num�ro voulu et le texte voulu
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

	if (WriteFile(hComm,        // Handle to the Serial port
		commande.c_str(),     // Data to be written to the port
		dNoOFBytestoWrite,  //No of bytes to write
		&dNoOfBytesWritten, //Bytes written
		NULL))
	{
		return true;
	}
	else
	{
		return false;
	}

	



	

}