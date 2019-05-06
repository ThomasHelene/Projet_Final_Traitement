//---------------------------------------------------------------------------

#include "ufCoder.h"
#include "vcl.h"
#ifndef LecteurRFIDH
#define LecteurRFIDH
//---------------------------------------------------------------------------
#endif



class LecteurRFID {

public :
String yolo;
		 LecteurRFID();
		 ~LecteurRFID();
		 void Ouverture();
		 int Lecture();

};