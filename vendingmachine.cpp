#include "vendingmachine.h"
#include <iostream>
#include <algorithm>
#include <utility>

VendingMachine::VendingMachine()
{
	initializeProduct();
}

void VendingMachine::initializeProduct()
{
    VendingMachine::Product p;
    p.number = 1;
    p.name = "Nacchan!";
    p.price = 130;
	products.push_back(p);
}

void VendingMachine::run()
{
	showProduct();
	int charge = waitCharge();
	int choose = waitChoose();
	Product *p = chooseProduct(choose);
    bool okng = calcMoney(p->price, charge);
	if(okng == true){
        giveProduct(p);
    }
}

void VendingMachine::showProduct()
{
    for(int i = 0; i < products.size(); i++){
	    std::cout << products[i].number;
	    std::cout << " ";
	    std::cout << products[i].name;
	    std::cout << " ";
	    std::cout << products[i].price;
	    std::cout << "円" << std::endl;
	}
}

int VendingMachine::waitCharge()
{
	int charge;
	std::cout << "お金をいれてください" << std::endl;
	std::cin >> charge;
	return charge;
}

int VendingMachine::waitChoose()
{
	int choose;
	std::cout << "商品をえらんでください" << std::endl;
	std::cin >> choose;
	return choose;
}

VendingMachine::Product *VendingMachine::chooseProduct(const int choose)
{
    int i;

    for(i = 0; i < products.size(); i++){
        if(products[i].number == choose){
            break;
        }
    }

	return &products[i];
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

void VendingMachine::giveProduct(VendingMachine::Product *p)
{
	std::cout << p->name;
	std::cout << " をお買い上げありがとうございます" << std::endl;
	std::cout << "・・・・・ゴトッ" << std::endl;
}
