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

	//waitSec(2,true);
	char enter[50];
	api.connectToServer(2000,(char *)"127.0.0.1");
	

	api.getClientAddr();

	api.sendToClient(0,(char*)"Mhey",(char*)"tcp");
	api.sendToClient(0,(char*)"Mhoyy",(char*)"tcp");
	api.sendToClient(0,(char*)"Mhoazda",(char*)"tcp");
	api.clearSendingThread();
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
