#include "test.h"


//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
void PrintMulTable()
{
	int num = 0;
	printf("输入乘法口诀表行数/列数:\n");
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
//2.使用函数实现两个数的交换。
void Exchange(int* x, int* y)
{
	int* tmp ;
	tmp = x;
	x = y;
	y = tmp;
	printf("%d %d\n", *x, *y);
}
//3.实现一个函数判断year是不是润年。
void JudgeYear()
{
	int year = 0;
	printf("输入需要判断的年份:\n");
	scanf("%d", &year);
	if (year % 100 == 0 && year % 400 == 0)
		printf("%d年是世纪闰年\n", year);
	else if (year % 4 == 0 && year % 100 != 0)
		printf("%d是普通闰年\n", year);
	else
		printf("%d不是闰年\n", year);
}
/*
4.创建一个数组，实现函数init（）初始化数组、
实现empty（）清空数组、
实现reverse（）函数完成数组元素的逆置。
要求：自己设计函数的参数，返回值。
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
//5.实现一个函数，判断一个数是不是素数。
void JudgePrime()
{
	while (1)
	{
		int num = 0;
		int count = 0;
		printf("输入需要判断的数字:\n");
		scanf("%d", &num);
		if (num < 2)
		{
			printf("输入数字非法,应为大于1的自然数\n");
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
				printf("%d是素数\n", num);
			else
				printf("%d不是素数\n", num);
		}
	}
}