//---------------------------------------------------------------------------
// Dev mercier
// permet de communiquer avec la base de donn�e et de former les requet sdl
// V1 03/2019

#ifndef sqlH
#define sqlH

#include <string.h>
#include <iostream>
#include <string>
#include "recette.h"
#include "./include/mysql.h"
using namespace std;

class Sql
{
	private:
//	Sql *sql1;
	 MYSQL *mySQL;


	public:

	//Construteur destructeur
	Sql();
	~Sql();

	//Se connecter � la base via la lib mysql
	bool OnConnect(string adress, string user,string mdp, string nameBDD);
	//envoie   d'une requet et forme un objet de type recette
	Recette GetRecette(int IdRecette);


	void ReConnect();

};
//---------------------------------------------------------------------------
#endif