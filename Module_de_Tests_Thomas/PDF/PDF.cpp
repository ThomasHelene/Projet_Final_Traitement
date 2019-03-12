//---------------------------------------------------------------------------

#pragma hdrstop

#include "PDF.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)

PDF::PDF()
{

try
{
  vMSWord = Variant::GetActiveObject("Word.Application");
}
catch(...)
{
  vMSWord = Variant::CreateObject("Word.Application");
}
vMSWord.OlePropertySet("Visible", true); // ("Visible", false)
// ici on ouvre le document avec une feuille vierge
vWDocument = vMSWord.OlePropertyGet("Documents").OleFunction("Add");




}




PDF::~PDF()
{
	   WideString vFileName;
       //Enregistre le fichier au format PDF
	vFileName = L"E:\\exemple.pdf";
	vWDocument.OleProcedure("SaveAs2", vFileName,17);





 //Lance un script pour terminer tous les processus Word
ShellExecuteA(NULL, "open", "e:\\script.bat", NULL, NULL, SW_NORMAL);


}
bool PDF::Rapport()
{
	 // Centre le Pointeur
	vMSWord.OlePropertyGet("Selection").OlePropertyGet("ParagraphFormat").OlePropertySet("Alignment", 1);
	// Change la Taille de la police
	vMSWord.OlePropertyGet("Selection").OlePropertyGet("Font").OlePropertySet("Size",32);

	// Change la couleur du texte au rouge
	vMSWord.OlePropertyGet("Selection").OlePropertyGet("Font").OlePropertySet("ColorIndex", 6);

	// Ins�re le Titre
	 vMSWord.OlePropertyGet("Selection").OleFunction("TypeText", WideString( "Rapport d'erreur "));


	 // Ins�re une Ligne
	vMSWord.OlePropertyGet("Selection").OlePropertyGet("inLineShapes").OleFunction("AddHorizontalLineStandard");

	// Change la Taille de la police
	vMSWord.OlePropertyGet("Selection").OlePropertyGet("Font").OlePropertySet("Size",18);

	// Change la couleur du texte au noir
	vMSWord.OlePropertyGet("Selection").OlePropertyGet("Font").OlePropertySet("ColorIndex", 0);

	 // Aligne le pointeur vers la gauche
	vMSWord.OlePropertyGet("Selection").OlePropertyGet("ParagraphFormat").OlePropertySet("Alignment", 0);

	// Ins�re du Texte
	 vMSWord.OlePropertyGet("Selection").OleFunction("TypeText", WideString( "Un probl�me a �t� rep�r� sur la pi�ce suivante :"));


	 //Ins�re l'Image
	vMSWord.OlePropertyGet("Selection").OlePropertyGet("inLineShapes").OleFunction("AddPicture",WideString("e:\\ex.png"));

}

