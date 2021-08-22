#include "ORDER.h"

ORDER::ORDER()
{
	this->totalPrice = 0;
}

ORDER::~ORDER()
{
}

string ORDER::getCustomerPhone()
{
	return this->customerPhone;
}

void ORDER::setCustomerPhone(string phone)
{
	this->customerPhone = phone;
}

void ORDER::setTotalRevenue(__int64 revenue)
{
	this->totalRevenue = revenue;
}

__int64 ORDER::getTotalRevenue()
{
	return this->totalRevenue;
}

void ORDER::setTotalProfit(__int64 profit)
{
	this->totalProfit = profit;
}

__int64 ORDER::getTotalProfit()
{
	return this->totalProfit;
}

void ORDER::setProductLists(vector<ORDER*> pd)
{
	this->productLists = pd;
}

vector<ORDER*> ORDER::getProductLists()
{
	return this->productLists;
}

void ORDER::setOrderNumber(string orn)
{
	this->orderNumber = orn;
}

string ORDER::getOrderNumber()
{
	return this->orderNumber;
}

string ORDER::getOrderDate()
{
	return this->orderDate;
}

void ORDER::setProductName(string pd)
{
	this->productName = pd;
}

string ORDER::getProductName()
{
	return this->productName;
}

void ORDER::setAmount(int am)
{
	this->amount = am;
}

int ORDER::getAmount()
{
	return this->amount;
}

void ORDER::setPrice(__int64 pr)
{
	this->price = pr;
}

__int64 ORDER::getPrice()
{
	return this->price;
}

void ORDER::setTotalPrice(__int64 tt)
{
	this->totalPrice = tt;
}

__int64 ORDER::getTotalPrice()
{
	return this->totalPrice;
}

void ORDER::Insert()
{
	bool isValid;
	do
	{
		cout << "Ngay tao don (dd/mm/yyyy): ";
		getline(cin, this->orderDate);

		stringstream orderDateStr(this->orderDate);
		vector<string> dateTime;
		string segment;
		while (getline(orderDateStr, segment, '/')) {
			dateTime.push_back(segment);
		}

		string isMonthValid = dateTime[1];
		string isYearValid = dateTime[2];
		if ((isMonthValid == "01" || isMonthValid == "02" || isMonthValid == "03" || isMonthValid == "04" 
			|| isMonthValid == "05" || isMonthValid == "06" || isMonthValid == "07" 
			|| isMonthValid == "08" || isMonthValid == "09" || isMonthValid == "10" || isMonthValid == "11" || isMonthValid == "12") && stoi(isYearValid) >= 2021)
		{
			isValid = true;
		}
		else {
			isValid = false;
		}
		if (!isValid) {
			cout << "Dinh dang sai, vui long nhap theo dinh dang (dd/mm/yyyy)!" << endl;
		}
	} while (!isValid);

	cout << "Ten khach hang: ";
	getline(cin, this->customerName);
	cout << "Dia chi: ";
	getline(cin, this->customerAddr);
}

void ORDER::Display()
{
	cout << "\t\t============>>CHI TIET DON HANG<<============" << endl;
	cout << "Ma don hang: " << this->orderNumber << endl;
	cout << "Ngay tao don: " << this->orderDate << endl;
	cout << "Ten khach hang: " << this->customerName << endl;
	cout << "Dia chi: " << this->customerAddr << endl;
	cout << "So dien thoai: " << this->customerPhone << endl;
}

void ORDER::DisplayProductList()
{
	cout << "Ten san pham: " << this->getProductName() << endl;
	cout << "Gia ban: " << this->formatCurrency(this->getPrice()) << " VND" << endl;
	cout << "So luong: " << this->getAmount() << endl;
	cout << "----------------------------" << endl;
}

void ORDER::WriteToFile(string& orderNumbs)
{
	string file_path = "DONHANG/CHITIETDONHANG_" + orderNumbs + ".txt";
	ofstream file_out(file_path);
	file_out << "\t\t============>>CHI TIET DON HANG<<============" << endl;
	file_out << "Ma don hang: " << this->orderNumber << endl;
	file_out << "Ngay tao don: " << this->orderDate << endl;
	file_out << "Ten khach hang: " << this->customerName << endl;
	file_out << "Dia chi: " << this->customerAddr << endl;
	file_out << "So dien thoai: " << this->customerPhone << endl;
	file_out.close();
}

void ORDER::WriteProductToFile(string& orderNumbs)
{
	string file_path = "DONHANG/CHITIETDONHANG_" + orderNumbs + ".txt";
	ofstream file_out(file_path, ios::app);
	file_out << "Ten san pham: " << this->getProductName() << endl;
	file_out << "Gia ban: " << this->formatCurrency(this->getPrice()) << " VND" << endl;
	file_out << "So luong: " << this->getAmount() << endl;
	file_out << "----------------------------" << endl;
	file_out.close();
}

string ORDER::formatCurrency(long long val)
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