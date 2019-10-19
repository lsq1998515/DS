#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��ͷ˫��ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;

//��ʼ��
void ListInit(List* plist);

//������
ListNode* BuyListNode();

//����
void ListDestory(List* plist);

//β��
void ListPushBack(List* plist, LTDataType x);

//βɾ
void ListPopBack(List* plist);

//ͷ��
void ListPushFront(List* plist, LTDataType x);

//ͷɾ
void ListPopFront(List* plist);

//����
ListNode* ListFind(List* plist, LTDataType x);

// ��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);

// ɾ��posλ�õĽڵ�
void ListErase(List*plist,ListNode* pos);

//��ӡ
void ListPrint(List* plist);