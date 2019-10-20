//list2.c
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/* 实现功能*/
//初始化
//头插
//尾插
//打印
//查找
//删除
//逆置
//返回倒数第K个结点
 
//定义节点
typedef struct Node
{
	int date;
	struct Node* Next;
 
}Node,*p;
 
//初始化
void InitList(p head)
{
	assert(head != NULL);
	head->date = -1;
	head->Next = NULL;
}
 
//得到一个节点函数
Node* GetNode(int val)
{
	Node *pGet =(p) malloc(sizeof(Node));
	assert(pGet != NULL);
	pGet->date = val;
	pGet->Next = NULL;
	return pGet;
}
 
//头插
void InsertHead(p head, int val)
{
	Node*pGet= GetNode(val);
	assert(pGet != NULL);
	pGet->Next = head->Next;
	head->Next = pGet;
}
 
 
//尾插
void InsertTail(p head, int val)
{
	Node*pGet = GetNode(val);
	assert(head!= NULL);
	while (head->Next !=NULL)
	{
		head=head->Next;
	}
	head->Next = pGet;
}
 
 
//打印
void show(p head)
{
	Node*p1= NULL;
	assert(head != NULL);
	p1 = head->Next;
	while (p1!=NULL)
	{
		printf("%d  ", p1->date);
		p1 = p1->Next;
 
	}
}
 
//查找
void Search(p head,int i)
{
	Node*p1 = NULL;
	assert(head != NULL);
	p1 = head->Next;
	while (p1!=NULL)
	{
		if (i==p1->date)
		{
			printf("找到了!\n");
			printf("%p  ", &(p1->Next));
			return;
		}
		p1 = p1->Next;
	}
	printf("找不到!\n");
}
 
//删除   包括(头结点 尾结点 任意节点)
void Deletei(p head, int i)
{
	Node*p1 = NULL;
	Node*p2 = NULL;
	assert(head != NULL);
	p1 = head->Next;
	p2 = head;
	while (p1 != NULL)
	{
		if (i == p1->date)
		{
			p2->Next = p1->Next;
			return;
		}
		else
		{
			p2 = p1;
		}
		p1 = p1->Next;	
	}
	return ;
}
////逆置方法1
//void Inversion1(p head)
//{
//	if (head->date!=NULL)
//	{
//		Node*q1= head->Next->Next;
//		Node*q2;
//		Node*tem = head->Next;
//		tem->Next = NULL;
//		while (q1)
//		{
//			q2 = q1;
//			q1 = q1->Next;
//			q2->Next = tem;
//			tem = q2;
//		}
//		head->Next = tem;
//	}
//}
//
//	while (p != NULL)
//	{
//		q = p;
//		p = p->next;
//
//		q->next = L->next;
//		L->next = q;
//	}
//	return L;
//}
//逆置方法2 头插法逆置
void  Inversion2(p head)
{
	Node*p;
	Node*q;
	p = head->Next; 
	head->Next = NULL;
	while (p!=NULL)
	{
		q = p;
		p = p->Next;
		q->Next = head->Next;
		head->Next = q;
	}
	return head;
}
 
//返回倒数第K个结点
Node *LastKNode(p head, int k)
{
	//1、让一个指针先走K-1步
	//2.两个指针同时走
	Node *p = head;
	Node *q = head;
	if (k < 0)
	{
		return NULL;
	}
	assert(head != NULL);
	while (k-1)
	{
		if (p->Next != NULL)
		{
			p = p->Next;
			--k;
		}
		else
		{
			return NULL;
		}
	}
	while (p->Next!=NULL )
	{
		p = p->Next;
		q = q->Next;
	}
	return q;
}
 
