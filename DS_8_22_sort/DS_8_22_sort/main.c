#include <stdio.h>
#include "sort.h"


void PrintArray(int* src,int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", src[i]);

	}
	putchar('\n');
}


int main()
{

#if 0
	int src[10] = { 3, 5, 4, 7, 6, 8, 9, 0, 12, 2 };
	InsertSort(src, 10);
	PrintArray(src, 10);

#else
	srand(time(NULL));
	int src[BUFSIZE];
	int i;
	for (i = 0; i < BUFSIZE; i++)
	{
		src[i] = rand() % 5000 + 1;
	}
	//InsertSort(src, BUFSIZE);
	//ShellSort(src, BUFSIZE);
	MergeSort(src, BUFSIZE);


	PrintArray(src, BUFSIZE);
#endif

	system("pause");
	return 0;
}