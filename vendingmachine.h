#pragma once
#include <string>
#include <unordered_map>

class VendingMachine
{
public:
	VendingMachine();
	void run();
private:
	void initializeProduct();
	void showProduct();
	void waitCharge();
	void waitChoose();

	int charge;
	std::unordered_map<std::string, std::pair<std::string, int>> products;
};

