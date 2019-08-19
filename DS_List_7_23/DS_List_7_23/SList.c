#include "SList.h"

//链表初始化,链表头指针赋空
void SListInit(SList* plist)
{
	plist->_head = NULL;
}
//链表销毁,依次释放每个节点
void SListDestory(SList* plist)
{
	assert(plist);			//判断链表是否存在
	SListNode* tmp = NULL;
	while (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
//创建新的节点,
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* ptr = NULL;
	ptr = (SListNode*)malloc(sizeof(SLTDataType)+sizeof(SListNode));
	assert(ptr);
	ptr->_data = x;
	ptr->_next = NULL;
	return ptr;
}
//头插
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* ptr = (SListNode*)malloc(sizeof(SListNode));
	ptr->_data = x;
	ptr->_next = plist->_head;		//原先的头节点作为下一个节点
	plist->_head = ptr;				//将头指向新插入的节点
}
//头删
void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* tmp;
	tmp = plist->_head;
	if (plist->_head == NULL)
	{
		printf("PopFront Fail(链表为空)\n");
	}
	else
	{
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
//尾插
void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* ptr = plist->_head;
	//如果链表为空,让头节点指向新节点
	if (plist->_head == NULL)
	{
		plist->_head = BuySListNode(x);		
	}
	else
	{
		//找到链表最后一个节点
		while (ptr->_next)							
		{
			ptr = ptr->_next;
		}
		ptr->_next = BuySListNode(x);
	}
}
//尾删
void SListPopBack(SList* plist)
{
	assert(plist);
	SListNode* ptr = plist->_head;
	//链表为空,直接返回,尾删失败
	if (plist->_head == NULL)
		return;
	//只有一个节点
	else if (plist->_head->_next == NULL)
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	//存在两个及以上节点
	else
	{
		while (ptr->_next->_next)		//由于需要找到倒数第二个节点,所有判断后一个节点的后一个节点是否为空,不需要每走一步保存当前节点
		{
			ptr = ptr->_next;
		}
		free(ptr->_next);
		ptr->_next= NULL;
	}
}
//查找数据为 x 的节点,返回该节点
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* ptr = plist->_head;
	while (ptr)
	{
		//如果当前节点数据等于 x ,返回当前节点
		if (ptr->_data == x)
		{
			return ptr;
			//不等于,则向后走一个节点继续判断
		}  else
			ptr = ptr->_next;
	}
	//如果所有节点的数据都不等于 x ,则返回空
	return NULL;
}
//链表节点个数
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
//在pos的前面插入
void SListInsertFront(SList* plist, SLTDataType pos, SLTDataType x)
{
	assert(plist || pos <= SListSize(plist));
	int i = 1;								//用于确定走到第几个节点
	SListNode* ptr = plist->_head;
	SListNode* cur = ptr;
	while (i < pos)
	{
		cur = ptr;							//因为要用到pos前的一个节点,所以每走一步保存前一个的节点
		ptr = ptr->_next;
		i++;
	}
	//将数据 x 放入新创建好的节点
	SListNode* NewNode = BuySListNode(x);
	NewNode->_next = ptr;					//新节点指向pos处的节点ptr
	cur->_next = NewNode;					//pos前的节点指向新插入的节点
}
//在pos的后面插入
void SListInsertAfter(SList* plist, SLTDataType pos, SLTDataType x)
{
	assert(plist || pos <= SListSize(plist));

	int i = 1;								//用于确定走到第几个节点
	SListNode* ptr = plist->_head;
	SListNode* cur = ptr;
	while (i <= pos)
	{
		cur = ptr;							//因为要用到pos,及pos后一个节点,每走一步保存前一个节点
		ptr = ptr->_next;
		i++;
	}
	//将数据 x 放入新创建好的节点
	SListNode* NewNode = BuySListNode(x);
	NewNode->_next = ptr;					//新节点指向pos处的下一个节点ptr
	cur->_next = NewNode;					//pos处的节点指向新插入的节点
}
//删除 pos 处的节点
void SListEraseAfter(SList* plist, SLTDataType pos)
{
	assert(plist || pos <= SListSize(plist));
	SListNode* tmp = plist->_head;				//保存pos处的节点
	SListNode* ptr = NULL;						//保存pos的前一个节点
	//如果只有一个节点
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
		ptr->_next = tmp->_next;				//pos的前一个节点 ptr 指向 pos 的后一个节点
		free(tmp);								//删除 pos 处的节点
	}
}
//删除数据为 x 的节点
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
//打印链表数据
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
//测试函数
void TestList()
{
	SList plist;
	SListInit(&plist);		//链表初始化
	//尾插测试
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 6);
	SListPushBack(&plist, 7);
	SListPushBack(&plist, 8);
	SListPrint(&plist);
	//头插测试
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 1);
	SListPrint(&plist);
	//尾删测试
	SListPopBack(&plist);
	SListPrint(&plist);
	//头删测试
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
