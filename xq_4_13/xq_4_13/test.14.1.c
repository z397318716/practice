////1.实现一个函数，可以左旋字符串中的k个字符。 
////ABCD左旋一个字符得到BCDA
////ABCD左旋两个字符得到CDAB
//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//char* left_rotate(char* arr, int n)
//{
//	char tmp[1024] = " ";
//	for (int i = 0;arr[n+i]!='\0'; ++i)
//	{
//		tmp[i] = arr[n+i];
//	}
//	strncat(tmp, arr, n);
//	puts(tmp);
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	char arr[] = "abcdefg";
//	int len = strlen(arr);
//	printf("输入左旋字符个数:\n");
//	scanf("%d", &n);
//	if (n<0 || n>len)
//	{
//		printf("非法输入!\n");
//	}
//	else
//	{
//		left_rotate(arr, n);
//	}
//	system("pause");
//	return 0;
//}
