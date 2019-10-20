//test1.c
#define _CRT_SECURE_NO_WARNINGS 1
#include "list1 .h"
//测试
int main()
{
	Node head;
	Node *p1 = NULL;
	InitList(&head);
	//InsertHead(&head, 1);
	//InsertHead(&head, 11);
	//InsertHead(&head, 25);
	//InsertHead(&head, 56);
	//show(&head);
	InsertTail(&head, 12);
	InsertTail(&head, 22);
	InsertTail(&head, 32);
	InsertTail(&head, 42);
	show(&head);
	printf("\n");
	Search(&head, 5);
	Deletei(&head, 12);
	show(&head);
	printf("\n");
	//Inversion1(&head);
	Inversion2(&head);
	show(&head);
	printf("\n");
    p1 = LastKNode(&head, 2);
	printf("%d\n", p1->date);
	system("pause");
	return 0;
}
