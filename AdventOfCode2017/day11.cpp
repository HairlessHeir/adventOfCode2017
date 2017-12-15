#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

typedef hexPad
{
	int x;
	int y;
	int z;
};	
int main()
{
	std::ifstream inFile;
	inFile.open("day11input.txt");

	std::string line;
	std::getline(inFile,line);

	int n,s,nw,se,ne,sw = 0;

	line += ",";
	size_t pos = 0;
	std::string token;
	while ((pos = line.find(",")) != std::string::npos) {
    	token = line.substr(0, pos);

    	if(!token.compare("n")) n++;
    	else if(!token.compare("s")) s++;
    	else if(!token.compare("nw")) nw++;
    	else if(!token.compare("se")) se++;
    	else if(!token.compare("ne")) ne++;
    	else if(!token.compare("sw")) sw++;

    	line.erase(0, pos + 1);


		std::cout << "t: " << token << " " << n << " " << ne << " " << se << " " << s << " " << sw << " " << nw << std::endl;
	}

		std::cout << "NS: "<< n-s << " NESW: " << ne-sw << " NWSE: " << nw-se << std::endl;

	inFile.close();
	return 0;
}