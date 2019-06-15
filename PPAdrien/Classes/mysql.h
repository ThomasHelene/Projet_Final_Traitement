 #include <string.h>
  #include <vector>

  #include "./include/mysql.h"
#ifndef mysqlH
#define mysqlH
using namespace std;
class BDD
{
public:
		 BDD();
		 ~BDD();
		 bool Connexion(string adresse, string user,string mdp, string BDD);
 bool insert(std::string requete);
  vector< vector<std::string> > select(std::string requete);

  private:

      	 MYSQL *sql;

};

//---------------------------------------------------------------------------
#endif