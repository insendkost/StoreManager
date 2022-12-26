#ifndef _SHOPPING_H_
#define _SHOPPING_H_

typedef struct shoppingitem {

	char* barcode;
	float price;
	int items_amount;


}ShoppingItem;

typedef struct shoppingcart {

	ShoppingItem** shopping_items_list;
	int shopping_items_num;

}ShoppingCart;



void initNewCart(ShoppingCart* pCart);
void cartDetailsPrint(ShoppingCart* pCart);
void printProductDetails(ShoppingItem* pItem);
ShoppingItem* createItem(const char* name,const float price,const int count);

void freeShoppingItems(ShoppingCart* pCart);
#endif
