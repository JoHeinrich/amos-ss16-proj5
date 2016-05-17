//
// Projectname: amos-ss16-proj5
//
// Copyright (c) 2016 de.fau.cs.osr.amos2016.gruppe5
//
// This file is part of the AMOS Project 2016 @ FAU
// (Friedrich-Alexander University Erlangen-Nürnberg)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public
// License along with this program. If not, see
// <http://www.gnu.org/licenses/>.
//


#include <string>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "csCommunication.pb.h"

using namespace std;

void *task1(void *);

static int connFd;

int main(int argc, char* argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    int pId, portNo, listenFd;
    socklen_t len;
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
    
    if(bind(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd)) < 0)
    {
        cerr << "Cannot bind" << endl;
        return 0;
    }
    
    listen(listenFd, 5);
    
    len = sizeof(clntAdd);

    cout << "Listening" << endl;

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
    
    // Optional:  Delete all global objects allocated by libprotobuf.
   google::protobuf::ShutdownProtobufLibrary();
    
   close(listenFd); 
    
}

void *task1 (void *dummyPt)
{
	csCommunication::Warning otherCarWarning;
//	int size = otherCarWarning.ByteSize();
	// TODO: Still hardcoded; Länge sollte Größe des Objekts betragen; Problem: ByteSize liefert hier 0, weil noch keins der Felder gesetzt wurde. Eventuell vorher dummy Nachricht erstellen?
	int size = 28;
	// Need space for header

	void* buf = malloc(size); 
        

	int recvSize = recv(connFd, buf, size, 0);
	
//	cout << "Size received " << recvSize << endl;
	
	bool serSuccessful = otherCarWarning.ParseFromArray(buf,size);
	
//	cout << "Has mess " << boolalpha << otherCarWarning.has_mess() << endl;
	cout << "Message: " << otherCarWarning.mess() << endl;
	
    cout << "\nClosing thread and conn" << endl;
    close(connFd);

}
