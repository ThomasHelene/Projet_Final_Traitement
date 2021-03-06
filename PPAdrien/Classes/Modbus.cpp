//---------------------------------------------------------------------------

#pragma hdrstop

#include "Modbus.h"
#include "TCP_Client.h"
#include "Communication.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	Modbus::Modbus()
	{
	comm = new TCP_Client();
	}

	Modbus::~Modbus()
	{
		delete comm;
	}

	void Modbus::addEventManager(CommEventManager * em)
	{
		comm->addEventManager(em);
	}

	bool Modbus::removeEventManager(CommEventManager * em)
	{
		comm->removeEventManager(em);
		return true;
	}

	//Trame Modbus permettant l'écriture
	void Modbus::writeWord(int word, int value)
	{
		char trame[12];
		trame[0] = 0x00;
		trame[1] = 0x00;
		trame[2] = 0x00;
		trame[3] = 0x00;
		trame[4] = 0x00;
		trame[5] = 0x06;
		trame[6] = 0x00;
		trame[7] = 0x06;
//		trame[8] = (word & 0xFF00) >> 8;
//		trame[9] = word & 0x00FF;
//		trame[10] = (value & 0xFF00) >> 8;
//		trame[11] = value & 0x00FF;

		trame[8] = (word & 0xFF00) >> 8;
		trame[9] = word & 0x00FF;
		trame[10] = (value & 0xFF00) >> 8;
		trame[11] = value & 0x00FF;

		comm->Send(trame, 12);   //Envoie de la trame
	}

	//Vérification de la connexion entre le PC Supervision et l'Automate
	bool Modbus::isConnected()
	{
		comm->isConnected();
		return true;
	}

	//Connexion entre le PC Supervision et l'Automate
	bool Modbus::Connect(std::string ip, int port)
	{
		String params = ip.c_str();
		params += ":";
        params += port;
		comm->Connect(params);
		return true;
    }

