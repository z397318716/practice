//// ����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ�� 
//// ��20Ԫ�����Զ�����ˮ��
//// ���ʵ��
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//#define P 1;//һƿ��ˮһԪ
//#define E 2;//����ƿ����һƿ��ˮ
//
//// ��ƿ�һ������ϸ���
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
////�ݹ�ʵ��
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
//	int n = 0;            //ֱ���򵽵�������
//	int num = 0;          //�������ϸ���
//	int num1 = 0;
//	printf("���뻨�ѽ��:\n");
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