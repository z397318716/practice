#include "test.h"


void Test()
{
	
	/*
	int num = 0;
	scanf("%d", &num);
	//Non_Recursive_Fib();
	printf("%d\n",Recursive_Fibonacci(num));
	*/

	//Non_Recursive_Fib();
	
	/*
	int n = 0;
	int k = 0;
	printf("输入底数和指数:(中间使用,分隔)\n");
	scanf("%d,%d", &n, &k);
	printf("%d\n",Recursive_n_k(n, k));
	*/
	/*
	int num = 0;
	scanf("%d,%d", &num);
	printf("%d\n",Recursive_DigitSum(num));
	*/

	/*char string[] = "aehfiuh123123";
	printf("%d\n",My_Strlen(string));*/

	/*char string[] = "aehfiuh123123";
	Reverse_String(string);

	printf("%d",Recursive_MyStrlen(string));*/

	/*printf("%d\n", Rec_Factorial(4));
	printf("%d\n", Factorial(4));*/


}


int main()
{
	int num = 0;
	num = 5;
	printf("%d的阶乘为%d\n",num, Rec_Factorial(num));
	printf("%d的阶乘为%d\n",num, Factorial(num)); 
	Rec_Print(156);

	system("pause");
	return 0;
}