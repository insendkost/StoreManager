#ifndef _ADDRESS_H_ 
#define _ADDRESS_H_


typedef struct address {

	char* housenum;
	char* street_name;
	char* city_name;


}Address;

void initAddress(Address* pAddress);
void printAddress(Address* pAddress);
void updateAddress(Address* pAddress);
char* getCityName();
char* getStreetName();
char* getHouseNum();
void houseNumCheck(char* pNumber);
void getAddress(Address* pAddress);
int check_items(char** items, int count);
#endif
