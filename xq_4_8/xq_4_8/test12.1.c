//  编写函数： 
//  unsigned int reverse_bit(unsigned int value);
//  这个函数的返回值value的二进制位模式从左到右翻转后的值。

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

unsigned int reserve_bit(unsigned int value){
	unsigned int a = 0;
	unsigned int b = 0;
	
	// 1 1001
	// 1 0011
	for (unsigned int i=0; i < 32; ++i){
		
		a = value & 1;
		value = value >> 1;
		b = b << 1;
		b = b | a;

	}
	
	return b;
}
unsigned int Print_reverse_bit(unsigned int value){
	
	int a = 0;
	while (1){
		if (value < 2){
			printf("%d ", value);
			break;
		}
		else{
			a = value % 2;
			value = value / 2;
			printf("%d", a);	
		}
	}
	printf("\n");
	return 0;
}

int main(){

	unsigned int num = 0;
	printf("输入一个数:\n");
	scanf("%u", &num);


	reserve_bit(num);
	printf("%u\n",reserve_bit(num));
	Print_reverse_bit(reserve_bit(num));

	system("pause");
	return 0;
}