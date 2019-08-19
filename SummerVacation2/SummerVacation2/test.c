#include <stdio.h>

void Test()
{
	/*
	char str[6] = { '\0' };
	char str1[7] = "string";
	char str2[10];
	str2 = "string";
	char str3[6] = "g";
	*/
	/*
	 char* p = "hello!";
	 int a = 10;
	 a += a *= a -= a / 3;
	printf("%d\n", a);
	*/
	int i = 0;
	while (i < 10)
	{
		if (i < 1)
			continue;
		if (i == 5)
			break;
		i++;
	}
}

int main()
{

	Test();
	system("pause");
	return 0;
}