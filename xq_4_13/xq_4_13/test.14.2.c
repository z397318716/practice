//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.

//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ��һ���ַ������������������������һ�ַ������бȽ�,�����н��������ͬ,������ת����,��֮������ת����
int Judge_string(const char* str,const char* arr)
{ 
	//�����ж�
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

	//�����ж�
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
	printf("������Ҫ�жϵ��ַ���:\n");
	scanf("%s", &str);

	if (Judge_string(str, arr) == 1)
	{
		printf("%s �� %s ��ת�õ�\n", str, arr);
	}
	else
	{

		printf("%s �������� %s ��ת�õ�\n",str,arr);
	}

	


	system("pause");
	return 0;
}