#pragma once
#include <string>
#include <vector>

class VendingMachine
{
public:
	VendingMachine();
	void run();

private:
	typedef struct
	{
		int number;
		std::string name;
        int price;
	}Product;

	std::vector<Product> products;

	void initializeProduct();
	void showProduct();
	int waitCharge();
   	int waitChoose();
	Product *chooseProduct(const int choose);
    bool calcMoney(const int price, const int charge);
	void giveProduct(Product *p);
};
