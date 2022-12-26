#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "general.h"
#include "product.h"
#include "shopping.h"

//################################################################################
void cartDetailsPrint(ShoppingCart* pCart)
{
	int size = pCart->shopping_items_num;
	
	for (int i = 0; i < size; i++)
	{
		if (pCart->shopping_items_list[i] != NULL)
		{
			printf("\nProduct:\n");
			printProductDetails(pCart->shopping_items_list[i]);
			


		}
	}
}
//################################################################################

void printProductDetails(ShoppingItem* pItem)
{
	float total = 0;
	int items = 0;
	items = pItem->items_amount;
	total = (float)(items * pItem->price);
	
	printf("Barcode: %s\n", pItem->barcode);
	printf(" Total: %d\n", items);
	printf(" Total sum: %.2f\n", total);


}

//################################################################################

void initNewCart(ShoppingCart* pCart)
{
	pCart->shopping_items_num = 0;
	pCart->shopping_items_list = NULL;
}


//################################################################################
//################################################################################

ShoppingItem* createItem(const char* name, const float price, const int count)
{
	ShoppingItem* newItem = malloc(sizeof(ShoppingItem));
	if(newItem)
	{
		newItem->barcode = malloc(sizeof(char) * strlen(name));
		if (newItem->barcode)
		{
			strcpy(newItem->barcode, name);
		}
		newItem->price = price;
		newItem->items_amount = count;
		return newItem;
	}

	return NULL;
}

//################################################################################




void freeShoppingItems(ShoppingCart* pCart)
{
	int size = pCart->shopping_items_num;
	if (size == 0)
		return;
	for (int i = 0; i < size; i++)
	{
		free(pCart->shopping_items_list[i]);
	}
	free(pCart);
}