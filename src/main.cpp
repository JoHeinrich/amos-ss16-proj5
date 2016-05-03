#include <iostream>
#include <stdlib.h>
#include "MainHeader.h"

int main(int argc, char** argv)
{
	if(argc <= 1)
	{
		std::cout<<"Arg0: Control Index \nArg1-n: Controlspefific Commands\n";
	}
	else
	{
		int index = atoi(argv[0]);
		switch(index)
		{
			case 0: 
				return main0();
			default:
				std::cout<<"Max ControlIndex is 0\n";
		}
	}
}
