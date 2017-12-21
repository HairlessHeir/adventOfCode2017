#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>


bool executeCurrentCondition(int conReg, std::string curCon, int conInt)
{
	bool result = false;
	if(!curCon.compare("<"))
	{
		if(conReg < conInt) result = true;
		else result = false;
	}
	else if(!curCon.compare(">"))
	{
		if(conReg > conInt) result = true;
		else result = false;
	}
	else if(!curCon.compare(">="))
	{
		if(conReg >= conInt) result = true;
		else result = false;
	}
	else if(!curCon.compare("<="))
	{
		if(conReg <= conInt) result = true;
		else result = false;
	}
	else if(!curCon.compare("=="))
	{
		if(conReg == conInt) result = true;
		else result = false;
	}
	else if(!curCon.compare("!="))
	{
		if(conReg != conInt) result = true;
		else result = false;
	}
	//std::cout << result << " : " << conReg << curCon << conInt << std::endl;
	return result;
}
int main()
{

	std::ifstream inFile;
	inFile.open("day8input.txt");
	std::string line;
	std::map<std::string, int> registerValues;
	std::vector<std::string> registerKeys;
	
	while(std::getline(inFile,line))
	{
		std::istringstream iss(line);
		std::string registerName, direction, conditionRegister, currentCondition, ifText;
		int amount, conditionInteger;

		iss >> registerName;
		iss >> direction;
		iss >> amount;
		iss >> ifText;
		iss >> conditionRegister;
		iss >> currentCondition;
		iss >> conditionInteger;
		std::cout << line << std::endl;
		if(registerValues.count(registerName))
		{
			//key exists
			bool result;
			if(registerValues.count(conditionRegister))
			{
				result = executeCurrentCondition(registerValues[conditionRegister],currentCondition,conditionInteger);
			}
			else
			{
				registerKeys.push_back(conditionRegister);
				registerValues[conditionRegister] = 0;
				result = executeCurrentCondition(0,currentCondition,conditionInteger);
			}
			
			if(result){
				if(!direction.compare("inc"))
				{
					registerValues[registerName]+= amount;
				}
				else
				{
					registerValues[registerName]-= amount;
				}
			}
		}
		else
		{
			//key doesn`t exist
			registerKeys.push_back(registerName);
			registerValues[registerName] = 0;
			bool result;
			if(registerValues.count(conditionRegister))
			{
				result = executeCurrentCondition(registerValues[conditionRegister],currentCondition,conditionInteger);
			}
			else
			{
				registerKeys.push_back(conditionRegister);
				registerValues[conditionRegister] = 0;
				result = executeCurrentCondition(0,currentCondition,conditionInteger);
			}

			if(result){
				if(!direction.compare("inc"))
				{
					registerValues[registerName]+= amount;
				}
				else
				{
					registerValues[registerName]-= amount;
				}
			}
		}
	//	std::cout << std::endl;
	}

	int max = registerValues[registerKeys[0]];
	for (int i = 0; i < registerKeys.size(); ++i)
	{
		if ( registerValues[registerKeys[i]] > max)
		{
			max = registerValues[registerKeys[i]];
		}
		//std::cout << registerValues[registerKeys[i]] << std::endl;
	}
	std::cout << "MAX: " << max << std::endl;
	inFile.close();
	return 0;
}