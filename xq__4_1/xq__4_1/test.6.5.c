////5.实现一个函数，判断一个数是不是素数。
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int Judge_number(int n)
//{
//	for (int i = 2; i < n; ++i)
//	{
//		if (n%i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	while (1)
//	{
//		int n = 0;
//		printf("请输入需要判断的素数:(输入0退出判断)\n");
//		scanf("%d", &n);
//		if (n == 0)
//		{
//			printf("退出判断\n");
//			break;
//		}
//		else if (Judge_number(n) == 0)
//		{
//			printf("%d 不是素数\n", n);
//		}
//		else
//		{
//			printf("%d 是素数\n", n);
//		}
//	}
//	system("pause");
//	return 0;
//}