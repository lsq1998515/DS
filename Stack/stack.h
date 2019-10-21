#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include <malloc.h>
#include<assert.h>
 
//链表实现栈(双向链表实现O(1) 单向链表实现时间复杂度O(n)即进行尾插尾删操作 或者 O(1)即进行头插//头删操作)
//顺序表实现栈(类似于进行尾插,尾删操作,时间复杂度O(1))
//双向队列(库里面默认实现方式)
 
//顺序表实现栈
typedef int DataType;
typedef struct Stack
{
	DataType* _a;
	int _top;      // 栈顶
    int _capacity; // 容量
}Stack;
 
//初始化
void StackInit(Stack* ps);
 
//销毁
void StackDestory(Stack* ps);
 
//插入
void StackPush(Stack* ps, DataType x);
 
//删除
void StackPop(Stack* ps);
 
//返回栈顶元素
DataType StackTop(Stack* ps);
 
//判断栈是否为空
int StackEmpty(Stack* ps);
 
//返回栈元素个数
int StackSize(Stack* ps);
 
void StackPrint(Stack* ps);
 
void TestStack();
