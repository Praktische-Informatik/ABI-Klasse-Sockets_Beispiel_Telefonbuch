#include "TelefonbuchServer.h"
#include <iostream>
using namespace std;

CTelefonbuchServer::CTelefonbuchServer(int port)
{
	serverSocket = new CServerSocket(port);
	telefonbuch = new CTelefonbuch(10);
}

CTelefonbuchServer::~CTelefonbuchServer(void)
{
	serverSocket->close();
	delete serverSocket;
	delete telefonbuch;
}

void CTelefonbuchServer::verbindung()
{
	CSocket* workSocket;
	cout << "Warten auf Verbindungsanfrage (Blockierende accept-Funktion)!" << endl;
	workSocket = serverSocket->accept();  //Blockierende Funktion
	cout << "Verbindung zum Client akzeptiert... " << endl;
	
	string anfrageName = "";
	//char anfrage[100] = { 0 }; 
	string antwort;

	//Blockierende read-Funktion
	while (anfrageName != "EXIT")
	{
		anfrageName = workSocket->readLine();
		antwort = telefonbuch->nrSuche(anfrageName);
		cout << "Client; Empfange Anfrage " << anfrageName << " ; " << "Sende Antwort " << antwort << endl;
		workSocket->write(antwort);
	}

	cout << "Client abgemeldet!" << endl;
}

CTelefonbuch* CTelefonbuchServer::getTelefonbuch()
{
	return telefonbuch;
}
