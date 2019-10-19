#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//初始化
void ListInit(List* plist)
{
	plist->_head = BuyListNode(-1);
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

//申请新的结点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	//判断分配是否成功
	assert(newNode);
	newNode->_data = x;
	newNode->_next = NULL;
	newNode->_prev = NULL;
	return newNode;
}


//销毁
void ListDestory(List* plist)
{
	assert(plist);
	ListNode* tmp;
	tmp = plist->_head->_next;
	//不能先释放头结点,防止二次释放
	while (tmp!=plist->_head)
	{
		ListNode* next = tmp->_next;
		tmp = next;
	}
	//最后释放
	free(plist->_head);
	plist->_head = NULL;
}

// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* newnode = BuyListNode(x); // 申请新结点
	ListNode* prev = pos->_prev; // pos前一个结点

	prev->_next = newnode; // 连接pos前一个结点和新结点
	newnode->_prev = prev;

	pos->_prev = newnode; // 连接pos和新结点
	newnode->_next = pos;

}

//头插
void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	//头插和在第一个结点前面插入一样
	ListInsert(plist->_head->_next, x);
	//ListNode* next;
	//ListNode* newNode = BuyListNode(x);
	//next = plist->_head->_next;
	//plist->_head->_next = newNode;
	//newNode->_prev = plist->_head;
	//newNode->_next = next;
	//next->_prev = newNode;
}

//尾插
void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	////尾插和在头结点前面插入一个结点一样
	ListInsert(plist->_head, x);
	//ListNode* tail;
	//ListNode* newNode =BuyListNode(x) ;
	//tail = plist->_head->_prev;
	//tail->_next = newNode;
	//newNode->_prev = tail;
	//newNode->_next = plist->_head;
	//plist->_head->_prev = newNode;
}

// 删除当前pos位置的节点
void ListErase(List*plist,ListNode* pos)
{
	ListNode*prev, *next;
	assert(pos && plist);
	//注意空链表
	if (plist->_head == pos)
		return;

	prev = pos->_prev;
	next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}

//头删
void ListPopFront(List* plist)
{
	//assert(plist);
	//等于删除头结点后面的结点
	ListErase(plist,plist->_head->_next);
	//ListNode* ret,*next;
	////不能删掉头节点
	//if (plist->_head = plist->_head->_next)
	//	return;
	//next = plist->_head->_next;
	//ret = next->_next;
	//plist->_head->_next = ret;
	//ret->_prev = plist->_head;
	//free(next);
	//next = NULL;
}

//尾删
void ListPopBack(List* plist)
{
	//assert(plist);
	//等于删除头结点前面的结点
	ListErase(plist,plist->_head->_prev);
	//ListNode* ret,*tail;
	////注意不能删掉头节点
	//if (plist->_head == plist->_head->_next)
	//	return;
	//tail = plist->_head->_prev;
	//ret = tail->_prev;

	//ret->_next = plist->_head;
	//plist->_head->_prev = ret;
	//free(tail);
	//tail = NULL;
}

//查找
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
	printf("不存在此结点\n");
	return NULL;
}

//打印
void ListPrint(List* plist)
{
	assert(plist);
	//头不存放数据,所以直接指向头的下一个结点
	ListNode* ret=plist->_head->_next;
	while (ret!=plist->_head)
	{
		printf("%d  ", ret->_data);
		ret = ret->_next;
	}
	printf("\n");
}