//---------------------------------------------------------------------------

#ifndef IHMH
#define IHMH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include "Modbus.h"
#include "CommEventManagerIHM.h"
#include "Communication.h"
#include "CommEventManager.h"
#include "TCP_Client.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class CommEventManagerIHM;

class TForm1 : public TForm
{
__published:	// Composants g�r�s par l'EDI
	TShape *Shape1;
	TButton *Connect_Automate;
	TGroupBox *Sender;
	TButton *Launch;
	TButton *Close;
	TButton *Send_Recette;
	TButton *Raz_Bt;
	TGroupBox *GroupBox1;
	TShape *Shape_Etat1;
	TShape *Shape_Etat2;
	TShape *Shape_Etat3;
	TShape *Shape_Etat5;
	TMemo *InfosClient;
	TButton *AcquisitionTmp_Bt;
	void __fastcall Raz_BtClick(TObject *Sender);
	void __fastcall LaunchClick(TObject *Sender);
	void __fastcall CloseClick(TObject *Sender);
	void __fastcall Send_RecetteClick(TObject *Sender);
	void __fastcall Connect_AutomateClick(TObject *Sender);
	void __fastcall AcquisitionTmp_BtClick(TObject *Sender);
private:
Modbus * modbus;
CommEventManagerIHM * eventManagers;

	// D�clarations utilisateur
public:	// D�clarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
