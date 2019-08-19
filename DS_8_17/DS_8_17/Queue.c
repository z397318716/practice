#include "Queue.h"




QNode* BuyQueueNode(QDataType data)
{
	QNode* pNewNode = (QNode*)malloc(sizeof(QNode));	//sizeof(QNode)  QNode���ܼ� *,����* ��ʾ������ǽڵ�ĵ�ַ�����ǽڵ�
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
void QueueInit(Queue* q)
{
	assert(q);
	q->_back = q->_front = NULL;
}
// 8-18  �п�
int QueueIsEmpty(Queue* q)
{
	return q->_front == NULL;
}
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* pNewNode = BuyQueueNode(data);
	if (QueueIsEmpty(q))
	{
		q->_front = q->_back = pNewNode;
		return;
	}
	q->_back->_pNext = pNewNode;
	q->_back = pNewNode;
}
QDataType QueueTop(Queue* q)
{
	assert(q);
	if (QueueIsEmpty(q))
		return (QDataType)0;
	else
		return q->_front->_data;
}
void QueuePop(Queue* q)
{
	QNode* pDelNode = NULL;
	//�ж��Ƿ�Ϊ�ն���
	if (QueueIsEmpty(q))
		return;
	//�������ͷ
	pDelNode = q->_front;
	if (NULL == pDelNode->_pNext)			// �������ֻ��һ�����,����ͷβ����ָ��NULL
	{
		q->_front = q->_back = NULL;
	} else
	{
		q->_front = q->_front->_pNext;
	}
	free(pDelNode);
}
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_back->_data;
}
int QueueSize(Queue* q)
{
	int count = 0;
	QNode* pCur = q->_front;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
void QueueDestroy(Queue* q)
{
	QNode* pCur;
	while (q->_front)
	{
		pCur = q->_front;
		q->_front = q->_front->_pNext;
		free(pCur);
	}
	q->_front = q->_back = NULL;
}


/*
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("size = %d\n", QueueSize(&q));

	QueueDestroy(&q);
}
*/