#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//��ʼ��
void ListInit(List* plist)
{
	plist->_head = BuyListNode(-1);
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

//�����µĽ��
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	//�жϷ����Ƿ�ɹ�
	assert(newNode);
	newNode->_data = x;
	newNode->_next = NULL;
	newNode->_prev = NULL;
	return newNode;
}


//����
void ListDestory(List* plist)
{
	assert(plist);
	ListNode* tmp;
	tmp = plist->_head->_next;
	//�������ͷ�ͷ���,��ֹ�����ͷ�
	while (tmp!=plist->_head)
	{
		ListNode* next = tmp->_next;
		tmp = next;
	}
	//����ͷ�
	free(plist->_head);
	plist->_head = NULL;
}

// ��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* newnode = BuyListNode(x); // �����½��
	ListNode* prev = pos->_prev; // posǰһ�����

	prev->_next = newnode; // ����posǰһ�������½��
	newnode->_prev = prev;

	pos->_prev = newnode; // ����pos���½��
	newnode->_next = pos;

}

//ͷ��
void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	//ͷ����ڵ�һ�����ǰ�����һ��
	ListInsert(plist->_head->_next, x);
	//ListNode* next;
	//ListNode* newNode = BuyListNode(x);
	//next = plist->_head->_next;
	//plist->_head->_next = newNode;
	//newNode->_prev = plist->_head;
	//newNode->_next = next;
	//next->_prev = newNode;
}

//β��
void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	////β�����ͷ���ǰ�����һ�����һ��
	ListInsert(plist->_head, x);
	//ListNode* tail;
	//ListNode* newNode =BuyListNode(x) ;
	//tail = plist->_head->_prev;
	//tail->_next = newNode;
	//newNode->_prev = tail;
	//newNode->_next = plist->_head;
	//plist->_head->_prev = newNode;
}

// ɾ����ǰposλ�õĽڵ�
void ListErase(List*plist,ListNode* pos)
{
	ListNode*prev, *next;
	assert(pos && plist);
	//ע�������
	if (plist->_head == pos)
		return;

	prev = pos->_prev;
	next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}

//ͷɾ
void ListPopFront(List* plist)
{
	//assert(plist);
	//����ɾ��ͷ������Ľ��
	ListErase(plist,plist->_head->_next);
	//ListNode* ret,*next;
	////����ɾ��ͷ�ڵ�
	//if (plist->_head = plist->_head->_next)
	//	return;
	//next = plist->_head->_next;
	//ret = next->_next;
	//plist->_head->_next = ret;
	//ret->_prev = plist->_head;
	//free(next);
	//next = NULL;
}

//βɾ
void ListPopBack(List* plist)
{
	//assert(plist);
	//����ɾ��ͷ���ǰ��Ľ��
	ListErase(plist,plist->_head->_prev);
	//ListNode* ret,*tail;
	////ע�ⲻ��ɾ��ͷ�ڵ�
	//if (plist->_head == plist->_head->_next)
	//	return;
	//tail = plist->_head->_prev;
	//ret = tail->_prev;

	//ret->_next = plist->_head;
	//plist->_head->_prev = ret;
	//free(tail);
	//tail = NULL;
}

//����
ListNode* ListFind(List* plist, LTDataType x)
{
	ListNode* NewNode;
	assert(plist);
	NewNode = plist->_head;
	while (NewNode->_next!=plist->_head)
	{
		NewNode = NewNode->_next;
		if(NewNode->_data==x)
		{
			return NewNode;
		}
	}
	printf("�����ڴ˽��\n");
	return NULL;
}

//��ӡ
void ListPrint(List* plist)
{
	assert(plist);
	//ͷ���������,����ֱ��ָ��ͷ����һ�����
	ListNode* ret=plist->_head->_next;
	while (ret!=plist->_head)
	{
		printf("%d  ", ret->_data);
		ret = ret->_next;
	}
	printf("\n");
}