#include "List.h"

void ListTest()
{
	List plist;
	List tmp;
	ListInit(&tmp);
	ListInit(&plist);			//�����ʼ��
	ListPushBack(&plist, 5);	//β��
	ListPushBack(&plist, 6);
	ListPushBack(&plist, 7);
	ListPushBack(&plist, 8);
	ListPrint(&plist);

	ListPushFront(&plist, 4);	//ͷ��
	ListPushFront(&plist, 3);
	ListPushFront(&plist, 2);
	ListPushFront(&plist, 1);
	ListPrint(&plist);

	ListPopBack(&plist);		//βɾ
	ListPrint(&plist);

	ListPopFront(&plist);		//ͷɾ
	ListPrint(&plist);

	//ListRemove(&plist, 5);	//ɾ������Ϊ5 �Ľڵ�

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