//2.д����������������������в�����Ҫ�����֣�
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main(){
	int n = 0;
	int left = 0;
	int mid = 0;
	
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	printf("��������ҵ�Ԫ��:\n");
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
			printf("û�ҵ�\n");
			break;
		}
		else if (n == arr[mid])
		{
			printf("�ҵ���,�±���%d\n", mid);	
			break;
		}

	}
	system("pause");
	return 0;
}