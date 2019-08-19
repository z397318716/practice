#include <stdio.h>


void Test1()
{
	int a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 }, *q[4], k;
	for (k = 0; k < 4; k++)
	{
		q[k] = &a[k * 3];
	}
	printf("%d\n", q[3][1]);
}

void Test2()
{
	int i, j, a = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j % 2)
				break;
			a++;
		}
		a++;
	}
	printf("%d\n", a);
}
void Test3()
{
	int a[4][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19,20};
	int b = a[1][3];
	int c = a[1] + 3;
	printf("%d\n", a[1][1]);
	printf("%x\n", &a[1]);
	printf("%x\n", &a[1] + 1);
	printf("%x\n", &a + 1);
	printf("%x\n", &a + 2);
	printf("%d  %d\n", b, c);
}
void Test()
{
	//Test1();
	//Test2();
	//Test3();
	printf("%d\n", 5 / 2);
}
int main()
{
	Test();

	system("pause");
	return 0;
}