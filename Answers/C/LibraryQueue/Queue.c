#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

Node* head = NULL;
Node* last = NULL;
unsigned int lengh = 0;

/*Check if the queue is empty.
	Return 0 if true (empty)
	return the number of node in the queue (the lengh) if false (not empty)*/
int isEmpty()
{
	if ( lengh == 0 )
	{
		printf("\nQueue is empty.\n");
		return 0;
	}
	return lengh;
}

/*Initialize the queue and create the first node.*/
int initializeQueue(int val)
{
	/*Check if the queue is already initialized.*/
	if ( isEmpty() != 0 )
	{
		printf("Queue already initialized.\n");
		return ERROR;
	}

	head = createNode(val);
	/*Check createNode failed.*/
	if ( head == NULL )
	{
		printf("\nMalloc failed - Not enough memory to allocate.");
		return ERROR;
	}
	
	lengh++; /*If the initialize succeed the lengh of the queue is 1 now.*/
	last = head; /*There is only 1 node in the queue , so the first node is also the last.*/

	return SUCCESS;
}

/*Delete all the nodes in the queue recursivly.*/
void deleteNextNode(Node* node)
{
	if ( node == NULL )
	{
		head = NULL;
		last = NULL;
		lengh = 0;
	}
	else
	{
		Node* nextNode = node->next;
		free(node);
		deleteNextNode(nextNode);
	}
}
void deleteQueue()
{
	deleteNextNode(head);
}

/*Append new node with the inserted value to the end of the queue.*/
int push(int val)
{
	Node* nextNode = createNode(val);
	
	if ( nextNode == NULL )
	{
		printf("\nUnable to apped %d to the queue. ERROR: Not enough memory to allocate.", val);
		return ERROR;
	}
	
	if ( isEmpty() == 0 )
		return ERROR;
	
	last->next = nextNode;
	nextNode->prev = last;
	last = nextNode;

	lengh++;

	return SUCCESS;
}

/*Delete the first node in the queue and return its value.*/
int pop()
{
	int returnValue;
	Node* tmp;

	if ( isEmpty() == 0 )
		return ERROR;
	
	returnValue = head->value;
	tmp = head;

	head = head->next;

	free(tmp);
	lengh--;

	return returnValue;
}

/*Return the lengh of the queue.*/
int getQueueLen()
{
	return lengh;
}

/*Return the value of the head node in the queue*/
int getFirst()
{
	if ( isEmpty() == 0 )
		return ERROR;

	return head->value;
}