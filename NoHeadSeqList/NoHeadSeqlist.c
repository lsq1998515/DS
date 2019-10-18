#define _CRT_SECURE_NO_WARNINGS 1
#include "NoHeadSeqList.h"

//1.初始化
void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}

//2.销毁
void SListDestroy(SList* plist)
{
	assert(plist);
	SListNode* p;
	SListNode* q;
	p= plist->_head;
	while (p)
	{
		q = p->_next;
		free(p);
		p = q;
	}
	plist->_head = NULL;
}

//3.创建结点
SListNode* BuyListNode(SLTDataType x)
{
	SListNode* plist = (SListNode*)malloc(sizeof(SListNode));
	plist->_date = x;
	plist->_next = NULL;
	return plist;
}

////4.尾插 时间复杂度O(n)
void SlistPushBack(SList*plist, SLTDataType x)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		plist->_head = BuyListNode(x);
	}
	else
	{
		SListNode*cur = plist->_head;

		while (cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = BuyListNode(x);
	}
}

////4.尾插
//void SListPushBack(SList* plist, SLTDataType x)
//{
//	assert(plist);
//	if (plist->_head == NULL)
//	{
//		SListPushFront(plist, x);
//		return;
//	}
//	SListNode* pnode = BuyListNode(x);
//	assert(pnode);
//	SListNode* tmp = plist->_head;
//	while (tmp->_next)
//	{
//		tmp = tmp->_next;
//	}
//	tmp->_next = pnode;
//}
//5.头插
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* pnode = BuyListNode(x);
	assert(pnode);
	pnode->_next = plist->_head;
	plist->_head = pnode;
}

//6.头删 时间复杂度O(1)
void SListPopFront(SList* plist)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		return;
	}
	SListNode* pnode = plist->_head;
	plist->_head = pnode->_next;
	free(pnode);
	pnode = NULL;
}

//7.尾删
//void SListPopBack(SList* plist)
//{
//	assert(plist);
//	assert(plist->_head);
//	SListNode* pnode = plist->_head;
//	if (pnode->_next==NULL)
//	{
//		SListPopFront(plist);
//		return;
//	}
//	assert(pnode);
//	SListNode* ret = plist->_head;
//	while (ret->_next)
//	{
//		pnode = ret;
//		ret = ret->_next;
//	}
//	free(ret);
//	pnode->_next = NULL;
//}
//////7.尾删 时间复杂度O(n)
void SlistPopBack(SList* plist)
{
	assert(plist);
	SListNode* prev=NULL;
	SListNode* cur = plist->_head;
	while (cur->_next)
	{
		prev = cur;
		cur = cur->_next;
	}
	free(cur);
	cur = NULL;
	if (prev==NULL)
	{
		//如果删的是头
		plist->_head = NULL;
	}
	prev->_next = NULL;
}


//8.查找值为x的结点
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	assert(plist->_head);
	SListNode* pnode = plist->_head;
	while (pnode)
	{
		if (pnode->_date==x)
		{
			return pnode;
		}
		pnode = pnode->_next;
	}
	return NULL;
}

//9.在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode*pnode = BuyListNode(x);
    pnode->_next=pos->_next;
	pos->_next = pnode;
}

//10.前插
void SListInsertFront(SList* plist, SLTDataType x)
{
	SListNode* newdata = (SListNode*)malloc(sizeof(SListNode));
	SListNode *cur;
	if (plist->_head->_date)
	{
		SListPushFront(plist, x);
		return;
	}
	for (cur = plist->_head; cur->_next; cur = cur->_next)
	{
		if (cur->_next->_date == x)
		{
			break;
		}
	}
	newdata->_next = cur->_next;
	cur->_next = newdata;
}

//11.删除POS位后面的第一个结点
void SListEraseAfter(SListNode* pos)
{
	if (pos->_next==NULL)
	{
		return;
	}
	SListNode* pnode = pos->_next;
	pos->_next = pnode->_next;
	free(pnode);
}

//12.移除值为x的结点
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	while (plist->_head != NULL && plist->_head->_date == x)
	{
		SListPopFront(plist);
	}
	SListNode* prev = plist->_head;
	SListNode* cur = plist->_head->_next;
	for (; cur != NULL; cur = prev->_next)
	{
		if (cur->_date ==x)
		{
			prev->_next = cur->_next;
			free(cur);
			cur = NULL;
		}
		else
		{
			prev = cur;
		}
	}
}

//13.打印
void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* tmp = plist->_head;
	while (tmp)
	{
		printf("%d->", tmp->_date);
		tmp = tmp->_next;
	}
	printf("NULL\n");//代表结尾
}
