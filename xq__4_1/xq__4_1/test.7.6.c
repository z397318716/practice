////6.递归和非递归分别实现求n的阶乘
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
////递归实现阶乘
//int Recursive_factorial(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else if (n == 2)
//	{
//		return 2;
//	}
//	else
//	{
//		return (Recursive_factorial(n - 1))*n;
//	}
//}
//
////非递归实现阶乘
//int Non_Recursive_factorial(int n)
//{
//	int sum = n;
//	for (int i = 1; i < n; ++i)
//	{
//		sum= sum*i;
//	}
//	return sum;
//}
//
//int main()
//{
//	while (1)
//	{
//		int n = 0;
//		printf("输入数字:(输入0退出)\n");
//		scanf("%d", &n);
//		if (n < 0)
//		{
//			printf("非法输入\n");
//		} else if (n == 0)
//		{
//			printf("退出运算!\n");
//			break;
//		}
//		else
//		{
//			printf("%d\n", Non_Recursive_factorial(n));
//			printf("%d\n", Recursive_factorial(n));
//		}
//	}
//	system("pause");
//	return 0;
//}