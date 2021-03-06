//---------------------------------------------------------------------------
// Dev mercier
// permet de communiquer avec la base de donn�e et de former les requet sdl
// V1 03/2019

#ifndef sqlH
#define sqlH
#include <iostream>
#include <system.hpp>
#include <string.h>
#include <vector>

#include <string.h>
#include <stdlib.h>
#include "recette.h"
#include <windows.h>
#include "./Classes/mysql.h"
using namespace std;

class Sql
{
	private:
         BDD * bdd;
	public:

	//Construteur destructeur
	Sql();
	~Sql();

	//Se connecter � la base via la lib mysql
	bool OnConnect(string adress, string user,string mdp, string nameBDD);
	//envoie   d'une requet et forme un objet de type recette
	Recette GetRecette(std::string NomRecette);
	bool CreerRecette(std::string temps1,std::string temps2,std::string temps3,std::string CodeRfid,std::string Nom);
	bool SupprimerRecette(string NomRecette);
	  vector< vector<std::string> > GetNomRecettes();
	  bool MajRecette(recette r2);






};
//---------------------------------------------------------------------------
#endif
