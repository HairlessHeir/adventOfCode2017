#include <iostream>
#include <vector>

int main()
{
	std::vector<int> numbers;
	std::vector<int>::iterator it;
	int stepSize = 3;//04;	
	int currentIndex = 0;
	for(int i=0; i<10; i++)
	{
		if (numbers.size() == 0) numbers.push_back(0);
		else
		{
			// std::cout << ":" << (stepSize%numbers.size())<<"  ";
			currentIndex = (currentIndex + stepSize)%numbers.size();
			std::cout << "cu: " << currentIndex << std::endl;
			numbers.insert(numbers.begin()+currentIndex + 1,i);
			for(int i=0; i<numbers.size(); i++)
			{
				std::cout << numbers[i] << " " ;
			}

			std::cout <<std::endl;std::cout <<std::endl;
		}
	}

	for(int i=0; i<10; i++)
	{
		std::cout << numbers[i] << " " ;
	}
	std::cout << std::endl;
	return 0;
}