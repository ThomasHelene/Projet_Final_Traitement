//---------------------------------------------------------------------------

#pragma hdrstop

#include "Communication.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)

	//Permet la gestion d'évènements, (gestions d'erreurs notamment)
	void Communication::addEventManager(CommEventManager * em)
	{
        eventManager.push_back(em);
	}

    //Retirer la gestion d'évènements
	bool Communication::removeEventManager(CommEventManager * em)
	{
		bool bFound;

		std::vector<CommEventManager*>::iterator it = std::find(eventManager.begin(), eventManager.end(), em);

		if(bFound = (it != eventManager.end()))
			eventManager.erase(it);

		return bFound;
	}
