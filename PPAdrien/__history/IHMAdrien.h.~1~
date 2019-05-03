//---------------------------------------------------------------------------

#ifndef IHMH
#define IHMH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "sql.h"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdContext.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TInterface : public TForm
{
__published:	// Composants gérés par l'EDI
	TEdit *txtIdRecette;
	TButton *BddConnect_Bt;
	TShape *EtatBdd;
	void __fastcall BddConnect_BtClick(TObject *Sender);
	void __fastcall ServerConnect(TIdContext *AContext);
	void __fastcall ServerExecute(TIdContext *AContext);

private:	// Déclarations utilisateur

public:		// Déclarations utilisateur
	__fastcall TInterface(TComponent* Owner);
	 Sql* Sql_1;
	 TIdTCPClient * client;
};
//---------------------------------------------------------------------------
extern PACKAGE TInterface *Interface;
//---------------------------------------------------------------------------
#endif
