#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

int main()
{

	std::ifstream inFile;
	inFile.open("day10input.txt");
	char character;
	std::vector<int> knotList;
	std::vector<int> lengths;

	for(int i = 0; i<256; i++) knotList.push_back(i);
	while(inFile.get(character))
	{
		//std::cout << int(character) << std::endl;
		if(int(character) != 0)
			lengths.push_back(int(character));
	}
	lengths.push_back(17);
	lengths.push_back(31);
	lengths.push_back(73);
	lengths.push_back(47);
	lengths.push_back(23);

	int currentLength;
	int currentSkipSize = 0;
	int currentIndex = 0;
	//part one
	for(int i=0 ; i < 64 ; i++){
		//std::cout << "Index: " << currentIndex << " SkipSize: " << currentSkipSize << std::endl;
		for(int j=0 ; j<lengths.size() ; j++){
			currentLength = lengths[j];
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
		}
	}
	//part two
	int resultBuffer;
	std::vector<int> resultVector;
	for(int i = 0 ; i < 16 ; i++)
	{
		for(int j = 0 ; j < 16; j++)
		{
			if(j==0) resultBuffer = knotList[i*16+j];
			else resultBuffer = resultBuffer ^ knotList[i*16+j];
		}
		resultVector.push_back(resultBuffer);
	}

	//part three
	for( int i = 0 ; i < 16 ; i++)
	{
		//std::stringstream hexStream;
		std::cout << std::setfill ('0') << std::setw(2) << std::hex << resultVector[i];
	}
	std::cout << std::endl;
	//std::cout << knotList[0] * knotList[1] << std::endl;

	inFile.close();
	return 0;
}