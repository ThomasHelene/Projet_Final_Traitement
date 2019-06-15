//---------------------------------------------------------------------------

#ifndef CommEventManagerIHMH
#define CommEventManagerIHMH
#include "IHMJay.h"
#include <vcl.h>
#include <string>
#include <windows.h>
#include "CommEventManager.h"


class TForm1;

class CommEventManagerIHM : public CommEventManager
{
	private:

	TForm1 * ihm;

	public:

	CommEventManagerIHM(TForm1 * ihm);
	 void onConnected();
	 void onDisconnected();
	 void onError(std::string errorMessage);

};

//---------------------------------------------------------------------------
#endif
