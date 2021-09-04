#pragma once
#include "PRODUCT.h"
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;

class ORDER {
protected:
	string orderNumber, orderDate, productName, customerName, customerAddr, customerPhone;
	__int64 totalPrice, price, totalRevenue, totalProfit;
	int amount;
	vector<ORDER*> productLists;
public:
	ORDER();
	~ORDER();

	string getCustomerPhone();
	void setCustomerPhone(string);

	void setTotalRevenue(__int64);
	__int64 getTotalRevenue();

	void setTotalProfit(__int64);
	__int64 getTotalProfit();

	void setProductLists(vector<ORDER*>);
	vector<ORDER*> getProductLists();

	void setOrderNumber(string);
	string getOrderNumber();

	string getOrderDate();

	void setProductName(string);
	string getProductName();

	void setAmount(int);
	int getAmount();

	void setPrice(__int64);
	__int64 getPrice();

	void setTotalPrice(__int64);
	__int64 getTotalPrice();

	void Insert();
	void Display();
	void DisplayProductList();

	void WriteToFile(string&);
	void WriteProductToFile(string&);

	string formatCurrency(long long);
};