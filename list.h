/********************************************/
/*   list.h                                 */
/*   a dynamic  linked list with a header   */
/********************************************/


#ifndef _LIST_
#define _LIST_

#include "def.h"


/*** Definitions ***/

// Node
typedef struct node
{
	DATA_Product* key;
	struct node* next;
}NODE;

// List
typedef struct
{
	NODE head;
}LIST;


/*** Function prototypes ***/

BOOL L_init(LIST* pList);					// create new list

NODE* L_insert(NODE* pNode, DATA_Product* Value);	// add new node after *pNode

BOOL L_delete(NODE* pNode);					// erase node after *pNode

NODE* L_find(NODE* pNode, DATA_Product* Value);		// return a pointer to the node 

BOOL L_free(LIST* pList);					// free list memory

int L_print(LIST* pList);					// print the list content

#endif
