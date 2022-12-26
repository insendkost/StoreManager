#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_


#include "general.h"
#include "product.h"
#include "shopping.h"

typedef struct customer {
	char* customer_name;
	ShoppingCart* shp_cart;


}Customer;

void printShoppingCustomers(Customer** listOfCustomers, int num);
void printListOfCustomers(Customer** listOfCustomers, int numOfCustomers);
void printCustomersData(Customer* pCustomer);
void printCustShoppingItems(Customer** pCustomerList, Product** productsList, int cust_number);

Customer* initCustomerList();
void initCustomer(Customer* pCustomer);

void shoppingCartPrint(Customer* pCustomer);
int isCustomer(Customer* pCustomer, char* name);
void freeCust(Customer* pCust);



#endif // !_CUSTOMER_H_


