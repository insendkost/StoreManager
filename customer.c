#define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "general.h"
#include "market.h"
#include "customer.h"
#include "shopping.h"

							//PRINTS
//################################################################################

void printShoppingCustomers(Customer** listOfCustomers, int num)
{
	if (listOfCustomers == NULL)
	{
		printf("\nThe list is empty - no customers\n");
		return;
	}
	for (int i = 0; i < num; i++)
	{
		if (listOfCustomers[i]->shp_cart != NULL)
		{
			printf("\n\tCustomer %d).%s", i + 1, listOfCustomers[i]->customer_name);
		}
	}


}
//################################################################################

void printListOfCustomers(Customer** listOfCustomers, int numOfCustomers)
{

	for (int i = 0; i < numOfCustomers; i++)
	{
		printf("\n\t %d - %s", i + 1, listOfCustomers[i]->customer_name);
	}
}

//################################################################################
void printCustomersData(Customer* pCustomer)
{
	delimiter();
	printf(" Customers info: \n");
	printf("Current customers of supermarket: \n");
	if (pCustomer == NULL)
	{
		printf("Customer doesn't exist");
		return;
	}
	printf("\nCustomer name: [%s]", pCustomer->customer_name);
	delimiter_dash();

}
//################################################################################
void printCustShoppingItems(Customer** pCustomerList, Product** productsList, int cust_number) {

	if (pCustomerList == NULL)
	{
		printf("There is no customers");
		return;
	}

	for (int i = 0; i < cust_number; i++)
	{
		if (pCustomerList[i]->shp_cart != NULL && pCustomerList[i]->shp_cart->shopping_items_num > 0)//so there is an active shipping cart
		{
			printf("\nCusotmer: %s\n", pCustomerList[i]->customer_name);
			shoppingCartPrint(pCustomerList[i]);
		}
	}
}
//################################################################################

Customer* initCustomerList()

{
	Customer* ptrNewCustList = malloc(sizeof(Customer));
	if (ptrNewCustList != NULL)
	{
		ptrNewCustList[0].customer_name = malloc(sizeof(char) * MAX_LEN);
		ptrNewCustList[0].shp_cart = NULL;
	}
	return ptrNewCustList;
}


//################################################################################


void initCustomer(Customer* pCustomer)
{
	printf("\nEnter a name,");
	char* input = getInput();
	size_t input_len = strlen(input);
	pCustomer->customer_name = malloc((input_len + 1) * sizeof(char));
	if(pCustomer->customer_name)
	{
		strcpy(pCustomer->customer_name, input);
	}
}
//################################################################################



void shoppingCartPrint(Customer* pCustomer)
{
	if (pCustomer->shp_cart->shopping_items_num == 0)
	{
		printf("\nError: Shopping cart is empty\n");
		return;
	}
	cartDetailsPrint(pCustomer->shp_cart);
}


//################################################################################

int isCustomer(Customer* pCustomer, char* name)
{
	if (strcmp(pCustomer->customer_name, name) == 0)
	{
		return 1;
	}
	return 0;
}
//################################################################################

void freeCust(Customer* pCust)
{
	free(pCust->customer_name);
	freeShoppingItems(pCust->shp_cart);
}