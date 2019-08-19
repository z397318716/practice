//ʵ��memcpy
//��num�ֽڵ�ֵ�Ӱ�Դָ���λ��ֱ�Ӹ��Ƶ���Ŀ��ָ����ڴ�顣
//Դָ���Ŀ��ָ����ָ��Ķ���ĵײ�������˺����޹أ���������ݵĶ����Ƹ�����
//���������Դ�е��κ���ֹ���ַ�-�����Ǿ�ȷ�ظ���num�ֽڡ�
//Ϊ�˱��������Ŀ���Դ������ָ�������Ĵ�СӦ������Ϊnum�ֽڣ����Ҳ�Ӧ���ص�(�����ص��ڴ�飬memmove��һ�ָ���ȫ�ķ���)��


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