#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int LTDataType;
//�ڵ�
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
//�����ͷ
typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* plist);							//�����ʼ��
void ListDestory(List* plist);						//��������
ListNode* BuyNewNode(LTDataType data);				//�����½ڵ�

void ListPushBack(List* plist,LTDataType data);		//β��
void ListPopBack(List* plist);						//βɾ
void ListPushFront(List* plist,LTDataType data);	//ͷ��
void ListPopFront(List* plist);						//ͷɾ

void ListInsertAfter(ListNode* pos, LTDataType data);//��ָ��λ�ú�����½ڵ�
void ListInsertFront(ListNode* pos, LTDataType data);//��ָ��λ��ǰǰ�����½ڵ�

void ListErase(List* plist,ListNode* pos);						//ɾ�� pos ���ڵ�
void ListRemove(List* plist, LTDataType x);			//ɾ��ָ�����ݽڵ�

int ListSize(List* plist);							//������(�ڵ���)
ListNode* ListFind(List* plist, LTDataType data);	//����ָ�����ݵĽڵ�
void ListPrint(List* plist);						//��ӡ����

void ListTest();


