#pragma once
#include <string>
#include <unordered_map>

class VendingMachine
{
public:
	VendingMachine();
	void run();

private:
	typedef struct
	{
		// 商品番号
		int number;
		// キー, 商品名, 価格
		std::unordered_map<std::string, std::pair<std::string, int>> product;
	}Product;

	Product products;

	void initializeProduct();
	void showProduct();
	int waitCharge();
   	int waitChoose();
	Product *check(const int charge, const int choose);
	void giveProduct(Product *p);
};
