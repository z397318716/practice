//// 一个数组中只有两个数字是出现一次， 
//// 其他所有数字都出现了两次。
//// 找出这两个数字，编程实现。
//
//#include<stdio.h>
//#include<stdlib.h>
//
//// 两重循环,每次遍历整个数组,寻找是否有元素与该元素相等,筛选出单独的元素
//int Search_num(int* arr,int len){
//	for (int i = 0; i <= len; ++i){
//		if (arr[i] < 0){
//			continue;
//		} else{
//			for (int j = 0; j <= len; ++j){
//				if (arr[i] == arr[j]&&i==j){
//					continue;
//				} else if (arr[i] == arr[j]){
//					arr[i] = -1;
//					arr[j] = -1;
//				}
//			}
//		}
//	}
//	for (int i = 0; i <= len; ++i){
//		if (arr[i]>0){
//			printf("%d\n", arr[i]);
//		}
//	}
//	return 0;
//}
//int main(){
//	int arr[] = { 1, 1, 2, 4, 2, 3, 5, 3, 5, 6, 7, 8, 7 };
//	int len = sizeof(arr) / sizeof(arr[0]) - 1;
//	Search_num(arr,len);
//	system("pause");
//	return 0;
//}