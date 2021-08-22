#pragma once
#include<string>
using namespace std;

class APP {
protected:
	vector<string> brandNameList;
public:
	APP();
	~APP();
	void setBrandNameList(vector<string>);
	string formatCurrency(long long);
	bool SortBySecond(const pair<string, int>& a, const pair<string, int>& b);
	void Menu();
};