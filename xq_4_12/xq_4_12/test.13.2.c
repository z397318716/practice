//���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//����ʾ��:  1 3 5
//          2 4 6
//          5 7 9
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//˼·1: ��ȡ�Խ����ϵ�Ԫ�ؽ��бȽ�,���������ų�һ��ķ�Χ,ʣ�����������������Ҫ�Ƚ�
//˼·2: ��ȡ���Ͻǵ�Ԫ�ؽ��бȽ�,�ų����л�����,ʣ�µ�����Ҫô����,Ҫô���·�,����ȡ������������Ͻ�,��һֱ��С��Χ,
// ȡ˼·2   ��3 �� 3 �� ��ά����Ϊ��
int Search_num(int arr[3][3], int n){
	int i = 0;
	int j = 2;
	while (1)
	{


		if (i < 0 || i > 2 || j < 0 || j > 2){
			printf("û�ҵ�\n");
			break;
		} else if (n == arr[i][j])
		{

			printf("�ҵ���\n");
			break;
		} else if (n < arr[i][j])
		{
			j--;
		} else if (n > arr[i][j])
		{
			i++;
		} 

	}

	return 0;
}



int main(){

	int arr[3][3] = { { 1, 3, 4 }, { 2, 4, 5 }, { 4, 7, 9 } };
	
		int n = 0;
		printf("������Ҫ���ҵ���:(���븺���˳�)");
		scanf("%d", &n);
		Search_num(arr, n);
	
	system("pause");
	return 0;
}