#include "struct.h"


int main()
{
	SeqList arr;
	//print1(s); //传结构体
	//print2(&s); //传地址
	//printf("%d\n", sizeof(a));
	SeqListInit(&arr,10);

	SeqListPushBack(&arr, 3);
	SeqListPushBack(&arr, 4);
	SeqListPushBack(&arr, 5);
	SeqListPushBack(&arr, 5);
	SeqListPushBack(&arr, 5);
	SeqListPushBack(&arr, 6);
	SeqListPushBack(&arr, 7);
	SeqListPushBack(&arr, 8);
	SeqListPrint(&arr);

	SeqListPushFront(&arr, 2);
	SeqListPushFront(&arr, 1);
	SeqListPrint(&arr);

	SeqListPopBack(&arr);
	SeqListPopFront(&arr);
	SeqListPrint(&arr);

	SeqListInsert(&arr, 3, 10);
	SeqListPrint(&arr);

	SeqListErase(&arr, 3);
	SeqListPrint(&arr);

	SeqListBubbleSort(&arr);
	SeqListPrint(&arr);

	SeqListModify(&arr, 3, 19);
	SeqListPrint(&arr);

	SeqListRemove(&arr, 5);
	SeqListPrint(&arr);


	system("pause");
	return 0;
}