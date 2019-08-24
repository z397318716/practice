#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFSIZE 1000


void InsertSort(int* src, int n);
void ShellSort(int* src, int n);

void MergeSort(int* src, int n);
void DealMergeSort(int* src, int* tmp, int start, int end);

void QuickSort(int* src, int n);
void DealQuickSort(int* src, int start, int end);
int DoublePointWay1(int* src, int start, int end);
int DoublePointWay2(int* src, int start, int end);
int HoleQuickSort(int* src, int start, int end);

void SelectSort(int* src, int n);
void QuickSortNonR(int* src, int n);