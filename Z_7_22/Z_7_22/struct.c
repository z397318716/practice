#include "struct.h"


//typedef struct S
//{
//	int data[1000];
//	int num;
//}A;
//A s = { { 1, 2, 3, 4 }, 1000 };
////结构体传参
//void print1(A s)
//{
//	printf("%d\n", s.num);
//}
////结构体地址传参
//void print2(A* ps)
//{
//	printf("%d\n", ps->num);
//}

/*-------------------------------------
typedef struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
}a;
---------------------------------------*/

void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);
	psl->capacity = capacity;
	psl->array = (SLDataType*)malloc(capacity*(sizeof(SLDataType)));
	psl->size = 0;
}
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
		psl->size = 0;
		psl->array = NULL;
		psl->capacity = 0;
	}
}
void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType*)realloc(psl->array, psl->capacity*sizeof(SLDataType));
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)
{
	assert(psl ||psl->size);
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	for (int i = psl->size - 1; i >= 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	for (int i = 1; i < psl->size; i++)
	{
		psl->array[i-1] = psl->array[i];
	}
	psl->size--;
}
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
			return i;
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos < psl->size);
	CheckCapacity(psl);
	for (int i = psl->size - 1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);
	for (int i = pos+1; i < psl->size; i++)
	{
		psl->array[i-1] = psl->array[i];
	}
	psl->size--;
}
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);
	int pos = SeqListFind(psl, x);
	if (pos >= 0)
	{
		SeqListErase(psl, pos);
	}
	psl->size--;
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos < psl->size);
	psl->array[pos] = x;
}
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}
// 扩展面试题实现
void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);
	int tmp = 0;
	for (int i = 0; i < psl->size; i++)
	{
		for (int j = 0; j < psl->size - i - 1; j++)
		{
			if (psl->array[j] < psl->array[j + 1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}

// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	int left = 0;
	int right = psl->size-1;
	int mid = (left + right) / 2;
	SeqListBubbleSort(psl);
	while (left <= right)
	{
		if (psl->array[mid] > x)
		{
			left = mid+1;
			mid = (left + right) / 2;
		} 
		else if (psl->array[mid] < x)
		{
			right = mid - 1;
			mid = (left + right) / 2;
		}  else
			break;
	}
	return mid;
}
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			SeqListRemove(psl, x);
			psl->size--;
		}

	}
}