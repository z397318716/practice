////一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
////请找出这个数字。（使用位运算
//#include<stdio.h>
//#include<stdlib.h>
//
//
//
//int main(){
//	int arr[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
//	int s = 0;
//	int i = 1;
//	s = sizeof(arr) / sizeof(arr[0]);
//	for (; i < s; ++i){
//		arr[0] = arr[0] ^ arr[i];
//
//	}
//	printf("%d\n", arr[0]);
//	system("pause");
//	return 0;
//}