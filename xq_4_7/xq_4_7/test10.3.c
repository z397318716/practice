/* 在屏幕上打印杨辉三角。
   by 向前
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//求一个数的阶乘
int Factorial(int num){
	if (num == 0){
		return 1;
	} else{
		int tmp = num;
		for (int i = 1; i < num; ++i){
			tmp = tmp*i;
		}
		return tmp;
	}
}
//杨辉三角第 i 行,第 j 列的值为 C(j-1,i-1) 
int Num(int i, int j){
	int n = 0;
	n = Factorial(i - 1) / Factorial(i - j)/Factorial(j-1);
	return n;
}

int main(){
	int h = 0;
	printf("输入需要打印的行数\n");
	scanf("%d", &h);
	if (h<1){
		printf("非法输入!请重新输入\n");
	} else{

		int s = h - 1;
		for (int i = 1; i <= h; ++i){
			for (s = h - i; s > 0; --s){
				printf("  ");
			}
			for (int j = 1; j <= i; ++j){
				printf(" %d  ", Num(i, j));
			}
			printf("\n\n");
			
		}
	}
	system("pause");
	return 0;
}