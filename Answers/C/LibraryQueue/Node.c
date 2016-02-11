#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

Node* createNode(int val)
{

	Node* nNode = (Node*)malloc(sizeof(Node));

	/*Check if malloc failed to allocate memory.*/
	if ( nNode == NULL )
	{
		printf("\nMalloc failed - Not enough memory to allocate.");
		return NULL;
	}

	nNode->value = val;
	nNode->next = NULL;
	nNode->prev = NULL;
	
	return nNode;

}
