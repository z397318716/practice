#include "test.h"

//1.递归和非递归分别实现求第n个斐波那契数。
int Recursive_Fibonacci(int num)
{
	if (num<3)
		return 1;
	else
		return Recursive_Fibonacci(num - 1) + Recursive_Fibonacci(num - 2);
}
void Non_Recursive_Fib(int num)
{
	/*
	int num = 0;
	int a[1024] = { 0 };
	int i = 2;
	printf("输入求的斐波那契数:");
	scanf("%d", &num);
	a[0] = 1;
	a[1] = 1;
	for (; i < num; i++)
	{
	a[i] = a[i - 1] + a[i - 2];
	}
	printf("%d\n", a[i-1]);
	*/
	int a1 = 1;
	int a2 = 1;
	int a3 = 0;
	if (num < 3)
		printf("%d\n", 1);
	else
	{
		for (int i = 3; i <= num; i++)
		{
			a3 = a1 + a2;
			a1 = a2;
			a2 = a3;
		}
		printf("%d\n", a3);
	}
}
//2.编写一个函数实现n^k，使用递归实现
int Recursive_n_k(int n,int k)
{
	if (k == 1)
		return n;
	else
		return Recursive_n_k(n,k-1)*n;
}

//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
int Recursive_DigitSum(int num)
{
	if (num < 10)
		return num;
	else
	{
		return Recursive_DigitSum(num/10)+num%10;
	}
}
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
void Reverse_String(char* string)
{
	if (*string == '\0')
		printf("%c", *string);
	else
	{
		string++;
		Reverse_String(string);
		printf("%c", *(--string));
	}
}
//5.递归和非递归分别实现strlen
int My_Strlen(char* string)
{
	int count = 0;
	while (string)
	{
		if (string[count] == '\0')
			break;
		count++;
	}
	return count;
}
int Recursive_MyStrlen(char* string)
{
	if (*string == '\0')
		return 0;
	else
	{
		return Recursive_MyStrlen(++string)+1;
	}
}
//6.递归和非递归分别实现求n的阶乘
int Rec_Factorial(int n)
{
	if (n < 0)
		return -1;
	else if (n < 2)
		return 1;	//0 的阶乘为 1
	else
		return Rec_Factorial(n-1)*n;
}
int Factorial(int n)
{
	int count = 1;
	if (n < 0)
		return -1;
	else
	{
		for (; n>0; n--)
		{
			count *= n;
		}
		return count;
	}
	
}
//7.递归方式实现打印一个整数的每一位
void Rec_Print(int num)
{
	if (num > 9)
		Rec_Print(num / 10);
	printf("%d  ",num%10);
	
}
