#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
	std::ifstream inFile;
	inFile.open("day14input.txt");

	std::string line;
	int damage = 0;
	while(std::getline(inFile,line))
	{
		std::cout << line << std::endl;

		for( int i = 0 ; i < 32 ; i++)
		{
		    char c = line[i];
		    switch(c)
		    {
		    	case '0':
		    		break;
		    	case '1':
		    		damage+=1;
		    		break;
		    	case '2':
		    		damage+=1;
		    		break;
		    	case '3':
		    		damage+=2;
		    		break;
		    	case '4':
		    		damage+=1;
		    		break;
		    	case '5':
		    		damage+=2;
		    		break;
		    	case '6':
		    		damage+=2;
		    		break;
		    	case '7':
		    		damage+=3;
		    		break;
		    	case '8':
		    		damage+=1;
		    		break;
		    	case '9':
		    		damage+=2;
		    		break;
		    	case 'a':
		    		damage+=2;
		    		break;
		    	case 'b':
		    		damage+=3;
		    		break;
		    	case 'c':
		    		damage+=2;
		    		break;
	    		case 'd':
		    		damage+=3;
		    		break;
	    		case 'e':
		    		damage+=3;
		    		break;
	    		case 'f':
		    		damage+=4;
		    		break;

		    }
		}
	}

	std::cout << damage << std::endl;
	inFile.close();
	return 0;
}