//#include "slist.h"
//
///*
////������ͷ�������
//for(cur = head; cur; cur = cur->_next)
//{
//cur;
//}
////˫����ͷ�������
//for(cur = head->_next; cur != _head; cur = cur->_next)
//{
//cur;
//}
//
//
//*/
//
//void SListInit(SList* plist)
//{
//	plist->_head = NULL;
//
//}
//void SListDestory(SList* plist)
//{
//	assert(plist);
//	SListNode* tmp;
//	while (plist->_head)
//	{
//		tmp = plist->_head;
//		plist->_head = plist->_head->_next;
//		free(tmp);
//	}
//
//}
//
//
//void SListPushFront(SList* plist, SLTDataType x)
//{
//	assert(plist);
//	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
//	cur->_data = x;
//	cur->_next = plist->_head;
//	plist->_head = cur;
//
//}
//
//void SListPopFront(SList* plist)
//{
//	assert(plist);
//
//	SListNode* tmp;
//	if (plist->_head)
//	{
//
//		SListNode* tmp = plist->_head;
//		plist->_head = plist->_head->_next;
//		free(tmp);
//	}
//}
//
//void SListPrint(SList* plist)
//{
//	assert(plist);
//
//	SListNode* cur;
//	for (cur = plist->_head; cur; cur = cur->_next)
//	{
//		printf("%d->", cur->_data);
//	}
//	printf("NULL\n");
//}
//
//SListNode* SListFind(SList* plist, SLTDataType x)
//{
//	assert(plist);
//	SListNode* cur;
//	for (cur = plist->_head; cur; cur = cur->_next)
//	{
//		if (cur->_data == x)
//		{
//			return cur;
//		}
//	}
//	return NULL;
//}
////δ��
///*
//void SListInsertFront(SListNode* plist, SLTDataType x,SLTDataType src)
//{
//SListNode* cur;
//if (plist->_head->_data == x)
//{
//SListPushFront(plist, x);
//return;
//}
//for(cur = plist->_head;cur->_next;cur = cur->_next)
//{
//if(cur->_next->_data == x)
//{
//break;
//}
//}
//newdata->_data = src;
//newdata->_next = cur->_next;
//cur->_next = newdata;
//}
//*/
//
//void SListInsertAfter(SListNode* pos, SLTDataType x) // ��pos��ǰ����в��� 
//{
//	assert(pos);
//
//	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
//	cur->_data = x;
//	cur->_next = pos->_next;
//	pos->_next = cur;
//
//}
//
//void SListEraseAfter(SListNode* pos)
//{
//	SListNode* tmp = pos->_next;
//
//	pos->_next = tmp->_next;
//	free(tmp);
//}
//
//void SListReverse(SList* plist)
//{
//#if 0
//	assert(plist->_head);
//	SListNode* tmp = plist->_head->_next;
//	SListNode* cur = plist->_head;
//	while (tmp)                      //for (;;)    // while(1)   [ѭ����������->��ѭ��]
//	{
//		cur->_next = tmp->_next;
//		tmp->_next = plist->_head;
//
//		plist->_head = tmp;
//		tmp = cur->_next;
//
//	}
//#else
//	SListNode* tmp = plist->_head->_next;  //��¼ next
//	SListNode* cur = plist->_head;
//	cur->_next = NULL;                     //����, ��ͷ��������� next �Ͽ�    ��tmp��¼ ���ҵ�
//
//	while (tmp)						//ÿ��ѭ����Ҫ��ɶ���,Ȼ��;�ͷ���³���
//	{
//		plist->_head = tmp;                 //����ͷ, tmp λ�û��Ϊ�µ�ͷ , 
//		tmp = tmp->_next;					//��¼�´�ѭ���� tmp ��λ��,��Ϊ tmp ������Ѿ�������,
//		plist->_head->_next = cur;			//����,���ͷ�γ�����
//		cur = plist->_head;					//��¼��ͷλ��,�����´�ѭ������
//	}
//#endif
//}
