#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "general.h"
#include "product.h"
//################################################################################

//################################################################################

//################################################################################
Product initProduct(char* product_name, char* barcode, float price, productType product_type, int amount)
{
	Product product;
	product.product_name = malloc(strlen(product_name) + 1);
	if(product.product_name != NULL)
		strcpy(product.product_name, product_name);
	product.barcode = malloc(strlen(barcode) + 1);
	if (product.barcode != NULL)
		strcpy(product.barcode, barcode);
	product.price = price;
	product.product_type = product_type;
	product.amount = amount;
	return product;
}

//################################################################################

Product* initStockProductList(int size)
{
	
	Product* productsList = calloc(size+1,sizeof(Product));
	
	if (productsList != NULL)
	{
		if (size > 0) productsList[0] = initProduct("Tomatos", "TOMAT17", 9.5f, FruitVegetable, 1000);
		if (size > 1) productsList[1] = initProduct("Kartoshka", "POTATO5", 3.5f, FruitVegetable, 5000);
		if (size > 2) productsList[2] = initProduct("Milk", "MI45741", 6.5f, Fridge, 500);
		if (size > 3) productsList[3] = initProduct("Chocolate", "CHOCK17", 12.f, Shelf, 8000);
		if (size > 4) productsList[4] = initProduct("Beer", "BEER187", 15.f, Shelf, 700);
	}
		
	return productsList;
}
//################################################################################

void getReadyProduct_no_choice(Product* pProduct,int index)
{
	Product* productsList = initStockProductList(5);

	*pProduct = productsList[index];
	pProduct->barcode = malloc(sizeof(char)*MAX_LEN);
	pProduct->product_name = malloc(sizeof(char) * MAX_LEN);
	if (pProduct->product_name != NULL) {
		strcpy(pProduct->product_name, productsList[index].product_name);
	}

	if (pProduct->barcode != NULL) {
		strcpy(pProduct->barcode, productsList[index].barcode);
	}
	pProduct->price = productsList[index].price;
	pProduct->product_type = productsList[index].product_type;
	pProduct->amount = productsList[index].amount;
}
//################################################################################


void initProductFromReadyList(Product* pProduct, int choice)
{
	pProduct->product_type = Undefined;
	pProduct->amount = 0;
	
	Product tmpProduct = *pProduct;
	switch (choice)
	{
	case 1:
		tmpProduct = initProduct("Tomatos", "TOMAT17", 9.5f, FruitVegetable, 1000);
		*pProduct = tmpProduct;
		break;
	case 2:
		tmpProduct = initProduct("Kartoshka", "P147415", 3.5f, FruitVegetable, 5000);
		*pProduct = tmpProduct;
		break;
	case 3:
		tmpProduct = initProduct("Milk", "MI45741", 6.5f, Fridge, 500);
		*pProduct = tmpProduct;
		break;
	case 4:
		tmpProduct = initProduct("Chocolate", "CHOCK17", 12.f, Shelf, 8000);
		*pProduct = tmpProduct;
		break;
	case 5:
		tmpProduct = initProduct("Beer", "BEER187", 15.f, Shelf, 700);
		*pProduct = tmpProduct;
		break;
	default:
		tmpProduct = initProduct("default_product", "ABC1234", 0.f, Undefined, 0);
		*pProduct = tmpProduct;
		break;
	}
	

}
//################################################################################

void allocateMemoryProduct(Product* pProduct)
{
	size_t name_len = strlen(pProduct->product_name);
	size_t barcode_len = strlen(pProduct->barcode);

	pProduct->product_name = malloc((name_len + 1) * sizeof(char));
	pProduct->barcode = malloc((barcode_len + 1) * sizeof(char));
}

//################################################################################

void getReadyProduct(Product* pProduct) {

	stockProductsMenu();
	int choice = getUserChoice();
	
	initProductFromReadyList(pProduct, choice);
	
		
}

//################################################################################
void printListOfProducts(Product** listOfProducts, int numOfProducts)
{
	int total = numOfProducts;
	delimiter_dash();
	for(int i =0; i< numOfProducts;i++)
	{
		printf("\nProduct %d) - [%s] # Barcode: {%s}\n", i+ 1,
			listOfProducts[i]->product_name, listOfProducts[i]->barcode);
		printf("\nDetails: \t < %d ea >", listOfProducts[i]->amount);
		printf("\t - %.2f ils", listOfProducts[i]->price);
		printf("\t - Type:");
		printTypeByNum(listOfProducts[i]->product_type);
		short_delimiter_dash();
	}
	
	printf("\nTotal: %d", total);
	if (total == 1)
	{
		printf(" (product in market)\n");
	}
	else {
		printf(" (products in market)\n");
	}
}
//################################################################################

void printProduct(const Product* pProduct)
{	
	short_delimiter_dash();
	printf("\n\t Product Details: \n");
	printf("\n\t Name: %s", pProduct->product_name);
	printf("\n\t Barcode: %s", pProduct->barcode);
	printf("\n\t Type: %d", pProduct->product_type+1);
	printf("\n\t Price: %.2f ils", pProduct->price);
	printf("\n\t Name: %d", pProduct->amount);
	
	
}

//################################################################################

void createProduct(Product* pProduct)
{
	printf("\nEnter the product name\n");
	char* name = getInput();
	size_t len = strlen(name);
	pProduct->barcode = malloc(sizeof(char)*MAX_LEN);
	pProduct->product_name = malloc(sizeof(char) * len);
	if(pProduct->product_name!= NULL && pProduct->barcode != NULL)
	{
		strcpy(pProduct->barcode, getBarcode());
		strcpy(pProduct->product_name, name);
	}
	setPrice(pProduct);
	setType(pProduct);
	setAmount(pProduct);
	//allocateMemoryProduct(pProduct);
	
}


//################################################################################
//PRODUCT CREATION FUNCTIONS
//################################################################################
void setProductName(Product* pProduct)
{
	//char* input = getInput();
	char buffer[MAX_LEN];
	char* input = getInput();
	if (strlen(input) == 0)
	{
		printf("Empty name, get another try...");
		input = getInput();

	}
	if(pProduct->product_name != NULL)
	{
		strcpy(buffer, input);
		strcpy(pProduct->product_name, buffer);
	}
	//to add input check

}

void setType(Product* pProduct)
{
	if(pProduct)
	{
		printListOfTypes();
		int choice;
		printf("\nType choice:\n");
		if (scanf("%d", &choice));
		pProduct->product_type = choice-1;
	}
}


void setAmount(Product* pProduct)
{
	if (pProduct)
	{
		
		int amount;
		printf("\nAmount of items :\n");
		if (scanf("%d", &amount));
		pProduct->amount = amount;
	}
	
}


void setPrice(Product* pProduct)
{
	if (pProduct)
	{

		float price;
		printf("\nSet price :\n");
		if (scanf("%f", &price));
		pProduct->price = price;
	}

}
int barcodeCheck(char* input)
{
	if(input != NULL)
	{
		int i = 0;
		int digits = 0;
		while (input[i] != '\0')
		{
			if (isdigit(input[i]))
			{
				digits++;
			}
			if (!isalnum(input[i]))
			{
				printf("\nOnly letters & numbers are allowed\n");
				return 0;
			}
			if (islower(input[i]))
			{
				input[i] = toupper(input[i]);
			}
			i++;
		}
		if (digits < 3 || digits > 5)
		{
			printf("\nmsg {check digits rules}\n");
			return 0;
		}

		return 1;
	}
	return 0;
}
//################################################################################

int	checkProduct(const Product* pProduct, char* barcode)
{
	if (strcmp(pProduct->barcode, barcode) == 0)
		return 1;
	return 0;
}
//################################################################################


char* getBarcode()
{
	printf("\nBARCODE SET RULES:\n");
	printf("UPPERCASE & DIGITS ONLY\n");
	printf("***must have from 3 to 5 digits***\n");
	char* str = getInput();
	size_t len = strlen(str);
	char* new_barcode = malloc((len + 1) * sizeof(char));
	if (new_barcode != NULL && barcodeCheck(str) == 1)
	{
		strcpy(new_barcode, str);
		return new_barcode;
	}
	return NULL;
	

}
//################################################################################

void setProduct(Product* pProduct)
{
	
	int choice, flag = 0;
	char input[10];
	while (flag != 1) {
		printf("\nChoose your option: \n");
		printf("\t\t1 - custom product \n");
		printf("\t\t2 - ready product \n");
		printf("Input -> ");
		fgets(input, 10, stdin);

		if (sscanf(input, "%d", &choice) == 1)
		switch (choice)
		{
		case 1:
			createProduct(pProduct);
			flag = 1;
			break;
		case 2:
			getReadyProduct(pProduct);
			flag = 1;
			break;
		default:
			printf("False input");
			break;

		}
	}

}

//################################################################################

void freeProducts(Product** pProductList, int numOfProducts)
{
	for (int i = 0; i < numOfProducts; i++)
	{
		
		free(pProductList[i]);
		
	}
	free(pProductList);
}