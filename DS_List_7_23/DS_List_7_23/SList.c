#include "SList.h"

//�����ʼ��,����ͷָ�븳��
void SListInit(SList* plist)
{
	plist->_head = NULL;
}
//��������,�����ͷ�ÿ���ڵ�
void SListDestory(SList* plist)
{
	assert(plist);			//�ж������Ƿ����
	SListNode* tmp = NULL;
	while (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
//�����µĽڵ�,
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* ptr = NULL;
	ptr = (SListNode*)malloc(sizeof(SLTDataType)+sizeof(SListNode));
	assert(ptr);
	ptr->_data = x;
	ptr->_next = NULL;
	return ptr;
}
//ͷ��
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* ptr = (SListNode*)malloc(sizeof(SListNode));
	ptr->_data = x;
	ptr->_next = plist->_head;		//ԭ�ȵ�ͷ�ڵ���Ϊ��һ���ڵ�
	plist->_head = ptr;				//��ͷָ���²���Ľڵ�
}
//ͷɾ
void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* tmp;
	tmp = plist->_head;
	if (plist->_head == NULL)
	{
		printf("PopFront Fail(����Ϊ��)\n");
	}
	else
	{
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
//β��
void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* ptr = plist->_head;
	//�������Ϊ��,��ͷ�ڵ�ָ���½ڵ�
	if (plist->_head == NULL)
	{
		plist->_head = BuySListNode(x);		
	}
	else
	{
		//�ҵ��������һ���ڵ�
		while (ptr->_next)							
		{
			ptr = ptr->_next;
		}
		ptr->_next = BuySListNode(x);
	}
}
//βɾ
void SListPopBack(SList* plist)
{
	assert(plist);
	SListNode* ptr = plist->_head;
	//����Ϊ��,ֱ�ӷ���,βɾʧ��
	if (plist->_head == NULL)
		return;
	//ֻ��һ���ڵ�
	else if (plist->_head->_next == NULL)
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	//�������������Ͻڵ�
	else
	{
		while (ptr->_next->_next)		//������Ҫ�ҵ������ڶ����ڵ�,�����жϺ�һ���ڵ�ĺ�һ���ڵ��Ƿ�Ϊ��,����Ҫÿ��һ�����浱ǰ�ڵ�
		{
			ptr = ptr->_next;
		}
		free(ptr->_next);
		ptr->_next= NULL;
	}
}
//��������Ϊ x �Ľڵ�,���ظýڵ�
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* ptr = plist->_head;
	while (ptr)
	{
		//�����ǰ�ڵ����ݵ��� x ,���ص�ǰ�ڵ�
		if (ptr->_data == x)
		{
			return ptr;
			//������,�������һ���ڵ�����ж�
		}  else
			ptr = ptr->_next;
	}
	//������нڵ�����ݶ������� x ,�򷵻ؿ�
	return NULL;
}
//����ڵ����
int SListSize(SList* plist)
{
	assert(plist);
	int size = 0;
	SListNode* tmp = plist->_head;
	while (tmp)
	{
		tmp = tmp->_next;
		size++;
	}
	return size;
}
//��pos��ǰ�����
void SListInsertFront(SList* plist, SLTDataType pos, SLTDataType x)
{
	assert(plist || pos <= SListSize(plist));
	int i = 1;								//����ȷ���ߵ��ڼ����ڵ�
	SListNode* ptr = plist->_head;
	SListNode* cur = ptr;
	while (i < pos)
	{
		cur = ptr;							//��ΪҪ�õ�posǰ��һ���ڵ�,����ÿ��һ������ǰһ���Ľڵ�
		ptr = ptr->_next;
		i++;
	}
	//������ x �����´����õĽڵ�
	SListNode* NewNode = BuySListNode(x);
	NewNode->_next = ptr;					//�½ڵ�ָ��pos���Ľڵ�ptr
	cur->_next = NewNode;					//posǰ�Ľڵ�ָ���²���Ľڵ�
}
//��pos�ĺ������
void SListInsertAfter(SList* plist, SLTDataType pos, SLTDataType x)
{
	assert(plist || pos <= SListSize(plist));

	int i = 1;								//����ȷ���ߵ��ڼ����ڵ�
	SListNode* ptr = plist->_head;
	SListNode* cur = ptr;
	while (i <= pos)
	{
		cur = ptr;							//��ΪҪ�õ�pos,��pos��һ���ڵ�,ÿ��һ������ǰһ���ڵ�
		ptr = ptr->_next;
		i++;
	}
	//������ x �����´����õĽڵ�
	SListNode* NewNode = BuySListNode(x);
	NewNode->_next = ptr;					//�½ڵ�ָ��pos������һ���ڵ�ptr
	cur->_next = NewNode;					//pos���Ľڵ�ָ���²���Ľڵ�
}
//ɾ�� pos ���Ľڵ�
void SListEraseAfter(SList* plist, SLTDataType pos)
{
	assert(plist || pos <= SListSize(plist));
	SListNode* tmp = plist->_head;				//����pos���Ľڵ�
	SListNode* ptr = NULL;						//����pos��ǰһ���ڵ�
	//���ֻ��һ���ڵ�
	if (plist->_head->_next == NULL)
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	else
	{
		for (int i = 1; i < pos; i++)
		{
			ptr = tmp;
			tmp = tmp->_next;
		}
		ptr->_next = tmp->_next;				//pos��ǰһ���ڵ� ptr ָ�� pos �ĺ�һ���ڵ�
		free(tmp);								//ɾ�� pos ���Ľڵ�
	}
}
//ɾ������Ϊ x �Ľڵ�
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* ptr = plist->_head;
	for (int i = 0; i <= SListSize(plist);++i,ptr = ptr->_next)
	{
		if (ptr->_data == x)
		{
			SListEraseAfter(plist, i);
		}
	}
}
//��ӡ��������
void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* ptr = plist->_head;
	while (ptr)
	{
		printf("%d ", ptr->_data);
		ptr = ptr->_next;
	}
	printf("\n");
}
//���Ժ���
void TestList()
{
	SList plist;
	SListInit(&plist);		//�����ʼ��
	//β�����
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 6);
	SListPushBack(&plist, 7);
	SListPushBack(&plist, 8);
	SListPrint(&plist);
	//ͷ�����
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 1);
	SListPrint(&plist);
	//βɾ����
	SListPopBack(&plist);
	SListPrint(&plist);
	//ͷɾ����
	SListPopFront(&plist);
	SListPrint(&plist);
	
	SListInsertAfter(&plist, 3, 10);
	SListPrint(&plist);
	SListInsertFront(&plist, 4, 11);
	SListPrint(&plist);

	SListEraseAfter(&plist, 4);
	SListPrint(&plist);

	SListRemove(&plist, 10);
	SListPrint(&plist);

	SListDestory(&plist);
}
