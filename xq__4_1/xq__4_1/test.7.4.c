//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣� 
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������

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
	printf("�����ַ���\n");
	scanf("%s", &a);
	printf("%s\n", Reverse_string(a));

	system("pause");
	return 0;
}