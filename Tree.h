#include "TreeNode.h"
using namespace std;

class Tree
{
public:
	int count;    //当前查找的一个敏感词的字数
	TreeNode* insert(string& keyword);
	TreeNode* insert(const char* keyword);
	TreeNode* find(string& keyword);
	Tree() {
		count = 0;
	};
private:
	TreeNode m_emptyRoot;
	int m_pace;
	TreeNode* insert(TreeNode* parent, string& keyword);
	TreeNode* insertBranch(TreeNode* parent, string& keyword);
	TreeNode* find(TreeNode* parent, string& keyword);

};

