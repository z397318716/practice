//4. 编写一个函数 reverse_string(char * string)（递归实现） 
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int Reverse_string(char* a)
{
	int len = strlen(a);
	if (len <= 1)
	{
		return a;
	}
	else
	{
		char tmp = a[0];
		a[0] = a[len - 1];
		a[len - 1] = '\0';
		Reverse_string(a + 1);
		a[len - 1] = tmp;
		return a;
	}
	return 0;
}

int main()
{
	char a[9] = "as ";
	printf("输入字符串\n");
	scanf("%s", &a);
	printf("%s\n", Reverse_string(a));

	system("pause");
	return 0;
}