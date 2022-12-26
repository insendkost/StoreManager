#ifndef _GENERAL_H_
#define _GENERAL_H
#define MAX_LEN 255
void greetings();
void printMenu();
void delimiter();
void delimiter_star();
void delimiter_dash();
void short_delimiter_dash();
void double_delimiter_dash();

void printTypeByNum(int type);
void printListOfTypes();
char* getInput();
char* getAlphabeticString();
void wordCorrection(char* pWord, size_t length);
void numCorrection(char* pStr, size_t length);

int getUserChoice();
int wordCounter(const char* ch);
char* frontSpacesFormat(char* str);

char* resizeStr(char* ptrStr, int size);

char* editWhiteSpace(char* str, size_t length);
void stockProductsMenu();

void str_split(char** dest,char* source, int* items_num, const char* del);
char* str_allocate(char* pStr);
void getName(char* marketName);
#endif // !_GENERAL_H_

