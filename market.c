#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "market.h"
#include "address.h"
#include "customer.h"
#include "product.h"
#include "general.h"

//################################################################################
//			START
//################################################################################

void initSuperMarket(Market* pMarket) {

	if (pMarket == NULL)
	{
		printf("\nMarket init failed...\n");
		return;
	}
	Address* ptrAddress = malloc(sizeof(Address));
	ptrAddress = &pMarket->address;
	initAddress(ptrAddress);
	getAddress(ptrAddress);
	printf("Enter a market name:\n");
	pMarket->marketName = malloc(sizeof(char) * MAX_LEN);
	getName(pMarket->marketName);
	pMarket->customersList = malloc(sizeof(Customer*));
	pMarket->customersNum = 0;
	pMarket->productsList = malloc(sizeof(Product*));
	pMarket->productsNumber = 0;

	if (pMarket->productsList != NULL) {
		*(pMarket->productsList) = malloc(sizeof(Product*) + 1);
		addDefaultProducts(pMarket);
	}
	if (pMarket->customersList != NULL) {
		*(pMarket->customersList) = malloc(sizeof(Customer*) + 1);
	}
	printf("\nNew market initiated\n");
	
}

//################################################################################
//prints

void printMarketName(char* pName)
{
	printf("\n\tMarket name: [%s]\n", pName);
}

//################################################################################

void printCustomersList(Market* pMarket) {

	printf("\nCurrent list of customers:");
	if (pMarket->customersNum == 0)
	{
		printf("\n\tEmpty list - add some customers\n");
		return;
	}

	printCustomersListHelper(pMarket, pMarket->customersNum);
}

//################################################################################

void printCustomersListHelper(Market* pMarket, int numOfcutomers)
{
	Customer** listOfCustomers = pMarket->customersList;
	int total = numOfcutomers;
	for (int i = 0; i < numOfcutomers; i++)
	{
		printf("\nCustomer %d) [%s] \n", i + 1, listOfCustomers[i]->customer_name);

	}
	if (total == 1) {
		printf("Total: [%d] (customer)\n", pMarket->customersNum);
	}
	else {
		printf("Total: [%d] (customers)\n", pMarket->customersNum);
	}
	delimiter_dash();
}
//################################################################################
void printProductsList(Market* pMarket)
{
	printf("\nCurrent products in shop:");
	if (pMarket->productsNumber == 0)
	{
		printf("\n\tEmpty list - add some products\n");
		return;
	}
	printListOfProducts(pMarket->productsList,pMarket->productsNumber);
	delimiter_star();
}
//################################################################################

void printListOfShoppingUsers(Market* pMarket)
{
	if (pMarket->customersNum == 0)
	{
		printf("No shopping users, add some users");
		return;
	}
	printShoppingCustomers(pMarket->customersList,pMarket->customersNum);
}
//################################################################################



//################################################################################
//						MENU
//################################################################################
//1
void printMarketInfo(Market* pMarket) {
	if (!pMarket)
	{
		printf("\nObject doesn't exist....\n");
		return;
	}

	delimiter();
	printf("Super Market INFO:");
	//Address myAddress = pMarket->address;
	printMarketName(pMarket->marketName);
	printAddress(&pMarket->address);

	printCustomersList(pMarket);
	printProductsList(pMarket);
	delimiter_dash();
}
//################################################################################
//2
void addProductToMarket(Market* pMarket)
{
	Product** productsList = pMarket->productsList;
	int amount;
	char input[10];
	printf("How many products to add? \n");
	printf("Input ->");
	//scanf("%d",&amount);
	fgets(input, 10, stdin);
	if (sscanf(input, "%d", &amount) == 1)
		if (productsList != NULL)
		{
			pMarket->productsList = (Product**)realloc(pMarket->productsList, (pMarket->productsNumber + amount) * sizeof(Product*));;

			if (pMarket->productsList != NULL)
			{
				int i = 0;
				while (i < amount)
				{
					Product* pProduct = malloc(sizeof(Product) * 1);
					setProduct(pProduct);
					pMarket->productsList[pMarket->productsNumber] = pProduct;
					pMarket->productsNumber++;
					i++;
				}
			}
		}
}
//################################################################################
//3

void addCustomer(Market* pMarket)
{
	if (pMarket->customersList != NULL) {
		Customer** tmp = NULL;
		tmp = realloc(pMarket->customersList, (pMarket->customersNum + 1) * sizeof(Customer*));
		pMarket->customersList = tmp;
		if (pMarket->customersList != NULL)
		{
			pMarket->customersList[pMarket->customersNum] = malloc(sizeof(Customer));
			initCustomer(pMarket->customersList[pMarket->customersNum]);
		}

		pMarket->customersNum++;
	}
	else {
		pMarket->customersList = malloc(sizeof(Customer*));
		if (pMarket->customersList != NULL) {
			pMarket->customersList[0] = malloc(sizeof(Customer));
			initCustomer(pMarket->customersList[0]);
			pMarket->customersNum = 1;
		}
	}
}

//################################################################################
//4

void startShoppingProcess(Market* pMarket)
{
	if (pMarket->customersNum == 0)
	{
		printf("Error: no active customers found");
		return;
	}
	if (pMarket->productsNumber == 0)
	{
		printf("Error: no products found");
		return;
	}

	Customer* pCustomer = createShoppingCustomer(pMarket);
	if (pCustomer == NULL)
	{
		printf("Error: Invalid customer");
		return;
	}

	ShoppingCart* pCart = malloc(sizeof(ShoppingCart));
	initNewCart(pCart);
	fillCart(pMarket, pCart);
	pCustomer->shp_cart = pCart;
	
}

//################################################################################
//5

void printShoppingCartInfo(Market* pMarket)
{
	if (pMarket->customersNum == 0)
	{
		printf("\nError: no active Customers\n");
		return;
	}
	if (pMarket->customersList[pMarket->customersNum]->shp_cart == NULL)
	{
		printf("\nError: there is no shopping cards available\n");
		return;
	}
	if (pMarket->productsNumber == 0)
	{
		printf("\nError: no products in the market\n");
	}
	printCustShoppingItems(pMarket->customersList, pMarket->productsList, pMarket->customersNum);

}
//################################################################################
//6

void proceedPayment(Market* pMarket)
{
	printf("\nWho pays?\n");
	printf("\n->Choose from list<-\n");
	if (pMarket->customersNum == 0)
	{
		printf("\nError: No active customers in shop, add customers\n");
		return;
	}
	printListOfShoppingUsers(pMarket);
	proceedUserPayment(pMarket);


}
//################################################################################
//7
void printProductsListByType(Market* pMarket)
{
	if (pMarket->productsNumber == 0)
	{
		printf("Error: empty market, no products, add some");
		return;
	}
	printf("\nChoose a poduct type:\n");

	printListOfTypes();
	int choice = getUserChoice();

	if (choice < 1  || choice > pMarket->productsNumber)
	{
		printf("\nError: the choice is out of bound\n");
		return;
	}

	printProductsListWithType(pMarket, choice);


}

//################################################################################
//				ADDITIONAL
//################################################################################

void addDefaultProducts(Market* pMarket)
{
	int num_of_products = 5;
	if (pMarket != NULL && pMarket->productsList != NULL)
	{
		Product** tmp = pMarket->productsList;
		tmp = (Product**)realloc(pMarket->productsList, types_num * sizeof(Product*));
		pMarket->productsList = tmp;
		if (pMarket->productsList != NULL)
		{
			int i = 0;

			while (i < types_num)
			{
				Product* pProduct = malloc(sizeof(Product) * 1);
				editStockProduct(pProduct, i);
				pMarket->productsList[pMarket->productsNumber] = pProduct;
				pMarket->productsNumber++;
				i++;
			}
		}

	}
}


//################################################################################
void fillCart(Market* pMarket, ShoppingCart* pCart)
{
	printProductsList(pMarket);
	//choose a product from list
	int choice = getUserChoice();
	//cancel option - 0
	if (choice == 0)
		return;
	int amount = getUserChoice(); //how many products we buy
	Product* pProduct = pMarket->productsList[choice - 1]; //-1 because all indexes are printed aka i+1
	if (!pProduct)
	{
		printf("\nError:can't reach product, first add it to the system\n");
		return;
	}
	//lets add this product to shopping cart
	pCart->shopping_items_list = calloc((((size_t)pCart->shopping_items_num) + 1), sizeof(ShoppingItem*));
	ShoppingItem** shoppingList = pCart->shopping_items_list;
  	if(shoppingList)
	{
		int current_index = 0;
		current_index = pCart->shopping_items_num;
		ShoppingItem* shoppingItem = shoppingList[current_index];
		if (shoppingItem == NULL)
		{
			shoppingItem = malloc(sizeof(ShoppingItem));
			addNewItemToCart(pProduct, shoppingItem, shoppingList, current_index, amount);
		}
		else
		{
			ShoppingItem** tmp = NULL;
			tmp = realloc(pCart->shopping_items_list, sizeof(shoppingList) * (current_index + 1));
			shoppingList = tmp;
			addNewItemToCart(pProduct, shoppingItem, shoppingList, current_index, amount);
		}
		pCart->shopping_items_num++;
	}

}
//################################################################################
int addNewItemToCart(Product* pProduct, ShoppingItem* pItem, ShoppingItem** pShoppingList, int items_to_add, int basket_amount)
{
	if(pShoppingList != NULL && pItem != NULL)
	{
		pItem->items_amount = basket_amount; //getting amount
		if (pProduct->barcode != NULL)
		{
			pItem->barcode = malloc(sizeof(char) * BARCODE_L);
			if (pItem->barcode != NULL)
				strcpy(pItem->barcode,pProduct->barcode );//copying a name of product to barcode
		}
		pShoppingList[items_to_add] = pItem;
		pProduct->amount -= basket_amount;
		return 1;
	}
	return 0;
	



}
//################################################################################

Customer* createShoppingCustomer(Market* pMarket) {

	printCustomersList(pMarket);
	char cust_name[MAX_LEN];
	printf("\nEnter a customer name from a list\n");
	strcpy(cust_name, getInput());
	Customer* pCustomer = findCustomer(pMarket, cust_name);
	return pCustomer;
}
//################################################################################

Customer* findCustomer(Market* pMarket, char* name)
{
	for (int i = 0; i < pMarket->customersNum; i++)
	{
		if (isCustomer(pMarket->customersList[i], name))
			return pMarket->customersList[i];
	}
	return NULL;
}
//################################################################################

Product* findProductByBarcode(Market* pMarket, char* pBarcode)
{
	for (int i = 0; i < pMarket->productsNumber; i++)
	{
		if (checkProduct(pMarket->productsList[i], pBarcode))
			return pMarket->productsList[i];
	}
	return NULL;
}

//################################################################################
Product* getUserProduct(Market* pMarket, char* pBarcode)
{

	return findProductByBarcode(pMarket, pBarcode);
}

//################################################################################

Product* getProductDetails(Market* pMarket, int* count)
{
	char barcode[BARCODE_L + 1];
	int new_count;
	Product* pProduct = getUserProduct(pMarket, barcode);
	if (pProduct == NULL)
	{
		printf("\nProduct doesn't exist\n");
		return NULL;
	}
	if (pProduct->amount == 0)
	{
		printf("\nProduct is out of stock\n");
		return NULL;
	}
	printf("\nEnter a num of products\n");
	new_count = getUserChoice();
	*count = new_count;



	return pProduct;
}

//################################################################################


void editStockProduct(Product* pProduct, int index)
{
	getReadyProduct_no_choice(pProduct, index);
}

//################################################################################


void proceedUserPayment(Market* pMarket)
{
	char buffer[MAX_LEN];
	float total = 0;
	printf("\nPrint a user name\n");
	strcpy(buffer, getInput());
	Customer* myCust = NULL;
	myCust = findCustomer(pMarket, buffer);
	if (myCust)
	{
		total  = getAmountToPay(myCust);
		free(myCust->shp_cart->shopping_items_list);//free shopping items
	}
	

}

//################################################################################

float getAmountToPay(Customer* pCustomer)
{
	float total = 0;
	if (pCustomer == NULL)
		return 0;
	if (pCustomer->shp_cart->shopping_items_num <= 0)
		return 0;
	ShoppingCart* shoppingCart = NULL;
	shoppingCart = pCustomer->shp_cart;
	if(shoppingCart)

	{
		for (int i = 0; i < pCustomer->shp_cart->shopping_items_num; i++)
		{
			ShoppingItem** pItemList = NULL;
			pItemList = shoppingCart[i].shopping_items_list;
			if (pItemList && shoppingCart[i].shopping_items_num > 0)
			{
				for (int j = 0; j < shoppingCart[i].shopping_items_num; j++)
				{
					total += (pItemList[j]->price*(pItemList[j]->items_amount));
				}
			}
		}
	}
	return 0;
}

//################################################################################
void printProductsListWithType(Market* pMarket, int choice)
{
	int type = choice - 1;
	delimiter_dash();
	for (int i = 0; i < pMarket->productsNumber; i++)
	{
		if(pMarket->productsList[i]->product_type == type)
		printProduct(pMarket->productsList[i]);
	}
	delimiter_dash();
}
//################################################################################

void freeMarket(Market* pMarket)
{
	for (int i = 0; i < pMarket->customersNum; i++)
	{
		freeCust(pMarket->customersList[i]);
	}
	freeProducts(pMarket->productsList, pMarket->productsNumber);
	freeAddress(&pMarket->address);
	free(pMarket->marketName);
}

void freeAddress(Address* pAddress)
{
	free(pAddress->city_name);
	free(pAddress->street_name);
}