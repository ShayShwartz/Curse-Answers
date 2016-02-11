#ifndef _LIST_H_
#define _LIST_H_

#include "Node.h"

/*Initialize the list and create the first node.*/
int initializeList(int val);
/*Delete all the nodes in the list recursivly.*/
void deleteList();
/*Append new node with the inserted value to the end of the list.*/
int appendNode(int val);
/*Remove the spcified node from the list*/
int removeNode(Node* node);
/*Return the lengh of the list*/
int getListLen();
/*Return pointer to the head of the list (if exists), or null if the list is empty.*/
Node* getListHead();
/*Return pointer to the last node in the list (if exists), or null if the list is empty.*/
Node* getListTail();
/*Return pointer to the next node after the spcified node (if exists), or null in case of error or the next node does'nt exist*/
Node* getNext(Node* node);
/*Return pointer to the previous node after the spcified node (if exists), or null in case of error or the previous node does'nt exist*/
Node* getPrev(Node* node);
/*Return the value of the spcified node (if exists), or null if the node does'nt exist*/
int getValue(Node* node);
/*Calculate the avarage of the list if the list not empty, else, return error value (-1)*/
float getAvarage();


#endif