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

	for(int i = 0; i < captcha.length() ; i++)
	{
			currentChar = "";
			currentChar.push_back(captcha[i]);

			int currentIndex = (captcha.length()/2 + i)%captcha.length();

			std::string temp = "";
			temp.push_back(captcha[currentIndex]);

			if(currentChar == temp){
				totalSum += ((int)captcha[i] - 48);
			}
	}

	std::cout << "Total sum : " << std::to_string(totalSum) << std::endl;
	inFile.close();

	return 0;
}