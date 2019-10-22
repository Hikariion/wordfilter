#include <string>
#include "Tree.h"

class Filter
{
private:
	Tree m_tree;

public:
	void load(const char* fileName);
	bool m_initialized;
	void censor(string& source);
};

