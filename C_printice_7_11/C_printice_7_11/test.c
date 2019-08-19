#include "test.h"


//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
void PrintMulTable()
{
	int num = 0;
	printf("����˷��ھ�������/����:\n");
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d * %d = %d  ", j, i, i*j);
		}
		printf("\n");
	}
}
//2.ʹ�ú���ʵ���������Ľ�����
void Exchange(int* x, int* y)
{
	int* tmp ;
	tmp = x;
	x = y;
	y = tmp;
	printf("%d %d\n", *x, *y);
}
//3.ʵ��һ�������ж�year�ǲ������ꡣ
void JudgeYear()
{
	int year = 0;
	printf("������Ҫ�жϵ����:\n");
	scanf("%d", &year);
	if (year % 100 == 0 && year % 400 == 0)
		printf("%d������������\n", year);
	else if (year % 4 == 0 && year % 100 != 0)
		printf("%d����ͨ����\n", year);
	else
		printf("%d��������\n", year);
}
/*
4.����һ�����飬ʵ�ֺ���init������ʼ�����顢
ʵ��empty����������顢
ʵ��reverse���������������Ԫ�ص����á�
Ҫ���Լ���ƺ����Ĳ���������ֵ��
*/
void Init_(int arr[],int len)
{
	for (int i = 0; i <= len; i++)
	{
		arr[i] = -1;
	}
}
void Empty(int arr[],int len)
{
	for (int i = 0; i <= len; i++)
	{
		arr[i] = 0;
	}
}
void Reverse(int arr[],int len)
{
	int arr_copy[1024] = { 0 };
	for (int i = 0; i <= len; i++)
	{
		arr_copy[i] = arr[i];
	}
	for (int i = 0; i <= len; i++)
	{
		arr[i] = arr_copy[len - i];
	}
}
void PrintArr(int arr[], int len)
{
	for (int i = 0; i <= len; i++)
	{
		printf("%d ", arr[i]);
	}
}
//5.ʵ��һ���������ж�һ�����ǲ���������
void JudgePrime()
{
	while (1)
	{
		int num = 0;
		int count = 0;
		printf("������Ҫ�жϵ�����:\n");
		scanf("%d", &num);
		if (num < 2)
		{
			printf("�������ַǷ�,ӦΪ����1����Ȼ��\n");
			continue;
		}
		else
		{
			for (int i = 2; i < num; i++)
			{
				if (num % i == 0)
					count++;
			}
			if (count == 0)
				printf("%d������\n", num);
			else
				printf("%d��������\n", num);
		}
	}
}