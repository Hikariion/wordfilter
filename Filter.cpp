#include <iostream>
#include <fstream>
#include "Filter.h"

void Filter::load(const char* filePath)
{
	ifstream keywordsFile(filePath, ios::in);
	if (keywordsFile.is_open())
	{
		
	/*	char buffer[256];
		int count = 0;
		int offset = 0;
		while ((buffer[offset] = keywordsFile.get()) != EOF)
		{
			if ((buffer[offset] >= 'a' && buffer[offset] <= 'z') ||
				(buffer[offset] >= 'A' && buffer[offset] <= 'Z') ||
				(buffer[offset] >= '0' && buffer[offset] <= '9') ||
				buffer[offset] == '\'')
				continue;
			string word1;
			word1.assign(buffer, offset);
			if (buffer[offset] == ',' && (offset % 2) == 0)
			{
				string word;
				if (offset)
				{
					word.assign(buffer, offset);
					m_tree.insert(word);
				}
				offset = 0;
			}
			else
				offset++;
		}*/
		string word;
		while (getline(keywordsFile, word)) {
			//cout << word << endl;
			m_tree.insert(word);
		}

	}
	keywordsFile.close();
	m_initialized = true;
}


void Filter::censor(string& source)
{
	if (!m_initialized)
	{
		cout << "没有载入关键词";
		return;
	}
	else
	{
		int length = source.size();
		for (int i = 0; i < length; i += 2)
		{
			string substring = source.substr(i, length - i);
			if (m_tree.find(substring) != NULL)    //发现敏感词
			{
				cout << substring.substr(0, (m_tree.count + 1) * 2) << endl;
				source.replace(i, (m_tree.count + 1) * 2, "**");
				length = source.size();
			}
		}
		return;
	}
}

