#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//带头双向循环链表增删查改实现
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

//初始化
void ListInit(List* plist);

//申请结点
ListNode* BuyListNode();

//销毁
void ListDestory(List* plist);

//尾插
void ListPushBack(List* plist, LTDataType x);

//尾删
void ListPopBack(List* plist);

//头插
void ListPushFront(List* plist, LTDataType x);

//头删
void ListPopFront(List* plist);

//查找
ListNode* ListFind(List* plist, LTDataType x);

// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);

// 删除pos位置的节点
void ListErase(List*plist,ListNode* pos);

//打印
void ListPrint(List* plist);