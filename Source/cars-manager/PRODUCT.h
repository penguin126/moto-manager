#pragma once
#include "BRAND.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class PRODUCT {
protected:
	string brand;
	__int64 price;
	int manufactureDate;
public:
	PRODUCT();
	~PRODUCT();

	string formatCurrency(long long);
	virtual void Insert();
	virtual void Display();
};

class BRANDPRODUCT : public PRODUCT {
protected:
	int amount;
	string productName;
public:
	BRANDPRODUCT();
	~BRANDPRODUCT();

	int getAmount();
	void setAmount(int);

	__int64 getPrice();

	void setProductName(string);
	string getProductName();

	void setBrand(string);
	string getBrand();

	void Insert();
	void Display();
};

class BRANDMOTORPRODUCT : public PRODUCT {
protected:
	string chassisNumber, motorName;
public:
	BRANDMOTORPRODUCT();
	~BRANDMOTORPRODUCT();

	string getChassisNumber();

	void setMotorName(string);
	string getMotorName();

	void setBrand(string);
	string getBrand();

	void Insert();
	void Display();
	void Update(vector<BRANDMOTORPRODUCT*>&, vector<BRANDPRODUCT*>& );
	void Delete(vector<BRANDMOTORPRODUCT*>&);
};