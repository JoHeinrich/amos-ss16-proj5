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

int main(int argc, char* argv[])
{

	GOOGLE_PROTOBUF_VERIFY_VERSION;
	int listenFd, portNo;
	struct sockaddr_in svrAdd;
	struct hostent *server;
    
	if(argc < 3)
	{
		cerr<<"Syntax : ./client <host name> <port>"<<endl;
		return 0;
	}
    
	portNo = atoi(argv[2]);
    
	if((portNo > 65535) || (portNo < 2000))
	{
		cerr<<"Please enter port number between 2000 - 65535"<<endl;
		return 0;
	}       
    
	listenFd = socket(AF_INET, SOCK_STREAM, 0);
    
	if(listenFd < 0)
	{
		cerr << "Cannot open socket" << endl;
		return 0;
	}
    
	server = gethostbyname(argv[1]);
    
	if(server == NULL)
	{
		cerr << "Host does not exist" << endl;
		return 0;
	}
    
	bzero((char *) &svrAdd, sizeof(svrAdd));
	svrAdd.sin_family = AF_INET;
    
	bcopy((char *) server -> h_addr, (char *) &svrAdd.sin_addr.s_addr, server -> h_length);
    
	svrAdd.sin_port = htons(portNo);
    
	int checker = connect(listenFd,(struct sockaddr *) &svrAdd, sizeof(svrAdd));
    
	if (checker < 0)
	{
	cerr << "Cannot connect!" << endl;
	return 0;
	}

	// Set message     
	csCommunication::Warning otherCarWarning;
	otherCarWarning.set_mess("Warning! People in front of bus!");
	// Initialize array and serialize the message
	int size = otherCarWarning.ByteSize();
	void* arr = malloc(size);
	bool serSuccessful = otherCarWarning.SerializeToArray(arr,size);

	cout << "Serializing successful: " << boolalpha << serSuccessful << endl;

	/*
	csCommunication::Warning test;
	test.ParseFromArray(arr,size);
	
	cout << test.mess() << endl;
	*/
	// Just verbose stuff
	cout << "Object detected" << endl;
	cout << "Warn other cars" << endl;

	sleep(2);

	int written = write(listenFd, arr, size);
	//	cout << "Bytes written " << written << endl;

	sleep(2);

	cout << "Warning sent" << endl;
	// Optional:  Delete all global objects allocated by libprotobuf.
  	google::protobuf::ShutdownProtobufLibrary();

	close(listenFd);	
}
