#include "netapi.hpp"
#include <iostream>
#include <unistd.h>
#include <ctime>



int main()
{
	NetAPI api;
	api.verbose();
	api.setConnectable();
	api.setConnectionPhrase((char*)"ok");

	api.startReceiver(2000,(char*)"TCP");


	char enter[50];
	//cin>>enter;
	api.connectToServer(2000,(char *)"127.0.0.1");
	//waitSec(2);
	cin>>enter;

	api.getClientAddr();

	api.sentToClientTCP(0,(char*)"Mhey");
	api.sentToClientTCP(0,(char*)"Mhoyy");
	api.sentToClientTCP(0,(char*)"Mhoazda");
	cin>>enter;

	int n;
	cout << "start" << endl;
	while((n=api.getReceiverBuffer(enter))>-1)
	{
		cout << "buffer n°"<< n<< ": "<<enter<< endl;
	}
	cin>>enter;
	api.endReceiver();
	//
	return 0;
}
