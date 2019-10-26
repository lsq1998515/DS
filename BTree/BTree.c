#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
#include "Queue.h"
#include "stack.h"
#include<stdlib.h>

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		++(*pi);
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else
		return NULL;
}

//销毁   传二级指针 传外部指针的地址 要保证每次修改的是指针的值
void BinaryTreeDestory(BTNode** root)
{
	BTNode* curNode = *root;
	//左子树销毁 右子树销毁  最后销毁根
	if (curNode)
	{
		BinaryTreeDestory(&curNode->_left);
		BinaryTreeDestory(&curNode->_right);
		free(curNode);
		*root = NULL;
	}
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//叶子节点
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_right) + BinaryTreeLeafSize(root->_left);
}

//第K层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

//找到以x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	//空树  没找到
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
	{
		return ret;
	}
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
	{
		return ret;
	}
	return NULL;
}

// 遍历 递归写法

void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
	else
	{
		printf("#");
	}
}
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreeInOrder(root->_right);
	}
	else
		printf("#");
}
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c", root->_data);
	}
	else
		printf("#");
}

////非递归遍历
////层序遍历
//void BinaryTreeLevelOrder(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	//根入队
//	if(root)
//		QueuePush(&q, root);
//	//每次出队头元素 ,带出孩子节点,入队
//	while (QueueEmpty(&q) == 1)
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		//遍历
//		printf("%c ", front->_data);
//		//孩子入队
//		if (front->_left)
//		{
//			QueuePush(&q, front->_left);
//		}
//		if (front->_right)
//		{
//			QueuePush(&q, front->_right);
//		}
//	}
//	printf("\n");	
//}
//
//// 判断二叉树是否是完全二叉树
//int BinaryTreeComplete(BTNode* root)
//{
//	//通过层序遍历判断
//	Queue q;
//	QueueInit(&q);
//	if (root)
//	{
//		QueuePush(&q, root);
//	}
//	while (QueueEmpty(&q)==1)
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		//判断是否为空
//		if (front)
//		{
//			QueuePush(&q, front->_left);
//			QueuePush(&q, front->_right);
//		}
//		else
//			//判断后面是否都为空
//			break;
//	}
//	while (QueueEmpty(&q)==1)
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		//判断是否为空 非空说明不连续-->不是完全二叉树
//		if (front)
//		{
//			QueueDestory(&q);
//			return 0;//0-->不是完全二叉树
//		}
//		QueuePop(&q);
//	}
//	return 1;//1-->是完全二叉树
//}
//非递归实现三种遍历
//前序遍历
void BinaryTreePrevOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* top;
	Stack st;
	StackInit(&st);
	while (cur||StackEmpty(&st)==0)
	{
		while (cur)
		{
			printf("%c", cur->_data);
			StackPush(&st,cur);
			cur = cur->_left;
		}
		//最后一颗子树的右子树
		top = StackTop(&st);
		StackPop(&st);
		cur = top->_right;	 
	}
	printf("\n");
}

//中序遍历
void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* top;
	Stack st;
	StackInit(&st);
	while (cur || StackEmpty(&st) == 0)
	{
		//访问左子树,根入栈
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		//访问根
		top = StackTop(&st);
		printf("%c", top->_data);
		StackPop(&st);
		//访问右子树
		cur = top->_right;
	}
	printf("\n");
}

//后序遍历
void BinaryTreePostOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* top,*prev=NULL;
	Stack st;
	StackInit(&st);
	while (cur || StackEmpty(&st) == 0)
	{
		while (cur)
		{
			
			StackPush(&st, cur);
			cur = cur->_left;
		}
		top = StackTop(&st);
		//判断是否存在右子树
		//不存在: 访问根 出栈
		//存在:  先访问右子树 如果右子树已经访问完,可以访问根
		if (top->_right==NULL || top->_right== prev)
		{
			printf("%c", top->_data);
			StackPop(&st);
			prev = top;
		}
		//存在右子树,且没有访问,先访问右子树
		else
			cur = top->_right;
	}
	printf("\n");
}



void TestBinaryTree()
{
	int i = 0;
	//ABD##E#H##CF##G##
	char a[] = { 'A', 'B', 'D', '#', '#', 'E', '#', 'H', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };
	BTNode* root = BinaryTreeCreate(a, &i);
	printf("前序遍历递归版:\n");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("前序遍历非递归版:\n");
	BinaryTreePrevOrderNonR(root);
	printf("中序遍历递归版:\n");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("中序遍历非递归版:\n");
	BinaryTreeInOrderNonR(root);
	printf("后序遍历递归版:\n");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("后序遍历非递归版:\n");
	BinaryTreePostOrderNonR(root);

	BinaryTreeDestory(&root);
}

//void TestBinaryTree1()//测试层序遍历
//{
//	int i = 0;
//	//ABD##E#H##CF##G##
//	char a[] = { 'A', 'B', 'D', 'G', '#', '#', 'H', '#', '#', '#', 'C', 'E', '#', 'I', '#', '#', 'F', '#', '#' };
//	BTNode* root = BinaryTreeCreate(a, &i);
//	BinaryTreePrevOrder(root);//ABDG##H###CE#I##F##
//	putchar('\n');
//	BinaryTreeLevelOrder(root);//ABCDEFGHI
//	putchar('\n');
//	BinaryTreeDestory(&root);
//}

//void TestBinaryTree2()//测试是否为完全二叉树
//{
//	int i = 0;
//	int ret1;
//	int ret2;
//	char a1[] = { 'A', 'B', 'D', 'G', '#', '#', 'H', '#', '#', '#', 'C', 'E', '#', 'I', '#', '#', 'F', '#', '#' };
//	char a2[] = { 'A', 'B', 'D', 'G', '#', '#', 'H', '#', '#', 'Z', '#', '#', 'C', 'E', '#', '#', 'F', '#', '#' };
//	BTNode* root1 = BinaryTreeCreate(a1, &i);
//	i = 0;
//	BTNode* root2 = BinaryTreeCreate(a2, &i);
//	BinaryTreeLevelOrder(root1);
//	BinaryTreeLevelOrder(root2);
//	putchar('\n');
//	ret1 = BinaryTreeComplete(root1);//非完全二叉树
//	printf("%d\n", ret1);
//	ret2 = BinaryTreeComplete(root2);//完全二叉树
//	printf("%d\n", ret2);
//	BinaryTreeDestory(&root2);
//}

int main()
{
	TestBinaryTree();
	//TestBinaryTree1();
	//TestBinaryTree2();
	system("pause");
	return 0;
}
