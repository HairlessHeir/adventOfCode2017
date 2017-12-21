#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{

	std::ifstream inFile;
	inFile.open("day10input.txt");
	std::string line;
	std::vector<int> knotList;

	for(int i = 0; i<256; i++) knotList.push_back(i);
	while(std::getline(inFile,line))
	{
		size_t pos = 0;
		std::string token;
		int currentLength;
		int currentSkipSize = 0;
		int currentIndex = 0;
		line+=",";
		while ((pos = line.find(",")) != std::string::npos) {
			token = line.substr(0,pos);
			std::istringstream iss(token);
			iss>>currentLength;
		    std::cout << currentLength << std::endl;
		    line.erase(0, pos + 1);

		    std::vector<int> temp;
		    for(int i = 0; i < currentLength; i++)
		    {
		    	temp.push_back(knotList[(currentIndex+i)%256]);
		    }
		    for(int j = currentLength; j > 0; j--)
		    {
		    	knotList[(currentIndex+j-1)%256] = temp[0];
		    	temp.erase(temp.begin());
		    }
		    currentIndex=(currentIndex+currentLength+currentSkipSize)%256;
		    currentSkipSize++;
		
		    for(int i = 0; i<256; i++)
		    {
		    	//std::cout << knotList[i] << " ";
		    }
		    //std::cout << std::endl;
		}
	}

	std::cout << knotList[0] * knotList[1] << std::endl;

	inFile.close();
	return 0;
}