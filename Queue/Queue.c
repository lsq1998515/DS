#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
//队列就是一个尾插头删的单链表
 
//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
}
 
//销毁
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* pret;
	while (pq->_front)
	{
		//保存下要删结点的下个元素
		pret = pq->_front;
		pq->_front = pq->_front->_next;
		free(pret);
	}
	pq->_front = NULL;
	pq->_rear = NULL;
}
 
//创建新的结点
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newNode);
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}
 
//入队 
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* pnewNode = BuyQueueNode(x);
	//判断是否为空
	if (QueueEmpty(pq)==0)
	{
		pq->_front = pnewNode;
		pq->_rear = pnewNode;
	}
	else
	{
		//不为空
		//进行插入
		pq->_rear->_next = pnewNode;
		//移动队尾指针
		pq->_rear = pnewNode;
	}
}
 
//出队
void QueuePop(Queue* pq)
{
	QueueNode* cur = pq->_front;
	if (pq->_front==NULL)
	{
		return;
	}
	assert(pq);
	if (pq->_front==pq->_rear)
	{
		pq->_front = NULL;
		pq->_rear = NULL;
	}
	else
	{
		//移动队首指针
		pq->_front = pq->_front->_next;
		free(cur);
	}
 
 
}
 
//返回队首
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	if (QueueEmpty(pq) != 0)
	{
		return pq->_front->_data;
	}
	return;
}
 
//返回队尾
QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	if (QueueEmpty(pq) != 0)
	{
		return pq->_rear->_data;
	}
	return;
}
 
//判断是否为空
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front != NULL;//空返回0,否则返回1
}
 
//返回队元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	int cout = 0;
	QueueNode* ret = pq->_front;
	while (ret!=NULL)
	{
		++cout;
		ret = ret->_next;
	}
	return cout;
}
 
void QueueDisplay(Queue*pq)
{
	assert(pq);
	QueueNode* ret = pq->_front;
	if (ret==NULL)
	{
		printf("队列为空!\n");
		return;
	}
	while (ret)
	{
		printf("%d ", ret->_data);
		ret = ret->_next;
	}
	printf("\n");
}
 
void TestQueue()
{
	Queue tmp;
	int num = 0;
	QueueInit(&tmp);
	QueuePush(&tmp, 1);
	QueuePush(&tmp, 2);
	QueuePush(&tmp, 3);
	QueuePush(&tmp, 4);
	QueueDisplay(&tmp);// 1 2 3 4
	QueuePop(&tmp);//2 3 4
	QueuePop(&tmp);//3 4
	num = QueueSize(&tmp);
	printf("%d\n", num);//2
	printf("%d\n", QueueFront(&tmp));//3 
	printf("%d\n", QueueBack(&tmp));//4
	QueueDisplay(&tmp);//3 4
	QueueDestory(&tmp);
}
