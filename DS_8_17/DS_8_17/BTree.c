#include "BTree.h"
#include "Queue.h"
#include "Stack.h"

static int s_n;
//BTNode* BinaryTreeCreate(BTDataType* src, int n ,int* pi)		//����ʵ�ֽ�Ϊ����
BTNode* BinaryTreeCreate(BTDataType* src)
{
	//һ�δ��������,�ò��� δ�� 0 �����
	//static int s_n = 0;						//���⴫��(����)
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

//�ô��η��� �ݹ� ʵ�� ǰ����� ʵ�� �ѻ�ԭ
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


// 1. ���������,�����Ƿ������Һ��Ӷ������(û�к��Ӿ�������� NULL) ��֤��������һ����ȫ������,���ͳ�Ƶ� k �� �ǿս�����
// 2. �ݹ� , 
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//���������ʵ��ͳ��ÿ���������ͳ��
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
		BinaryTreeInOrder(root->_left);
		putchar(root->_data);
		BinaryTreeInOrder(root->_right);
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
// �ڲ������������
// 1. ������ĳ��������Һ��� û������,ֱ�ӷ���
// 2. ĳ����� ������ û���Һ���,֮�����н�㶼����ҪΪҶ��,���򷵻�
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

// �ǵݹ����
// ǰ����� 
void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack st;
	BTNode* cur = root;									// �Ӹ���ʼ
	StackInit(&st);

	// �� ���� ��ջ��Ϊ�� ����ѭ��( curΪ�� ջ�϶�Ϊ��,)
	while (cur)
	{
		putchar(cur->_data);							// ���ʵ�ǰ���

		//���������,�ͷ�������,������Һ��ӽڵ�,�ͷ����Һ���,����ȡջ��
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
// ������� �ǵݹ�
// 1. ��ջ->�����ӽ��->��ջ->û�����ӽ��->��ӡջ������->û���Һ��ӽ��->ȡջ��
void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	Stack st;
	StackInit(&st);

	while (cur || !(StackEmpty(&st)))
	{
		for (; cur; cur = cur->_left)		// ����ǰ�ڵ㼰 ���� ��ջ
		{
			StackPush(&st, cur);
		}
		cur = StackTop(&st);				// ȡջ��(1.����Һ���Ϊ��,����forѭ��,ֱ��ȥջ�� -> �������������
											// 2.����Һ��Ӳ�Ϊ��,��ô�ý��û�����ӽ��	  -> ������Ϊ��
											// ���������������,��ǰ��㶼���ӡ
		if (cur)			// ���ж� ���п��� ( �� �ýڵ��Һ���Ϊ����ջΪ��ʱ,��һ�β������ while ѭ��)
		{
			/*if (cur)
			{
			break;
			}*/
			putchar(cur->_data);
			StackPop(&st);
			cur = cur->_right;				// �������Һ��ӽ��Ϊ��,���ջΪ��,��������
		}
	}
}
// ������� �ǵݹ�
void BinaryTreePostOrderNonR(BTNode* root)
{
	char tag[1024];
	BTNode* cur = root;
	Stack st;
	StackInit(&st);
	
	do{
		for (; cur; cur = cur->_left)					// ��������,����ǰ��㼰�����ӽ����ջ
		{
			StackPush(&st, cur);
			tag[st._top - 1] = 0;						// �������������ʱ�� tag
		}
		// ѭ����ӡ��ջ
		while (!StackEmpty(&st) && tag[st._top - 1])	//���ж����� ֻ�����һ��ѭ������ʱ��Ч
		{
			// ���� ���������
			// 1. �� cur Ϊ��ʱ, ����� for ����,����������
			// 2. �� cur ��Ϊ��,����� for ��,�������������
			// ��� �жϵ� ��ǰ�� tag ����λ(��� 1),��ô��
			cur = StackTop(&st);
			putchar(cur->_data);
			StackPop(&st);
		}

		if (!StackEmpty(&st))							// ������ֻ�����һ��ѭ������ʱ��Ч
		{

			cur = StackTop(&st);
			// 1. ��� ����� while ����,˵�� �������������
			// 2. ��� ����� while û��,˵�� û��������
			tag[st._top - 1] = 1;
			cur = cur->_right;
			// ������������Ϻ�,����������
		}
	}while (!StackEmpty(&st));			// ���ں������
}
void TestBinaryTree();