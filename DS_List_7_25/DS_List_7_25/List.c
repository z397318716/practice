#include "List.h"

//�����ʼ��
void ListInit(List* plist)
{
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}
//��������
void ListDestory(List* plist)
{
	assert(plist);
	ListNode* ptr = plist->_head->_next;
	ListNode* cur;
	while (ptr != plist->_head)
	{
		cur = ptr;
		ptr = ptr->_next;
		free(cur);
	}
	free(ptr);
	plist->_head = NULL;
}
//����һ�������½ڵ�
ListNode* BuyNewNode(LTDataType data)
{
	ListNode* ptr = (ListNode*)malloc(sizeof(ListNode));
	assert(ptr);
	ptr->_data = data;
	ptr->_next = NULL;
	ptr->_prev = NULL;
	return ptr;
}
//β��
void ListPushBack(List* plist, LTDataType data)
{
	assert(plist);
	ListNode* cur = BuyNewNode(data);
	
	//1.�ҵ����һ���ڵ�,���ֻ��ͷ�ڵ�,��ֱ����ͷ�ڵ������½ڵ�
	ListNode* ptr = plist->_head;
	while (ptr->_next != plist->_head)
	{
		ptr = ptr->_next;
	}
	cur->_next = plist->_head;
	cur->_prev = plist->_head->_prev;
	ptr->_next = cur;
	plist->_head->_prev = cur;
	
	/*-----------2.����ѭ�������ص�--------------------------------------
	cur->_next = plist->_head;
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev->_next = cur;
	plist->_head->_prev = cur;
	----------------------------------------------------------------------------*/
}
//βɾ
void ListPopBack(List* plist)
{
	assert(plist);
	//���ֻ��ͷ,��βɾʧ��
	if (plist->_head->_next == plist->_head)
	{
		return;
		//ListDestory(plist);
	}
	else
	{
		ListNode* ptr = plist->_head;
		//1.�ҵ������ڶ����ڵ�,����ָ��ͷ,�ͷ����һ���ڵ�
		ListNode* cur = NULL;							
		while (ptr->_next != plist->_head)
		{
			cur = ptr;							//��ΪҪ�õ������ڶ����ڵ�,����ÿ��һ��,����ǰһ���ڵ�
			ptr = ptr->_next;
		}
		cur->_next = plist->_head;				//�����ڶ����ڵ����ָ��ͷ
		plist->_head->_prev = cur;				//ͷ��ǰָ�����ڶ����ڵ�
		/*----2.����ѭ�������ص�---------------------------------
		ListNode* ptr = plist->_head->_prev;
		ptr->_prev->_next = plist->_head;
		plist->_head->_prev = ptr->_prev;
		
		-------------------------------------------------------*/
		free(ptr);
	}
}
//ͷ��
void ListPushFront(List* plist, LTDataType data)
{
	assert(plist);
	ListNode* ptr = BuyNewNode(data);
	ptr->_next = plist->_head->_next;
	ptr->_prev = plist->_head;
	plist->_head->_next = ptr;
	plist->_head->_next->_prev = ptr;
}
//ͷɾ
void ListPopFront(List* plist)
{
	assert(plist);
	//���ֻ��ͷ,��ͷɾʧ��,ֱ�ӷ���
	if (plist->_head->_next == plist->_head)
		return;
	else
	{
		ListNode* ptr = plist->_head->_next;
		plist->_head->_next = plist->_head->_next->_next;		//ͷ���ָ�� �ڶ����ڵ�
		plist->_head->_next->_prev = plist->_head;				//�ڶ����ڵ���ǰָ��ͷ
		free(ptr);												//ɾ����һ���ڵ�

	}
}
//ָ��λ��ǰ����ڵ�
void ListInsertFront(ListNode* pos, LTDataType data)
{
	//assert(plist);
	ListNode* NewNode = BuyNewNode(data);
	NewNode->_next = pos;
	NewNode->_prev = pos->_prev;
	pos->_prev->_next = NewNode;
	pos->_prev = NewNode;
}
//��ָ��λ��ǰ����ڵ�
void ListInsertAfter(ListNode* pos, LTDataType data)
{
	assert(pos);
	ListNode* NewNode = BuyNewNode(data);
	NewNode->_next = pos;
	NewNode->_prev = pos->_prev;
	pos->_prev->_next = NewNode;
	pos->_prev = NewNode;
}
//ɾ��ָ��λ�ýڵ�
void ListErase(List* plist,ListNode* pos)
{
	assert(pos);
	//���Ҫɾ��ͷ�ڵ�,ɾ��ʧ��,ֱ�ӷ���
	if (pos == plist->_head)
		return;
	else
	{
		pos->_prev->_next = pos->_next;
		pos->_next->_prev = pos->_prev;
		free(pos);
		pos = NULL;
	}
}
//ɾ��ָ�����ݽڵ�
void ListRemove(List* plist, LTDataType data)
{
	assert(plist);
	//���ֻ��ͷ,ɾ��ʧ��,ֱ�ӷ���
	if (plist->_head->_next == plist->_head)
		return;
	else
	{
		ListNode* ptr = plist->_head->_next;
		while (ptr != plist->_head)
		{
			if (ptr->_data == data)
				ListErase(plist, ptr);
			ptr = ptr->_next;
		}
	}
}
//������(�ڵ���)
int ListSize(List* plist)
{
	assert(plist);
	int i = 0;
	ListNode* ptr = plist->_head->_next;
	while (ptr != plist->_head)
	{
		ptr = ptr->_next;
		i++;
	}
	return i;
}
//����ָ�����ݵĽڵ�
ListNode* ListFind(List* plist, LTDataType data)
{
	assert(plist);
	ListNode* ptr = plist->_head->_next;
	while (ptr != plist->_head)
	{
		if (ptr->_data == data)
			return ptr;
		ptr = ptr->_next;
	}
	return NULL;
}
//��ӡ����
void ListPrint(List* plist)
{
	assert(plist);
	ListNode* ptr = plist->_head->_next;
	printf("->head->");
	while (ptr != plist->_head)
	{
		printf("%d->", ptr->_data);
		ptr = ptr->_next;
	}
	printf("\n");
}