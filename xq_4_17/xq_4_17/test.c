#include <stdio.h>
#include<stdlib.h>

const char *my_strstr(const char *str, const char *sub_str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		int tem = i; //tem���������е���ʼ�ж��±�λ�� 
		int j = 0;
		while (str[i++] == sub_str[j++])
		{
			if (sub_str[j] == '\0')
			{
				return &str[tem];
			}
		}
		i = tem;
	}

	return NULL;
}

int main12()
{
	char *s = "1233345hello";
	char *sub = "345";
	printf("%s\n", my_strstr(s, sub));

	system("pause");
	return 0;
}

