
#pragma hdrstop

#include "mysql.h"






//---------------------------------------------------------------------------
#pragma package(smart_init)



	BDD::BDD()
	{
        this->sql = new MYSQL();
		mysql_init(this->sql);
	}
	BDD::~BDD()
	{
        mysql_close(this->sql);
	}
	bool BDD::Connexion(string adresse, string user,string mdp, string BDD)
	{
        	bool etat;
			  if (!mysql_real_connect(this->sql, adresse.c_str(), user.c_str(), mdp.c_str() , BDD.c_str(), 0, NULL, 0))
			   {
					etat = false;

			   }
			   else
			   {
					etat = true;

			   }
			   return etat;
	}
  vector<vector<std::string> > BDD::select(std::string requete)
  {
     std::vector< std::vector<string> > RequestResult;

		MYSQL_RES *res; /* holds the result set */
		MYSQL_ROW row;
		int NbCol=0;

		mysql_query(this->sql,requete.c_str());
		res = mysql_store_result(this->sql);
		int rows = mysql_num_rows(res);
		//RequestResult.resize(rows);
		NbCol =  mysql_num_fields(res);

		while ((row = mysql_fetch_row(res))) {
			std::vector<string> copie;
		   for(int x = 0; x < NbCol; x++)
		   {
			   if(row[x] != NULL)
			   {
					copie.push_back(row[x]);
			   }
		   }

		   RequestResult.push_back(copie);
		   //copie.clear();
		}
		if(res != NULL)
		mysql_free_result(res);

        return RequestResult;
  }

  bool BDD::insert(std::string requete)
  {
	int  etat;

	 etat=mysql_query(this->sql,requete.c_str());

		 if(etat==0)
		 {
             return true;
		 }
		 else
		 {
             return false;
		 }
  }

