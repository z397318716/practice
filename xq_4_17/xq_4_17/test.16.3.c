////ʵ��strcmp
////�ַ��� str1 �� str2 �Ƚ�
////С�� ���� ��ֵ
////���� ���� 0
////���� ���� ����
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
//	//���϶̵��ַ�������ʱ,�����ڱȽ�һ�� ,���϶��ַ��������ַ� \0 ����һ�ַ��Ƚ�
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
//		printf("str1 ���� str2\n");
//	} else if (a == 0){
//		printf("str1 �� str2 ���");
//	} else{
//		printf("str1 С�� str2 \n");
//	}
//
//	system("pause");
//	return 0;
//}