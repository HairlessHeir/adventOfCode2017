#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::vector<int> offsets;
	int currentIndex = 0;
	int currentOffset;

	std::ifstream inFile;
	inFile.open("day5input.txt");

	while(!inFile.eof())
	{
		int i;
		inFile>>i;
		offsets.push_back(i);
	}

	int stepCount = 0;
	while(currentIndex >= 0 && currentIndex < offsets.size())
	{
		stepCount++;
		//std::cout << currentIndex << " : " << offsets[currentIndex] << std::endl;
		currentOffset = offsets[currentIndex];
		if(currentOffset >= 3) offsets[currentIndex]--;
		else offsets[currentIndex]++;
		currentIndex += currentOffset;
	}

	std::cout << "Total steps: " << stepCount << std::endl;
	return 0;

}