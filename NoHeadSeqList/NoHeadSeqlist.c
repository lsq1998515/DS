#define _CRT_SECURE_NO_WARNINGS 1
#include "NoHeadSeqList.h"

//1.��ʼ��
void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}

//2.����
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

//3.�������
SListNode* BuyListNode(SLTDataType x)
{
	SListNode* plist = (SListNode*)malloc(sizeof(SListNode));
	plist->_date = x;
	plist->_next = NULL;
	return plist;
}

////4.β�� ʱ�临�Ӷ�O(n)
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

////4.β��
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
//5.ͷ��
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* pnode = BuyListNode(x);
	assert(pnode);
	pnode->_next = plist->_head;
	plist->_head = pnode;
}

//6.ͷɾ ʱ�临�Ӷ�O(1)
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

//7.βɾ
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
//////7.βɾ ʱ�临�Ӷ�O(n)
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
		//���ɾ����ͷ
		plist->_head = NULL;
	}
	prev->_next = NULL;
}


//8.����ֵΪx�Ľ��
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

//9.��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode*pnode = BuyListNode(x);
    pnode->_next=pos->_next;
	pos->_next = pnode;
}

//10.ǰ��
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

//11.ɾ��POSλ����ĵ�һ�����
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

//12.�Ƴ�ֵΪx�Ľ��
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

//13.��ӡ
void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* tmp = plist->_head;
	while (tmp)
	{
		printf("%d->", tmp->_date);
		tmp = tmp->_next;
	}
	printf("NULL\n");//�����β
}
