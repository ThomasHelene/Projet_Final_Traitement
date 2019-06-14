//---------------------------------------------------------------------------

#pragma hdrstop

#include "sql.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)

	bool Sql::OnConnect(string adress, string user,string mdp, string nameBDD){
			// Utiliser la librairie mysql pour se connecter
			bool etat;
			  if (!mysql_real_connect(mySQL, adress.c_str(), user.c_str(), mdp.c_str() , nameBDD.c_str(), 0, NULL, 0) == NULL)
			   {
					etat = true;

			   }
			   else
			   {
					etat = false;

			   }
			   return etat;
	}



	Recette Sql::GetRecette(int IdRecette){
			 Recette R1 ;
			 // utilise l'objet mysql de la librairie pour executer une requete
			 // R1 = new Recette(t1,T2,T3)

			 //3,6,5,1 viernt de la base
			// R1.creerRecette(3,6,5,1) ;

			 return R1;

	}


	Sql::Sql()
	{
		mySQL = new MYSQL();
		mySQL = mysql_init(NULL);



	}
	Sql::~Sql()
	{


	}

	bool Sql::CreerRecette()
	{
		std::string requete;

		 if(mysql_query(mySQL, "select * from testbcb"))
		 {
             return true;
		 }
		 else
		 {
             return false;
         }
	}
	bool Sql::SupprimerRecette()
	{

    }
