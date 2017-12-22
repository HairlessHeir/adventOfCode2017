#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>



int main()
{
	std::ifstream inFile("day19input.txt");
	std::string line;

	while(std::getline(inFile,line))
	{
		std::cout << line.length() << std::endl;
	}
	inFile.close();
	return 0;
}