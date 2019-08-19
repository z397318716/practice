///*
//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。 
//*/
//
//#include<stdio.h>
//#include<stdlib.h>
//
////思路1:将数组元素用冒泡排个序,然后依次比较元素是否与相邻元素相等,筛选出单个元素
//
//
////思路2: 0异或 任何数 等于任何数 
////       如果数组中只有一个数出现一次,将 0 依次与数组中的元素相与,便可筛选出那个数
////       数组中有两个数出现一次,筛选出的数则是 这两个数相与的结果,将这两个数分离出来
////       分离方法: 首先 两个数异或 得到的二进数为 1 的那一位表示这两个数在这一位不同(一个数该位为 0 ,另一个为 1)
////                然后 根据这一位的不同 将原数组分成两部分 每一部分在一次和 0 异或 筛选出只出现一次的数字
//
//
//void bobble(int* arr,int len)
//{
//	int tmp = 0;
//	int i = 0;
//	
//	for (; i <= len; ++i)
//	{
//		for (int j=0; j <len-i-1; ++j)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//void Select_num(int* arr,int len)
//{
//	for (int i = 0; i <= len; ++i)
//	{
//		if (i == len&&arr[i] == arr[i - 1])
//		{
//
//			printf("%d", arr[i]);
//		}
//		else if (arr[i] != arr[i - 1] && arr[i]!= arr[i + 1])
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//}
//
//int Yihuo(int* arr, int len)
//{
//	int ret = 0;
//	int pose = 0;
//
//	int num1 = 0;
//	int num2 = 0;//记录两个只出现一次的数
//	int a[1024] = { 0 };
//	int b[1024] = { 0 };
//	int n1 = 0, n2 = 0;
//	for (int i = 0; i <= len; ++i)
//	{
//		ret ^= arr[i];
//	}//得到只出现一次的那两个数异或值
//	
//	for (int i = 0; i < 32; ++i)
//	{
//		if (1 == ((ret >> 1) & 1))
//		{
//			pose = i;
//		}//找到异或值开始为1的位次
//	}
//	for (int i = 0; i <= len; ++i)
//	{
//		if (1 == (arr[i] >> pose))
//		{
//			a[n1] = arr[i];
//			n1++;
//		}
//		else
//		{
//			b[n2] = arr[i];
//			n2++;
//		}//将数组分离(其实是将 两个单独出现的数 分别分到了两个数组中)
//
//	}
//	for (int i = 0; a[i]; ++i)
//	{
//		num1 ^= a[i];
//		num2 ^= b[i];
//		
//		
//	}
//	printf("  %d %d\n",num1,num2);
//	return 0;
//}
//
	char destation[1024] = { 0 };
//
//int main()
//{
//	int arr[] = { 1, 2, 1, 2, 3, 5, 5, 3, 4, 6 };
//	int len = 0;
//	len = sizeof(arr) / sizeof(arr[0]) - 1;
//
//	//思路1:
//	bobble(arr, len);
//	Select_num(arr, len);
//	
//	Yihuo(arr, len);
//
//
//
//	system("pause");
//	return 0;
//}