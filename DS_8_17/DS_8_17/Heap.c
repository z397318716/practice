#include "Heap.h"



void Swap(int a, int b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

//��һ�������е� n �����,��ʵ��;
// 1.������
// 2.������
// 3.ɾ����
// 4.��������

//�����µ�������
void Adjustdown(Heap* hp, int i)
{
	
	int  cur = i;				//���浱ǰ����±�
	int num;					//���溢�ӽ���нϴ�����±�
	while (cur <= hp->_size)
	{
		int _left = cur * 2 + 1;		//��ǰ�������ӽ���±�
		int _right = cur * 2 + 2;
		//�������Һ��ӽ��ϴ�����±�
		if (hp->_data[_left] > hp->_data[_right])
		{
			num = _left;
		}  else
			num = _right;
		//�Ƚϸ��׽ڵ��뺢�ӽ���С,С���򽻻�
		if (hp->_data[cur] < hp->_data[num])
		{
			Swap(hp->_data[cur], hp->_data[num]);
			cur = num;
		}  else
			break;
	}
}
//�ѳ�ʼ��
void HeapInit(Heap* hp, int* arr, int n)
{
	hp->_size = n;
	hp->_capacity = n * 2;
	hp->_data = (HPDataType*)malloc(n * sizeof(HPDataType));
	int num = hp->_size / 2 - 1;		//�ѵ�����һ��Ҷ�ӽ���±�
	for (int i = 0; i < n; i++)
	{
		hp->_data[i] = arr[i];
	}
	for (; num > 0; num--)
	{
		Adjustdown(hp, num);
	}
}
//ɾ���Ѷ�Ԫ��
void HeapPop(Heap* hp)
{
	hp->_data[0] = hp->_data[hp->_size];
	hp->_size--;
	int cur = 0;

	//ɾ���Ѷ�Ԫ�غ�,�ѵĽṹ���ƻ�,�������µ���;
	Adjustdown(hp, cur);
}
HPDataType HeapTop(Heap* hp)
{
	return hp->_data[0];
}

//�Ҷ��е� n �����
HPDataType Heap_num(Heap* hp,int n)
{
	for (int i = 0; i < n; i++)
	{
		HeapPop(hp);
	}
	return HeapTop;
}