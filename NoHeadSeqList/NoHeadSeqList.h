#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _date;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

//1.初始化
void SListInit(SList* plist);

//2.销毁
void SListDestroy(SList* plist);

//3.创建结点
SListNode* BuyListNode(SLTDataType x);

//4.尾插
void SListPushBack(SList* plist, SLTDataType x);
//5.头插
void SListPushFront(SList* plist, SLTDataType x);
//6.头删
void SListPopFront( SList* plist);
//7.尾删
void SListPopBack(SList* plist);

//8.查找值为x的结点
SListNode* SListFind(SList* plist, SLTDataType x);

//9.在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);

//10.前插
void SListInsertFront(SList* plist, SLTDataType x);

//11.删除POS后面的第一个结点
void SListEraseAfter(SListNode* pos);

//12.移除值为x的结点
void SListRemove(SList* plist, SLTDataType x);

//13.打印
void SListPrint(SList* plist);
