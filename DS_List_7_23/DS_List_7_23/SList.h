#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;				//����ڵ�����
	struct SListNode* _next;		//ָ����һ���ڵ�
}SListNode;

typedef struct SList
{
	SListNode* _head;			
}SList;
void SListInit(SList* plist);						//�����ʼ��
void SListDestory(SList* plist);					//��������
SListNode* BuySListNode(SLTDataType x);				//�����½ڵ�
void SListPushFront(SList* plist, SLTDataType x);	//ͷ��
void SListPopFront(SList* plist);					//ͷɾ
void SListPushBack(SList* plist, SLTDataType x);	//β��
void SListPopBack(SList* plist);					//βɾ
SListNode* SListFind(SList* plist, SLTDataType x);	//����ָ�����ݽڵ�
int SListSize(SList* plist);						//�ڵ����
//��pos��ǰ�����
void SListInsertFront(SList* plist, SLTDataType pos, SLTDataType x);
//��pos�ĺ������
void SListInsertAfter(SList* plist, SLTDataType pos, SLTDataType x);
void SListEraseAfter(SList* plist, SLTDataType pos);//ɾ��ָ��λ�ýڵ�
void SListRemove(SList* plist, SLTDataType x);		//ɾ��ָ�����ݽڵ�
void SListPrint(SList* plist);						//��ӡ�ڵ�����
void TstList();										//���Ժ���
