#define _CRT_SECURE_NO_WARNINGS
#pragma warning( disable : 4267 4083 )
#include "BRAND.h"
#include "PRODUCT.h"
#include "ORDER.h"
#include "APP.h"
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<algorithm>
#include <fstream>

using namespace std;

int main() {
	vector<BRANDPRODUCT*> brandProductList;
	vector<BRANDMOTORPRODUCT*> brandMotorProductList;
	APP* app = new APP;
	app->Menu();
	system("pause");
	return 0;
}

APP::APP()
{
}

APP::~APP()
{
}

void APP::setBrandNameList(vector<string> brandNameList)
{
	this->brandNameList.swap(brandNameList);
}

string APP::formatCurrency(long long val)
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

bool APP::SortBySecond(const pair<string, int>& a, const pair<string, int>& b)
{
	return (a.second > b.second);
}

void APP::Menu()
{
	MOTORBRAND* brand = new MOTORBRAND;
	BRANDPRODUCT* brandProduct = new BRANDPRODUCT;
	BRANDMOTORPRODUCT* brandMotorProduct = new BRANDMOTORPRODUCT;
	ORDER* order = new ORDER;
	ORDER* productLists = new ORDER;
	vector<BRANDMOTORPRODUCT*> brandMotorProductList;
	vector<BRANDPRODUCT*> brandProductList;
	vector<ORDER*> orderProductList;
	while (1)
	{
		system("cls");
		int select;
		cout << "\t\t============>>HE THONG QUAN LI<<============" << endl;
		cout << "\n\t\t1. Quan li Danh muc" << endl;
		cout << "\t\t2. Quan li Don hang " << endl;
		cout << "\t\t3. Thong ke Bao cao" << endl;
		cout << "\t\t0. Ket thuc Chuong trinh" << endl;
		cout << "\n\t\tNhap lua chon: ";
		cin >> select;
		if (select == 1)
		{
			while (1)
			{
				brand->setBrandName(brandNameList);
				system("cls");
				int select;
				cout << "\t\t============>>QUAN LI DANH MUC<<============" << endl;
				cout << "\n\t\t1. Quan li Hang xe" << endl;
				cout << "\t\t2. Quan li San pham" << endl;
				cout << "\t\t0. Quay lai" << endl;
				cout << "\n\t\tNhap lua chon: ";
				cin >> select;
				if (select == 1) {
					while (1)
					{
						system("cls");
						int select;
						cout << "\t\t============>>QUAN LY HANG XE<<============" << endl;
						cout << "\n\t\t1. Them Hang xe" << endl;
						cout << "\t\t2. Xuat Hang xe" << endl;
						cout << "\t\t3. Cap nhat Hang xe" << endl;
						cout << "\t\t4. Xoa Hang xe" << endl;
						cout << "\t\t0. Quay lai" << endl;
						cout << "\n\t\tNhap lua chon: ";
						cin >> select;
						if (select == 1)
						{
							brand->Insert();
						}
						else if (select == 2)
						{
							brand->Display();
						}
						else if (select == 3)
						{
							brand->Update();
						}
						else if (select == 4)
						{
							brand->Delete();
						}
						else if (select == 0)
						{
							this->setBrandNameList(brand->getBrandName());
							break;
						}
					}
				}
				else if (select == 2)
				{
					size_t size = this->brandNameList.size();
					while (1)
					{
						system("cls");
						int select;
						cout << "\t\t============>>QUAN LI SAN PHAM<<============" << endl;
						cout << "\n\t\t1. Them San pham" << endl;
						cout << "\t\t2. Xuat San pham" << endl;
						cout << "\t\t3. Cap nhat Xe may" << endl;
						cout << "\t\t4. Xoa Xe may" << endl;
						cout << "\t\t0. Quay lai" << endl;
						cout << "\n\t\tNhap lua chon: ";
						cin >> select;
						if (select == 1)
						{
							system("cls");
							if (size == 0)
							{
								cout << "Chua ton tai hang xe, vui long kiem tra lai!" << endl;
								system("pause");
							}
							else {
								system("cls");
								int select;
								cout << "\t\t============>>QUAN LI SAN PHAM<<============" << endl;
								cout << "\n\t\t1. Them San pham theo Hang" << endl;
								cout << "\t\t2. Them Xe may theo Hang" << endl;
								cout << "\t\t0. Quay lai" << endl;
								cout << "\t\tNhap lua chon: ";
								cin >> select;
								if (select == 1)
								{
									while (1)
									{
										system("cls");
										bool flag;
										do
										{
											string brandName;
											cin.ignore();
											cout << "Nhap hang can them san pham (Khong phan biet chu hoa/ thuong): ";
											getline(cin, brandName);
											transform(brandName.begin(), brandName.end(), brandName.begin(), ::toupper);
											flag = true;
											for (size_t i = 0; i < size; i++)
											{
												if (brandName == this->brandNameList[i])
												{
													flag = true;
													bool duplChecking;
													string productName;

													// CHECK DUPLICATE ITEM
													do
													{
														cout << "Ten san pham: ";
														getline(cin, productName);
														transform(productName.begin(), productName.end(), productName.begin(), ::toupper);
														duplChecking = false;
														size_t brandProductListSize = brandProductList.size();
														for (size_t j = 0; j < brandProductListSize; j++)
														{
															if (brandProductList[j]->getProductName() == productName)
															{
																duplChecking = true;
															}
														}
														if (duplChecking)
														{
															cout << "San pham bi trung, vui long kiem tra lai";
														}
													} while (duplChecking);
													brandProduct = new BRANDPRODUCT;
													brandProduct->setProductName(productName);
													brandProduct->Insert();
													brandProduct->setBrand(brandName);
													brandProductList.push_back(brandProduct);
													cout << "Them san pham thanh cong!" << endl;
													system("pause");
													break;
												}
												else {
													flag = false;
												}
											}
											if (!flag)
											{
												cout << "Hang chua ton tai, vui long kiem tra lai!";
											}
										} while (!flag);

										// CHECK WHETHER USER WANT TO CONTINOUSLY INSERT OR NOT?
										int luaChon;
										cout << "\nBan co muon tiep tuc them san pham khong? (1: Tiep tuc; 0: Dung lai): ";
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
								else if (select == 2)
								{
									while (1)
									{
										system("cls");
										bool flag;
										do
										{
											string brandName;
											cin.ignore();
											cout << "Nhap hang can them xe may (Khong phan biet chu hoa/ thuong): ";
											getline(cin, brandName);
											transform(brandName.begin(), brandName.end(), brandName.begin(), ::toupper);
											flag = true;
											for (size_t i = 0; i < size; i++)
											{
												if (brandName == this->brandNameList[i])
												{
													flag = true;
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
															cout << "San pham chua ton tai, vui long kiem tra lai";
														}
													} while (!existChecking);
													brandMotorProduct = new BRANDMOTORPRODUCT;
													brandMotorProduct->setMotorName(mortorName);
													brandMotorProduct->Insert();
													brandMotorProduct->setBrand(brandName);
													brandMotorProductList.push_back(brandMotorProduct);
													cout << "Them xe may thanh cong!" << endl;
													system("pause");
													break;
												}
												else {
													flag = false;
												}
											}
											if (!flag)
											{
												cout << "Hang chua ton tai, vui long kiem tra lai!";
											}
										} while (!flag);

										// CHECK WHETHER USER WANT TO CONTINOUSLY INSERT OR NOT?
										int luaChon;
										cout << "\nBan co muon tiep tuc them xe may khong? (1: Tiep tuc; 0: Dung lai): ";
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
								else if (select == 0)
								{
									break;
								}
							}
						}
						else if (select == 2)
						{
							system("cls");
							if (size == 0) {
								cout << "Chua ton tai hang xe, vui long kiem tra lai!" << endl;
								system("pause");
							}
							else {
								while (1)
								{
									int luaChon;
									cout << "\t\t============>>XUAT SAN PHAM<<============" << endl;
									cout << "\t\t1. Xuat San pham theo Hang" << endl;
									cout << "\t\t2. Xuat Xe may theo Hang" << endl;
									cout << "\t\t0. Quay lai" << endl;
									cout << "\t\tNhap lua chon: ";
									cin >> luaChon;
									if (luaChon == 1)
									{
										while (1)
										{
											system("cls");
											cout << "\t\t============>>XUAT SAN PHAM THEO HANG<<============" << endl;
											bool flag;
											do
											{
												string brandName;
												cin.ignore();
												cout << "Nhap hang can xuat san pham (Khong phan biet chu hoa/ thuong): ";
												getline(cin, brandName);
												transform(brandName.begin(), brandName.end(), brandName.begin(), ::toupper);
												flag = true;
												for (size_t i = 0; i < size; i++)
												{
													if (brandName == this->brandNameList[i])
													{
														flag = true;
														size_t brandProductListSize = brandProductList.size();
														if (brandProductListSize == 0)
														{
															cout << "Chua ton tai san pham, vui long kiem tra lai!" << endl;
															system("pause");
															break;
														}
														for (size_t j = 0; j < brandProductListSize; j++)
														{
															if (brandName == brandProductList[j]->getBrand())
															{
																brandProductList[j]->Display();
															}
															
														}
														break;
													}
													else {
														flag = false;
													}
												}
												if (!flag)
												{
													cout << "Hang chua ton tai, vui long kiem tra lai!";
												}
											} while (!flag);

											// CHECK WHETHER USER WANT TO CONTINOUSLY INSERT OR NOT?
											int luaChon;
											cout << "\nBan co muon tiep tuc xuat san pham khong? (1: Tiep tuc; 0: Dung lai): ";
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
									else if (luaChon == 2)
									{
										while (1)
										{
											system("cls");
											cout << "\t\t============>>XUAT XE MAY THEO HANG<<============" << endl;
											bool flag;
											do
											{
												string brandName;
												cin.ignore();
												cout << "Nhap hang can xuat xe may (Khong phan biet chu hoa/ thuong): ";
												getline(cin, brandName);
												transform(brandName.begin(), brandName.end(), brandName.begin(), ::toupper);
												flag = true;
												for (size_t i = 0; i < size; i++)
												{
													if (brandName == this->brandNameList[i])
													{
														flag = true;
														size_t brandMotorProductListSize = brandMotorProductList.size();
														if (brandMotorProductListSize == 0)
														{
															cout << "Chua ton tai san pham, vui long kiem tra lai!" << endl;
															system("pause");
															break;
														}
														for (size_t j = 0; j < brandMotorProductListSize; j++)
														{
															if (brandName == brandMotorProductList[j]->getBrand())
															{
																brandMotorProductList[j]->Display();
																cout << "---------------------------------" << endl;
															}
														}
														break;
													}
													else {
														flag = false;
													}
												}
												if (!flag)
												{
													cout << "Hang chua ton tai, vui long kiem tra lai!";
												}
											} while (!flag);

											// CHECK WHETHER USER WANT TO CONTINOUSLY INSERT OR NOT?
											int luaChon;
											cout << "\nBan co muon tiep tuc xuat xe may khong? (1: Tiep tuc; 0: Dung lai): ";
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
									else if (luaChon == 0)
									{
										break;
									}
								}
							}
						}
						else if (select == 3)
						{
							brandMotorProduct->Update(brandMotorProductList, brandProductList);
						}
						else if (select == 4)
						{
							brandMotorProduct->Delete(brandMotorProductList);
						}
						else if (select == 0)
						{
							break;
						}
					}
				}
				else if (select == 0)
				{
					break;
				}
			}
		}
		else if (select == 2)
		{
			while (1)
			{
				system("cls");
				int luaChon;
				cout << "\t\t============>>QUAN LI DON HANG<<============" << endl;
				cout << "\n\t\t1. Them Don hang" << endl;
				cout << "\t\t2. Xem Chi tiet Don hang" << endl;
				cout << "\t\t3. Cap nhat Don hang" << endl;
				cout << "\t\t4. Xoa Don hang" << endl;
				cout << "\t\t5. Hien thi Don hang trong thang" << endl;
				cout << "\t\t6. Xuat hoa don chi tiet don hang" << endl;
				cout << "\t\t0. Quay lai" << endl;
				cout << "\n\t\tNhap lua chon: ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					system("cls");
					cout << "============>>THEM DON HANG<<============" << endl;
					order = new ORDER;
					vector<ORDER*> productList;
					bool duplChecking, exist;
					string orderNumber, customerPhone;
					// CHECK DUPLICATE ITEM
					do
					{
						cin.ignore();
						cout << "Ma don hang: ";
						getline(cin, orderNumber);
						transform(orderNumber.begin(), orderNumber.end(), orderNumber.begin(), ::toupper);
						duplChecking = false;
						exist = false;
						size_t orderProductListSize = orderProductList.size();
						for (size_t i = 0; i < orderProductListSize; i++)
						{
							if (orderProductList[i]->getOrderNumber() == orderNumber)
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
					order->setOrderNumber(orderNumber);
					order->Insert();
					do
					{
						cout << "So dien thoai: ";
						getline(cin, customerPhone);
						transform(customerPhone.begin(), customerPhone.end(), customerPhone.begin(), ::toupper);
						exist = false;
						size_t orderProductListSize = orderProductList.size();
						for (size_t i = 0; i < orderProductListSize; i++)
						{
							if (orderProductList[i]->getCustomerPhone() == customerPhone)
							{
								exist = true;
								break;
							}
						}
						if (exist)
						{
							cout << "So dien thoai bi trung, vui long kiem tra lai!" << endl;
						}
					} while (exist);
					order->setCustomerPhone(customerPhone);
					while (1)
					{
						system("cls");
						int luaChon;
						cout << "============>>SAN PHAM DA MUA<<============" << endl;
						cout << "1. Them san pham" << endl;
						cout << "0. Thoat" << endl;
						cout << "Nhap lua chon: ";
						cin >> luaChon;
						if (luaChon == 1)
						{
							system("cls");
							string productName;
							bool existChecking;
							productLists = new ORDER;
							do
							{
								cin.ignore();
								cout << "Nhap ten san pham: ";
								getline(cin, productName);
								transform(productName.begin(), productName.end(), productName.begin(), ::toupper);
								existChecking = false;
								size_t brandProductListSize = brandProductList.size();
								for (size_t i = 0; i < brandProductListSize; i++)
								{
									if (brandProductList[i]->getProductName() == productName)
									{
										existChecking = true;
										int amount, productAmount;
										__int64 price, totalPrice;

										productLists->setProductName(productName);

										fflush(stdin);
										cout << "Gia ban: ";
										cin >> price;
										productLists->setPrice(price);

										productAmount = brandProductList[i]->getAmount();
										do
										{
											cout << "So luong: ";
											cin >> amount;
											if (amount > productAmount || amount <= 0)
											{
												cout << "So luong khong hop le, vui long nhap lai!" << endl;
											}
										} while (amount > productAmount || amount <= 0);
										productLists->setAmount(amount);
										
										// Cap nhat so luong hang ton kho
										productAmount -= amount;
										brandProductList[i]->setAmount(productAmount);

										totalPrice = order->getTotalPrice();
										totalPrice += price * amount;
										order->setTotalPrice(totalPrice);

										productList.push_back(productLists);
										cout << "San pham da duoc them!" << endl;
										system("pause");
										break;
									}
								}
								if (!existChecking)
								{
									cout << "San pham khong ton tai, vui long kiem tra lai!";
								}
							} while (!existChecking);
						}
						else if (luaChon == 0)
						{
							break;
						}
					}
					order->setProductLists(productList);
					orderProductList.push_back(order);
					cout << "Don hang da duoc tao thanh cong!" << endl;
					system("pause");
				}
				else if (luaChon == 2)
				{
					system("cls");
					size_t orderProductListSize = orderProductList.size();
					if (orderProductListSize == 0)
					{
						cout << "Don hang rong, vui long kiem tra lai!" << endl;
						system("pause");
					}
					else {
						while (1)
						{
							bool existChecking;
							string orderNumbs;
							do
							{
								cin.ignore();
								cout << "Nhap ma don hang can tra cuu (Khong phan biet chu hoa/ thuong): ";
								getline(cin, orderNumbs);
								transform(orderNumbs.begin(), orderNumbs.end(), orderNumbs.begin(), ::toupper);
								existChecking = false;
								for (size_t i = 0; i < orderProductListSize; i++)
								{
									if (orderProductList[i]->getOrderNumber() == orderNumbs)
									{
										existChecking = true;
										orderProductList[i]->Display();
										vector<ORDER*> buffer = orderProductList[i]->getProductLists();
										size_t bufferSize = buffer.size();
										cout << "\n- San pham da mua" << endl;
										cout << "----------------------------" << endl;
										for (size_t j = 0; j < bufferSize; j++)
										{
											buffer[j]->DisplayProductList();
										}
										cout << "TONG TIEN PHAI TRA: " << orderProductList[i]->formatCurrency(orderProductList[i]->getTotalPrice()) << " VND" << endl;
										break;
									}
								}
								if (!existChecking)
								{
									cout << "Ma don hang khong dung, vui long kiem tra lai";
								}
							} while (!existChecking);

							int luaChon;
							cout << "\nBan co muon tiep tuc xuat chi tiet don hang khong? (1: Tiep tuc; 0: Dung lai): ";
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
				else if (luaChon == 3)
				{
					system("cls");
					size_t orderProductListSize = orderProductList.size();
					if (orderProductListSize == 0)
					{
						cout << "Chua ton tai don hang, vui long kiem tra lai!" << endl;
						system("pause");
					}
					else {
						while (1)
						{
							bool existChecking;
							string orderNumbs;
							do
							{
								cin.ignore();
								cout << "Nhap ma don hang can cap nhat (Khong phan biet chu hoa/ thuong): ";
								getline(cin, orderNumbs);
								transform(orderNumbs.begin(), orderNumbs.end(), orderNumbs.begin(), ::toupper);
								existChecking = false;
								for (size_t i = 0; i < orderProductListSize; i++)
								{
									if (orderProductList[i]->getOrderNumber() == orderNumbs)
									{
										existChecking = true;
										// LOGIC HERE
										// Cap nhat so luong ton kho
										vector<ORDER*> product = orderProductList[i]->getProductLists();
										size_t productSize = product.size();
										size_t brandProductListSize = brandProductList.size();
										for (size_t j = 0; j < productSize; j++)
										{
											for (size_t k = 0; k < brandProductListSize; k++)
											{
												if (product[j]->getProductName() == brandProductList[k]->getProductName())
												{
													brandProductList[k]->setAmount(brandProductList[k]->getAmount() + product[j]->getAmount());
												}
											}
										}
										bool duplChecking, exist;
										string newOrderNums, customerPhone;
										// CHECK DUPLICATE ITEM
										do
										{
											cout << "Ma don hang moi: ";
											getline(cin, newOrderNums);
											transform(newOrderNums.begin(), newOrderNums.end(), newOrderNums.begin(), ::toupper);
											duplChecking = false;
											size_t orderProductListSize = orderProductList.size();
											for (size_t i = 0; i < orderProductListSize; i++)
											{
												if (orderProductList[i]->getOrderNumber() == newOrderNums)
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
										orderProductList[i]->setOrderNumber(newOrderNums);
										orderProductList[i]->Insert();
										do
										{
											cout << "So dien thoai: ";
											getline(cin, customerPhone);
											transform(customerPhone.begin(), customerPhone.end(), customerPhone.begin(), ::toupper);
											exist = false;
											size_t orderProductListSize = orderProductList.size();
											for (size_t i = 0; i < orderProductListSize; i++)
											{
												if (orderProductList[i]->getCustomerPhone() == customerPhone)
												{
													exist = true;
													break;
												}
											}
											if (exist)
											{
												cout << "So dien thoai bi trung, vui long kiem tra lai!" << endl;
											}
										} while (exist);
										order->setCustomerPhone(customerPhone);
										vector<ORDER*> productList;
										int initializePrice = 0;
										while (1)
										{
											system("cls");
											int luaChon;
											cout << "============>>SAN PHAM DA MUA<<============" << endl;
											cout << "1. Them san pham" << endl;
											cout << "0. Thoat" << endl;
											cout << "Nhap lua chon: ";
											cin >> luaChon;
											if (luaChon == 1)
											{
												system("cls");
												string productName;
												bool existChecking;
												productLists = new ORDER;
												++initializePrice;
												if (initializePrice == 1)
												{
													order->setTotalPrice(0);
												}
												do
												{
													cin.ignore();
													cout << "Nhap ten san pham: ";
													getline(cin, productName);
													transform(productName.begin(), productName.end(), productName.begin(), ::toupper);
													existChecking = false;
													size_t brandProductListSize = brandProductList.size();
													for (size_t i = 0; i < brandProductListSize; i++)
													{
														if (brandProductList[i]->getProductName() == productName)
														{
															existChecking = true;
															int amount, productAmount;
															__int64 price, totalPrice;
															productLists->setProductName(productName);
															fflush(stdin);
															cout << "Gia ban: ";
															cin >> price;
															productLists->setPrice(price);

															productAmount = brandProductList[i]->getAmount();
															do
															{
																cout << "So luong: ";
																cin >> amount;
																if (amount > productAmount || amount <= 0)
																{
																	cout << "So luong khong hop le, vui long nhap lai!" << endl;
																}
															} while (amount > productAmount || amount <= 0);
															productLists->setAmount(amount);

															// Cap nhat so luong hang ton kho
															productAmount -= amount;
															brandProductList[i]->setAmount(productAmount);		

															totalPrice = order->getTotalPrice();
															totalPrice += price * amount;
															order->setTotalPrice(totalPrice);

															productList.push_back(productLists);
															cout << "San pham da duoc them!" << endl;
															system("pause");
															break;
														}
													}
													if (!existChecking)
													{
														cout << "San pham khong ton tai, vui long kiem tra lai!";
													}
												} while (!existChecking);
											}
											else if (luaChon == 0)
											{
												break;
											}
										}
										orderProductList[i]->setProductLists(productList);
										cout << "Chi tiet don hang da duoc cap nhat thanh cong!" << endl;
										system("pause");
										break;
									}
								}
								if (!existChecking)
								{
									cout << "Ma don hang khong ton tai, vui long kiem tra lai!";
								}
							} while (!existChecking);
							int luaChon;
							cout << "\nBan co muon tiep tuc cap nhat chi tiet don hang khong? (1: Tiep tuc; 0: Dung lai): ";
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
				else if (luaChon == 4)
				{
					system("cls");
					size_t orderProductListSize = orderProductList.size();
					if (orderProductListSize == 0)
					{
						cout << "Chua ton tai don hang, vui long kiem tra lai!" << endl;
						system("pause");
					}
					else {
						while (1)
						{
							bool existChecking;
							string orderNumbs;
							do
							{
								cin.ignore();
								cout << "Nhap ma don hang can cap nhat (Khong phan biet chu hoa/ thuong): ";
								getline(cin, orderNumbs);
								transform(orderNumbs.begin(), orderNumbs.end(), orderNumbs.begin(), ::toupper);
								existChecking = false;
								for (size_t i = 0; i < orderProductListSize; i++)
								{
									if (orderProductList[i]->getOrderNumber() == orderNumbs)
									{
										existChecking = true;
										// LOGIC HERE
										int luaChon;
										cout << "Ban co chac chan muon xoa khong? (1: Co; 0: Khong): ";
										cin >> luaChon;
										if (luaChon == 1)
										{
											auto buffer = orderProductList.begin();
											while (buffer != orderProductList.end()) {
												if ((*buffer)->getOrderNumber() == orderNumbs)
												{
													delete* buffer;
													orderProductList.erase(buffer);
													break;
												}
												buffer++;
											}
											cout << "Xoa thanh cong!" << endl;
											orderProductListSize--;
											break;
										}
										else if (luaChon == 0)
										{
											system("cls");
											break;
										}
										break;
									}
								}
								if (!existChecking)
								{
									cout << "Ma don hang khong ton tai, vui long kiem tra lai!";
								}
							} while (!existChecking);
							if (orderProductListSize != 0)
							{
								int luaChon;
								cout << "\nBan co muon tiep tuc xoa don hang khac khong? (1: Tiep tuc; 0: Dung lai): ";
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
								cout << "Danh sach don hang rong, vui long kiem tra lai!" << endl;
								system("pause");
								break;
							}
						}
					}
				}
				else if (luaChon == 5)
				{
					system("cls");
					time_t theTime = time(NULL);
					struct tm* aTime = localtime(&theTime);
					int month = aTime->tm_mon + 1;		
					int year = aTime->tm_year + 1900;
					size_t orderProductListSize = orderProductList.size();
					bool exist = false;
					for (size_t i = 0; i < orderProductListSize; i++)
					{
						string monthBuffer = orderProductList[i]->getOrderDate().substr(3, 2);
						string yearBuffer = orderProductList[i]->getOrderDate().substr(6, 4);
						if (month == stoi(monthBuffer) && year == stoi(yearBuffer))	
						{
							cout << "Ma don hang:  " << orderProductList[i]->getOrderNumber() << endl;
							cout << "Ngay tao don: " << orderProductList[i]->getOrderDate() << endl;
							cout << "---------------" << endl;
							exist = true;
						}
					}
					if (!exist) {
						cout << "Chua ton tai don hang" << endl;
					}
					system("pause");
				}
				else if (luaChon == 6)
				{
					system("cls");
					size_t orderProductListSize = orderProductList.size();
					if (orderProductListSize == 0)
					{
						cout << "Don hang rong, vui long kiem tra lai!" << endl;
						system("pause");
					}
					else {
						while (1)
						{
							bool existChecking;
							string orderNumbs;
							do
							{
								cin.ignore();
								cout << "Nhap ma don hang can xuat hoa don (Khong phan biet chu hoa/ thuong): ";
								getline(cin, orderNumbs);
								transform(orderNumbs.begin(), orderNumbs.end(), orderNumbs.begin(), ::toupper);
								existChecking = false;
								for (size_t i = 0; i < orderProductListSize; i++)
								{
									if (orderProductList[i]->getOrderNumber() == orderNumbs)
									{
										existChecking = true;
										string file_path = "DONHANG/CHITIETDONHANG_" + orderNumbs + ".txt";
										ofstream file_out(file_path, ios::app);
										orderProductList[i]->WriteToFile(orderNumbs);
										vector<ORDER*> buffer = orderProductList[i]->getProductLists();
										size_t bufferSize = buffer.size();
										file_out << "\n- San pham da mua" << endl;
										file_out << "----------------------------" << endl;
										for (size_t j = 0; j < bufferSize; j++)
										{
											buffer[j]->WriteProductToFile(orderNumbs);
										}
										file_out << "TONG TIEN PHAI TRA: " << orderProductList[i]->formatCurrency(orderProductList[i]->getTotalPrice()) << " VND" << endl;
										file_out.close();
										cout << "Don hang " << orderNumbs << " da duoc xuat thanh cong, vui long kiem tra o thu muc DONHANG" << endl;
										system("pause");
										break;
									}
								}
								if (!existChecking)
								{
									cout << "Ma don hang khong dung, vui long kiem tra lai";
								}
							} while (!existChecking);

							int luaChon;
							cout << "\nBan co muon tiep tuc xuat hoa don chi tiet don hang khong? (1: Tiep tuc; 0: Dung lai): ";
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
				else if (luaChon == 0)
				{
					break;
				}
			}
		}
		else if (select == 3)
		{
			while (1)
			{
				system("cls");
				int luaChon;
				cout << "\t\t============>>THONG KE BAO CAO<<============" << endl;
				cout << "\n\t\t1. Cac mat hang sap het" << endl;
				cout << "\t\t2. Mat hang ban chay trong thang truoc" << endl;
				cout << "\t\t3. Doanh thu, loi nhuan theo thang" << endl;
				cout << "\t\t0. Quay lai" << endl;
				cout << "\n\t\tNhap lua chon: ";
				cin >> luaChon;
				if (luaChon == 1)
				{
					system("cls");
					size_t brandProductListSize = brandProductList.size();
					if (brandProductListSize == 0)
					{
						cout << "Danh sach mat hang rong, vui long kiem tra lai!" << endl;
						system("pause");
					}
					else {
						while (1)
						{

							system("cls");
							cout << "\t\t============>>CAC MAT HANG SAP HET<<============" << endl;
							size_t brandProductListSize = brandProductList.size();
							for (size_t i = 0; i < brandProductListSize; i++)
							{
								if (brandProductList[i]->getAmount() < 10)
								{
									cout << "\nTen mat hang: " << brandProductList[i]->getProductName() << endl;
									cout << "So luong con lai: " << brandProductList[i]->getAmount() << endl;
									cout << "-------------------" << endl;
								}
							}
							system("pause");

							int luaChon;
							cout << "Ban co muon xuat hoa don cac mat hang sap het khong? (1: Co; 0: Khong): ";
							cin >> luaChon;
							if (luaChon == 1) {
								string file_path = "MATHANGSAPHET/DANHSACH.txt";
								ofstream file_out(file_path);
								file_out << "\t\t============>>CAC MAT HANG SAP HET<<============" << endl;
								size_t brandProductListSize = brandProductList.size();
								for (size_t i = 0; i < brandProductListSize; i++)
								{
									if (brandProductList[i]->getAmount() < 10)
									{
										file_out << "\nTen mat hang: " << brandProductList[i]->getProductName() << endl;
										file_out << "So luong con lai: " << brandProductList[i]->getAmount() << endl;
										file_out << "-------------------" << endl;
									}
								}
								file_out.close();
								cout << "Xuat hoa don thanh cong, vui long kiem tra o thu muc MATHANGSAPHET" << endl;
								system("pause");
								break;
							}
							else if (luaChon == 0)
							{
								system("cls");
								break;
							}
						}
					}					
				}
				else if (luaChon == 2)
				{
					while (1)
					{
						system("cls");
						cout << "\t\t============>>CAC MAT HANG BAN CHAY TRONG THANG TRUOC<<============" << endl;
						time_t theTime = time(NULL);
						struct tm* aTime = localtime(&theTime);
						int month = aTime->tm_mon;
						int year = aTime->tm_year + 1900;
						size_t orderProductListSize = orderProductList.size();
						bool exist = false;
						vector<pair<int, string>> product;

						for (size_t i = 0; i < orderProductListSize; i++)
						{
							string monthBuffer = orderProductList[i]->getOrderDate().substr(3, 2);
							string yearBuffer = orderProductList[i]->getOrderDate().substr(6, 4);
							if (month == stoi(monthBuffer) && year == stoi(yearBuffer))
							{
								exist = true;
								// LOGIC
								vector<ORDER*> productListBuff = orderProductList[i]->getProductLists();
								for (size_t j = 0; j < productListBuff.size(); j++)
								{
									product.push_back(make_pair(productListBuff[j]->getAmount(), productListBuff[j]->getProductName()));
								}
							}
						}
						if (!exist) {
							cout << "Chua ton tai don hang" << endl;
							system("pause");
							break;
						}

						// Handle duplicate
						for (size_t h = 0; h < product.size() - 1; h++)
						{
							for (size_t k = h + 1; k < product.size(); k++)
							{
								if (product[h].second == product[k].second)
								{
									product[h].first += product[k].first;
									product.erase(product.begin() + k);
								}
							}
						}

						// Sort 
						sort(product.begin(), product.end());
						reverse(product.begin(), product.end());
						cout << endl;
						for (size_t i = 0; i < product.size(); i++)
						{
							cout << i + 1 << ". Ten San pham: " << product[i].second << endl;
							cout << "So luong Da ban : " << product[i].first << endl;
							cout << "----------------------" << endl;
						}
						system("pause");

						int luaChon;
						cout << "Ban co muon xuat hoa don cac mat hang ban chay trong thang " << month << " khong? (1: Co; 0: Khong)";
						cin >> luaChon;
						if (luaChon == 1)
						{
							string file_path = "MATHANGBANCHAY/DANHSACHBANCHAY_THANG" + to_string(month) + ".txt";
							ofstream file_out(file_path);
							file_out << "\t\t============>>CAC MAT HANG BAN CHAY<<============" << endl;
							for (size_t i = 0; i < product.size(); i++)
							{
								file_out << i + 1 << ". Ten San pham: " << product[i].second << endl;
								file_out << "So luong Da ban : " << product[i].first << endl;
								file_out << "----------------------" << endl;
							}
							file_out.close();
							cout << "Xuat hoa don thanh cong, vui long kiem tra o thu muc MATHANGBANCHAY" << endl;
							system("pause");
							break;
						}
						else if (luaChon == 0)
						{
							system("cls");
							break;
						}
					}
				}
				else if (luaChon == 3)
				{
					while (1)
					{	
						system("cls");
						size_t orderProductListSize = orderProductList.size();
						if (orderProductListSize == 0)
						{
							cout << "Don hang rong, vui long kiem tra lai!" << endl;
							system("pause");
							break;
						}
						else
						{
							bool hasMonth;
							string isMonthValid, isYearValid;
							string time;
							__int64 totaRevenue = 0, totalProfit = 0, initialPrice = 0;
							do
							{
								bool isValid;
								hasMonth = false;
								do
								{
									cin.ignore();
									cout << "Nhap thang can xem doanh thu, loi nhuan (mm/yyyy): ";
									getline(cin, time);

									stringstream orderDateStr(time);
									vector<string> dateTime;
									string segment;
									while (getline(orderDateStr, segment, '/')) {
										dateTime.push_back(segment);
									}

									isMonthValid = dateTime[0];
									isYearValid = dateTime[1];
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
										cout << "Dinh dang sai, vui long nhap theo dinh dang (mm/yyyy)!";
									}
								} while (!isValid);
								size_t orderProductListSize = orderProductList.size();
								size_t brandProductListSize = brandProductList.size();
								for (size_t i = 0; i < orderProductListSize; i++)
								{
									string monthBuffer = orderProductList[i]->getOrderDate().substr(3, 2);
									string yearBuffer = orderProductList[i]->getOrderDate().substr(6, 4);
									if (isMonthValid == monthBuffer && isYearValid == yearBuffer)
									{
										// LOGIC
										hasMonth = true;

										// Handle revenue
										totaRevenue += orderProductList[i]->getTotalPrice();

										// Handle profit
										vector<ORDER*> productListBuff = orderProductList[i]->getProductLists();
										size_t productListBuffSize = productListBuff.size();
										for (size_t j = 0; j < productListBuffSize; j++)
										{
											for (size_t k = 0; k < brandProductListSize; k++)
											{
												if (productListBuff[i]->getProductName() == brandProductList[j]->getProductName())
												{
													initialPrice += productListBuff[i]->getAmount() * brandProductList[j]->getPrice();
												}
											}
										}
									}
								}
								if (!hasMonth) {
									cout << "Chua ton tai don hang, vui long kiem tra lai!";
								}
								else
								{
									cout << "\n- Tong doanh thu: " << formatCurrency(totaRevenue) << " VND" << endl;
									cout << "- Tong kinh phi bo ra ban dau: " << formatCurrency(initialPrice) << " VND" << endl;
									cout << "- Tong loi nhuan: " << formatCurrency(totaRevenue - initialPrice) << " VND" << endl;
								}
							} while (!hasMonth);
							system("pause");

							int luaChon;
							cout << "\nBan co muon xuat hoa don doanh thu, loi nhuan trong thang " << isMonthValid << " khong? (1: Co; 0: Khong): ";
							cin >> luaChon;
							if (luaChon == 1)
							{
								string file_path = "DOANHTHU_LOINHUAN/DOANHTHU_LOINHUAN_THANG" + isMonthValid + ".txt";
								ofstream file_out(file_path);
								file_out << "\t\t============>>DOANH THU, LOI NHUAN<<============" << endl;
								file_out << "\n- Tong doanh thu: " << formatCurrency(totaRevenue) << " VND" << endl;
								file_out << "- Tong kinh phi bo ra ban dau: " << formatCurrency(initialPrice) << " VND" << endl;
								file_out << "- Tong loi nhuan: " << formatCurrency(totaRevenue - initialPrice) << " VND" << endl;
								file_out.close();
								cout << "Xuat hoa don thanh cong, vui long kiem tra o thu muc DOANHTHU_LOINHUAN" << endl;
								system("pause");
								break;
							}
							else if (luaChon == 0) {
								system("cls");
								break;
							}
						}
					}
				}
				else if (luaChon == 0)
				{
					break;
				}
			}
		}
		else if (select == 0)
		{
			exit(1);
		}
	}
}

