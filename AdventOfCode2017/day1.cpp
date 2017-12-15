#include <iostream>
#include <fstream>
#include <string>

int main()
{

	std::string captcha;
	std::ifstream inFile;
	inFile.open("day1input.txt");
	if(inFile.fail())
	{
		std::cout << "Failed to open file!" << std::endl;
	}

	inFile >> captcha;
	
	std::string currentChar = "";
	int totalSum = 0;

	if(captcha.length() > 0)
	{
		currentChar = captcha[captcha.length()-1];
	}
	for(int i = 0; i < captcha.length() ; i++)
	{
		{
			std::string temp = "";
			if(i == captcha.length() - 1) temp.push_back(captcha[0]);
			else temp.push_back(captcha[i]);

			if(temp == currentChar){
				totalSum += ((int)captcha[i] - 48);
			}
			else
			{
				currentChar = temp;
			}
		}
	}

	std::cout << "Total sum : " << std::to_string(totalSum) << std::endl;
	inFile.close();

	return 0;
}