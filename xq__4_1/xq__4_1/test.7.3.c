////3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和， 
////例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int DigitSum(int n)
//{
//	if (n < 10)
//	{
//		return n;
//	}
//	else if (n>9 && n < 100)
//	{
//		return n % 10 + n / 10;
//	}
//	else
//	{
//		return DigitSum(n / 10) + DigitSum(n % 10);
//	}
//	
//}
//int main()
//{
//	while (1)
//	{
//		int n = 0;
//		printf("请输入一个非负整数:(输入0退出!)\n");
//		scanf("%d", &n);
//		if (n == 0)
//		{
//			printf("退出循环\n");
//			break;
//		}
//		else if (n < 0)
//		{
//			printf("非法输入,请重新输入\n");
//		}
//		else
//		{
//			printf("%d\n", DigitSum(n));
//		}
//	}
//	system("pause");
//	return 0;
//}