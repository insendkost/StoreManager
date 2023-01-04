#ifndef _MAIN__SYSTEM_H_
#define _MAIN__SYSTEM_H_

#include "market.h"

typedef enum {sort_by_name, sort_by_visit, numOfOptions};

void super_market_init();
void main_menu(Market* pMarket);
void sort_customers_by_name(Market* pMarket);
int compare_cust_names(const void* a, const void* b);
void sort_customers_by_visits(Market* pMarket);
int compare_cust_visits(const void* a, const void* b);
#endif // !_MAIN__SYSTEM_H_
