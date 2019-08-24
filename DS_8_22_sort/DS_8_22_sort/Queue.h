#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
//#include "BTree.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

typedef BTNode* QDataType;

typedef struct QNode	//����ڵ�
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front;	//ָ���ͷԪ��
	QNode* _back;	//ָ���βԪ��
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueIsEmpty(Queue* q);
void QueueDestroy(Queue* q);
void TestQueue();