////输入一个整数数组，实现一个函数， 
////来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
////所有偶数位于数组的后半部分。
//#include<stdio.h>
//#include<stdlib.h>
//
//
//
//
//void Sequence(int* arr, int len){
//	int i = 0;
//	int j = 0;
//	int tmp[1024] = { 0 };
//	for (int a = 0,j=len-1,i=0; a < len; a++){
//		
//		if (arr[a] % 2 == 0){
//			tmp[j] = arr[a];
//			j--;
//		} else{
//			tmp[i] = arr[a];
//			i++;
//		}
//		
//	}
//
//	for (int b = 0; b < len; ++b){
//		printf("%d ", tmp[b]);
//	}
//}
//
//
//int main(){
//	int len = 0;
//	int arr[] = { 1, 2, 5, 7, 9, 12, 14, 19, 18, 16 };
//	len = sizeof(arr) / sizeof(arr[0]);
//	Sequence(arr,len);
//	
//
//	system("pause");
//	return 0;
//}