//---------------------------------------------------------------------------

#ifndef ModbusH
#define ModbusH

#include <string>


class Communication;
class CommEventManager;

class Modbus
{

	private:

	Communication * comm;

	public:

	Modbus();
	virtual ~Modbus();
	void addEventManager(CommEventManager * em);
	bool removeEventManager(CommEventManager * em);
	void writeWord(int word, int value);
	bool isConnected();
	bool Connect(std::string ip, int port);
};



//---------------------------------------------------------------------------
#endif
