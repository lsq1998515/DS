#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <malloc.h>

//�����������Ǿ�Ҫʵ�ֶ�̬˳������ز�������Ҫ������
//��ʼ��˳���
//˳���β�塢βɾ
//˳���ͷ�塢ͷɾ
//˳�������λ�ò��롢����λ��ɾ��
//˳���Ԫ�ز���
//ɾ��˳����е�һ��ֵΪx��Ԫ��
//ɾ��˳���������ֵΪx��Ԫ��
//�޸�˳�����ĳһԪ�ص���ֵ
//˳���Ԫ�ظ�����������ѯ
//˳�������,���ټ���ӡ
//��˳���ʵ��BinaryFind(���ֲ���) 
//��˳���ʵ��InsertSort(��������)
//��˳���ʵ��BubbleSort(ð������)

//��ʼ��
void SeqListInit(PSeq ps1, size_t newcapicity)
{
    assert(ps1);
	assert(newcapicity != 0);
	ps1->arr = (SLDataType*)malloc(sizeof(int)*newcapicity);
	assert(ps1->arr);
	ps1->capicity = newcapicity;
	ps1->size = 0;
}

//����
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

//��������
void CheckCapaticity(PSeq ps1)
{
	assert(ps1);
	if (ps1->capicity==ps1->size)
	{
		ps1->capicity *= 2;
		realloc(ps1->arr, sizeof(SLDataType)*ps1->capicity);
	}
}

//��ӡ���
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

//β��
void SeqListPushBack(PSeq ps1, SLDataType x)
{
	assert(ps1);
	CheckCapaticity(ps1);
	ps1->arr[ps1->size] = x;
	ps1->size++;
}

//ͷ��   ����ʹ��malloc,��Ϊ�п��������ظ�
//ֻ�ܴӺ���ǰ�ƶ�
void SeqListPushFront(PSeq ps1, SLDataType x)
{
	assert(ps1);
	//�������
	CheckCapaticity(ps1);
	int i = 0;
    //�ƶ�,�Ӻ���ǰ
	for (i = (ps1->size);i>0; --i)
	{
		ps1->arr[i] = ps1->arr[i - 1];
	}
	//����
	ps1->arr[0] = x;
	//��С++
	ps1->size++;
}

//����posλ�õĲ���
void SeqListInsert(PSeq ps1, size_t pos, SLDataType x)
{
	assert(ps1);
	assert(pos >= 0 && pos <= ps1->size);//pos=0 �൱��ͷ��  pos=size �൱��β��
	//�ж�����
	CheckCapaticity(ps1);
	size_t i = 0;
	//�ƶ�
	for (i = (ps1->size); i > pos;i--)
	{
		ps1->arr[i] = ps1->arr[i-1];
	}
	//����
	ps1->arr[pos] = x;
	//����
	ps1->size++;
}

//βɾ
void SeqListPopBack(PSeq ps1)
{
	assert(ps1);
	assert(ps1->size > 0);
	ps1->size--;
}

//ͷɾ
void SeqListPopFront(PSeq ps1)
{
	assert(ps1);
	assert(ps1->size > 0);
	size_t i = 0;
	//�ƶ�Ԫ�� ��ǰ�����ƶ� O(n)
	for (i = 1; i < ps1->size;i++)
	{
		ps1->arr[i-1] = ps1->arr[i];
	}
	ps1->size--;
}

//ɾ��posλ��Ԫ�� 
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

//��ֵΪx�Ľڵ�,�������±�
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

//ɾ����һ��ֵΪx�Ľڵ�
void SeqListRemove(PSeq ps1, SLDataType x)
{
	assert(ps1);
	int ret=SeqListFind(ps1, x);
	if (ret != -1)
	{
		SeqListErase(ps1, ret);
	}
}

//ɾ������ֵΪx�Ľڵ�
//�����м����tem�ظ�����SeqlistFind��SeqlistErase����
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

//�޸ĵ�POSλ��ֵ
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

//��˳���ʵ��BubbleSort
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

//��˳���ʵ��BinaryFind(���ֲ���) ǰ���������
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

//��˳���ʵ�ֲ������� InsertSort
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
//		//�������������һ�Ƚϣ�����tempʱ�������ƺ�
//		while ((j >= 0) && (ps1->arr[j]>tmp))
//		{
//			ps1->arr[j + 1] = ps1->arr[j];
//			j--;
//		}
//		//���ڴ���temp����
//		if (j!=i-1)
//		{
//			ps1->arr[j + 1] = tmp;
//		}
//	}
//}
//������������Ż�
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
