#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef int HPDataType;
typedef struct Heap
{
	HPDataType* data;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
// ∂—≈≈–Ú
void HeapSort(int* a, int n);
void TestHeap();