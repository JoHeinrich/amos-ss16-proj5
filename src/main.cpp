#include <iostream>
#include <stdlib.h>
#include "MainHeader.h"

int main(int argc, char** argv)
{
	if(argc <= 1)
	{
		
		std::cerr << "Usage:  " << argv[0] << " MAIN_INDEX \n 1: hdf5\n 2: protobuf" << std::endl;
	}
	else
	{
		int index = atoi(argv[1]);
		for(int m = 1; m < argc-1;m++)
		{
			argv[m] = argv[m+1];
		}
		argc --;
		switch(index)
		{
			case 0: 
				return main0();
			case 1:
				return main1(argc,argv);
			default:
				std::cout<<"Max ControlIndex is 1\n";
		}
	}
}
