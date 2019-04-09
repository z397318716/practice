//// 日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
////嫌疑犯的一个。以下为4个嫌疑犯的供词。
////A说：不是我。
////B说：是C。
////C说：是D。
////D说：C在胡说
////已知3个人说了真话，1个人说的是假话。
////现在请根据这些信息，写一个程序来确定到底谁是凶手。
//#include<stdio.h>
//#include<stdlib.h>
//
//
////先假设一人说的是假话,然后验证是否同时成立,然后依次顺延判断(1表示凶手,0表示不是凶手)
//// 1.假设 a 说了假话则 a=1 c=1 d=1 d=0  矛盾不成立
//// 2.假设 b 说了假话则 a=0 c=0 d=1 d=0  矛盾不成立
//// 3.假设 c 说了假话则 a=0 c=1 d=0 d=0  成立 c 是凶手
//// 4.假设 d 说了假话则 a=0 c=1 d=1 d=1  矛盾两名凶手
//int Judge_murderer(){
//	int sum = 0;
//	for (int i = 0; i < 4; ++i){
//		char muderer = 'a' + i;
//		sum = (muderer != 'a') + (muderer == 'c') + (muderer == 'd') + (muderer != 'd');
//		if (sum == 3){
//			return muderer;
//		}
//	}
//	return -1;
//}
//int main(){
//	if (Judge_murderer() != -1){
//		printf("凶手是%c\n", Judge_murderer());
//	}
//	else{
//		printf("没找到凶手\n");
//	}
//	system("pause");
//	return 0;
//}
