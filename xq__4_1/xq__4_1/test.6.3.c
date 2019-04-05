////3.实现一个函数判断year是不是润年。
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//void Judge_year(int n)
//{
//	if (n % 100 != 0 && n % 4 == 0)
//	{
//		printf("%d 年是普通闰年\n", n);
//	}
//	else if (n % 100 == 0 && n % 400 == 0)
//	{
//		printf("%d 年是世纪闰年\n", n);
//	}
//	else
//	{
//		printf("%d 不是闰年\n",n);
//	}
//}
//
//int main()
//{
//	while (1)
//	{
//		int n = 0;
//		printf("请输入需要判断的年份:(输入0退出)\n");
//		scanf("%d", &n);
//		if (n == 0)
//		{
//			printf("退出判断\n");
//			break;
//		}
//		Judge_year(n);
//	}
//	system("pause");
//	return 0;
//}