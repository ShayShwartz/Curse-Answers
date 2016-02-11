#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

Node* listHead = NULL;
Node* listTail = NULL;
unsigned int listLengh = 0;
float sum = 0;

/*Check if the list is empty.
	Return 0 if true (empty)
	return the number of node in the list (the lengh) if false (not empty)*/
int listIsEmpty()
{
	if ( listLengh == 0 )
	{
		printf("\nList is empty.\n");
		return 0;
	}
	return listLengh;
}

/*Initialize the list and create the first node.*/
int initializeList(int val)
{
	
	/*Check if the list is already initialized.*/
	if ( listIsEmpty() != 0 )
	{
		printf("List already initialized.\n");
		return ERROR;
	}

	listHead = createNode(val);

	/*Check createNode failed.*/
	if ( listHead == NULL )
	{
		printf("\nMalloc failed - Not enough memory to allocate.");
		return ERROR;
	}
	
	listLengh++; /*If the initialize succeed the lengh of the list is 1 now.*/
	sum += val; 
	listTail = listHead; /*There is only 1 node in the list , so the first node is also the listTail.*/

	return SUCCESS;
}

/*Delete all the nodes in the list recursivly.*/
void deleteListNextNode(Node* node)
{
	if ( node == NULL )
	{
		listHead = NULL;
		listTail = NULL;
		listLengh = 0;
		sum = 0;
	}
	else
	{
		Node* nextNode = node->next;
		free(node);
		deleteListNextNode(nextNode);
	}
}
void deleteList()
{
	deleteListNextNode(listHead);
}

/*Append new node with the inserted value to the end of the list.*/
int appendNode(int val)
{
	Node* newNode = NULL;
	if ( listIsEmpty() == 0 )
		return ERROR;

	newNode = createNode(val);
	if ( newNode == NULL )
	{
		printf("\nUnable to apped %d to the list. ERROR: Not enough memory to allocate.", val);
		return ERROR;
	}

	listTail->next = newNode;
	newNode->prev = listTail;
	listTail = newNode;

	listLengh++;
	sum += val;

	return SUCCESS;
}

/*Remove the spcified node from the list*/
int removeNode(Node* node)
{
	if (node == NULL)
	{
		printf("Node not exist");
		return ERROR;
	}
	else if( node->prev == NULL) /*The inserted node is the listHead*/
		listHead = listHead->next;
	else if( node->next == NULL)/*The inserted node is the listTail*/
	{
		listTail = listTail->prev;
		listTail->next = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	sum -= node->value;
	listLengh--;

	free(node);

	return SUCCESS;
}

/*Return the lengh of the list*/
int getListLen()
{
	return listLengh;
}
/*Return pointer to the listHead of the list (if exists), or null if the list is empty.*/
Node* getListHead()
{
	return listHead;
}

/*Return pointer to the listTail node in the list (if exists), or null if the list is empty.*/
Node* getListTail()
{
	return listTail;
}

/*Return pointer to the next node after the spcified node (if exists), or null in case of error or the next node does'nt exist*/
Node* getNext(Node* node)
{
	if ( node == NULL )
	{
		printf("Node not exist");
		return NULL;
	}
	return node->next;/*if node->next == NULL (the listTail node in the list), so NULL will be returned.*/
}

/*Return pointer to the previous node after the spcified node (if exists), or null in case of error or the previous node does'nt exist*/
Node* getPrev(Node* node)
{
	if ( node == NULL )
	{
		printf("Node not exist");
		return NULL;
	}
	return node->prev;/*if node->prev == NULL (listHead of the list), so NULL will be returned.*/
}

/*Return the value of the spcified node (if exists), or ERROR (-1) if the node does'nt exist*/
int getValue(Node* node)
{
	if ( node == NULL )
	{
		printf("Node not exist");
		return ERROR;
	}
	return node->value;
}

/*Calculate the avarage of the list if the list not empty, else, return ERROR (-1)*/
float getAvarage()
{
	if ( listIsEmpty() == 0 )
		return ERROR;
	return sum / listLengh;
}