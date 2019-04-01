// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "PDF.h"




int main()
{
    std::cout << "Hello World!\n"; 
	PDF * test;
	test = new PDF(L"E:\\kermit.jpg");
	bool etat = test->getEtat();
	
	if (etat==true)
	{
		delete test;
	}
	else
	{
		MessageBox(NULL, L"Erreur, le fichier PDF n'as pas été créer !", L"Erreur Programme", 0x00000030L);
	}
}

