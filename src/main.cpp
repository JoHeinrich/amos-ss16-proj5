#include <iostream>
#include <stdlib.h>
#include "MainHeader.h"

int main(int argc, const char** argv)
{
	if(argc <= 1)
	{
		
        std::cerr << "Usage:  " << argv[0] << " MAIN_INDEX \n 0: hdf5\n 1: protobuf\n 2: human detector" << std::endl;
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
            case 2:
                return main2(argc, argv);
			default:
				std::cout<<"Max ControlIndex is 1\n";
		}
	}
}
