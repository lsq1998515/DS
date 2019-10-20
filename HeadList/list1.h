//list1 .h
#ifndef __LIST_H__
#define __LIST_H__
//#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
 
//定义节点
typedef struct Node
{
	int date;
	struct Node* Next;
 
}Node, *p;
 
//初始化
void InitList(p head);
 
//打印
void show(p head);
 
//尾插
void InsertTail(p head, int val);
 
//头插
void InsertHead(p head, int val);
 
//删除
void Deletei(p head, int i);
 
//查找
void Search(p head, int i);
 
//逆置
//void  Inversion(p head);
void  Inversion2(p head);
 
//返回倒数第k个结点
Node *LastKNode(p head, int k);
 
#endif //__LIST_H__
