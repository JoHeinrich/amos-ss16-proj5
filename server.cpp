#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <pthread.h>

using namespace std;

void *task1(void *);

static int connFd;

int main(int argc, char* argv[])
{
    int pId, portNo, listenFd;
    socklen_t len; //store size of the address
    bool loop = false;
    struct sockaddr_in svrAdd, clntAdd;
    
    pthread_t thread;
    
    if (argc < 2)
    {
        cerr << "Syntam : ./server <port>" << endl;
        return 0;
    }
    
    portNo = atoi(argv[1]);
    
    if((portNo > 65535) || (portNo < 2000))
    {
        cerr << "Please enter a port number between 2000 - 65535" << endl;
        return 0;
    }
    
    //create socket
    listenFd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(listenFd < 0)
    {
        cerr << "Cannot open socket" << endl;
        return 0;
    }
    
    bzero((char*) &svrAdd, sizeof(svrAdd));
    
    svrAdd.sin_family = AF_INET;
    svrAdd.sin_addr.s_addr = INADDR_ANY;
    svrAdd.sin_port = htons(portNo);
    
    //bind socket
    if(bind(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd)) < 0)
    {
        cerr << "Cannot bind" << endl;
        return 0;
    }
    
    listen(listenFd, 5);
    
    len = sizeof(clntAdd);

    cout << "Listening" << endl;

    //this is where client connects. svr will hang in this mode until client conn
    connFd = accept(listenFd, (struct sockaddr *)&clntAdd, &len);

    if (connFd < 0)
    {
	cerr << "Cannot accept connection" << endl;
        return 0;
    }
    else
    {
        cout << "Connection successful" << endl;
    }
       
    pthread_create(&thread, NULL, task1, NULL); 
    
    pthread_join(thread, NULL);
    
    
    
}

void *task1 (void *dummyPt)
{
    char test[300];
    bzero(test, 301);
    
    bzero(test, 301);
        
    read(connFd, test, 300);
       
    string tester (test);
    cout << tester << endl;

    cout << "\nClosing thread and conn" << endl;
    close(connFd);
}
