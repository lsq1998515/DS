#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include<malloc.h>
 
typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front; // 队头
	QueueNode* _rear; // 队尾
}Queue;
 
//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestory(Queue* pq);
//创建新的结点
QueueNode* BuyQueueNode(QUDataType x);
//入队
void QueuePush(Queue* pq, QUDataType x);
//出队
void QueuePop(Queue* pq);
//返回队首
QUDataType QueueFront(Queue* pq);
//返回队尾
QUDataType QueueBack(Queue* pq);
//判断是否为空
int QueueEmpty(Queue* pq);
//返回队元素个数
int QueueSize(Queue* pq);
//打印
void QueueDisplay(Queue*pq);
 
void TestQueue();
