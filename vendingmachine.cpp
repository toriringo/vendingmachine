#include "vendingmachine.h"
#include <iostream>
#include <algorithm>

VendingMachine::VendingMachine()
{
	initializeProduct();
}

void VendingMachine::initializeProduct()
{
    products.number = 1;
	products.product["nacchan"] = std::make_pair("NA-CCHAN!", 130);
}

void VendingMachine::run()
{
	showProduct();
	int charge = waitCharge();
    int choose = waitChoose();
    Products *product = check(charge, choose);
    giveProduct(product);
}

void VendingMachine::showProduct()
{
    // 商品番号
    std::cout << products.number;
    std::cout << " ";
    for(auto itr = products.product.begin(); itr != products.product.end(); ++itr){
        #ifdef _DEBUG
        // キー
        std::cout << itr->first << std::endl;
        #endif
        // 商品名
        std::cout << itr->second.first;
        std::cout << " ";
        // 価格
        std::cout << itr->second.second;
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

VendingMachine::Products * VendingMachine::check(const int charge, const int choose)
{
    //chargeとchooseでお金の確認やおつり、商品選択など
    return &products;
}

void VendingMachine::giveProduct(VendingMachine::Products *p)
{
    // 商品名
    std::cout << p->product["nacchan"].first;
    std::cout << "をお買い上げありがとうございます" << std::endl;
    std::cout << "・・・・・ゴトッ" << std::endl;
}
