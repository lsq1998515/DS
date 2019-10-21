#include"stack.h"
 
//初始化
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}
 
//销毁
void StackDestory(Stack* ps)
{
	int i = 0;
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
 
 
 
//入栈 :相当于顺序表的尾插
void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	//检查容量
	if (ps->_capacity==ps->_top)
	{
		//如果栈为空,将栈容量设置为10,不为空且栈已经满了扩充容量为原来的2倍
		size_t newC = (ps->_capacity == 0 ? 10 : 2 * ps-_capacity );
		ps->_a = (DataType*)realloc(ps->_a, newC*sizeof(DataType));
		ps->_capacity = newC;
	}
	ps->_a[ps->_top++] = x;
}
 
 
//出栈 完成元素删除
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top)
	{
		--ps->_top;
	}
}
 
//返回栈顶元素
DataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}
 
//判断栈是否为空
int StackEmpty(Stack* ps)
{
	return ps->_top == 0 ? 1 : 0;  //1代表不为空 0代表为空
}
 
//返回栈元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
 
 
 
void StackPrint(Stack* ps)
{
	assert(ps);
	while (StackEmpty(ps)!=1)
	{
		printf("%d ", StackTop(ps));
		StackPop(ps);
	}
	printf("\n");
}
 
void TestStack()
{
	Stack S;
	StackInit(&S); 
	StackPush(&S, 1);
	StackPush(&S, 2);
	StackPush(&S, 3);
	StackPush(&S, 4);
	StackPush(&S, 5);
	StackPrint(&S);
	StackDestory(&S);
}
