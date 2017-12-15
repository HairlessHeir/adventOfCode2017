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
	inFile.open("day6testinput.txt");

	std::vector<int> banks;
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
		if(orders.insert(newOrder).second == false)
		{
			sameOrder = true;
			//int distance = std::distance(orders.find(newOrder),orders.end());
			//std::cout << "DISTANCE: " << distance << std::endl;
		}
		else
		{
			orders.insert(newOrder);
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
