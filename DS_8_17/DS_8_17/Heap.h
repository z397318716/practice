#ifndef _HEAP_H_
#define _HEAP_H_
//��һ�������е� n �����;
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _data;
	int _size;
	int _capacity;
}Heap;







#endif /*_HEAP_H_*/