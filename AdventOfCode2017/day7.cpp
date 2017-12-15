#include <iostream>
#include <fstream>
#include <vector>
#include <map>

class TreeNode
{
public:
	TreeNode(){}
	std::string _name;
	int _weight;
	std::string _parentName;
	std::vector<std::string> _children;
};

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
			for(int i = 0; i < tempNode._children.size(); i++)
			{
				TreeNode childNode;
				childNode._parentName = tempNode._name;
				childNode._name = tempNode._children[i];
				tree[childNode._name] = childNode;
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
				tree[childNode._name] = childNode;
			}
		}
	}
	std::cout << std::endl;
	for(int i=0; i < treeKeys.size(); i++)
	{
		if(tree[treeKeys[i]]._parentName == "")
		std::cout << tree[treeKeys[i]]._name  << std::endl;
	}

	inFile.close();

	return 0;
}