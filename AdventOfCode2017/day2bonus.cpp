#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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
		int n, first,second;
		std::vector<int> v;

		while(iss >> n)
		{
			v.push_back(n);
		}
		for(int i = 0; i < v.size() - 1; i++)
		{
			for(int j = i + 1; j < v.size(); j++)
			{
				if(v[i]%v[j] == 0){
					checksum += v[i]/v[j];
					break;
				}
				else if(v[j]%v[i] == 0){
					checksum += v[j]/v[i];
					break;
				}
			}
		}
		//checksum += (max - min);
	}
	std::cout << "Checksum : " << checksum << std::endl;

	inFile.close();
	return 0;
}