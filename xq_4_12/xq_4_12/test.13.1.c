////����һ���������飬ʵ��һ�������� 
////�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
////����ż��λ������ĺ�벿�֡�
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