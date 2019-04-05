////2.编写一个函数实现n^k，使用递归实现 
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int N_k(int n,int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	else if (k == 1)
//	{
//		return n;
//	}
//	else
//	{
//		return n*N_k(n, k-1);
//	}
//}
//
//int main()
//{
//	while (1)
//	{
//		int n = 0;
//		int k = 0;
//		printf("请输入底数n和指数k(中间用空格隔开)\n");
//		scanf("%d %d", &n, &k);
//		printf("%d\n", N_k(n, k));
//	}
//	system("pause");
//	return 0;
//}