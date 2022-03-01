#pragma once
#include "CServerSocket.hpp"
#include "Telefonbuch.h"

class CTelefonbuchServer
{
private:
	CServerSocket *serverSocket;
	CTelefonbuch* telefonbuch;

public:
	CTelefonbuch* getTelefonbuch();
	CTelefonbuchServer(int port);
	~CTelefonbuchServer();
	void verbindung();
};