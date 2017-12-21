#include <iostream>
#include <map>
#include <sstream>



std::map<std::string,int> values;
int n = 0;

std::string numToString(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}

std::string numKeyPair(int a, int b)
{
	//std::cout << numToString(a)+":"+numToString(b) << std::endl;
	return numToString(a)+":"+numToString(b);
}

int valueForField(int x, int y)
{
	int total = 0;
	if(values.count(numKeyPair(x-1,y-1))) {total+= values[numKeyPair(x-1,y-1)];}
	if(values.count(numKeyPair(x-1,y))) {total+= values[numKeyPair(x-1,y)];}
	if(values.count(numKeyPair(x-1,y+1))) {total+= values[numKeyPair(x-1,y+1)];}
	if(values.count(numKeyPair(x,y-1))) {total+= values[numKeyPair(x,y-1)];}
	if(values.count(numKeyPair(x,y+1))) {total+= values[numKeyPair(x,y+1)];}
	if(values.count(numKeyPair(x+1,y-1))) {total+= values[numKeyPair(x+1,y-1)];}
	if(values.count(numKeyPair(x+1,y))) {total+= values[numKeyPair(x+1,y)];}
	if(values.count(numKeyPair(x+1,y+1))) {total+= values[numKeyPair(x+1,y+1)];}

	std::cout << "Value for field : " << numKeyPair(x,y) << "  =  " << total << std::endl;
	n = total;

	return total;
}

int main()
{
	int myNumber = 347991;
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
			values[numKeyPair(i,j)] = 1;
			j++;
		}
		if(!isTR){
			for(int k=i; k<currentRadius;k++)
			{
				values[numKeyPair(i,j)]=valueForField(i,j);
				i++;
			}
			isTR = true;
		}
		else if(isTR && !isTL){
			for(int k=j; k>-currentRadius;k--)
			{
				values[numKeyPair(i,j)]=valueForField(i,j);
				j--;
			}
			isTL = true;
		}
		else if(isTR && isTL && !isBL){
			for(int k=i; k>-currentRadius;k--)
			{
				values[numKeyPair(i,j)]=valueForField(i,j);
				i--;
			}
			isBL = true;
		}
		else if(isTR && isTL && isBL && !isBR){
			for(int k=j; k<currentRadius;k++)
			{
				values[numKeyPair(i,j)]=valueForField(i,j);
				j++;
			}
			isBR = true;
		}
		else{
			currentRadius++;
			isTR = isTL = isBL = isBR = false;
			values[numKeyPair(i,j)]=valueForField(i,j);
			j++;
		}
	}

	return 0;
}