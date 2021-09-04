#pragma warning( disable : 4267 )
#include "PRODUCT.h"
#include "BRAND.h"

PRODUCT::PRODUCT()
{
}

PRODUCT::~PRODUCT()
{
}

string PRODUCT::formatCurrency(long long val)
{
	string ans = "";

	string num = to_string(val);

	int count = 0;

	for (int i = num.size() - 1;
		i >= 0; i--) {
		count++;
		ans.push_back(num[i]);

		if (count == 3) {
			ans.push_back(',');
			count = 0;
		}
	}

	reverse(ans.begin(), ans.end());

	if (ans.size() % 4 == 0) {

		ans.erase(ans.begin());
	}

	return ans;
}

void PRODUCT::Insert()
{
	do
	{
		fflush(stdin);
		cout << "Gia ban: ";
		cin >> this->price;
		if (this->price <= 0)
		{
			cout << "Vui long nhap gia ban > 0" << endl;
		}
	} while (this->price <= 0);	
	do
	{
		cout << "Nam san xuat: ";
		cin >> this->manufactureDate;
		if (this->manufactureDate < 0 || this->manufactureDate > 2021)
		{
			cout << "Nam san xuat khong hop le, vui long kiem tra lai!" << endl;
		}
	} while (this->manufactureDate < 0 || this->manufactureDate > 2021);
}


void PRODUCT::Display()
{
	cout << "Gia ban: " << this->formatCurrency(this->price) <<" VND" << endl;
	cout << "Nam san xuat: " << this->manufactureDate << endl;
}

BRANDPRODUCT::BRANDPRODUCT()
{
}

BRANDPRODUCT::~BRANDPRODUCT()
{
}

int BRANDPRODUCT::getAmount()
{
	return this->amount;
}

void BRANDPRODUCT::setAmount(int am)
{
	this->amount = am;
}

__int64 BRANDPRODUCT::getPrice()
{
	return this->price;
}

void BRANDPRODUCT::setProductName(string name)
{
	this->productName = name;
}

string BRANDPRODUCT::getProductName()
{
	return this->productName;;
}

void BRANDPRODUCT::setBrand(string br)
{
	this->brand = br;
}

string BRANDPRODUCT::getBrand()
{
	return this->brand;
}

void BRANDPRODUCT::Insert()
{
	PRODUCT::Insert();
	do
	{
		cout << "So luong: ";
		cin >> this->amount;
		if (this->amount <= 0)
		{
			cout << "Vui long nhap so luong > 0" << endl;
		}
	} while (this->amount <= 0);
}

void BRANDPRODUCT::Display()
{
	cout << "\nTen san pham: " << this->getProductName() << endl;
	PRODUCT::Display();
	cout << "So luong nhap: " << this->getAmount() << endl;
	cout << "Hang: " << this->getBrand() << endl;
	cout << "---------------------------------" << endl;
}

BRANDMOTORPRODUCT::BRANDMOTORPRODUCT()
{
}

BRANDMOTORPRODUCT::~BRANDMOTORPRODUCT()
{
}

string BRANDMOTORPRODUCT::getChassisNumber()
{
	return this->chassisNumber;
}

void BRANDMOTORPRODUCT::setMotorName(string name)
{
	this->motorName = name;
}

string BRANDMOTORPRODUCT::getMotorName()
{
	return this->motorName;
}

void BRANDMOTORPRODUCT::setBrand(string br)
{
	this->brand = br;
}

string BRANDMOTORPRODUCT::getBrand()
{
	return this->brand;
}

void BRANDMOTORPRODUCT::Insert()
{
	PRODUCT::Insert();
	cin.ignore();
	cout << "So khung xe: ";
	getline(cin, this->chassisNumber);
}

void BRANDMOTORPRODUCT::Display()
{
	cout << "\nTen xe may: " << this->getMotorName() << endl;
	PRODUCT::Display();
	cout << "So khung xe: " << this->getChassisNumber() << endl;
	cout << "---------------------------------" << endl;
}

void BRANDMOTORPRODUCT::Update(vector<BRANDMOTORPRODUCT*>& brandMotorProductList, vector<BRANDPRODUCT*>& brandProductList)
{
	system("cls");
	size_t brandMotorProductListSize = brandMotorProductList.size();
	if (brandMotorProductListSize == 0)
	{
		cout << "Danh sach san pham rong, vui long kiem tra lai!" << endl;
		system("pause");
	}
	else {
		while (1)
		{
			system("cls");
			bool hasChassis;
			string chassisNumber;
			do
			{
				cin.ignore();
				cout << "So khung xe: ";
				getline(cin, chassisNumber);
				hasChassis = false;
				for (size_t i = 0; i < brandMotorProductListSize; i++)
				{
					if (brandMotorProductList[i]->getChassisNumber() == chassisNumber)
					{
						hasChassis = true;
						bool existChecking;
						string mortorName;

						// CHECK EXISTING ITEM IN PRODUCT LIST
						do
						{
							cout << "Ten xe may: ";
							getline(cin, mortorName);
							transform(mortorName.begin(), mortorName.end(), mortorName.begin(), ::toupper);
							existChecking = false;
							size_t brandProductListSize = brandProductList.size();
							for (size_t j = 0; j < brandProductListSize; j++)
							{
								if (brandProductList[j]->getProductName() == mortorName) {
									existChecking = true;
									break;
								}
							}
							if (!existChecking)
							{
								cout << "San pham chua ton tai, vui long kiem tra lai" << endl;;
							}
						} while (!existChecking);
						brandMotorProductList[i]->setMotorName(mortorName);
						brandMotorProductList[i]->Insert();
						cout << "Cap nhat thanh cong!" << endl;
						system("pause");
						break;
					}
				}
				if (!hasChassis)
				{
					cout << "So khung khong hop le, vui long kiem tra lai!";
				}
			} while (!hasChassis);
			int luaChon;
			cout << "\nBan co muon tiep tuc cap nhat xe may khac khong? (1: Tiep tuc; 0: Dung lai): ";
			cin >> luaChon;
			if (luaChon == 1)
			{
				system("cls");
				continue;
			}
			else if (luaChon == 0) {
				system("cls");
				break;
			}
		}
	}
}

void BRANDMOTORPRODUCT::Delete(vector<BRANDMOTORPRODUCT*>& brandMotorProductList)
{
	system("cls");
	size_t brandMotorProductListSize = brandMotorProductList.size();
	if (brandMotorProductListSize == 0)
	{
		cout << "Danh sach san pham rong, vui long kiem tra lai!" << endl;
		system("pause");
	}
	else {
		while (1)
		{
			system("cls");
			bool hasChassis;
			string chassisNumber;
			do
			{
				cin.ignore();
				cout << "So khung xe: ";
				getline(cin, chassisNumber);
				hasChassis = false;
				for (size_t i = 0; i < brandMotorProductListSize; i++)
				{
					if (brandMotorProductList[i]->getChassisNumber() == chassisNumber)
					{
						hasChassis = true;
						int luaChon;
						cout << "Ban co chac chan muon xoa khong? (1: Co; 0: Khong): ";
						cin >> luaChon;
						if (luaChon == 1)
						{
							auto buffer = brandMotorProductList.begin();
							while (buffer != brandMotorProductList.end()) {
								if ((*buffer)->getChassisNumber() == chassisNumber)
								{
									delete* buffer;
									brandMotorProductList.erase(buffer);
									break;
								}
								buffer++;
							}
							cout << "Xoa thanh cong!" << endl;
							brandMotorProductListSize--;
							break;
						}
						else if (luaChon == 0)
						{
							system("cls");
							break;
						}
					}
				}
				if (!hasChassis)
				{
					cout << "So khung khong hop le, vui long kiem tra lai!";
				}
			} while (!hasChassis);
			if (brandMotorProductListSize != 0)
			{
				int luaChon;
				cout << "\nBan co muon tiep tuc xoa xe may khac khong? (1: Tiep tuc; 0: Dung lai): ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					system("cls");
					continue;
				}
				else if (luaChon == 0) {
					system("cls");
					break;
				}
			}
			else {
				cout << "Danh sach san pham rong, vui long kiem tra lai!" << endl;
				system("pause");
				break;
			}
		}
	}
}

