//---------------------------------------------------------------------------

#ifndef IHMAdrienH
#define IHMAdrienH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "./Classes/sql.h"
#include "LecteurRFID.h"
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
__published:	// Composants g�r�s par l'EDI
	TEdit *txtIdRecette;
	TButton *BddConnect_Bt;
	TShape *EtatBdd;
	TLabel *Label1;
	TTimer *Timer1;
	TEdit *EdtTps1;
	TEdit *EdtTps2;
	TEdit *EdtTps3;
	TLabel *LblCreer;
	TButton *BtnCreer;
	TButton *BtnCreation;
	TEdit *EdtNom;
	TLabel *LblNom;
	void __fastcall BddConnect_BtClick(TObject *Sender);
	void __fastcall ServerConnect(TIdContext *AContext);
	void __fastcall ServerExecute(TIdContext *AContext);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall BtnCreerClick(TObject *Sender);
	void __fastcall BtnCreationClick(TObject *Sender);


private:	// D�clarations utilisateur

public:		// D�clarations utilisateur
	__fastcall TInterface(TComponent* Owner);
	 Sql* Sql_1;
	 LecteurRFID * lecteur;
	 TIdTCPClient * client;
};
//---------------------------------------------------------------------------
extern PACKAGE TInterface *Interface;
//---------------------------------------------------------------------------
#endif
