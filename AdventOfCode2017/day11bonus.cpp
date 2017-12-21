#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
int main()
{

	std::ifstream inFile;
	inFile.open("day11input.txt");
	std::string line;

	int x = 0;
	int z = 0;
	int max = 0;
	int distance = 0;

	while(std::getline(inFile,line))
	{
		size_t pos = 0;
		std::string token;
		line+=",";
		while ((pos = line.find(",")) != std::string::npos) {
			token = line.substr(0,pos);
			//std::istringstream iss(token);
			//iss>>currentLength;
			if(!token.compare("n")){z--;}
			else if(!token.compare("ne")){x++; z--;}
			else if(!token.compare("se")){x++;}
			else if(!token.compare("s")){z++;}
			else if(!token.compare("sw")){x--; z++;}
			else if(!token.compare("nw")){x--;}
		    //std::cout << token << " : (" << x << "," << z << ")" << std::endl;
		    distance = (abs(x)+abs(z)+abs(-x-z))/2;
		    if(distance > max) max = distance;
		    line.erase(0, pos + 1);
		}
	}

	//std::cout << "x: " << x << "  y: " << z << std::endl;
	std::cout << max << std::endl;

	inFile.close();
	return 0;
}