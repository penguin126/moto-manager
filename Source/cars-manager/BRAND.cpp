#include "BRAND.h"

MOTORBRAND::MOTORBRAND()
{
}

MOTORBRAND::~MOTORBRAND()
{
	
}

vector<string> MOTORBRAND::getBrandName()
{
	return this->brandName;
}

void MOTORBRAND::setBrandName(vector<string> brandName)
{
	this->brandName.swap(brandName);
}

void MOTORBRAND::Insert()
{
	while (1) {
		system("cls");
		bool duplChecking;
		// CHECK DUPLICATE ITEM
		do
		{
			cin.ignore();
			cout << "Ten hang xe: ";
			getline(cin, child);
			transform(this->child.begin(), this->child.end(), this->child.begin(), ::toupper);
			duplChecking = false;
			size_t brandNameSize = brandName.size();
			for (size_t i = 0; i < brandNameSize; i++)
			{
				if (brandName[i] == child)
				{
					duplChecking = true;
					break;
				}
			}
			if (duplChecking)
			{
				cout << "Ma don hang bi trung, vui long kiem tra lai!";
			}
		} while (duplChecking);
		brandName.push_back(child);
		cout << "Them hang xe thanh cong!" << endl;
		system("pause");

		// CHECK WHETHER USER WANT TO CONTINOUSLY INSERT OR NOT?
		int luaChon;
		cout << "\nBan co muon tiep tuc them hang xe khong? (1: Tiep tuc; 0: Dung lai): ";
		cin >> luaChon;
		if (luaChon == 1)
		{
			system("cls");
			continue;	
		}
		else if (luaChon == 0) {
			break;
			system("cls");
		}
	}
}

void MOTORBRAND::Display()
{
	system("cls");
	cout << "\t===>>Danh sach cac hang xe<<===" << endl;
	size_t size = brandName.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << brandName[i] << endl;
	}
	system("pause");
}

void MOTORBRAND::Update()
{
	system("cls");
	cout << "\t===>>Cap nhat hang xe<<===" << endl;
	size_t size = brandName.size();
	if (size > 0) {
		while (1)
		{
			bool flag;
			do
			{
				string brand;
				cin.ignore();
				cout << "Nhap ten hang xe (Khong phan biet chu hoa/ thuong): ";
				getline(cin, brand);
				transform(brand.begin(), brand.end(), brand.begin(), ::toupper);
				flag = true;
				for (size_t i = 0; i < size; i++)
				{
					if (brandName[i] == brand)
					{
						flag = true;
						// LOGIC HANDLING
						string update;
						cout << "Nhap ten hang xe cap nhat: ";
						getline(cin, update);
						transform(update.begin(), update.end(), update.begin(), ::toupper);
						replace(brandName.begin(), brandName.end(), brandName[i], update);
						cout << "Cap nhat thanh cong!" << endl;
						system("pause");
						break;
					}
					else {
						flag = false;
					}
				}
				if (!flag)
				{
					cout << "Ten hang chua ton tai, vui long kiem tra lai!";
				}
			} while (!flag);
			if (size != 0) {
				int luaChon;
				cout << "\nBan co muon tiep tuc cap nhat hang xe khac? (1: Tiep tuc; 0: Dung lai): ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					system("cls");
					continue;
				}
				else if (luaChon == 0)
				{
					break;
					system("cls");
				}
			}
		}
	}
	else {
		cout << "Danh sach hang xe rong, vui long kiem tra lai" << endl;
		system("pause");
	}
}
void MOTORBRAND::Delete()
{
	system("cls");
	cout << "\t===>>Xoa hang xe<<===" << endl;
	size_t size = brandName.size();
	if (size > 0) {
		while (1)
		{
			bool flag;
			do
			{
				string brand;
				cin.ignore();
				cout << "Nhap ten hang xe (Khong phan biet chu hoa/ thuong): ";
				getline(cin, brand);
				transform(brand.begin(), brand.end(), brand.begin(), ::toupper);
				flag = true;
				for (size_t i = 0; i < size; i++)
				{
					if (brandName[i] == brand)
					{
						flag = true;
						brandName.erase(remove(brandName.begin(), brandName.end(), brandName[i]), brandName.end());
						size--;
						cout << "Xoa thanh cong!" << endl;
						break;
					}
					else {
						flag = false;
					}
				}
				if (!flag)
				{
					cout << "Ten hang chua ton tai, vui long kiem tra lai!";
				}
			} while (!flag);
			if (size != 0) {
				int luaChon;
				cout << "\nBan co muon tiep tuc xoa hang xe khac? (1: Tiep tuc; 0: Dung lai): ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					system("cls");
					continue;
				}
				else if (luaChon == 0)
				{
					break;
					system("cls");
				}
			}
			else {
				cout << "\nDanh sach hang xe rong, vui long kiem tra lai" << endl;
				system("pause");
				break;
			}
		}
	}
	else {
		cout << "Danh sach hang xe rong, vui long kiem tra lai" << endl;
		system("pause");
	}
}