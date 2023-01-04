#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#define BARCODE_L 7
typedef enum { Shelf, Frozen, Fridge, FruitVegetable, Undefined, types_num }productType;


typedef struct product {

	char* product_name;
	char* barcode;
	productType product_type;
	float price;
	int amount;
}Product;


//void printListOfProducts(Product* listOfProducts);
void printProduct(const Product* pProduct);

Product initProduct(char* product_name, char* barcode, float price, productType product_type, int amount);
Product* initStockProductList(int size);
Product getDefaultProduct();
void getReadyProduct_no_choice(Product* pProduct, int index);
void initProductFromReadyList(Product* pProduct, int choice);



void setProductName(Product* pProduct);
void setType(Product* pProduct);
void setAmount(Product* pProduct);
void setPrice(Product* pProduct);
char* getBarcode();
int barcodeCheck(char* input);
int	checkProduct(const Product* pProduct,char* barcode);


void allocateMemoryProduct(Product* pProduct);
void setProduct(Product* pProduct);

void createProduct(Product* pProduct);
void getReadyProduct(Product* pProduct);

void freeProducts(Product** pProductList, int numOfProducts);

#endif
