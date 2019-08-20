#include "BTree.h"
#include "Heap.h"
#include "Queue.h"
#include "Stack.h"

//用传参方法递归实现 前序遍历 实现 堆还原

void TestBinaryTree()
{
	BTNode* root = BinaryTreeCreateExe("ABD#GI##J###CE#HK###F##");
	BTNode* root1 = BinaryTreeCreateExe("ABDH##I##E##CF##G##");
	BTNode* root2 = BinaryTreeCreateExe("ABD##E#H##CF##G##");

	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	putchar('\n');
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	putchar('\n');
	printf("该树有%d个结点\n", BinaryTreeSize(root));
	printf("叶子结点有%d个\n", BinaryTreeLeafSize(root));

	
	BinaryTreeInOrderNonR(root);		//中序遍历 非递归
	putchar('\n');
	BinaryTreePostOrderNonR(root);		//后序遍历 非递归
	putchar('\n');

	printf("%d\n",BinaryTreeComplete(root));
	//putchar('\n');
	printf("%d\n",BinaryTreeComplete(root1));
	//putchar('\n');

	printf("%d\n", BinaryTreeLevelKSize(root2, 3));
	//BinaryTreeDestory(root);
}
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("front = %d\n", QueueFront(&q));
	//printf("back = %d\n", QueueBack(&q));
	//printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	//printf("back = %d\n", QueueBack(&q));
	//printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	//printf("back = %d\n", QueueBack(&q));
	//printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	//printf("back = %d\n", QueueBack(&q));
	//printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	//printf("size = %d\n", QueueSize(&q));

	QueueDestroy(&q);
}

void TestStack()
{
	Stack st;
	StackInit(&st, 100);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	//printf("%d\n", StackTop(&st));
	StackPop(&st);
	printf("%d\n", StackTop(&st));

	StackDestory(&st);
}
int main()
{
	//BinaryTreeTest();

	//TestQueue();
	//TestStack();

	TestBinaryTree();


	/*int arr[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	Heap* hp = arr;
	HeapInit(hp, arr, 10);
	printf("%d\n", Heap_num(hp, 2));*/

	//用传参方法递归实现 前序遍历 实现 堆还原
	//Test();
	

	system("pause");
	return 0;
}