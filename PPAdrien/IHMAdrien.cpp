//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IHMAdrien.h"
#include "sql.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TInterface *Interface;
//---------------------------------------------------------------------------
__fastcall TInterface::TInterface(TComponent* Owner)
	: TForm(Owner)
{
	Sql_1 = new Sql();

	lecteur = new LecteurRFID();
	client = new TIdTCPClient();
	 lecteur->Ouverture();


}
//---------------------------------------------------------------------------
void __fastcall TInterface::BddConnect_BtClick(TObject *Sender)
{
	// si la connexion se passe bien
	if(Sql_1->OnConnect("192.168.64.111","pharma","pharma","traitement") == true){
		EtatBdd->Brush->Color = clLime;
	}else
	{
		EtatBdd->Brush->Color = clRed;

	}


}

void __fastcall TInterface::ServerConnect(TIdContext *AContext)
{
String requete="DIO";
int i;

//ServerInfos->Lines->Add("Serveur connect�!");
//ServerInfos->Lines->Add("L'addresse ip du client est :");
//ServerInfos->Lines->Add(AContext->Binding->PeerIP);
//ServerInfos->Lines->Add("L'addresse du port du client est :");
//ServerInfos->Lines->Add(AContext->Binding->PeerPort);
//	if(i==0)
//	{
//	 client->Host="192.168.64.124";
//			client->Port=60100;
//			client->Connect();
//	}
//while(AContext->Connection->Socket->Connected()==true)
//{
//requete=AContext->Connection->Socket->ReadLn();
//ServerInfos->Lines->Add(requete);


//	if(requete=="Cloche1")                     //Si la requete envoy� est cloche1 on active la petite cloche
//	{
//
//		unsigned char msg= 0x08;
//		trame->activation(msg,client);
//		trame->retourMarteau(client);
//
//	}
//	if(requete=="Cloche2")
//	{
//
//
//		unsigned char msg=0x04;
//		trame->activation(msg,client);
//		trame->retourMarteau(client);
//
//	}

//	  i=1;
//	  }
//
//
//	AContext->Connection->IOHandler->WriteLn("Termin�");
//	AContext->Connection->Disconnect();
//	i=0;
}

//---------------------------------------------------------------------------

void __fastcall TInterface::ServerExecute(TIdContext *AContext)
{
	//ServerInfos->Lines->Add("Le serveur a re�u");
}
//---------------------------------------------------------------------------


void __fastcall TInterface::Timer1Timer(TObject *Sender)
{
	Label1->Caption=lecteur->Lecture();
}
//---------------------------------------------------------------------------

