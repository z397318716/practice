////3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ� 
////���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int DigitSum(int n)
//{
//	if (n < 10)
//	{
//		return n;
//	}
//	else if (n>9 && n < 100)
//	{
//		return n % 10 + n / 10;
//	}
//	else
//	{
//		return DigitSum(n / 10) + DigitSum(n % 10);
//	}
//	
//}
//int main()
//{
//	while (1)
//	{
//		int n = 0;
//		printf("������һ���Ǹ�����:(����0�˳�!)\n");
//		scanf("%d", &n);
//		if (n == 0)
//		{
//			printf("�˳�ѭ��\n");
//			break;
//		}
//		else if (n < 0)
//		{
//			printf("�Ƿ�����,����������\n");
//		}
//		else
//		{
//			printf("%d\n", DigitSum(n));
//		}
//	}
//	system("pause");
//	return 0;
//}