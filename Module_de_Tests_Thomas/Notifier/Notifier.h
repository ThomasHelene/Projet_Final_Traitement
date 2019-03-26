//---------------------------------------------------------------------------

#ifndef NotifierH
#define NotifierH
//---------------------------------------------------------------------------
  #include <string.h>
  #include <vcl.h>
 class Notifier
 {
	 private:
	   String MessageErreur;


	 public:

	 Notifier();
	 ~Notifier();

	 virtual bool Rapport()=0;
	 void GetMessageErreur(String Erreur);




 };





#endif
