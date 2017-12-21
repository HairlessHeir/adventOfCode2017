#include <iostream>
#include <fstream>
#include <sstream>
//#include <vector>
#include <string>

int main()
{

	std::ifstream inFile;
	inFile.open("day2input.txt");
	std::string line;

	int checksum = 0;
	
	while(std::getline(inFile,line))
	{
		std::istringstream iss(line);
		int n, max, min;
		bool isFirst = true;
		//std::vector<int> v;

		while(iss >> n)
		{
			if(isFirst)
			{
				max = n;
				min = n;
				isFirst = false;
			}
			else
			{
				if(n >= max) max = n;
				if(n <= min) min = n;
			}
			//std::cout << n << std::endl;
			//v.push_back(n);
		}
		checksum += (max - min);
		std::cout << "max: " << max << "  min: " << min << std::endl;
		

	}
	std::cout << "Checksum : " << checksum << std::endl;

	inFile.close();
	return 0;
}