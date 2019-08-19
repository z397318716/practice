#include "BTree.h"
#include "Queue.h"
#include "Stack.h"

//BTNode* BinaryTreeCreate(BTDataType* src, int n ,int* pi)		//传参实现较为复杂
BTNode* BinaryTreeCreate(BTDataType* src)
{
	static int s_n = 0;						//避免传参(复杂)
	if (src[s_n] == '#')
	{
		s_n++;
		return NULL;
	}
	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	cur->_data = src[s_n];
	s_n++;

	cur->_left = BinaryTreeCreate(src);
	cur->_right = BinaryTreeCreate(src);

	return cur;
}
//用传参方法递归实现 前序遍历 实现 堆还原
BTNode* BinaryTreeCreate1(BTDataType* src, int n, int* pi)
{
	if (src[*pi] != '#')
	{
		BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
		cur->_data = src[*pi];
		(*pi)++;
		cur->_left = BinaryTreeCreate1(src, n, pi);
		(*pi)++;
		cur->_right = BinaryTreeCreate1(src, n, pi);
		return cur;
	} else
	{
		(*pi)++;
		return NULL;
	}
}
// 销毁  后序遍历 销毁最方便(不需要记录左右孩子), 传参 **root 是想将 root 置空
void BinaryTreeDestory(BTNode* root)
{
	if (root)
	{
		//传参为 BTNode** root
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		free(root);
	}
}
//*------------------------------------------------------------------------------------------------------------------
//下午
int BinaryTreeSize(BTNode* root)
{
	int count = 0;
	Queue qu;
	BTNode* cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		cur = QueueFront(&qu);

		count++;
		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}
		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		QueuePop(&qu);
	}
	return count;
}
int BinaryTreeLeafSize(BTNode* root)
{
	int leaf_num = 0;
	Queue qu;
	BTNode* cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		cur = QueueFront(&qu);
		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}
		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		if (cur->_left ==NULL && cur->_right == NULL)
			leaf_num++;
		QueuePop(&qu);
	}
	return leaf_num;
}
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//-------------------------------------------------------------------------------------------------------*/
// 递归实现 前 中 后序遍历 (具有 后入先出 的特性就用递归来做)
// 前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		putchar(root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
// 中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePrevOrder(root->_left);
		putchar(root->_data);
		BinaryTreePrevOrder(root->_right);
	}
}
// 后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		putchar(root->_data);
	}
}

// 层序遍历 循环实现
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue qu;
	BTNode* cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		cur = QueueFront(&qu);

		putchar(cur->_data);
		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}
		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		QueuePop(&qu);
	}
}


// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);

// 非递归遍历
// 前序遍历 
void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack st;
	BTNode* cur = root;
	StackInit(&st, 100);

	while (cur)
	{
		putchar(cur->_data);

		if (cur->_right)
		{
			StackPush(&st, cur->_right);
		}
		if (cur->_left)
		{
			cur = cur->_left;
		}
		else
		{
			cur = StackTop(&st);
			StackPop(&st);
		}
	}

	StackDestory(&st);
}
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);
void TestBinaryTree();