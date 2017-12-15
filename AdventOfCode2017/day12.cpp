#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

struct Node
{
	std::string name;
	std::vector<std::string> nodes;
	bool visited;
};

std::vector<std::string> villageKeys;
std::map<std::string, Node > villageMap;
std::set<std::string> visitedNodes;

void visitNodes(std::string currentNode)
{
	if(villageMap[currentNode].visited == false)
	{
		visitedNodes.insert(currentNode);
		villageMap[currentNode].visited = true;
		std::vector<std::string> connectedNodes = villageMap[currentNode].nodes;
		for(int i = 0; i<connectedNodes.size() ; i++)
		{
			visitNodes(connectedNodes[i]);
		}
	}
}

int main()
{
	std::ifstream inFile("day12input.txt");
	std::string line;


	size_t pos = 0;
	std::string token;

	while(std::getline(inFile,line))
	{
		Node currentNode;

		currentNode.name = line.substr(0,line.find("<")-1);
    	line.erase(0, line.find(">")+2);
    	line+=",";

		while ((pos = line.find(",")) != std::string::npos) {
			currentNode.nodes.push_back(line.substr(0, pos));
    		line.erase(0, pos + 2);
		}

		currentNode.visited = false;
		villageMap[currentNode.name] = currentNode;
		villageKeys.push_back(currentNode.name);
	}

	visitNodes("0");
	std::cout << visitedNodes.size() << std::endl;

	inFile.close();
	return 0;
}