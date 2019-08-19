#include "test.h"

//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
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
	printf("�������쳲�������:");
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
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
int Recursive_n_k(int n,int k)
{
	if (k == 1)
		return n;
	else
		return Recursive_n_k(n,k-1)*n;
}

//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
int Recursive_DigitSum(int num)
{
	if (num < 10)
		return num;
	else
	{
		return Recursive_DigitSum(num/10)+num%10;
	}
}
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
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
//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
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
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
int Rec_Factorial(int n)
{
	if (n < 0)
		return -1;
	else if (n < 2)
		return 1;	//0 �Ľ׳�Ϊ 1
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
//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void Rec_Print(int num)
{
	if (num > 9)
		Rec_Print(num / 10);
	printf("%d  ",num%10);
	
}
