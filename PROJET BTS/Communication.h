//---------------------------------------------------------------------------

#ifndef CommunicationH
#define CommunicationH
#include "Modbus.h"
#include "CommEventManager.h"
#include <string>
#include <vector>
#include <iostream>
#include <vcl.h>

class Communication
{
	protected:
	std::vector<CommEventManager*> eventManager;

	public:

	void addEventManager(CommEventManager * em);
	bool removeEventManager(CommEventManager * em);
	virtual void Connect(String params) = 0;
	virtual bool isConnected() = 0;
	virtual char * Receive(int size) = 0;
	virtual bool Send(char * buffer, int size) = 0;
	virtual void Disconnect() = 0;

};
//---------------------------------------------------------------------------
#endif