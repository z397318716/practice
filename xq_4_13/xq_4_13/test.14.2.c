//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.

//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 将一个字符串所有左旋与右旋结果与另一字符串进行比较,若所有结果都不相同,则不是旋转所得,反之则是旋转所得
int Judge_string(const char* str,const char* arr)
{ 
	//左旋判断
	int len = 0;
	len = strlen(arr);
	
	for (int j = 0; j < len; j++)
	{
		char tmp_left[1024] = " ";
		for (int i = 0; i + j < len; i++)
		{
			tmp_left[i] = arr[i + j];
		}
		strncat(tmp_left, arr, j);
		if (strcmp(tmp_left, str) == 0)
		{
			
			return 1;
			break;
		}
	}

	//右旋判断
	for (int j = 0; j < len; ++j)
	{
		char tmp_right[1024] = " ";
		for (int i = 0; i + j < len; ++i)
		{
			tmp_right[i] = arr[len - j];

		}
		strncat(tmp_right, arr, len-j);
		if (strcmp(tmp_right, str) == 0)
		{
			
			return 1;
			break;
		}
	}

	return 0;
}

int main()
{
	int a = 0;
	char arr[] = "abcdefg";
	char str[1024] = " ";
	printf("输入需要判断的字符串:\n");
	scanf("%s", &str);

	if (Judge_string(str, arr) == 1)
	{
		printf("%s 由 %s 旋转得到\n", str, arr);
	}
	else
	{

		printf("%s 不是又由 %s 旋转得到\n",str,arr);
	}

	


	system("pause");
	return 0;
}