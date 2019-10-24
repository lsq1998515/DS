#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
 
//向下调整算法  实现大堆
void adjustDown(Heap* hp, int m)
{
	int cur = m;
	int n;//记录左右结点中较大孩子结点的下标
	
	while (cur*2+1<hp->_size)
	{
		//找到左右孩子中较大的结点下标

		//判断右孩子是否存在
		if (cur * 2 + 2 >= hp->_size)//左孩子不存在
		{
			n = cur * 2 + 1;
		}
		else
		{
			//左孩子存在,且右孩子结点大于左孩子结点
			if (hp->_a[cur * 2 + 1] > hp->_a[cur * 2 + 2])
			{
				//交换
				n = cur * 2 + 1;
			}
			//左孩子存在,且右孩子结点小于等于左孩子结点
			else
			{
				//交换
				n = cur * 2 + 2;
			}
		}

		//比较较大结点和根的大小
		if (hp->_a[cur] < hp->_a[n])
		{
			//交换
			int tmp = hp->_a[cur];
			hp->_a[cur] = hp->_a[n];
			hp->_a[n] = tmp;
			//重置根节点
			cur = n;
		}
		else
		{
			break;
		}
	}
}

//创建堆
void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->_capacity = n * 2;
	hp->_size = n;
	hp->_a = (HPDataType*)calloc(hp->_capacity, sizeof(HPDataType));
	for (int j = 0; j < n; j++)
	{
		hp->_a[j] = a[j];
	}
	//从第一个非叶子节点开始,向前遍历,对每一个叶子结点进行向下调整算法
	for (int i = n/2-1; i >= 0; i--)
	{
		adjustDown(hp, i);
	}
}

void HeapDestory(Heap* hp)
{
	//防止重复释放
	if (hp->_a)
	{
		free(hp->_a);
	}
	hp->_size = 0;
	hp->_capacity = 0;
}

//堆插入
//先插入一个num到数组的尾上，再进行向上调整算法，直到满足堆。
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	//判断容量
	if (hp->_capacity = hp->_size)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc (hp->_a, hp->_capacity*sizeof(HPDataType));
	}
	int cur = hp->_size;
	//先在最后面添加新节点
	hp->_a[hp->_size] = x;
	hp->_size++;
	//再进行向上调整
	while (cur>0)
	{
		if (hp->_a[cur] > hp->_a[(cur-1)/2])
		{
			//交换
			int tmp = hp->_a[cur];
			hp->_a[cur] = hp->_a[(cur - 1) / 2];
			hp->_a[(cur - 1) / 2] = tmp;

			cur = (cur - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//删除堆顶的数据
//将堆顶的数据根最后一个数据一换，然后删除数组最后一个数据，再进行向下调整算法。
void HeapPop(Heap* hp)
{
	if (hp->_size==0)
	{
		return;
	}
	hp->_size--;
	//进行交换
	int tmp = hp->_a[0];
	hp->_a[0] = hp->_a[hp->_size];
	hp->_a[hp->_size] = tmp;
	//进行向下调整
	adjustDown(hp, 0);
}

HPDataType HeapTop(Heap* hp)
{
	if (hp->_size==0)
	{
		return (HPDataType)0;
	}
	return hp->_a[0];
}
int HeapSize(Heap* hp)
{
	return hp->_size;
}
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}
// 堆排序
void HeapSort(Heap* hp)
{
	int tmp = hp->_size;
	while (hp->_size>1)
	{
		HeapPop(hp);
	}
	hp->_size = tmp;
}

void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
}

void TestHeap()
{
	int data[10] = { 6,2,5,4,1,9,8,10,7,3 };
	Heap hp;
	HeapInit(&hp, data, 10);
	HeapPush(&hp, 13);
	HeapPush(&hp, 11);
	//HeapPop(&hp);
	HeapSort(&hp);
	HeapPrint(&hp);
	HeapDestory(&hp);
}
