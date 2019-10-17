#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
int main()
{
	SeqList s;
	SeqListInit(&s, 5);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 18);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 9);
	//SeqListPrint(&s);
	SeqListPushFront(&s, 12);
	SeqListPushFront(&s, 5);
	//SeqListPrint(&s);
	//SeqListDestory(&s);
	//SeqListInsert(&s, 5, 2);
	//SeqListPopBack(&s);
	//SeqListPopFront(&s);
	//SeqListErase(&s, 4);
	//SeqListRemove(&s, 3);
	//SeqListModify(&s, 4, 55);
	//SeqListRemoveAll(&s, 1);
	//SeqListBubbleSort(&s);
	//int key = SeqListBinaryFind(&s, 18);
	//printf("%d\n", key);
	InsertSort(&s);
	SeqListPrint(&s);
	return 0;
}
