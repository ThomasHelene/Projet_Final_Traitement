//---------------------------------------------------------------------------

#ifndef TCP_ClientH
#define TCP_ClientH
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include "IHMJay.h"

class TCP_Client : public Communication
{
  private:

  TIdTCPClient * Client;

  public:

  void Connect(String params);
  bool isConnected();
  char* Receive(int size);
  bool Send(char * buffer, int size);
  bool onDisconnected();
  void Disconnect();

};
//---------------------------------------------------------------------------
#endif
