//// 模拟实现 strstr
//// 返回主串中子字符串的位置后的所有字符
//// 如果主串中没有子字符串 则返回 NULL
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//
//
//const char* Mystrstr(const char* arr2,const char* arr1){
//	
//	for (int i = 0; arr2[i] != '\0'; ++i){
//		int tmp = i;
//		int j = 0;
//		while (arr2[i++] == arr1[j++]){
//			if (arr1[j] == '\0'){
//				return &arr2[tmp];
//			}
//		}
//		i = tmp;
//	}
//
//
//
//	return NULL;
//}
//
//
//int main(){
//	char arr1[] = "asdf";
//	char arr2[] = "bvjhsdbhf asdf sdf";
//	
//
//	printf("%s\n", Mystrstr(arr2,arr1));
//
//	system("pause");
//	return 0;
//}