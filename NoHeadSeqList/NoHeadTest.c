#define _CRT_SECURE_NO_WARNINGS 1
#include "NoHeadSeqList.h"

int main()
{
	SList plist;
	SListInit(&plist);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 5);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 9);
	SListPushFront(&plist, 15);
	//SListPushBack(&plist, 8);  //15 9 1 5 2 8
	//SListRemove(&plist, 5);    //15 9 1 2 8
	SListPrint(&plist);
	//SListPopFront(&plist);
	/*SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);*/
	//SListPopBack(&plist);
	/*SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);*/
	//SListPrint(&plist);
	SListInsertFront(&plist, 7);
	SListPrint(&plist);

	SListNode* pos = SListFind(&plist, 2);
	SListEraseAfter(pos);      // 15 9  1  2
	
	SListInsertAfter(pos, 12); // 15 9  1  2  12
	SListPrint(&plist);
	
	SListDestroy(&plist);
	system("pause");
	return 0;
}

