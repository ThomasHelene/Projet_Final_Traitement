//---------------------------------------------------------------------------

#ifndef CommEventManagerH
#define CommEventManagerH
//#include "IHM.h"

#include <string>

class CommEventManager
{

	virtual void onConnected() = 0;
	virtual void onDisconnected() = 0;
	virtual void onError(std::string errorMessage) = 0;

};

//---------------------------------------------------------------------------
#endif
