////1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
////�ݹ鷽ʽʵ��
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
////�ǵݹ�ʵ��
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
//		printf("����һ������(����-1 �˳�):\n");
//		scanf("%d", &n);
//		if (n == -1)
//		{
//			printf("�˳�\n");
//			break;
//		}
//		printf("%d(�ݹ�ʵ��)\n",Fibonacci_sequence(n));
//		printf("%d(�ǵݹ�ʵ��)\n", _Fibonacci_sequence(n));
//	}
//	system("pause");
//	return 0;
//}
//
