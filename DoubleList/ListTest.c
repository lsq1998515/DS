#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

int main()
{
	List phead;
	ListNode* ret;
	ListInit(&phead);
	ListPushFront(&phead, 3);
	ListPushFront(&phead, 2);
	ListPushFront(&phead, 1);
    ListPushBack(&phead, 4);
	ListPushBack(&phead, 5);
	//ListPrint(&phead);//1 2 3 4 5
	//ListPopBack(&phead);
	//ListPopBack(&phead);
	//ListPopBack(&phead);
	//ListPopBack(&phead);
	//ListPopBack(&phead);
	//ListPopBack(&phead);
	//ListPopFront(&phead);
	//ListPopFront(&phead);
	//ListPopFront(&phead);
	//ListPopFront(&phead);
	//ListPopFront(&phead);
	//ListPopFront(&phead);
	ret = ListFind(&phead, 3);
	
	printf("%d\n", ret->_data);
	ListInsert(ret, 10);
	//ListPopBack(&ret);
	ListPrint(&phead);//2 4
	ListDestory(&phead);
	system("pause");
	return 0;
}