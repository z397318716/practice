////6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
////�ݹ�ʵ�ֽ׳�
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
////�ǵݹ�ʵ�ֽ׳�
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
//		printf("��������:(����0�˳�)\n");
//		scanf("%d", &n);
//		if (n < 0)
//		{
//			printf("�Ƿ�����\n");
//		} else if (n == 0)
//		{
//			printf("�˳�����!\n");
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