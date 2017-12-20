#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<char> dancers = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};
	std::ifstream inFile("day16input.txt");
	std::string line,originalLine;
	std::getline(inFile,line);
	originalLine = line;

	for(int k = 0; k<1000000000%44; k++){
		line = originalLine+",";
		while(line!="")
		{
			std::string token = line.substr(0,line.find(","));
			//std::cout << token << std::endl;
	    	line.erase(0, line.find(",")+1);

	    	if(token[0] == 'x')
	    	{
	    		//swap at positions
	    		token.erase(0,1);
				int first = stoi(token.substr(0,token.find("/")));
				int second = stoi(token.substr(token.find("/")+1));
				//std::cout << first << ":" <<second << std::endl;

				char temp = dancers[first];
				dancers[first] = dancers[second];
				dancers[second] = temp;
	    	}
	    	else if(token[0] == 'p')
	    	{
	    		//swap with name
				char first = token[1];
				char second = token[3];
				//std::cout << first << ":" <<second << std::endl;

				int pos1,pos2;
				for(int i = 0 ; i < dancers.size(); i++)
				{
					if(dancers[i] == first) pos1 = i;
					if(dancers[i] == second) pos2 = i;
				}

				char temp = dancers[pos1];
				dancers[pos1] = dancers[pos2];
				dancers[pos2] = temp;
				
	    	}
	    	else if(token[0] == 's')
	    	{
	    		//spin that shit
	    		token.erase(0,1);
	    		int spinAmount = stoi(token);
	    		std::vector<char> spin = dancers;
	    		for(int i=0 ; i<dancers.size(); i++)
	    		{
	    			dancers[(i+spinAmount)%dancers.size()] = spin[i];
	    		}

	    	}
		}
		std::cout << "          <" << k << "> ";
		for(int i=0 ; i<dancers.size(); i++)
		{
			std::cout <<dancers[i];
		}
		std::cout << std::endl;
	}
	
    	for(int i=0 ; i<dancers.size(); i++)
		{
			std::cout <<dancers[i];
		}
		std::cout << std::endl;

	inFile.close();
	return 0;
}