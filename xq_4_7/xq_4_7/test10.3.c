/* ����Ļ�ϴ�ӡ������ǡ�
   by ��ǰ
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//��һ�����Ľ׳�
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
//������ǵ� i ��,�� j �е�ֵΪ C(j-1,i-1) 
int Num(int i, int j){
	int n = 0;
	n = Factorial(i - 1) / Factorial(i - j)/Factorial(j-1);
	return n;
}

int main(){
	int h = 0;
	printf("������Ҫ��ӡ������\n");
	scanf("%d", &h);
	if (h<1){
		printf("�Ƿ�����!����������\n");
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