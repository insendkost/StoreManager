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
	void* product;
	struct node* next;
}NODE;

// List
typedef struct
{
	NODE* head;
	NODE* tail;
}LIST;


/*** Function prototypes ***/

LIST* L_init(void* data);				// create new list

NODE* L_insert(LIST* list, void* data);	// add new node after *list

BOOL L_delete(NODE* pNode);					// erase node after *pNode

NODE* L_find(NODE* pNode, DATA* Value);		// return a pointer to the node 

BOOL L_free(LIST* pList);					// free list memory

//int L_print(LIST* pList);					// print the list content

#endif
