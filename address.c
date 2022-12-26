#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "address.h"
#include "market.h"
#include "general.h"
//################################################################################

int check_items(char** items, int count) {
	if (count != 3)
		return 0;
	char* house_num = items[1];

	while (*house_num)
	{
		if (!isdigit(*house_num))
		{
			return 0;
		}
		house_num++;
	}
	return 1;
}


//################################################################################
void initAddress(Address* pAddress)
{
	Address* newAddress = NULL;
	char* new_city = NULL;
	char* new_num = NULL;
	char* new_street = NULL;
	new_city = (char*)malloc(sizeof(char) * MAX_LEN);
	new_num= (char*)malloc(sizeof(char) * MAX_LEN);
	new_street= (char*)malloc(sizeof(char) * MAX_LEN);
	if (pAddress)
	{
		
	
	pAddress->city_name = new_city;
	pAddress->street_name = new_street;
	pAddress->housenum = new_num;
	printf("\nNew empty address created\n");
	}
}
//################################################################################
void printAddress(Address* pAddress) {

		printf("\n\tAddress:  \n\tStreet:[%s],[%s] \n\tCity:[%s]\n",
		pAddress->street_name,
		pAddress->housenum,
		pAddress->city_name);

	delimiter_dash();

}
//################################################################################
//getStreetName()->

char* getStreetName() {
	char* ptr_name = NULL;
	printf("Enter street name:");
	ptr_name = getInput();

	char* tmpAddress = ptr_name;
	size_t word_length = strlen(tmpAddress);

	wordCorrection(tmpAddress, word_length);

	printf("\n\tAddress: %s", tmpAddress);
	return ptr_name;
}
//################################################################################
void houseNumCheck(char* pNumber)
{
	if (pNumber == NULL)
	{
		return;
	}
	int i = 0;
	char* localStr = pNumber;
	size_t length = strlen(localStr);
	while (localStr[i] != '\0')
	{
		if (!isdigit(localStr[i]))
		{
			printf("Invalid number format");
			return;
		}
		i++;
	}
	pNumber = localStr;
}


//################################################################################
char* getHouseNum()
{
	char* ptr_num = NULL;
	printf("Enter house number:");
	ptr_num = getInput();
	size_t num_length = strlen(ptr_num);
	numCorrection(ptr_num, num_length);
	houseNumCheck(ptr_num);

	return ptr_num;
}
//################################################################################
char* getCityName()
{
	
	char* ptr_name = NULL;
	printf("Enter city name:");
	ptr_name = getInput();
	char* tmpAddress = ptr_name;
	size_t word_length = strlen(tmpAddress);
	wordCorrection(tmpAddress, word_length);
	return ptr_name;
}

//################################################################################
void updateAddress(Address* pAddress)
{
	Address* ptrAddress = pAddress;
	if (ptrAddress != NULL)
	{
		
		ptrAddress->street_name = getStreetName();
		ptrAddress->housenum = getHouseNum();
		ptrAddress->city_name = getCityName();
	}
}
//################################################################################
void getAddress(Address* pAddress)
{
	char buffer[MAX_LEN];
	char* str_items[3] = { 0 };

	int check = 0;
	while (check != 1)
	{
		printf("\nEnter new market address:\n");
		printf("Format: STREET # HOUSE_N # CITY\n");
		printf("**street and city can have spaces\n");
		strcpy(buffer, getInput());
		int count = 0;
		str_split(str_items, buffer, &count, "#");
		check = check_items(str_items, count);
	}

	if (str_items[0] != NULL && str_items[1] != NULL && str_items[2] != NULL)
	{
		strcpy(pAddress->street_name, str_items[0]);
		strcpy(pAddress->housenum, str_items[1]);
		strcpy(pAddress->city_name, str_items[2]);
	}

	for (int i = 0; i < 3; i++)
	{
		if (str_items[i] != NULL)
		{
			free(str_items[i]);
		}
	}
}

