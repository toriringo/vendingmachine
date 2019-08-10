#include "vendingmachine.h"
#include <iostream>
#include <algorithm>

VendingMachine::VendingMachine()
{
	initializeProduct();
}

void VendingMachine::initializeProduct()
{
	products["Nacchan"] = std::make_pair("Nacchan", 130);
}

void VendingMachine::run()
{
	showProduct();
	waitCharge();	
	waitChoose();
}

void VendingMachine::showProduct()
{
	std::unordered_map<std::string, std::pair<std::string, int>>::iterator ite = products.begin();
/*
	std::for_each(products.begin(),
	              products.end(),
	              [](std::unordered_map<std::string, std::pair<std::string, int>>) p){
		cout << p.first << p.second << endl;
*/
/*
	while(ite != products.end()){
		std::cout << ite[""].first << ite[""].second << std::endl;
	}
*/
}

void VendingMachine::waitCharge()
{
	std::cin >> charge;
}

void VendingMachine::waitChoose()
{
}

