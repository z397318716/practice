#include "BTree.h"
#include "Queue.h"
#include "Stack.h"

//BTNode* BinaryTreeCreate(BTDataType* src, int n ,int* pi)		//����ʵ�ֽ�Ϊ����
BTNode* BinaryTreeCreate(BTDataType* src)
{
	static int s_n = 0;						//���⴫��(����)
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
//�ô��η����ݹ�ʵ�� ǰ����� ʵ�� �ѻ�ԭ
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
// ����  ������� �������(����Ҫ��¼���Һ���), ���� **root ���뽫 root �ÿ�
void BinaryTreeDestory(BTNode* root)
{
	if (root)
	{
		//����Ϊ BTNode** root
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		free(root);
	}
}
//*------------------------------------------------------------------------------------------------------------------
//����
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
// �ݹ�ʵ�� ǰ �� ������� (���� �����ȳ� �����Ծ��õݹ�����)
// ǰ�����
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		putchar(root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
// �������
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePrevOrder(root->_left);
		putchar(root->_data);
		BinaryTreePrevOrder(root->_right);
	}
}
// �������
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		putchar(root->_data);
	}
}

// ������� ѭ��ʵ��
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


// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);

// �ǵݹ����
// ǰ����� 
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