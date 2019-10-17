#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <malloc.h>

//接下来，我们就要实现动态顺序表的相关操作，主要包括：
//初始化顺序表
//顺序表尾插、尾删
//顺序表头插、头删
//顺序表任意位置插入、任意位置删除
//顺序表元素查找
//删除顺序表中第一个值为x的元素
//删除顺序表中所有值为x的元素
//修改顺序表中某一元素的数值
//顺序表元素个数、容量查询
//顺序表扩容,销毁及打印
//对顺序表实现BinaryFind(二分查找) 
//对顺序表实现InsertSort(插入排序)
//对顺序表实现BubbleSort(冒泡排序)

//初始化
void SeqListInit(PSeq ps1, size_t newcapicity)
{
    assert(ps1);
	assert(newcapicity != 0);
	ps1->arr = (SLDataType*)malloc(sizeof(int)*newcapicity);
	assert(ps1->arr);
	ps1->capicity = newcapicity;
	ps1->size = 0;
}

//销毁
void SeqListDestory(PSeq ps1)
{
	if (ps1->arr)
	{
		free(ps1->arr);
		ps1->arr = NULL;
		ps1->capicity = 0;
		ps1->size = 0;
	}
}

//数据扩容
void CheckCapaticity(PSeq ps1)
{
	assert(ps1);
	if (ps1->capicity==ps1->size)
	{
		ps1->capicity *= 2;
		realloc(ps1->arr, sizeof(SLDataType)*ps1->capicity);
	}
}

//打印输出
void SeqListPrint(PSeq ps1)
{
	assert(ps1);
	size_t i = 0;
	for (i = 0; i< (ps1->size); ++i)
	{
		printf("%d ", ps1->arr[i]);
	}
	printf("\n");
}

//尾插
void SeqListPushBack(PSeq ps1, SLDataType x)
{
	assert(ps1);
	CheckCapaticity(ps1);
	ps1->arr[ps1->size] = x;
	ps1->size++;
}

//头插   不能使用malloc,因为有可能内容重复
//只能从后向前移动
void SeqListPushFront(PSeq ps1, SLDataType x)
{
	assert(ps1);
	//检查容量
	CheckCapaticity(ps1);
	int i = 0;
    //移动,从后往前
	for (i = (ps1->size);i>0; --i)
	{
		ps1->arr[i] = ps1->arr[i - 1];
	}
	//插入
	ps1->arr[0] = x;
	//大小++
	ps1->size++;
}

//任意pos位置的插入
void SeqListInsert(PSeq ps1, size_t pos, SLDataType x)
{
	assert(ps1);
	assert(pos >= 0 && pos <= ps1->size);//pos=0 相当于头插  pos=size 相当于尾插
	//判断容量
	CheckCapaticity(ps1);
	size_t i = 0;
	//移动
	for (i = (ps1->size); i > pos;i--)
	{
		ps1->arr[i] = ps1->arr[i-1];
	}
	//插入
	ps1->arr[pos] = x;
	//扩容
	ps1->size++;
}

//尾删
void SeqListPopBack(PSeq ps1)
{
	assert(ps1);
	assert(ps1->size > 0);
	ps1->size--;
}

//头删
void SeqListPopFront(PSeq ps1)
{
	assert(ps1);
	assert(ps1->size > 0);
	size_t i = 0;
	//移动元素 从前往后移动 O(n)
	for (i = 1; i < ps1->size;i++)
	{
		ps1->arr[i-1] = ps1->arr[i];
	}
	ps1->size--;
}

//删除pos位的元素 
void SeqListErase(PSeq ps1, size_t pos)
{
	assert(ps1);
	assert(pos <= ps1->size && pos >= 0);
	size_t i = 0;
	for (i = pos+1; i<=ps1->size;i++)
	{
		ps1->arr[i - 1] = ps1->arr[i];
	}
	ps1->size--;
}

//查值为x的节点,并返回下标
int SeqListFind(PSeq ps1, SLDataType x)
{
	assert(ps1);
	size_t i = 0;
	for (i = 0; i <ps1->size;i++)
	{
		if (ps1->arr[i]==x)
		{
			return i;
		}
	}
	return -1;
}

//删除第一个值为x的节点
void SeqListRemove(PSeq ps1, SLDataType x)
{
	assert(ps1);
	int ret=SeqListFind(ps1, x);
	if (ret != -1)
	{
		SeqListErase(ps1, ret);
	}
}

//删除所有值为x的节点
//设置中间变量tem重复利用SeqlistFind与SeqlistErase函数
void SeqListRemoveAll(PSeq ps1, SLDataType x)
{
	assert(ps1);
	int tem = -1;
	while ((tem=SeqListFind(ps1,x))!=-1)	
	{
		SeqListErase(ps1, tem);
	}
}


//void SeqListRemoveAll(PSeq ps1, SLDataType x)
//{ 
//	assert(ps1);
//
//
//}

//修改第POS位的值
void SeqListModify(PSeq ps1, size_t pos, SLDataType x)
{
	assert(ps1);
	assert((pos >= 0) && pos <= (ps1->size));
	size_t i = 0;
	for (i = 0; i < ps1->size;i++)
	{
		if (i==pos)
		{
			ps1->arr[i] = x;
		}
	}
}

//对顺序表实现BubbleSort
void SeqListBubbleSort(PSeq ps1)
{
	assert(ps1);
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < (ps1->size);i++)
	{
		int flag = 1;
		for (j = 0; j <(ps1->size-1-i);j++)
		{
			if ((ps1->arr[j]) > (ps1->arr[j+1]))
			{
				int ret = 0;
				ret = ps1->arr[j];
				ps1->arr[j] = ps1->arr[j+1];
				ps1->arr[j+1] = ret;
				flag = 0;
			}
		}
		if (flag==1)
		{
			return;
		}
	}
}

//对顺序表实现BinaryFind(二分查找) 前提进行排序
int SeqListBinaryFind(PSeq psl, SLDataType x)
{
	SeqListBubbleSort(psl);
	assert(psl);
	assert(psl->size >= 2);
	int left = 0;
	int right = psl->size - 1;
	while (left<right)
	{
		int mid = left + (right - left) / 2;
		if (psl->arr[mid]>x)
		{
			right = mid - 1;
		}
		else if (psl->arr[mid] < x)
		{
			left = mid + 1;
		}
		else
			return mid+1;	
	}
	return -1;
}

//对顺序表实现插入排序 InsertSort
//void InsertSort(PSeq ps1)
//{
//	assert(ps1);
//	int i = 0;
//	int j = 0;
//	int tmp=0;
//	for (i = 1; i<ps1->size; i++)
//	{
//		tmp = ps1->arr[i];
//		j = i - 1;
//		//与已排序的数逐一比较，大于temp时，该数移后
//		while ((j >= 0) && (ps1->arr[j]>tmp))
//		{
//			ps1->arr[j + 1] = ps1->arr[j];
//			j--;
//		}
//		//存在大于temp的数
//		if (j!=i-1)
//		{
//			ps1->arr[j + 1] = tmp;
//		}
//	}
//}
//插入排序代码优化
void InsertSort(PSeq ps1)
{
	assert(ps1);
	size_t i = 0;
	for (i = 0; i < ps1->size-1; i++)
	{
		int right = i;
	    int tmp = ps1->arr[right+1];
		while((right>=0) && ((ps1->arr[right])>tmp))
		{
			ps1->arr[right+1]=ps1->arr[right];
			right--;
		}
		ps1->arr[right+1] = tmp;
	}
}
