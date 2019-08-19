#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;				//保存节点数据
	struct SListNode* _next;		//指向下一个节点
}SListNode;

typedef struct SList
{
	SListNode* _head;			
}SList;
void SListInit(SList* plist);						//链表初始化
void SListDestory(SList* plist);					//链表销毁
SListNode* BuySListNode(SLTDataType x);				//创建新节点
void SListPushFront(SList* plist, SLTDataType x);	//头插
void SListPopFront(SList* plist);					//头删
void SListPushBack(SList* plist, SLTDataType x);	//尾插
void SListPopBack(SList* plist);					//尾删
SListNode* SListFind(SList* plist, SLTDataType x);	//查找指定数据节点
int SListSize(SList* plist);						//节点个数
//在pos的前面插入
void SListInsertFront(SList* plist, SLTDataType pos, SLTDataType x);
//在pos的后面插入
void SListInsertAfter(SList* plist, SLTDataType pos, SLTDataType x);
void SListEraseAfter(SList* plist, SLTDataType pos);//删除指定位置节点
void SListRemove(SList* plist, SLTDataType x);		//删除指定数据节点
void SListPrint(SList* plist);						//打印节点数据
void TstList();										//测试函数
