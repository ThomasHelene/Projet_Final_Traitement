//---------------------------------------------------------------------------

#ifndef PDFH
#define PDFH
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>

#include <vcl.h>
#include <windows.h>

#include "./share/litePDF.h"

#include <string.h>
#include <cstdlib>
#include <sstream>




class PDF
{
	private:
	 Variant vMSWord ,vWDocument,vWDocuments;


	public:
			PDF();

			~PDF();
			bool Rapport();
};


#endif