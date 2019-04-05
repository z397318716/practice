////1.递归和非递归分别实现求第n个斐波那契数。
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
////递归方式实现
//int Fibonacci_sequence(int n)
//{
//	if (n==0)
//	{
//		return 0;
//	}
//	else if (n == 1)
//	{
//		return 1;
//	}
//	return Fibonacci_sequence(n - 2) + Fibonacci_sequence(n - 1);
//}
//
////非递归实现
//int _Fibonacci_sequence(int n)
//{
//	if (n==0)
//	{
//		return 0;
//	}
//	else if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		int f0 = 0;
//		int f1 = 1;
//		int f2 = 1;
//		for (int i = 1; i < n; ++i)
//		{
//			f2 = f0 + f1;
//			f0 = f1;
//			f1 = f2;
//		}
//		return f2;
//	}
//}
//int main()
//{
//	while (1)
//	{
//		int n = 0;
//		printf("输入一个数字(输入-1 退出):\n");
//		scanf("%d", &n);
//		if (n == -1)
//		{
//			printf("退出\n");
//			break;
//		}
//		printf("%d(递归实现)\n",Fibonacci_sequence(n));
//		printf("%d(非递归实现)\n", _Fibonacci_sequence(n));
//	}
//	system("pause");
//	return 0;
//}
//
