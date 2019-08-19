#include "List.h"

//链表初始化
void ListInit(List* plist)
{
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}
//销毁链表
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
//创建一个链表新节点
ListNode* BuyNewNode(LTDataType data)
{
	ListNode* ptr = (ListNode*)malloc(sizeof(ListNode));
	assert(ptr);
	ptr->_data = data;
	ptr->_next = NULL;
	ptr->_prev = NULL;
	return ptr;
}
//尾插
void ListPushBack(List* plist, LTDataType data)
{
	assert(plist);
	ListNode* cur = BuyNewNode(data);
	
	//1.找到最后一个节点,如果只有头节点,则直接在头节点后添加新节点
	ListNode* ptr = plist->_head;
	while (ptr->_next != plist->_head)
	{
		ptr = ptr->_next;
	}
	cur->_next = plist->_head;
	cur->_prev = plist->_head->_prev;
	ptr->_next = cur;
	plist->_head->_prev = cur;
	
	/*-----------2.利用循环链表特点--------------------------------------
	cur->_next = plist->_head;
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev->_next = cur;
	plist->_head->_prev = cur;
	----------------------------------------------------------------------------*/
}
//尾删
void ListPopBack(List* plist)
{
	assert(plist);
	//如果只有头,则尾删失败
	if (plist->_head->_next == plist->_head)
	{
		return;
		//ListDestory(plist);
	}
	else
	{
		ListNode* ptr = plist->_head;
		//1.找到倒数第二个节点,将其指向头,释放最后一个节点
		ListNode* cur = NULL;							
		while (ptr->_next != plist->_head)
		{
			cur = ptr;							//因为要用到倒数第二个节点,所以每走一步,保存前一个节点
			ptr = ptr->_next;
		}
		cur->_next = plist->_head;				//倒数第二个节点向后指向头
		plist->_head->_prev = cur;				//头向前指向倒数第二个节点
		/*----2.利用循环链表特点---------------------------------
		ListNode* ptr = plist->_head->_prev;
		ptr->_prev->_next = plist->_head;
		plist->_head->_prev = ptr->_prev;
		
		-------------------------------------------------------*/
		free(ptr);
	}
}
//头插
void ListPushFront(List* plist, LTDataType data)
{
	assert(plist);
	ListNode* ptr = BuyNewNode(data);
	ptr->_next = plist->_head->_next;
	ptr->_prev = plist->_head;
	plist->_head->_next = ptr;
	plist->_head->_next->_prev = ptr;
}
//头删
void ListPopFront(List* plist)
{
	assert(plist);
	//如果只有头,则头删失败,直接返回
	if (plist->_head->_next == plist->_head)
		return;
	else
	{
		ListNode* ptr = plist->_head->_next;
		plist->_head->_next = plist->_head->_next->_next;		//头向后指向 第二个节点
		plist->_head->_next->_prev = plist->_head;				//第二个节点向前指向头
		free(ptr);												//删除第一个节点

	}
}
//指定位置前插入节点
void ListInsertFront(ListNode* pos, LTDataType data)
{
	//assert(plist);
	ListNode* NewNode = BuyNewNode(data);
	NewNode->_next = pos;
	NewNode->_prev = pos->_prev;
	pos->_prev->_next = NewNode;
	pos->_prev = NewNode;
}
//在指定位置前插入节点
void ListInsertAfter(ListNode* pos, LTDataType data)
{
	assert(pos);
	ListNode* NewNode = BuyNewNode(data);
	NewNode->_next = pos;
	NewNode->_prev = pos->_prev;
	pos->_prev->_next = NewNode;
	pos->_prev = NewNode;
}
//删除指定位置节点
void ListErase(List* plist,ListNode* pos)
{
	assert(pos);
	//如果要删除头节点,删除失败,直接返回
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
//删除指定数据节点
void ListRemove(List* plist, LTDataType data)
{
	assert(plist);
	//如果只有头,删除失败,直接返回
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
//链表长度(节点数)
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
//查找指定数据的节点
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
//打印链表
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