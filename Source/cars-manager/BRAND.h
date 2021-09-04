#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "APP.h"

using namespace std;
class MOTORBRAND: public APP {
protected:
	vector<string> brandName;
	string child;
public:
	MOTORBRAND();
	~MOTORBRAND();

	vector<string> getBrandName();
	void setBrandName(vector<string>);

	void Insert();
	void Display();
	void Update();
	void Delete();
};