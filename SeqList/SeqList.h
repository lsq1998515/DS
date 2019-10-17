#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
//定义顺序表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;   //指向动态开辟的数组
	size_t size;     //有效数据个数
	size_t capicity; //容量

}SeqList,*PSeq; 

//初始化
void SeqListInit(PSeq ps1, size_t capicity);

//销毁
void SeqListDestory(PSeq ps1);

//扩容
void CheckCapaticity(PSeq ps1);

//打印输出
void SeqListPrint(PSeq ps1);

//尾插
void SeqListPushBack(PSeq ps1,SLDataType x);

//头插
void SeqListPushFront(PSeq ps1,SLDataType x);

//任意pos位置的插入
void SeqListInsert(PSeq ps1, size_t pos, SLDataType x);

//尾删
void SeqListPopBack(PSeq ps1);

//头删
void SeqListPopFront(PSeq ps1);

//删除pos位的元素
void SeqListErase(PSeq ps1, size_t pos);

//查值为x的节点,并返回下标
int SeqListFind(PSeq ps1, SLDataType x);

//删除第一个值为x的节点
void SeqListRemove(PSeq ps1, SLDataType x);

//删除所有值为x的节点
void SeqListRemoveAll(PSeq ps1, SLDataType x);

//修改第POS位的值
void SeqListModify(PSeq ps1, size_t pos, SLDataType x);

//对顺序表实现BubbleSort
void SeqListBubbleSort(PSeq ps1);

//对顺序表实现BinaryFind(二分查找) 
int SeqListBinaryFind(PSeq psl, SLDataType x);

//对顺序表实现插入排序 InsertSort
void InsertSort(PSeq ps1);