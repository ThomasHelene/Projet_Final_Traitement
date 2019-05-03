//---------------------------------------------------------------------------

#pragma hdrstop

#include "TCP_Client.h"
#include "IHMJay.h"
#include "StringUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

  //Permet la connexion entre le PC Supervision et le PC Méthode
  void TCP_Client::Connect(String params)
  {

   std::vector<std::string> res = StringUtils::explode(StringUtils::convertStr(params), ':');
   int port = atoi(res[1].c_str());
   Client = new TIdTCPClient();
   Client->Connect(res[0].c_str(), port);

  }

  //Permet la vérification de la connexion
  bool TCP_Client::isConnected()
  {
	Client->IOHandler->Connected();
	return true;
  }


  char* TCP_Client::Receive(int size)
  {
	Client->IOHandler->ReadLn();
	return 0;
  }

  //Permet d'envoyer le caractère hexadecimal Modbus
  bool TCP_Client::Send(char * buffer, int size)
  {
	for(int i = 0; i < size; i++)
	{
        unsigned char c = buffer[i];
		Client->IOHandler->Write(c);
	}
	return true;
  }

  //Permet la déconnexion du Client
  void TCP_Client::Disconnect()
  {
   Client->IOHandler->Close();
  }


