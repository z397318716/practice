//  ��д������ 
//  unsigned int reverse_bit(unsigned int value);
//  ��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>



unsigned int reverse_bit(unsigned int value){
	
	int a = 0;
	while (1){
		if (value < 2){
			printf("%d ", value);
			break;
		}
		else{
			a = value % 2;
			value = value / 2;
			printf("%d ", a);	
		}
	}

	return 0;
}

int main(){

	int num = 0;
	printf("����һ����:\n");
	scanf("%d", &num);
	reverse_bit(num);


	system("pause");
	return 0;
}