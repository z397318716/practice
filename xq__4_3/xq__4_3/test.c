//  n ��ʾ���ָ���   k ��ʾ�� n ��ȡ�������ָ���
// ��   4  3   (12 16 17 18)�Ӹ��ĸ���������ȡ�������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>



int main1()
{
	int n = 0;
	scanf("%d", &n);
	int arr[] = { '0','1','2' };
	switch(n){
	case 1:
		printf("%c\n", arr[0]);
		break;
	default:
		printf("%d", 99);
	}
	
	system("pause");
	return 0;
}