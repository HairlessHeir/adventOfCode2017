#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

int main()
{
	std::ifstream inFile("day18input.txt");
	std::string line;
	int lastPlayed = 0;
	bool received = false;
	std::map<std::string, long long> soundBank;
	std::vector<std::string> instructions;
	while(std::getline(inFile,line))
	{
		instructions.push_back(line);
	}
	inFile.close();

	int currentInstruction = 0;
	while(!received)
	{
		line = instructions[currentInstruction];
		//std::cout << line << std::endl;
		std::string part;
		part = line.substr(0,line.find(" "));
		line.erase(0,line.find(" ")+1);
		std::string currentBank = line.substr(0,1);
		line.erase(0,line.find(" ")+1);
		if(soundBank.count(currentBank)==0)
		{
			soundBank[currentBank] = 0;
		}

		long long bankValue = 0;
		if(line.length() != 0)
		{
			try
			{
				bankValue =stoi(line);
			}
			catch (const std::invalid_argument& ia) {
				if(soundBank.count(line)==0)
				{
					soundBank[line] = 0;
				}
	  			bankValue = soundBank[line];
  			}
		}
		if(!part.compare("jgz"))
		{
			if(soundBank[currentBank]>0){
				currentInstruction+=bankValue;
			}
			else
			{
				currentInstruction++;
			}
		}
		else
		{
			currentInstruction++;
			if(!part.compare("snd"))
			{	
				lastPlayed = soundBank[currentBank];
				std::cout << currentBank << " : " << soundBank[currentBank] << std::endl;
			}
			else if(!part.compare("set"))
			{
				soundBank[currentBank] = bankValue;
			}
			else if(!part.compare("add"))
			{
				soundBank[currentBank] += bankValue;
			}
			else if(!part.compare("mul"))
			{	
				soundBank[currentBank] *= bankValue;
			}
			else if(!part.compare("mod"))
			{
				soundBank[currentBank] = soundBank[currentBank]%bankValue;
			}
			else if(!part.compare("rcv"))
			{
				if(soundBank[currentBank]!=0){ 
					received = true;
				}
			}
			
			else
			{
				std::cout << "WRONG!" << std::endl;
			}
		}
	}
	std::cout << lastPlayed << std::endl;
	return 0;
}