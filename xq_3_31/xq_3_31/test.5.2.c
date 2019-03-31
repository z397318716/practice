//2.写代码可以在整型有序数组中查找想要的数字，
//找到了返回下标，找不到返回 - 1.（折半查找）
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main(){
	int n = 0;
	int left = 0;
	int mid = 0;
	
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	printf("请输入查找的元素:\n");
	scanf("%d", &n);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (n > arr[mid])
		{
			left = mid + 1;
		} 
		else if (n < arr[mid])
		{
			right = mid - 1;
		}
		else if (n != arr[mid])
		{
			printf("没找到\n");
			break;
		}
		else if (n == arr[mid])
		{
			printf("找到了,下边是%d\n", mid);	
			break;
		}

	}
	system("pause");
	return 0;
}