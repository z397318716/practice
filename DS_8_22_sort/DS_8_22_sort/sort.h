#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFSIZE 10000


void InsertSort(int* src, int n);
void ShellSort(int* src, int n);

void MergeSort(int* src, int n);
void DealMergeSort(int* src, int* tmp, int start, int end);