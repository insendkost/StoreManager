/**************/
/*   list.c   */
/**************/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"



//////////////////////////////////////////
// Init
// Aim:		create new list
// Input:	pointer to the list structure
// Output:	TRUE if succeeded
//////////////////////////////////////////
LIST* L_init(void* data)
{
	NODE* node = malloc(sizeof(NODE));
	node->product = data;
	node->next = NULL;

	LIST* list = (LIST*)malloc(sizeof(LIST));
	list->head = node;
	list->tail = node;
	return list;
}


/////////////////////////////////////////////////////////////////
// Insert
// Aim:		add new node
// Input:	pointer to the node BEFORE the place for the new one
//			a value to be stored in the new node
// Output:	pointer to the new node
/////////////////////////////////////////////////////////////////
NODE* L_insert(LIST* list, void* data) {
	NODE* tmp = (NODE*)malloc(sizeof(NODE));
	if (tmp != NULL) {
		tmp->product = data;
		tmp->next = NULL;

		list->tail->next = tmp;
		list->tail = tmp;
	}
	return tmp;
}


//////////////////////////////////////////////////////////////
// Delete
// Aim:		erase node
// Input:	pointer to the node BEFORE the node to be deleted 
// Output:	TRUE if succeeded
//////////////////////////////////////////////////////////////
BOOL L_delete(NODE* pNode)
{
	NODE* tmp;

	if (!pNode || !(tmp = pNode->next)) return False;

	pNode->next = tmp->next;
	free(tmp);
	return True;
}


/////////////////////////////////////////////////////////
// Find
// Aim:		search for a value
// Input:	pointer to the node to start with 
//			a value to be found
// Output:	pointer to the node containing the Value
/////////////////////////////////////////////////////////
NODE* L_find(NODE* pNode, DATA* Value)
{
	NODE* tmp;

	if (!pNode) return NULL;

	for (tmp = pNode; tmp && (tmp->product != Value); tmp = tmp->next);
	return tmp;
}


////////////////////////////////////////////////
// Free (additional function)
// Aim:		free the list memory
// Input:	pointer to the list structure
// Output:	TRUE if succeeded
////////////////////////////////////////////////
BOOL L_free(LIST* pList)
{
	NODE* tmp;

	if (!pList) return False;

	for (tmp = (pList->head); L_delete(tmp); );
	return True;
}


////////////////////////////////////////////////
// Print (additional function)
// Aim:		print the list content (assume the DATA is int)
// Input:	pointer to the list structure
// Output:	a number of the printed elements
////////////////////////////////////////////////
//int L_print(LIST* pList)
//{
//	NODE* tmp;
//	int		c = 0;
//
//	if (!pList) return 0;
//
//	printf("\n");
//	for (tmp = pList->head->next; tmp; tmp = tmp->next, c++)
//		printf(" %s ", tmp->product);
//	printf("\n");
//	return c;
//}