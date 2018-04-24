#include "netapi.hpp"
#include <iostream>
#include <unistd.h>

int main()
{
       NetAPI api;
       api.verbose();
       api.setConnectable();
       api.setConnectionPhrase((char*)"ok");
       
       api.startReceiver(2000);
       
       
       char enter[50];
       cin>>enter;
       api.connectToServer(2000,(char *)"127.0.0.1");
       usleep(0.5);
       
       api.getClientAddr();
       
       api.sentToClient(0,(char*)"Mhey");
       api.sentToClient(0,(char*)"Mhoyy");
       
       int n;
       do{
              n=api.getReceiverBuffer(enter);
              cout << "buffer n°"<< n+1<< ": "<<enter<< endl;
       }while( n > -1);
       cout << "buffer n°"<< n+1<< ": "<<enter<< endl;
       cin>>enter;
       api.endReceiver();
       //
       return 0;
}
