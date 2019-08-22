#include "BTree.h"
#include "Queue.h"
#include "Stack.h"

static int s_n;
//BTNode* BinaryTreeCreate(BTDataType* src, int n ,int* pi)		//传参实现较为复杂
BTNode* BinaryTreeCreate(BTDataType* src)
{
	//一次创建多颗树,该参数 未置 0 会出错
	//static int s_n = 0;						//避免传参(复杂)
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
BTNode* BinaryTreeCreateExe(BTDataType* src)
{
	s_n = 0;
	return BinaryTreeCreate(src);
}

//用传参方法 递归 实现 前序遍历 实现 堆还原
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


// 1. 层序遍历法,无论是否有左右孩子都入队列(没有孩子就向队列入 NULL) 保证二叉树是一颗完全二叉树,最后统计第 k 层 非空结点个数
// 2. 递归 , 
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//层序遍历法实现统计每层结点个数的统计
	int count = 0;
	int start = pow(2, k);
	int end = pow(2, k + 1);
	int n = 1;
	Queue qu;
	BTNode* cur = root;
	QueueInit(&qu);
	QueuePush(&qu, cur);
	while (n < end)
	{



		cur = QueueFront(&qu);

		if (cur->_left == NULL)
		{
			QueuePush(&qu, NULL);
		} else
		{
			QueuePush(&qu, cur->_left);
		}
		if (cur->_right == NULL)
		{
			QueuePush(&qu, NULL);
		} else
		{
			QueuePush(&qu, cur->_right);
		}

		if (n >= start && cur != NULL)
			count++;

		QueuePop(&qu);
		n++;


	}
	return count;
}
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
		BinaryTreeInOrder(root->_left);
		putchar(root->_data);
		BinaryTreeInOrder(root->_right);
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
// 在层序遍历基础上
// 1. 遍历到某个结点有右孩子 没有左孩子,直接返回
// 2. 某个结点 有左孩子 没有右孩子,之后所有结点都必须要为叶子,否则返回
int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode* cur;
	int tag = 0;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		cur = QueueFront(&qu);

		putchar(cur->_data);
		if (cur->_right && !cur->_left)
			return 0;
		if (tag && (cur->_left || cur->_right))
		{
			return 0;
		}
		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}
		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		else
		{
			tag = 1;
		}
		QueuePop(&qu);
	}
	return 1;
}

// 非递归遍历
// 前序遍历 
void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack st;
	BTNode* cur = root;									// 从根开始
	StackInit(&st);

	// 当 左孩子 和栈都为空 跳出循环( cur为空 栈肯定为空,)
	while (cur)
	{
		putchar(cur->_data);							// 访问当前结点

		//如果有左孩子,就访问左孩子,如果有右孩子节点,就访问右孩子,否则取栈顶
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
// 中序遍历 非递归
// 1. 入栈->进左孩子结点->入栈->没有左孩子结点->打印栈顶数据->没有右孩子结点->取栈顶
void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	Stack st;
	StackInit(&st);

	while (cur || !(StackEmpty(&st)))
	{
		for (; cur; cur = cur->_left)		// 将当前节点及 左孩子 入栈
		{
			StackPush(&st, cur);
		}
		cur = StackTop(&st);				// 取栈顶(1.如果右孩子为空,不进for循环,直接去栈顶 -> 左子树访问完毕
											// 2.如果右孩子不为空,那么该结点没有左孩子结点	  -> 左子树为空
											// 无论上述哪种情况,当前结点都会打印
		if (cur)			// 该判断 可有可无 ( 当 该节点右孩子为空且栈为空时,下一次不会进入 while 循环)
		{
			/*if (cur)
			{
			break;
			}*/
			putchar(cur->_data);
			StackPop(&st);
			cur = cur->_right;				// 当结点的右孩子结点为空,如果栈为空,遍历结束
		}
	}
}
// 后序遍历 非递归
void BinaryTreePostOrderNonR(BTNode* root)
{
	char tag[1024];
	BTNode* cur = root;
	Stack st;
	StackInit(&st);
	
	do{
		for (; cur; cur = cur->_left)					// 类似中序,将当前结点及其左孩子结点入栈
		{
			StackPush(&st, cur);
			tag[st._top - 1] = 0;						// 重置左子树访问标记 tag
		}
		// 循环打印出栈
		while (!StackEmpty(&st) && tag[st._top - 1])	//该判断条件 只在最后一次循环跳出时生效
		{
			// 后面 分两种情况
			// 1. 当 cur 为空时, 上面的 for 不进,此条件成立
			// 2. 当 cur 不为空,上面的 for 进,则此条件不成立
			// 如果 判断到 当前的 tag 被置位(情况 1),那么在
			cur = StackTop(&st);
			putchar(cur->_data);
			StackPop(&st);
		}

		if (!StackEmpty(&st))							// 此条件只在最后一次循环跳出时生效
		{

			cur = StackTop(&st);
			// 1. 如果 上面的 while 进了,说明 左子树访问完毕
			// 2. 如果 上面的 while 没进,说明 没有左子树
			tag[st._top - 1] = 1;
			cur = cur->_right;
			// 左子树访问完毕后,访问右子树
		}
	}while (!StackEmpty(&st));			// 由于后序遍历
}
void TestBinaryTree();