#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

int main()
{
	std::string line, currentPass;
	std::string delim = " ";
	std::ifstream inFile;
	std::map<std::string, int> passphrases;
	
	inFile.open("day4input.txt");
	int valid = 0;
	bool invalidFlag = false;

	while(!inFile.eof()){
		std::getline(inFile,line);
		int start = 0U;
		int end = line.find(delim);
		invalidFlag = false;
		passphrases.clear();

		while(end != std::string::npos)
		{
			currentPass = line.substr(start,end - start);
			std::sort(currentPass.begin(), currentPass.end());
			if(passphrases.count(currentPass) > 0)
			{
				invalidFlag = true;
			}
			passphrases[currentPass] = 1;

			start = end + delim.length();
			end = line.find(delim,start);
			std::cout << currentPass << " ";
		}
		currentPass = line.substr(start,end);
		std::sort(currentPass.begin(), currentPass.end());
		if(passphrases.count(currentPass) > 0)
		{
			invalidFlag = true;
		}

		std::cout << currentPass << " " << std::endl;

		if(!invalidFlag) valid++;
		std::cout << line << " : " << valid << std::endl;
	}
	
	std::cout << valid << std::endl;
	inFile.close();

	return 0;
}