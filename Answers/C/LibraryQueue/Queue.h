#ifndef _QEUEU_H_
#define _QEUEU_H_

#include "Node.h"

/*Initialize the queue and create the first node.*/
int initializeQueue(int val);
/*Delete all the nodes in the queue recursivly.*/
void deleteQueue();
/*Append new node with the inserted value to the end of the queue.*/
int push(int val);
/*Delete the first node in the queue and return its value.*/
int pop();
/*Return the lengh of the queue.*/
int getQueueLen();
/*Return the value of the head node in the queue*/
int getFirst();

#endif