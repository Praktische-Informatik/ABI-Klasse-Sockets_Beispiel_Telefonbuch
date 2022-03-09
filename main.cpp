// Anmerkung: 
// Dies ist ein Win32 Projekt (siehe oben in deiner Symbolleste).
// Solltest du ein x64 Projekt haben erstellt haben musst du in der Klasse CSocket.hppp die filgenden Zeile einfügen
// #pragma comment(lib,"ws2_32.lib")
// Auch #include <Windows.h> kann manchmal helfen. 

#include "TelefonbuchServer.h"
#include "TelefonClient.h"
#include <iostream>

using namespace std;

void server();
void client();

int main()
{
	int typ = 0;

	cout << endl << " Server\t-->[1]"
		<< endl << " Client\t-->[2]"
		<< endl << endl << "Bitte auswaehlen --> ";

	cin >> typ;

	if (typ == 1) server();
	if (typ == 2) client();

	return 0;
}

void server()
{
	CTelefonbuchServer tbServer(5566);
	cout << "------------SERVER--------------" << endl;
	tbServer.verbindung();

}

void client()
{
	TelefonClient tc;
	cout << "------------CLIENT--------------" << endl;
	if (tc.verbinden("127.0.0.1", 5566) == false)
		cout << "Server nicht gefunden!" << endl;
	
	if (tc.abmelden() == false)
		cout << "Nicht abgemeldet!" << endl;

}