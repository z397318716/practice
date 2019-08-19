#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int LTDataType;
//节点
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
//链表的头
typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* plist);							//链表初始化
void ListDestory(List* plist);						//销毁链表
ListNode* BuyNewNode(LTDataType data);				//创建新节点

void ListPushBack(List* plist,LTDataType data);		//尾插
void ListPopBack(List* plist);						//尾删
void ListPushFront(List* plist,LTDataType data);	//头插
void ListPopFront(List* plist);						//头删

void ListInsertAfter(ListNode* pos, LTDataType data);//在指定位置后插入新节点
void ListInsertFront(ListNode* pos, LTDataType data);//在指定位置前前插入新节点

void ListErase(List* plist,ListNode* pos);						//删除 pos 处节点
void ListRemove(List* plist, LTDataType x);			//删除指定数据节点

int ListSize(List* plist);							//链表长度(节点数)
ListNode* ListFind(List* plist, LTDataType data);	//查找指定数据的节点
void ListPrint(List* plist);						//打印链表

void ListTest();


