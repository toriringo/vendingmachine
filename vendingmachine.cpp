#include "vendingmachine.h"
#include <iostream>
#include <algorithm>
#include <utility>

VendingMachine::VendingMachine()
{
	initializeProducts();
}

void VendingMachine::initializeProducts()
{
	VendingMachine::ProductNum productnum;
	productnum.product.id = 1;
	productnum.product.name = "Nacchan!";
	productnum.product.price = 130;
	productnum.num = 20;

	m_products.push_back(productnum);
}

void VendingMachine::run()
{
	showProducts();
	int choose = waitChoose();
	int charge = waitCharge();
	ProductNum *productnum = chooseProduct(choose);
	bool chargeFlag = calcMoney(productnum->product.price, charge);
	if(chargeFlag == true){
		giveProduct(productnum);
	}
}

void VendingMachine::showProducts()
{
	for(int i = 0; i < m_products.size(); i++){
		std::cout << m_products[i].product.id;
		std::cout << " ";
		std::cout << m_products[i].product.name;
		std::cout << " ";
		std::cout << m_products[i].product.price;
		std::cout << "円" << std::endl;
		#ifdef _DEBUG
		std::cout << m_products[i].num << std::endl;
		#endif
	}
}

int VendingMachine::waitChoose()
{
	int choose;

	do{
		std::cout << "商品をえらんでください ";
		std::cin >> choose;
	}while(choose > m_products.size() || choose < 1);

	return choose;
}

int VendingMachine::waitCharge()
{
	int charge;
	std::cout << "お金をいれてください ";
	std::cin >> charge;
	return charge;
}

VendingMachine::ProductNum *VendingMachine::chooseProduct(const int choose)
{
	int i;

	for(i = 0; i < m_products.size(); i++){
		if(m_products[i].product.id == choose){
			break;
		}
	}

	return &(products[i]);
}

bool VendingMachine::calcMoney(const int price, const int charge)
{
	int change = charge - price;

	if(change > 0){
		std::cout << "おつりは ";
		std::cout << change;
		std::cout << " 円です" << std::endl;
		return true;
	}
	else if(change == 0){
		return true;
	}
	else{
		std::cout << "料金がたりません" << std::endl;
		return false;
	}
}

void VendingMachine::giveProduct(VendingMachine::ProductNum *productnum)
{
	std::cout << productnum->product.name;
	std::cout << " をお買い上げありがとうございます" << std::endl;
	productnum->num -= 1;
	std::cout << "・・・・・ゴトッ" << std::endl;
}
