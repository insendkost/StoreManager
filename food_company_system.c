
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"food_company_system.h"
#include "market.h"
#include "address.h"
#include "customer.h"
#include "product.h"
#include "general.h"



void super_market_init()
{ 
	Market* pMarket = NULL;
	pMarket = (Market*)malloc(sizeof(Market));
	greetings();
	main_menu(pMarket);
	
}


void main_menu(Market* pMarket)
{
	int choice = 0, flag = 0;
	
	initSuperMarket(pMarket); 
	
	
	while (flag!=1)
	{
		printMenu();
		choice = 0;
		printf("\n[Choose your option] -> ");
		choice = getUserChoice();

			switch (choice)
			{
			case 0:
				break;
			case 1:
				//1 - Print Market Info -
				
				printf("\n\t\t 1 - Print Store Info - ");
				printMarketInfo(pMarket);
				break;
			case 2:
				//2 - Add New Product -
				printf("\n\t\t 2 - Add New Product - ");
				addProductToMarket(pMarket);
				printf("\n->Product was added");
				break;
			case 3:
				//3 - Add New Customer -
				printf("\n\t\t 3 - Add New Customer -");
				addCustomer(pMarket);
				break;
			case 4:
				//4 - Start Shopping -
				printf("\n\t\t 4 - Start Shopping - ");
				startShoppingProcess(pMarket);
				break;
			case 5:
				//5 - Print Shopping Cart Info -
				printf("\n\t\t 5 - Print Shopping Cart Info - ");
				printShoppingCartInfo(pMarket);
				break;
			case 6:
				//6 - Proceed Payment -
				printf("\n\t\t 6 - Proceed Payment - ");
				proceedPayment(pMarket);
				break;
			case 7:
				//7 - Print List of Products in Store - 
				printf("\n\t\t 7 - Printing the List By Type ");
				//show current products
				printProductsListByType(pMarket);
				break;
			case 8:
				//System Exit
				printf("\nClosing system...\n");
				flag = 1;
				freeMarket(pMarket);
				//make free to all items
				break;

			default:
				printf("\nFalse input\n");

			}
		
		
	}
	

}

int compare_cust_names(const void* a, const void* b)
{
	Customer* customer_a = (Customer*)a;
	Customer* customer_b = (Customer*)b;
	return strcmp(customer_a->customer_name, customer_b->customer_name);
}

void sort_customers_by_name(Market* pMarket)
{
	qsort(*pMarket->customersList,
		pMarket->customersNum,
		sizeof(Customer),
		compare_cust_names);

}

int compare_cust_visits(const void* a, const void* b)
{
	Customer* customer_a = (Customer*)a;
	Customer* customer_b = (Customer*)b;
	return customer_a->shopTimes - customer_b->shopTimes;
}


void sort_customers_by_visits(Market* pMarket)
{
	qsort(*pMarket->customersList,
		pMarket->customersNum,
		sizeof(Customer),
		compare_cust_visits);

}