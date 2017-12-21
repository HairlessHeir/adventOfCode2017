#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>


int main()
{
	std::ifstream inFile("day13input.txt");
	std::string line;
	std::map< int,std::vector<bool> > firewall;
	std::vector<int> firewallKeys;
	std::vector<bool> traceDirection;

	size_t pos = 0;
	std::string token;

	int depth, range;
	while(std::getline(inFile,line))
	{
    	token = line.substr(0,line.find(":"));
    	depth = stoi(token);
    	line.erase(0, line.find(":")+2);
    	range = stoi(line);

    	std::vector<bool> temp;
    	for(int i = 0; i<range ; i++)
    	{
    		temp.push_back(false);
    	}

    	temp[0] = true;

    	firewall[depth] = temp;
    	firewallKeys.push_back(depth);
    	traceDirection.push_back(true);
	}

	int maximumDepth = firewallKeys[firewallKeys.size()-1];

	int counter = 0;
	int totalScore = 0;
	int delayedCounter = 0;
	int delayedCounterMAX = 0;
	bool canGo = false;
	do{
	while(counter < maximumDepth+1)
	{
		if(canGo){
			if(std::find(firewallKeys.begin(), firewallKeys.end(), counter) != firewallKeys.end())
			{
			 	if(firewall[counter][0] == true)
			 	{
			 		totalScore+=counter*firewall[counter].size();
			 	}
			}
		}

		//RangeTrackerMove
		for(int i=0; i<firewallKeys.size(); i++)
		{
			if(traceDirection[i])
			{
				//going down
				int currentRange;
				for(int j = 0 ; j < firewall[firewallKeys[i]].size() ; j++)
				{
					if(firewall[firewallKeys[i]][j])
					{
						currentRange = j;
						break;
					}
				}

				//std::cout << firewallKeys[i] << " -> " << currentRange << " : " << counter << std::endl;
				firewall[firewallKeys[i]][currentRange] = false;
				if(currentRange == firewall[firewallKeys[i]].size()-1)
				{
					traceDirection[i] = false;
					firewall[firewallKeys[i]][currentRange-1] = true;
				}
				else
				{
					firewall[firewallKeys[i]][currentRange+1] = true;
				}
				
			}
			else
			{
				//going up
				int currentRange;
				for(int j = 0 ; j < firewall[firewallKeys[i]].size() ; j++)
				{
					if(firewall[firewallKeys[i]][j])
					{
						currentRange = j;
						break;
					}
				}

				//std::cout << firewallKeys[i] << " <- " << currentRange << " : " << counter << std::endl;
				firewall[firewallKeys[i]][currentRange] = false;
				if(currentRange == 0)
				{
					traceDirection[i] = true;
					firewall[firewallKeys[i]][currentRange+1] = true;
				}
				else
				{
					firewall[firewallKeys[i]][currentRange-1] = true;
				}
			}
		}

		if(canGo) counter++;
		else
		{
			if(delayedCounter<delayedCounterMAX)
			{
				delayedCounter++;
			}
			if(delayedCounter ==)
		}
	}
	} while(totalScore!=0);

	std::cout << "DAMAGE: " << totalScore << std::endl;
	inFile.close();
	return 0;
}