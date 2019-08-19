//实现memcpy
//将num字节的值从按源指向的位置直接复制到按目标指向的内存块。
//源指针和目标指针所指向的对象的底层类型与此函数无关；结果是数据的二进制副本。
//函数不检查源中的任何终止空字符-它总是精确地复制num字节。
//为了避免溢出，目标和源参数所指向的数组的大小应该至少为num字节，并且不应该重叠(对于重叠内存块，memmove是一种更安全的方法)。


#include<stdio.h>
#include<stdlib.h>


void* my_memcpy_byte(void *dst, const void *src, int n)
{
	if (dst == NULL || src == NULL || n <= 0)
		return NULL;

	char * pdst = (char *)dst;
	char * psrc = (char *)src;

	if (pdst > psrc && pdst < psrc + n)
	{
		pdst = pdst + n - 1;
		psrc = psrc + n - 1;
		while (n--)
			*pdst-- = *psrc--;
	} else
	{
		while (n--)
			*pdst++ = *psrc++;
	}
	
	return dst;
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int dest[100] = { 0 };
	int n = 0;
	int k = 0;
	n = 5;
	
	my_memcpy_byte(dest, arr, n);
	
	system("pause");
	return 0;
}