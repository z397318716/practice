////实现strcmp
////字符串 str1 与 str2 比较
////小于 返回 负值
////等于 返回 0
////大于 返回 正数
//#include<stdio.h>
//#include<stdlib.h>
//
//int My_strcmp(const char* str1, const char* str2){
//	while (*str1 != '\0'&&*str2 != '\0'){
//		if (*str1 < *str2){
//			return -1;
//			break;
//		} else if(*str1 > *str2){
//			return 1;
//			break;
//		} else{
//			*str1++;
//			*str2++;
//		}
//	}
//	//当较短的字符串结束时,还需在比较一次 ,将较短字符串结束字符 \0 与另一字符比较
//	if (*str1 < *str2){
//		return -1;
//	} else if (*str1 > *str2){
//		return 1;
//	} 
//	return 0;
//}
//
//int main(){
//	char str1[] = "abcdefgsd";
//	char str2[] = "abcdefg";
//
//	int a=My_strcmp(str1, str2);
//	if (a > 0){
//		printf("str1 大于 str2\n");
//	} else if (a == 0){
//		printf("str1 与 str2 相等");
//	} else{
//		printf("str1 小于 str2 \n");
//	}
//
//	system("pause");
//	return 0;
//}