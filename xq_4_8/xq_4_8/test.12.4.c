////有一个字符数组的内容为:"student a am i", 
////请你将数组的内容改为"i am a student".
////要求：
////不能使用库函数。
////只能开辟有限个空间（空间个数和字符串的长度无关）。
//
////   student a am i
////   i ma a tneduts
////   i am a student
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int Mystrlen(char* arr){
//	int i = 0;
//	for (; arr[i]; ++i){
//	}
//	return i;
//}
//
//char* Reverse_str(char* arr, int start, int end){
//	int tmp = 0;
//	int i = 0;
//	int j = 0;
//	for (i = start, j = end - 1; i < j; i++, j--){
//		tmp = arr[i];
//		arr[i] = arr[j];
//		arr[j] = tmp;
//	}
//	return arr;
//}
//
//char* Reverse_word(char* arr){
//	int i = 0;
//	int len = 0;
//	int start = 0;
//	len = Mystrlen(arr);
//	for (; arr[i]; i++){
//		if (arr[i] == ' '){
//			Reverse_str(arr, start, i);
//			start = i + 1;
//		}
//	}
//	Reverse_str(arr, start, i);
//	
//	
//	return arr;
//}
//
//
//int main(){
//
//	char arr[] = "student a am i";
//	puts(Reverse_str(arr, 0, Mystrlen(arr)));
//	puts(Reverse_word(arr));
//
//
//	system("pause");
//	return 0;
//}