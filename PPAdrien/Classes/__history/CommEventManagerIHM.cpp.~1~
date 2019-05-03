//---------------------------------------------------------------------------

#pragma hdrstop

#include "CommEventManagerIHM.h"
#include "IHM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	 CommEventManagerIHM::CommEventManagerIHM(TForm1 * ihm)
	 {
         this->ihm = ihm;
     }

	 void CommEventManagerIHM::onConnected()
	 {
		ihm->Brush->Color=clGreen;
	 }

	 void CommEventManagerIHM::onDisconnected()
	 {
		ihm->Brush->Color=clRed;
	 }

	 void CommEventManagerIHM::onError(std::string errorMessage)
	 {
		  int msgboxID = MessageBox(NULL, L"Error404", L"", MB_ICONWARNING | MB_OK);
	 }
