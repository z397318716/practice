////喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
////给20元，可以多少汽水。
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int Bottle_drinks(int money)
//{
//	int drinks = 0;
//	int bottle = 0;
//
//	bottle = money;
//	while (bottle > 1)
//	{
//		drinks += bottle / 2;
//		if (1 == bottle % 2)
//		{
//			bottle = bottle / 2 + 1;
//		}
//		else
//		{
//			bottle = bottle / 2;
//		}
//	}
//	return drinks + money;
//}//兑换的饮料瓶数
//
//
//int main()
//{
//	int money = 20;
//	printf("%d\n", Bottle_drinks(money));
//
//	system("pause");
//	return 0;
//
//}
