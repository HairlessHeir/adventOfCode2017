#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

std::string keyForVector(std::vector<int> currentBanks)
{
	std::string newKey = std::to_string(currentBanks[0]);
	for (int i = 1; i < currentBanks.size(); i++)
	{
		newKey+= ":" + std::to_string(currentBanks[i]);
	}
	std::cout << newKey << std::endl;
	return newKey;
}

int main()
{
	std::ifstream inFile;
	inFile.open("day6input.txt");

	std::vector<int> banks;
	std::vector<std::string> newOrders;
	std::set<std::string> orders;

	while(!inFile.eof())
	{	
		int current;
		inFile >> current;
		banks.push_back(current);
	}

	bool sameOrder = false;
	int countCycles = 0;
	while(!sameOrder)
	{
		std::string newOrder = keyForVector(banks);
		if(std::find(newOrders.begin(), newOrders.end(), newOrder) != newOrders.end())
		{
			std::cout << "Distance : " << std::distance(std::find(newOrders.begin(), newOrders.end(), newOrder),newOrders.end()) << std::endl;
			sameOrder = true;
		}
		else
		{
			newOrders.push_back(newOrder);
			int maxValue = banks[0];
			int position = 0;
			for(int i=0;i<banks.size();i++)
			{
				if(banks[i]>maxValue)
				{
					maxValue = banks[i];
					position = i;
				}
			}

			banks[position] = 0;
			while(maxValue > 0)
			{
				position = (position+1)%banks.size();
				banks[position]++;
				maxValue--;
			}
			countCycles++;
		}
	}

	std::cout << "COUNT: " << countCycles << std::endl;
	inFile.close();
	return 0;
}
