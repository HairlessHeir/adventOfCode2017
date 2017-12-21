#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


std::map<int,int> firewall;
std::vector<int> firewallKeys;

bool damageForLayerAndDelay(int delay,int depth, int range)
{
	//ako je recimo depth 3
	//a range je 5
	//puni krug je 0 1 2 3 4 3 2 1 0
	//std::cout << "combo: " << (delay+depth)%(range*2-2) << " range:" << range << " depth:" << depth << " delay:" << delay+depth << std::endl;
	if((delay+depth)%(range*2-2) == 0)
	{
		//std::cout << "        -> damaged!" << std::endl;
		return true;
	}
	return false;
}

bool damagedForPassWithDelay(int delay)
{
	for(int i = 0; i<firewallKeys.size() ; i++)
	{
		if(damageForLayerAndDelay(delay,firewallKeys[i],firewall[firewallKeys[i]])) return true;
	}
	return false;
}

int main()
{
	std::ifstream inFile("day13input.txt");
	std::string line;

	size_t pos = 0;
	std::string token;

	int depth, range;
	while(std::getline(inFile,line))
	{
    	token = line.substr(0,line.find(":"));
    	std::istringstream ss1(token);
 		ss1 >> depth;

    	line.erase(0, line.find(":")+2);
    	std::istringstream ss2(line);
 		ss2 >> range;

    	firewall[depth] = range;
    	firewallKeys.push_back(depth);
	}

	int delay = 10;
	int damaged = false;
	do{
		damaged = damagedForPassWithDelay(delay);
		if(damaged) delay++;
	} while(damaged);

	std::cout << delay << std::endl;
	
	inFile.close();
	return 0;
}