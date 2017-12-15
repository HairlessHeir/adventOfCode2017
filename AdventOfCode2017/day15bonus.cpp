#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


std::string binary(long long num)
{
	std::string binaryNum;
	long long rem;
	while(num > 1)
	{
		rem = num % 2;
		binaryNum = std::to_string(rem)+binaryNum;
		num = num / 2;
	}
	binaryNum = std::to_string(num)+binaryNum;
	while(binaryNum.length()<16)
	{
		binaryNum = std::to_string(0)+binaryNum;
	}
	return binaryNum;
}

int main()
{
	long long aStart = 873;
	long long bStart = 583;

	long long aMultiplier = 16807;
	long long bMultiplier = 48271;

	long long divider = 2147483647;

	long long currentA = aStart;
	long long currentB = bStart;

	bool different = false;
	int totalCount = 0;
	for(int i=0; i<5000000; i++)
	{
		different = false;
		do{
			currentA = (currentA*aMultiplier) % divider;
		}
		while(currentA%4!=0);
		do{
			currentB = (currentB*bMultiplier) % divider;
		}while(currentB%8!=0);


		std::string a = binary(currentA);
		std::string b = binary(currentB);
		a = a.substr(a.length() - 16);
		b = b.substr(b.length() - 16);

		if(!a.compare(b)) totalCount++;

		//std::cout << " " << i << " -> " << totalCount << " : " << different << std::endl;
	}

	std::cout << "Total : " << totalCount << std::endl;

	return 0;
}