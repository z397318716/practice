#include <stdio.h>

static void AdjustHeap(int* data, int size, int num)
{
	int cur = num;					//��ǰ����±�
	
	while (cur <=size)
	{
		//���Һ��ӽ��Ƚ�,�����ϴ��ӵ��±�
		if (data[cur * 2 + 1] > data[cur * 2 + 2])
			num = cur * 2 + 1;
		else
			num = cur * 2 + 2;
		if (data[cur] > data[num])
			break;
		else
		{
			int tmp = data[num];
			data[num] = data[cur];
			data[cur] = tmp;

			cur = num;
		}
	}
}

void PrintArray(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

void Swap(int a, int b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}
int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
//ɾ���Ѷ�Ԫ��֮��,�ѵĽṹ���ƻ�,�����¹����
//����:���Ѷ�Ԫ�����ĩβԪ�ػ���,size-1,ɾ�����Ѷ�Ԫ��,Ȼ��ԶѶ�Ԫ�ؽ���һ�����϶��µĶѵ���(����)
static void SwapHeap(int* data , int size)
{
	//hp->data[0] = hp->data[--hp->_size];	//�����һ��Ԫ���滻�Ѷ�Ԫ��,Ȼ��--,�Ѷ�Ԫ�ر�ɾ��
	data[0] = data[size];
	size--;

	int cur = 0;
	int left_child = cur * 2 + 1;
	int right_child = left_child + 1;
	while (left_child < size && Max(data[left_child], data[right_child]) > data[cur])
	{
		if (data[left_child] > data[right_child])
		{
			Swap(data[left_child], data[cur]);
			cur = left_child;
		} else
		{
			Swap(data[right_child], data[cur]);
			cur = right_child;
		}
	}
	left_child = cur * 2 + 1;
	right_child = left_child + 1;
}
//�κ�����ֻ��Ҫ��������(����Դ + ����)/(����Դ + ���ݽ���)
void HeapSortS(int* src, int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		AdjustHeap(src, n, i);
	}
	for (; n > 1; n--)
	{
		SwapHeap(src, n);
	}
}
int main()
{
	int data[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	HeapSortS(data, 10);
	PrintArray(data, 10);

	system("pause");
	return 0;
}
