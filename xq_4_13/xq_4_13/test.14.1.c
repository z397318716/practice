////1.ʵ��һ�����������������ַ����е�k���ַ��� 
////ABCD����һ���ַ��õ�BCDA
////ABCD���������ַ��õ�CDAB
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
//	printf("���������ַ�����:\n");
//	scanf("%d", &n);
//	if (n<0 || n>len)
//	{
//		printf("�Ƿ�����!\n");
//	}
//	else
//	{
//		left_rotate(arr, n);
//	}
//	system("pause");
//	return 0;
//}
