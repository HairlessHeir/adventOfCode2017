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
	std::vector<std::string> children;
};

std::set<std::string> nodeConnections;
std::vector<std::string> villageKeys;
std::map<std::string, std::vector<std::string> > villageMap;
std::set<std::string> visitedNodes;

void visitConnectedNodes(std::string currentNode)
{
	if(!visitedNodes.count(currentNode)) visitedNodes.insert(currentNode);
	else return;
	std::vector<std::string> currentConnections = villageMap[currentNode];
	for(int i=0; i< currentConnections.size(); i++)
	{
		std::cout << currentConnections[i] << " " << !nodeConnections.count(currentConnections[i]) <<std::endl;
			if(!nodeConnections.count(currentConnections[i])) 
				//{
					nodeConnections.insert(currentConnections[i]);
					visitConnectedNodes(currentConnections[i]);
				//}
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
			currentNode.children.push_back(line.substr(0, pos));
    		line.erase(0, pos + 2);
		}

		villageMap[currentNode.name] = currentNode.children;
		villageKeys.push_back(currentNode.name);
	}

	nodeConnections.insert("0");
	visitConnectedNodes("0");
	std::cout << "Peace: " << visitedNodes.size() << std::endl;
	inFile.close();
	return 0;
}