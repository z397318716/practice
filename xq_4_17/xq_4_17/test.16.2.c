////实现strchr 
////返回指向C字符串str中字符第一次出现的指针。
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//const char* My_strchr(const char* arr, int character){
//	const char* ptr = arr;
//	while (ptr++ != '\0'){
//		if (*ptr == character){
//			return ptr;	
//			break;
//		}
//	}
//	return NULL;
//}
//
//int main(){
//	char c = ' ';
//	printf("输入需要查找的字符:\n");
//	scanf("%c", &c);
//	char arr[] = "It's a fine day taday!";
//	const char* a=My_strchr(arr, c);
//	printf("%d\n", a - arr + 1);
//
//	system("pause");
//	return 0;
//}