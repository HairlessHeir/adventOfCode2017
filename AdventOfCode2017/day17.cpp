#include <iostream>
#include <vector>

int main()
{
	std::vector<int> numbers;
	std::vector<int>::iterator it;
	int stepSize = 304;	
	int amount = 2018;
	int currentIndex = 0;
	for(int i=0; i<amount; i++)
	{
		if (numbers.size() == 0) numbers.push_back(0);
		else
		{
			// std::cout << ":" << (stepSize%numbers.size())<<"  ";
			currentIndex = (currentIndex + stepSize)%(numbers.size());
			//std::cout << "cu: " << currentIndex << " : " <<numbers.size() << std::endl;
			numbers.insert(numbers.begin()+currentIndex + 1,i);
			currentIndex++;
			// std::cout << "After insert: ";
			// for(int i=0; i<numbers.size(); i++)
			// {
			// 	std::cout << numbers[i] << " " ;
			// }

			//std::cout <<std::endl;std::cout <<std::endl;
		}
		std::cout << i << std::endl;
	}

	for(int i=0; i<amount; i++)
	{
		std::cout << numbers[i] << " " ;
	}
	std::cout << std::endl;
	return 0;
}