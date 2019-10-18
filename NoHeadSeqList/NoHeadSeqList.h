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

//1.��ʼ��
void SListInit(SList* plist);

//2.����
void SListDestroy(SList* plist);

//3.�������
SListNode* BuyListNode(SLTDataType x);

//4.β��
void SListPushBack(SList* plist, SLTDataType x);
//5.ͷ��
void SListPushFront(SList* plist, SLTDataType x);
//6.ͷɾ
void SListPopFront( SList* plist);
//7.βɾ
void SListPopBack(SList* plist);

//8.����ֵΪx�Ľ��
SListNode* SListFind(SList* plist, SLTDataType x);

//9.��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x);

//10.ǰ��
void SListInsertFront(SList* plist, SLTDataType x);

//11.ɾ��POS����ĵ�һ�����
void SListEraseAfter(SListNode* pos);

//12.�Ƴ�ֵΪx�Ľ��
void SListRemove(SList* plist, SLTDataType x);

//13.��ӡ
void SListPrint(SList* plist);
