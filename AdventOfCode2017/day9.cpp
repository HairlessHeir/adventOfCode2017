#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>

int main()
{

	std::ifstream inFile;
	inFile.open("day9input.txt");
	std::string line;
	std::stack<char> characterStack;
	bool isGarbage = false;
	bool skipNext = false;

	int groupValue = 0;
	int totalValue = 0;

	while(std::getline(inFile,line))
	{
		std::istringstream iss(line);
		char c;

		while(iss.get(c))
		{
			//std::cout << c << std::endl;
			if(skipNext)
			{
				skipNext = false;
				continue;
			}

			if(isGarbage)
			{
				//all characters are garbage
				if(c== '!') skipNext = true;
				else if(c == '>') isGarbage = false;
			}
			else
			{
				if(c == '<') isGarbage = true;
				else if(c == '{')
				{
					groupValue++;
					characterStack.push(c);
				}
				else if(c == '}')
				{
					totalValue+=groupValue;
					groupValue--;
					characterStack.pop();
				}
			}
		}		
	}
	std::cout << totalValue << std::endl;
	inFile.close();
	return 0;
}