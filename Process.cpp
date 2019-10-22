#include<iostream>
#include<string>
#include<list>
#include <fstream>
#include "Filter.h"
#include <sys/timeb.h>

using namespace std;

void main()
{
	Filter filter;
	string str;
	filter.load("keywords.txt");
	ifstream inputFile("input.txt", ios::in);
	inputFile >> str;
	//cout  << str ;
	inputFile.close();
	ofstream outputFile("output.txt", ios::out);
	struct timeb startTime, endTime;
	ftime(&startTime);
	for (int i = 0;i < 1000;i++)
	{
		filter.censor(str);
	}
	ftime(&endTime);
	cout << str << endl;
	cout << "查询用时：" << (endTime.time - startTime.time) * 1000 +
		(endTime.millitm - startTime.millitm) << "ms" << endl;
	outputFile << str << endl;
	outputFile << "查询用时：" << (endTime.time - startTime.time) * 1000 +
		(endTime.millitm - startTime.millitm) << "ms";
	outputFile.close();
}

