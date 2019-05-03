//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IHMJay.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
   	modbus = new Modbus();
	eventManagers = new CommEventManagerIHM(this);
	modbus->addEventManager(eventManagers);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::LaunchClick(TObject *Sender)
{
    modbus->writeWord(0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CloseClick(TObject *Sender)
{
   modbus->writeWord(0, 1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Send_RecetteClick(TObject *Sender)
{
   modbus->writeWord(5, 1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Raz_BtClick(TObject *Sender)
{
	modbus->writeWord(5, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Connect_AutomateClick(TObject *Sender)
{
	if (modbus->Connect("127.0.0.1", 502) == true )
	{
		Shape1->Brush->Color = clGreen;
		InfosClient->Lines->Add("\nClient connecté!");
	}
	else
	{
		Shape1->Brush->Color = clRed;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::AcquisitionTmp_BtClick(TObject *Sender)
{
   // InfosClient->Lines->Add()
}
//---------------------------------------------------------------------------

