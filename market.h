#ifndef _MARKET_H_
#define _MARKET_H_

#include "address.h"
#include "customer.h"
#include "product.h"

typedef struct market {
	
	char* marketName;
	Address address;
	Customer** customersList;
	int customersNum;
	Product** productsList;
	//int productsNumber;

}Market;

//start
void initSuperMarket(Market* pMarket);

//market prints
void printMarketName(char* pName);
void printCustomersList(Market* pMarket);
void printCustomersListHelper(Market* pMarket, int numOfcutomers);
void printProductsList(Market* pMarket);
void printListOfShoppingUsers(Market* pMarket);
//Menu
//#1
void printMarketInfo(Market* pMarket);
//#2
void addProductToMarket(Market* pMarket);
//#3
void addCustomer(Market* pMarket);
//#4
void startShoppingProcess(Market* pMarket);
//#5
void printShoppingCartInfo(Market* pMarket);
//#6
void proceedPayment(Market* pMarket);
//#7
void printProductsListByType(Market* pMarket);

//ADDITIONAL
void addDefaultProducts(Market* pMarket);

void fillCart(Market* pMarket, ShoppingCart* pCart);
int addNewItemToCart(Product* pProduct, ShoppingItem* pItem, ShoppingItem** pShoppingList,int items_to_add, int basket_amount);
Customer* createShoppingCustomer(Market* pMarket);
Customer* findCustomer(Market* pMarket, char* name);

Product* findProductByBarcode(Market* pMarket, char* pBarcode);
Product* getUserProduct(Market* pMarket, char* pBarcode);
Product* getProductDetails(Market* pMarket, int* count);

void editStockProduct(Product* pProduct, int index);
void proceedUserPayment(Market* pMarket);
float getAmountToPay(Customer* pCustomer);
void printProductsListWithType(Market* pMarket, int choice);
void freeMarket(Market* pMarket);
void freeAddress(Address* pAddress);

#endif // !_MARKET_H_
