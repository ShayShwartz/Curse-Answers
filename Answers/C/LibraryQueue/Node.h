#ifndef _NODE_H_
#define _NODE_H_

#define SUCCESS 0
#define ERROR -1


typedef struct sNode
{
	int value;
	struct sNode* next;
	struct sNode* prev;
}Node;

Node* createNode(int val);

#endif