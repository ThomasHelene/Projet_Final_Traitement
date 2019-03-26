#include "pch.h"
#include "PDF.h"

#pragma endregion

PDF::PDF()
{
	

	
	hThread = CreateThread(NULL, 0,  Rapport,this, 0, NULL);
	WaitForSingleObject(hThread, INFINITE);
	
	

}


PDF::~PDF()
{
	
	CloseHandle(hThread);
	
}

  DWORD WINAPI PDF::Rapport(LPVOID lpParam)
{
	
	 CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	 try
	 {
		 PDF * pdf = ((PDF*)lpParam);
		
		 // On créer une instance Word

		 Word::_ApplicationPtr spWordApp;

		 HRESULT hr = spWordApp.CreateInstance(__uuidof(Word::Application));
		 if (FAILED(hr))
		 {
			 wprintf(L"CreateInstance failed w/err 0x%08lx\n", hr);
			 return 1;
		 }

		 _putws(L"Word.Application is started");


		 /////////////////////////////////////////////////////////////////////
		 // Cache Word. (i.e. Application.Visible = 0)
		 // 

		 spWordApp->Visible = VARIANT_FALSE;


		 /////////////////////////////////////////////////////////////////////
		 // Créer un nouveau document. (i.e. Application.Documents.Add)
		 // 

		 Word::DocumentsPtr spDocs = spWordApp->Documents;
		 Word::_DocumentPtr spDoc = spDocs->Add();

		 _putws(L"A new document is created");


		 /////////////////////////////////////////////////////////////////////
		 // Insère du Texte dans le document et une image
		 // 

		 _putws(L"Insert a paragraph");

		 Word::ParagraphsPtr spParas = spDoc->Paragraphs;
		 Word::ParagraphPtr spPara = spParas->Add();
		 Word::RangePtr spParaRng = spPara->Range;

		 spParaRng->Text = _bstr_t(L"Rapport d'erreur de Production");
		 spPara->Alignment = Word::wdAlignParagraphCenter;
		 Word::_FontPtr spFont = spParaRng->Font;
		 spFont->Underline = Word::wdUnderlineDash;

		 spFont->Bold = 1;
		 spFont->Size = 24;


		 spParaRng->InsertParagraphAfter();
		 spParaRng->ParagraphFormat->Space2();
		 spParaRng->ParagraphFormat->Space2();
		 spPara->Alignment = Word::wdAlignParagraphLeft;
		 spPara = spParas->Add();
		 spParaRng = spPara->Range;

		 spParaRng->Text = _bstr_t(L"Une pièce a été jugée défectueuse par la caméra , voici une image de la pièce en question:");
		 spFont = spParaRng->Font;
		 spFont->Size = 14;
		 spFont->Bold = 1;
		 spParaRng->InsertParagraphAfter();



		 variant_t Left = 100;
		 variant_t Top = 250;
		 variant_t Width = 300;
		 variant_t Height = 300;
		 variant_t left = 100;
		 spDoc->Shapes->AddPicture(_bstr_t(L"E:\\kermit.jpg"), &vtMissing, &vtMissing, &Left, &Top, &Width, &Height, &vtMissing);

		 







		 /////////////////////////////////////////////////////////////////////
		 // Sauvegarde le document comme un PDF
		 // 

		 _putws(L"Save and close the document");

		 //Fais le nom du Fichier

		 // Obtiens le répertoire de l'executable.
		 wchar_t szFileName[MAX_PATH];
		 if (!PDF::GetDossier(szFileName, ARRAYSIZE(szFileName)))
		 {
			 _putws(L"GetModuleDirectory failed");
			 return 1;
		 }

		 // Concaténe le nom du fichier à l'adresse du fichier
		 wcsncat_s(szFileName, ARRAYSIZE(szFileName), L"Sample1.pdf", 12);






		 Word::WdExportFormat format;
		 format = Word::wdExportFormatPDF;
		 Word::WdExportOptimizeFor Opti;
		 Opti = Word::wdExportOptimizeForOnScreen;
		 Word::WdExportRange range;
		 range = Word::WdExportRange::wdExportAllDocument;
		 Word::WdExportItem item;
		 item = Word::WdExportItem::wdExportDocumentContent;
		 Word::WdExportCreateBookmarks bookmark;
		 bookmark = Word::WdExportCreateBookmarks::wdExportCreateHeadingBookmarks;


		 spDoc->ExportAsFixedFormat(szFileName, format, false, Opti, range, 0, 0, item, true, false, bookmark, false, false, false, &vtMissing);
		 //delete v;

		 variant_t Savechanges;
		 Savechanges = 0;
		 spDoc->Close(&Savechanges, &vtMissing, &vtMissing);


		 /////////////////////////////////////////////////////////////////////
		 // Ferme Word
		 // 

		 _putws(L"Quit the Word application");
		 spWordApp->Quit();
		 pdf->Etat = true;

		 


		 /////////////////////////////////////////////////////////////////////
		 // Libère les objets COM .
		 // 

		

	 }
	 catch (_com_error &err)
	 {
		 wprintf(L"Word throws the error: %s\n", err.ErrorMessage());
		 wprintf(L"Description: %s\n", (LPCWSTR)err.Description());
		 
	 }

	 
	 CoUninitialize();

	 return true;
}

DWORD PDF::GetDossier(LPWSTR pszDir, DWORD nSize)
{

	nSize = GetModuleFileName(NULL, pszDir, nSize);
	if (!nSize || GetLastError() == ERROR_INSUFFICIENT_BUFFER)
	{
		*pszDir = L'\0'; 
		return 0;
	}



	for (int i = nSize - 1; i >= 0; i--)
	{
		if (pszDir[i] == L'\\' || pszDir[i] == L'/')
		{
			pszDir[i + 1] = L'\0';
			nSize = i + 1;
			break;
		}
	}
	return nSize;
}

bool PDF::getEtat()
{
	return Etat;
}