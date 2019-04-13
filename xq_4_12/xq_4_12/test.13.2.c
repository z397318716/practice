//杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//数组示例:  1 3 5
//          2 4 6
//          5 7 9
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//思路1: 先取对角线上的元素进行比较,这样可以排除一半的范围,剩下了两块矩形区域需要比较
//思路2: 先取右上角的元素进行比较,排除整行或整列,剩下的区域要么在左方,要么在下方,依次取余下区域的右上角,可一直缩小范围,
// 取思路2   以3 行 3 列 二维数组为例
int Search_num(int arr[3][3], int n){
	int i = 0;
	int j = 2;
	while (1)
	{


		if (i < 0 || i > 2 || j < 0 || j > 2){
			printf("没找到\n");
			break;
		} else if (n == arr[i][j])
		{

			printf("找到了\n");
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
		printf("输入想要查找的数:(输入负数退出)");
		scanf("%d", &n);
		Search_num(arr, n);
	
	system("pause");
	return 0;
}