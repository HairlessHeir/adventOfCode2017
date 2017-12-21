#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

struct Square
{
	bool isFree;
	bool isVisited;
	int groupNumber;
};

std::vector < std::vector<Square> > squares;

void markCurrentGroup(int i, int j, int groupNumber)
{
	if(i==-1 || j==-1 || i==128 || j==128) return;
	if(squares[i][j].isVisited) return;

		std::cout << i << " " << j << "  " << groupNumber << " " <<  squares[i][j].isFree <<  std::endl;
	squares[i][j].isVisited = true;
	if(!squares[i][j].isFree)
	{ 
		squares[i][j].groupNumber = groupNumber;

		markCurrentGroup(i,j+1, groupNumber);
		markCurrentGroup(i,j-1, groupNumber);
		markCurrentGroup(i+1,j, groupNumber);
		markCurrentGroup(i-1,j, groupNumber);
	}
}

int findAllGroups()
{
	int groupCount = 0;
	for(int i = 0 ; i<squares.size(); i++)
	{
		for(int j = 0; j<squares[i].size(); j++)
		{
			if(squares[i][j].groupNumber==0 && !squares[i][j].isVisited)
			{
				markCurrentGroup(i,j,groupCount+1);
				groupCount++;
				std::cout << std::endl;
			}
		}
	}
	return groupCount;
}
int main()
{
	std::ifstream inFile;
	inFile.open("day14input.txt");

	std::string line;
	int damage = 0;
	while(std::getline(inFile,line))
	{
		for( int i = 0 ; i < 32 ; i++)
		{
			std::vector<Square> temp;
		    char c = line[i];
		    std::string current;
		    switch(c)
		    {
		    	case '0':
		    		current = "0000";
		    		break;
		    	case '1':
		    		current = "0001";
		    		damage+=1;
		    		break;
		    	case '2':
		    		current = "0010";
		    		damage+=1;
		    		break;
		    	case '3':
		    		current = "0011";
		    		damage+=2;
		    		break;
		    	case '4':
		    		current = "0100";
		    		damage+=1;
		    		break;
		    	case '5':
		    		current = "0101";
		    		damage+=2;
		    		break;
		    	case '6':
		    		current = "0110";
		    		damage+=2;
		    		break;
		    	case '7':
		    		current = "0111";
		    		damage+=3;
		    		break;
		    	case '8':
		    		current = "1000";
		    		damage+=1;
		    		break;
		    	case '9':
		    		current = "1001";
		    		damage+=2;
		    		break;
		    	case 'a':
		    		current = "1010";
		    		damage+=2;
		    		break;
		    	case 'b':
		    		current = "1011";
		    		damage+=3;
		    		break;
		    	case 'c':
		    		current = "1100";
		    		damage+=2;
		    		break;
	    		case 'd':
		    		current = "1101";
		    		damage+=3;
		    		break;
	    		case 'e':
		    		current = "1110";
		    		damage+=3;
		    		break;
	    		case 'f':
		    		current = "1111";
		    		damage+=4;
		    		break;
		    }
		    for(int j=0; j<current.length(); j++)
		    {
		    	Square square;
		    	square.groupNumber = 0;
		    	square.isVisited = false;
		    	std::cout<<current[j];
		    	if(current[j]=='0')
		    	{
		    		square.isFree = true;
		    	}
		    	else
		    	{
		    		square.isFree = false;
		    	}
		    	temp.push_back(square);
		    }
		    squares.push_back(temp);
		}
		std::cout << std::endl;
	}

	int amount = findAllGroups();

	inFile.close();
	return 0;
}