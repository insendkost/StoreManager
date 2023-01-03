/**************************************************************************/
/* def.h                                                                  */
/* This file contains GENERAL definitions used in several data structures */
/**************************************************************************/

#ifndef _DEF_
#define _DEF_

// a value not supposed in stack and queue
#define		EMPTY	0x7FFFFFFF
#include "product.h"
#include "customer.h"
// new types
typedef int DATA;	// a type for data (easy to change)
typedef Product DATA_Product;
typedef Customer DATA_Customer;
typedef enum { False, True } BOOL;	// a boolean type



#endif