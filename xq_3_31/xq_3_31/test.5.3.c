////3.编写代码模拟三次密码输入的场景。 
////最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
////可以重新输入，最多输入三次。三次均错，则提示退出程序。
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//char Login(char* n, char* pwd)
//{
//	if (strcmp(n, pwd) != 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//int main()
//{
//	for (int i = 0; i < 3; ++i)
//	{
//		char* pwd = "12345";
//		char n[10] = { 0 };
//		printf("请输入密码:\n");
//		scanf("%s", n);
//		if (Login(n, pwd) == 0)
//		{
//			printf("密码错误,请重新输入,还剩%d次机会\n", (2 - i));
//		} else
//		{
//			printf("登录成功\n");
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}