//// 喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
//// 给20元，可以多少汽水。
//// 编程实现
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//#define P 1;//一瓶汽水一元
//#define E 2;//两空瓶等于一瓶汽水
//
//// 空瓶兑换的饮料个数
//int Empty_num(int num_bottle){
//	int n = 0;
//	//n = num_bottle;
//	while (1){
//		if (num_bottle < 2){
//			
//			break;
//		} else{
//			num_bottle = num_bottle / E;
//			n = n + num_bottle;
//		}
//	}
//	return n;
//}
//
////递归实现
//int D_Empty_num(int n){
//	int num = 0;
//	num = n / E;
//	if (n < 2){
//		return num;
//	}
//	else{
//		num = num + D_Empty_num(n / 2);
//		return num;
//	}
//}
//
//int main(){
//	int moeny = 0;
//	int n = 0;            //直接买到的饮料数
//	int num = 0;          //最终饮料个数
//	int num1 = 0;
//	printf("输入花费金额:\n");
//	scanf("%d", &moeny);
//	n = moeny / P;
//	num=n+Empty_num(n);
//	num1 = n + D_Empty_num(n);
//	printf("%d\n", num);
//	printf("%d\n", num1);
//	
//
//	system("pause");
//	return 0;
//}