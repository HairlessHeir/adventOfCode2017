#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>

class TreeNode
{
public:
	TreeNode(){}
	std::string _name;
	int _weight;
	std::string _parentName;
	std::vector<std::string> _children;
};

int totalWeightForNode(std::string name, std::map<std::string,TreeNode> tree)
{
	if(tree[name]._children.size() == 0)
	{
		return tree[name]._weight;
	}
	else
	{
		int totalChildWeight = tree[name]._weight;
		for(int i=0; i<tree[name]._children.size(); i++)
		{
			totalChildWeight += totalWeightForNode(tree[name]._children[i],tree);
		}
		return totalChildWeight;
	}
}

void printTree(std::map<std::string,TreeNode> tree, std::string nodeName, int level)
{
	std::cout << std::setfill('-') << std::setw(level*2 +nodeName.length()) << nodeName << " (" << totalWeightForNode(nodeName,tree) << ")"<< std::endl;

	for(int i=0; i<tree[nodeName]._children.size(); i++)
	{
		printTree(tree,tree[nodeName]._children[i],level+1);
	}
}

int main()
{
	std::string currentLine;
	std::map<std::string,TreeNode> tree;
	std::vector<std::string> treeKeys;
	std::ifstream inFile;

	inFile.open("day7input.txt");

	while(!inFile.eof())
	{
		std::getline(inFile,currentLine);
		//std::cout << currentLine << std::endl;
		
		TreeNode tempNode;
		tempNode._parentName = "";
		
		std::istringstream ss(currentLine.substr(currentLine.find_first_of("(")+1,currentLine.find_first_of(")")-currentLine.find_first_of("(")-1));
		ss >> tempNode._weight;

		if(currentLine.find("->") != std::string::npos){
			std::string firstPart = currentLine.substr(0, currentLine.find("->"));
			std::string secondPart = currentLine.substr(currentLine.find("->") + 3,currentLine.length()-1)+", ";

			std::string nodeName = firstPart.substr(0,firstPart.find(" "));
			tempNode._name = nodeName;

			while(secondPart.find(",")!=std::string::npos)
			{
				std::string currentChild = secondPart.substr(0,secondPart.find_first_of(","));
				secondPart = secondPart.substr(secondPart.find_first_of(",")+2 ,secondPart.length()-1);
				tempNode._children.push_back(currentChild);
			}
		}
		else
		{
			//it's just a child
			std::string nodeName = currentLine.substr(0,currentLine.find(" "));
			tempNode._name = nodeName;
		}

		treeKeys.push_back(tempNode._name);

		if(tree.count(tempNode._name))
		{
			tree[tempNode._name]._children = tempNode._children;
			tree[tempNode._name]._weight = tempNode._weight;
			for(int i = 0; i < tempNode._children.size(); i++)
			{
				TreeNode childNode;
				childNode._parentName = tempNode._name;
				childNode._name = tempNode._children[i];
				if(tree.count(childNode._name))
				{
					tree[childNode._name]._parentName = childNode._parentName;
				}
				else tree[childNode._name] = childNode;
			}
		}
		else
		{
			tree[tempNode._name] = tempNode;
			for(int i = 0; i < tempNode._children.size(); i++)
			{
				TreeNode childNode;
				childNode._parentName = tempNode._name;
				childNode._name = tempNode._children[i];
				if(tree.count(childNode._name))
				{
					tree[childNode._name]._parentName = childNode._parentName;
				}
				else tree[childNode._name] = childNode;
			}
		}
	}
	
	std::string topNodeName;
	for(int i=0; i < treeKeys.size(); i++)
	{	
		if(tree[treeKeys[i]]._parentName == ""){
			topNodeName = tree[treeKeys[i]]._name;
			break;
		}
		//std::cout << tree[treeKeys[i]]._parentName << " - " << tree[treeKeys[i]]._name << " w: " << tree[treeKeys[i]]._weight  << " childNum: " << tree[treeKeys[i]]._children.size() << " tot: " << totalWeightForNode(treeKeys[i],tree) << std::endl;
	}
	printTree(tree,topNodeName,0);

	inFile.close();

	return 0;
}