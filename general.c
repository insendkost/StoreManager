#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "general.h"
//################################################################################
void delimiter() {
	
	printf("\n");
	for (int i = 0; i < 70; i++)
	{
		printf("=");
	}
	printf("\n");

}
//################################################################################
void delimiter_star() {

	printf("\n");
	for (int i = 0; i < 70; i++)
	{
		printf("*");
	}
	printf("\n");

}
//################################################################################
void delimiter_dash() {
	
	printf("\n");
	for (int i = 0; i < 70; i++)
	{
		printf("-");
	}
	printf("\n");
}
//################################################################################

void short_delimiter_dash()
{
	printf("\n\t");
	for (int i = 0; i < 20; i++)
	{
		printf("-");
	}
	printf("\n");
}

//################################################################################
void double_delimiter_dash()
{
	printf("\n");
	for (int i = 0; i < 100; i++)
	{
		printf("-");
	}
	printf("\n");
}

//################################################################################

void greetings() {
	printf("\t\n##############################################################\n");
	printf("\t# Welcome to shopping system! #");
	printf("\t\n##############################################################\n");

}
//################################################################################
void printMenu() {
	printf("\n\t Choose your option: ");
	printf("\n\t\t 1 - Print Store Info - ");
	printf("\n\t\t 2 - Add New Product - ");
	printf("\n\t\t 3 - Add New Customer -");
	printf("\n\t\t 4 - Start Shopping - ");
	printf("\n\t\t 5 - Print Shopping Cart Info - ");
	printf("\n\t\t 6 - Proceed Payment - ");
	printf("\n\t\t 7 - Print List of Products By Type - ");
	printf("\n\t\t 8 - System Exit - ");
	delimiter_dash();

}
//################################################################################

void printListOfTypes()
{
	char list[][15] = {
		{"Shelf"},
		{"Frozen"},
		{"Fridge"},
		{"FruitVegetable"},
		{"Undefined"} };
	printf("\nChoose a type: \n");
	for (int i = 0; i < 5; i++)
	{
		printf(" %d - %s\n",i+1, list[i]);
	}
}


//################################################################################

void printTypeByNum(int type)
{
	char list[][15] = {
		{"Shelf"},
		{"Frozen"},
		{"Fridge"},
		{"FruitVegetable"},
		{"Undefined"} };
	printf(" %s", list[type]);
}

//################################################################################

void stockProductsMenu() {
	printf("\nChoose a products from list:\n");
	printf("\t\t1 - Tomatos\n");
	printf("\t\t2 - Kartoshka\n");
	printf("\t\t3 - Milk\n");
	printf("\t\t4 - Chocolate\n");
	printf("\t\t5 - Beer\n");
	printf(" \nYour choice ->\n");
}

//################################################################################
char* getInput()
{
	int nBuffer = MAX_LEN;
	char input[MAX_LEN];
	printf("\n\nInput:");
	fflush(stdin);
	if (fgets(input, nBuffer, stdin) == NULL) {
		return NULL;
	}

	size_t str_size = strlen(input);
	input[str_size - 1] = '\0';
	char* my_string = malloc(sizeof(char) * str_size);
	if (my_string != NULL && (input[0] != '\0' || strlen(input) != 0)) {
		strncpy(my_string, input, str_size);
		return my_string;
	}
	else {
		if (my_string == NULL) {
			return NULL;
		}
		if (input[0] == '\0' || strlen(input) == 0) {
			strcpy(my_string, getInput());
			return my_string;
		}
		else {
			free(my_string);
			return NULL;
		}
	}
}


//################################################################################
char* getAlphabeticString()
{
	char input[MAX_LEN];
	char* output = malloc(sizeof(char) * MAX_LEN);
	if(output!= NULL)
	{
		int output_index = 0;

		printf("\nInput ->");
		fgets(input, MAX_LEN, stdin);

		for (int i = 0; i < strlen(input); i++)
		{
			if (isalpha(input[i]))
			{
				output[output_index++] = input[i];
			}
		}

		output[output_index] = '\0';
		return output;
	}
	printf("Error: allocation failed");
	return NULL;
}
//################################################################################


int getUserChoice()
{
	char input[10];
	int choice;
	
	
	printf("Enter your choice: ");
	fgets(input, 10, stdin);
	if (sscanf(input, "%d", &choice) == 1);

	return choice;
}

//################################################################################
int wordCounter(const char* ch)
{
	int words_count = 0;
	int inword = 0;
	for (; *ch; ch++)
	{
		if (!isspace(*ch))
		{
			if (inword == 0)
			{
				inword = 1;
				words_count++;
			}
		}
		else if (inword)
		{
			inword = 0;
		}
	}
	return words_count;
}
//################################################################################

char* frontSpacesFormat(char* str)
{
	if (str == NULL)
	{
		return NULL;
	}
	char* formattetStr = str;
	int length = (int)strlen(formattetStr);
	int front_spaces_count = 0;
	int i = 0;
	while (isspace(formattetStr[i]))
	{
		front_spaces_count++;
		i++;
	}
	for (i = 0; i < (int)length - front_spaces_count; i++)
	{

		formattetStr[i] = formattetStr[i + front_spaces_count];
		formattetStr[i] = tolower(formattetStr[i]);
	}
	formattetStr[length - front_spaces_count - 1] = '\0';
	formattetStr[0] = toupper(formattetStr[0]);
	return formattetStr;
}
//################################################################################

char* resizeStr(char* ptrStr,int size)
{
	char* tmp = NULL;
	if (ptrStr == NULL) {
		return NULL;
	}
	char* localStr = ptrStr;
	size_t str_length = strlen(localStr);
	tmp = realloc(localStr, str_length + 1);
	if (tmp!= NULL)
	{
		localStr = tmp;
		return localStr;
	}
	return NULL;

}
//################################################################################
char* editWhiteSpace(char* str, size_t length)
{
	if (str == NULL)
	{
		return NULL;
	}
	char* tmp = NULL;
	char* myStr = str;
	int i = 0, j = 0;;
	tmp = calloc(length + 1, sizeof(char));
		int size = 1;
		tmp = resizeStr(myStr, size);
		while (myStr[i] != '\0')
		{
			tmp[j] = myStr[i];
			if ((myStr[i] == ' ') && (myStr[i + 1] != '\0'))
			{
				tmp[j] = myStr[i];
				tmp[j + 1] = ' ';
				j = j + 1;
			}
			i++, j++;
		}
		tmp[length] = '\0';
		myStr = tmp;
		return myStr;
}

//################################################################################


char* str_allocate(char* pStr)
{
	if (pStr)
	{
		char* newStr = malloc((strlen(pStr)+1) * sizeof(char));
		if (!newStr)
		{
			return NULL;
		}
		strcpy(newStr, pStr);
		return newStr;
	}
	return NULL;
}


//################################################################################
void numCorrection(char* pStr, size_t length) 
{
	char* myNum = pStr;
	myNum = frontSpacesFormat(myNum);
	pStr = myNum;
}

//################################################################################
void wordCorrection(char* pWord, size_t length)
{
	
	char* myStr = pWord;
	
	int words_count = wordCounter(pWord);
	int front_spaces_count = 0;
	int i = 0 , j = 0;
	int inword = 0;

	myStr = frontSpacesFormat(myStr);
	if (words_count > 1)
	{
		myStr = editWhiteSpace(myStr, length);
	}

	
	pWord = myStr;
}

//################################################################################

void str_split(char** dest,char* source, int* items_num, const char* del)
{
	char buffer[MAX_LEN];
	
	char* portion;
	int count = 0;

	strcpy(buffer, source);
	portion = strtok(buffer, del);
	while (portion != NULL)
	{
		
			//dest = tmp;
			dest[count] = str_allocate(portion);

			count++;
			portion = strtok(NULL, del);
		
	}
	*items_num = count;
}
//################################################################################

void getName(char* marketName)
{
	//
	if (marketName != NULL)
	{
		char* tmp = malloc(sizeof(char) * MAX_LEN);
		if (tmp != NULL)
		{
			strcpy(tmp, getInput());
			strcpy(marketName, tmp);
		}
	}
	//-> to add user input, for now it is static name


}