#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "List.h"
#include "MyColorChanger.h"

void printList(Node* node);

int main(void)
{
	int first, poped, second;
	/*Testing Queue library*/
	whiteText();
	printf("Testing Queue library...\n\n");
	if ( initializeQueue(1) == -1 )
	{
		redText();
		printf("Initializing error.\n");
		whiteText();
		system("pause");
		return 1;
	}
	push(-2);
	push(0x3);
	push(04);
	push(5);
	printf("Queue lengh: %d\n", getQueueLen());
	/* ****FOR TESTING THE DELETE REMOVE THE QUOTE****
	deleteQueue();
	printf("Queue has been deleted.\n");*/
	first = getFirst();
	if(first == -1)
		goto END;
	poped = pop();
	second = getFirst();
	if(second == -1)
		goto END;
	pop();
	greenText();
	printf("The First: %d\nPoped: %d\nThe second: %d\n", first, poped, second);
	whiteText();
	printf("Pop the rest of the elements in the queue:\n");
	poped = pop();
	while(poped != -1)
	{
		greenText();
		printf("%d\n", poped);
		poped = pop();
	}
	whiteText();
	printf("\n\nTesting List library...\n\n");
	
	/* initillize list */
	initializeList(0);

	/* add nodes with values 1 and 2 */
	appendNode(1);
	appendNode(2);

	/* print all list */
	printList(getPrev(getNext(getListHead())));

	printf("\nNeed to print without second node\n");
	/* delete the second node and print the list */
	removeNode(getListHead()->next);
	printList(getListHead());

	printf("\nNeed to print only the fisrt node\n");
	/* delete the first node and print the list */
	removeNode(getListTail());
	printList(getListHead());

	appendNode(-1);
	appendNode(-2);

	printf("\nThe last node value is: %d\n", getListTail()->value);
	printList(getListHead());

	printf("\nThe list average is: %.2f\n", getAvarage());

	deleteList();

	printf("List deleted -> now reInitializing.\n");
	initializeList(0);
	/* add nodes with values 1 and 2 */
	appendNode(1);
	appendNode(2);

	/* print all list */
	printList(getPrev(getNext(getListHead()))); 

END:
	system("pause");
	return 0;
}

void printList(Node* node)
{
	greenText();
	
	if (node == NULL)
	{
		printf("NULL\n");
		printf("Length: %u\n", getListLen());
	}
	else
	{
		printf("(%d)->", node->value);
		printList(node->next);
	}
	
	whiteText();
}