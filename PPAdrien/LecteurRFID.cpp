//---------------------------------------------------------------------------
#pragma hdrstop

#include "LecteurRFID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	   LecteurRFID::LecteurRFID()
	   {
              Ouverture();
	   }

	   LecteurRFID::~LecteurRFID()
	   {

	   }
	   void LecteurRFID::Ouverture()
	   {
       uint32_t reader_type, reader_sn;
			  if(ReaderOpen())                                       //v�rifie si le lecteur est connect�
				{

                    yolo=L"Pas co";
				}
				if(GetReaderType(&reader_type))
				{
					 yolo=L"Pas co";
				}
				if(GetReaderSerialNumber(&reader_sn))
				{
				 yolo=L"Pas co";
				}

				else
				{
                     yolo=L"co";
                }
	   }

	   int LecteurRFID::Lecture()
	   {

       }