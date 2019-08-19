#include "List.h"

void ListTest()
{
	List plist;
	List tmp;
	ListInit(&tmp);
	ListInit(&plist);			//链表初始化
	ListPushBack(&plist, 5);	//尾插
	ListPushBack(&plist, 6);
	ListPushBack(&plist, 7);
	ListPushBack(&plist, 8);
	ListPrint(&plist);

	ListPushFront(&plist, 4);	//头插
	ListPushFront(&plist, 3);
	ListPushFront(&plist, 2);
	ListPushFront(&plist, 1);
	ListPrint(&plist);

	ListPopBack(&plist);		//尾删
	ListPrint(&plist);

	ListPopFront(&plist);		//头删
	ListPrint(&plist);

	//ListRemove(&plist, 5);	//删除数据为5 的节点

	ListPushBack(&tmp, 2);
	ListPushBack(&tmp, 3);
	ListPushBack(&tmp, 4);
	ListPushBack(&tmp, 6);
	ListPushBack(&tmp, 7);
	ListPrint(&tmp);
	ListDestory(&plist);
	ListDestory(&tmp);
}
int main()
{
	ListTest();
	system("pause");
	return 0;
}