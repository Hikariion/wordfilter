#include "Tree.h"
#include<iostream>

#define PACE 2    //如果需要考虑英文或中英文结合的情况，将PACE改为1，另外程序还需要做部分修改

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
	if (keyword.size() == 0)
		return NULL;
	string firstChar = keyword.substr(0, PACE);
	TreeNode* firstNode = parent->findChild(firstChar);
	if (firstNode == NULL)
		return insertBranch(parent, keyword);
	string restChar = keyword.substr(PACE, keyword.size());
	return insert(firstNode, restChar);
}

TreeNode* Tree::insertBranch(TreeNode* parent, string& keyword)
{
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

