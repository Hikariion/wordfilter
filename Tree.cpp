#include "Tree.h"
#include<iostream>

int setPACE(string keyword) {
	string tmp = keyword.substr(0, 1);
	if (tmp[0] > 32 && tmp[0] <= 128)
		return 1;
	else
		return 2;
}

TreeNode * Tree::insert(string & keyword)
{
	return insert(&m_emptyRoot, keyword);
}

TreeNode* Tree::insert(const char* keyword)
{
	string wordstr(keyword);
	return insert(wordstr);
}


TreeNode* Tree::insert(TreeNode* parent, string& keyword)
{
	int PACE = 0;
	if (keyword.size() == 0)
		return NULL;
	PACE = setPACE(keyword);
	string	firstChar = keyword.substr(0, PACE);
	TreeNode* firstNode = parent->findChild(firstChar);
	if (firstNode == NULL)
		return insertBranch(parent, keyword);
	string restChar = keyword.substr(PACE, keyword.size());
	return insert(firstNode, restChar);
}

TreeNode* Tree::insertBranch(TreeNode* parent, string& keyword)
{
	int PACE = 0;
	PACE = setPACE(keyword);
	string firstChar = keyword.substr(0, PACE);
	TreeNode* firstNode = parent->insertChild(firstChar);
	if (firstNode != NULL)
	{
		string restChar = keyword.substr(PACE, keyword.size());
		if (!restChar.empty())
			return insertBranch(firstNode, restChar);
	}
	return NULL;
}

TreeNode* Tree::find(string& keyword)
{
	return find(&m_emptyRoot, keyword);
}


TreeNode* Tree::find(TreeNode* parent, string& keyword)
{
	int PACE = 0;
	PACE = setPACE(keyword);
	string firstChar = keyword.substr(0, PACE);
	TreeNode* firstNode = parent->findChild(firstChar);
	if (firstNode == NULL)            //未找到
	{
		count = 0;
		return NULL;
	}
	string restChar = keyword.substr(PACE, keyword.size());
	if (firstNode->m_map.empty())        //对应词组结束，则判断该词为敏感词
	{
		//std::cout<<count+1<<endl;
		return firstNode;
	}
	if (keyword.size() == PACE)    //最后一个字
		return NULL;
	count++;
	return find(firstNode, restChar);
}

