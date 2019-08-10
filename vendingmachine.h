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
		int id;
		std::string name;
		int price;
	}Product;

	typedef struct
	{
		Product product;
		int num;
	}ProductNum;

	std::vector<ProductNum> m_products;

	void initializeProducts();
	void showProducts();
	int waitCharge();
	int waitChoose();
	ProductNum *chooseProduct(const int choose);
	bool calcMoney(const int price, const int charge);
	void giveProduct(ProductNum *productnum);
};
