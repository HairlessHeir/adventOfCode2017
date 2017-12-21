#include <iostream>

int main()
{
	int stepSize = 304;	
	int amount = 50000000;
	int currentIndex = 0;
	int currentSize = 0;
	for(int i=0; i<amount; i++)
	{
		if (numbers.size() == 0) 
		{
			numbers.push_back(0);
			currentSize++;
		}
		else
		{
			currentIndex = (currentIndex + stepSize)%(currentSize);
			if(currentIndex==0)
			{
				std::cout << i << std::endl;
			}
			currentIndex++;
			currentSize++;
		}
	}
	return 0;
}