#include <iostream>

int main()
{
	int myNumber = 347991;
	int n = 1;
	int i = 0;
	int j = 0;
	int currentRadius = 1;
	//is in corner 
	//TR-top right
	//TL-top left
	//BL-bottom left
	//BR-bottom right
	bool isTR = false;
	bool isTL = false;
	bool isBL = false;
	bool isBR = false;

	while(n < myNumber)
	{
		if(i==0 && j==0){
			j++;
			n++;
			std::cout << "I: " << i << "   J: " << j << "   N: " << n << std::endl;
		}
		if(!isTR){
			for(int k=i; k<currentRadius;k++)
			{
				i++;
				n++;
				std::cout << "I: " << i << "   J: " << j << "   N: " << n << std::endl;
			}
			isTR = true;
		}
		else if(isTR && !isTL){
			for(int k=j; k>-currentRadius;k--)
			{
				j--;
				n++;
				std::cout << "I: " << i << "   J: " << j << "   N: " << n << std::endl;
			}
			isTL = true;
		}
		else if(isTR && isTL && !isBL){
			for(int k=i; k>-currentRadius;k--)
			{
				i--;
				n++;
				std::cout << "I: " << i << "   J: " << j << "   N: " << n << std::endl;
			}
			isBL = true;
		}
		else if(isTR && isTL && isBL && !isBR){
			for(int k=j; k<currentRadius;k++)
			{
				j++;
				n++;
				std::cout << "I: " << i << "   J: " << j << "   N: " << n << std::endl;
			}
			isBR = true;
		}
		else{
			currentRadius++;
			j++;
			n++;
			isTR = isTL = isBL = isBR = false;
			std::cout << "I: " << i << "   J: " << j << "   N: " << n << std::endl;
		}
	}
	std::cout << "I: " << i << "   J: " << j << "   N: " << n << std::endl;
	return 0;
}