#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
//����˳���
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;   //ָ��̬���ٵ�����
	size_t size;     //��Ч���ݸ���
	size_t capicity; //����

}SeqList,*PSeq; 

//��ʼ��
void SeqListInit(PSeq ps1, size_t capicity);

//����
void SeqListDestory(PSeq ps1);

//����
void CheckCapaticity(PSeq ps1);

//��ӡ���
void SeqListPrint(PSeq ps1);

//β��
void SeqListPushBack(PSeq ps1,SLDataType x);

//ͷ��
void SeqListPushFront(PSeq ps1,SLDataType x);

//����posλ�õĲ���
void SeqListInsert(PSeq ps1, size_t pos, SLDataType x);

//βɾ
void SeqListPopBack(PSeq ps1);

//ͷɾ
void SeqListPopFront(PSeq ps1);

//ɾ��posλ��Ԫ��
void SeqListErase(PSeq ps1, size_t pos);

//��ֵΪx�Ľڵ�,�������±�
int SeqListFind(PSeq ps1, SLDataType x);

//ɾ����һ��ֵΪx�Ľڵ�
void SeqListRemove(PSeq ps1, SLDataType x);

//ɾ������ֵΪx�Ľڵ�
void SeqListRemoveAll(PSeq ps1, SLDataType x);

//�޸ĵ�POSλ��ֵ
void SeqListModify(PSeq ps1, size_t pos, SLDataType x);

//��˳���ʵ��BubbleSort
void SeqListBubbleSort(PSeq ps1);

//��˳���ʵ��BinaryFind(���ֲ���) 
int SeqListBinaryFind(PSeq psl, SLDataType x);

//��˳���ʵ�ֲ������� InsertSort
void InsertSort(PSeq ps1);