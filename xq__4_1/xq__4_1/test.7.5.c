////5.递归和非递归分别实现strlen
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int Recursive_strlen(char* arr)
//{
//	if (*arr == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return Recursive_strlen(++arr) + 1;
//	}
//}
//
//int Non_Recursive_strlen(char* arr)
//{
//	int i = 0;
//	for (i = 0;; ++i)
//	{
//		if (arr[i] == '\0')
//		{
//			break;
//		}
//	}
//	return i;
//}
//int main()
//{
//	char arr[] = "12345";
//	printf("%d\n",Recursive_strlen(arr));
//	printf("%d\n",Non_Recursive_strlen(arr));
//
//	system("pause");
//	return 0;
//}