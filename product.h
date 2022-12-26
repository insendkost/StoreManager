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


void printListOfProducts(Product** listOfProducts, int numOfProducts);
void printProduct(const Product* pProduct);

Product initProduct(char* product_name, char* barcode, float price, productType product_type, int amount);
Product* initStockProductList(int size);

void getReadyProduct_no_choice(Product* pProduct, int index);
void initProductFromReadyList(Product* pProduct, int choice);


//void initProduct(Product* pProduct);
void setProductName(Product* pProduct);
void setType(Product* pProduct);
void setAmount(Product* pProduct);
void setPrice(Product* pProduct);
char* getBarcode();
int barcodeCheck(char* input);
int	checkProduct(const Product* pProduct,char* barcode);
//Product* initProductList();



void allocateMemoryProduct(Product* pProduct);
void setProduct(Product* pProduct);
//Product addCustomProduct();
void createProduct(Product* pProduct);
void getReadyProduct(Product* pProduct);
//Product** initListOfProducts(Product** pListOfProducts, int* numOfProducts);

void addNewProductToList(Product* pProduct, Product** listOfProducts, int numOfProducts);

void freeProducts(Product** pProductList, int numOfProducts);

#endif
