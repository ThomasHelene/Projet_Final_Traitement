//---------------------------------------------------------------------------

#ifndef recetteH
#define recetteH
#include <vector>
#include <string.h>


typedef struct Recette
{
	int idRecette;
	int idRfid;
	int t1;
	int t2;
	int t3;
	std::string nom;
	std::string RFID;

}recette;
//---------------------------------------------------------------------------
#endif
