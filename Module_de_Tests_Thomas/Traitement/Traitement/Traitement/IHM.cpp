// Traitement.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"

#include "Traitement.h"

int main()
{
	int i;
	Traitement * Traitement1;
	Traitement1 = new Traitement("E:\\ImageReference.jpg", "E:\\ImageAquise.jpg");
	std::vector <double> Resultat1;
	std::vector <double> Resultat2;
	Resultat1 = Traitement1->GetResultatsRef();
	Resultat2 = Traitement1->GetResultatsAcq();
	for (i = 0; i < 4; i++)
	{
		printf("Methode [%i], %f,%f \n", i, Resultat1[i], Resultat2[i]);
	}
	waitKey();
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
