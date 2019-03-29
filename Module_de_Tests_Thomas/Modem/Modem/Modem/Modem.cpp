#include "pch.h"
#include "Modem.h"


Modem::Modem()
{
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

	bool etat=Initialisation("0000");
	int i;
	for (i = 0; i < 10; i++)
	{
		bool etat2 = Rapport("Hey");
		Sleep(10000);
		if (etat2 == true)
		{
			printf("ok");
			
		}
	}


}


Modem::~Modem()
{
	CloseHandle(hComm);
}

bool Modem::Initialisation(std::string CodeSim)
{
	std::string commandePin;
	
	commandePin = "AT+CPIN=";
	commandePin += CodeSim;
	commandePin += "\r\n";
	DWORD dNoOFBytestoWrite = commandePin.length();         // No of bytes to write into the port
	DWORD dNoOfBytesWritten = 0;


	WriteFile(hComm,        // Handle to the Serial port
		commandePin.c_str(),     // Data to be written to the port
		dNoOFBytestoWrite,  //No of bytes to write
		&dNoOfBytesWritten, //Bytes written
		NULL);



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


	 dNoOFBytestoWrite = commande.length();         // No of bytes to write into the port
	 dNoOfBytesWritten = 0;

	return WriteFile(hComm,        // Handle to the Serial port
		commande.c_str(),     // Data to be written to the port
		dNoOFBytestoWrite,  //No of bytes to write
		&dNoOfBytesWritten, //Bytes written
		NULL);
}

bool Modem::Rapport(std::string Rapport)
{
	std::string commande;
	commande = " AT + CMGS =";
	commande += '"'; 
	commande += "+33665967182";
	commande += '"';
	commande+= ";\r\n";
	commande += Rapport;
	commande += 0x1A;
	

	DWORD dNoOFBytestoWrite = commande.length();         // No of bytes to write into the port
	DWORD dNoOfBytesWritten = 0;

	WriteFile(hComm,        // Handle to the Serial port
		commande.c_str(),     // Data to be written to the port
		dNoOFBytestoWrite,  //No of bytes to write
		&dNoOfBytesWritten, //Bytes written
		NULL);

	



	return true;

}