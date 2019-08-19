#include "Heap.h"



void Swap(int a, int b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

//求一个数组中第 n 大的数,堆实现;
// 1.建立堆
// 2.堆排序
// 3.删除根
// 4.重新排序

//堆向下调整函数
void Adjustdown(Heap* hp, int i)
{
	
	int  cur = i;				//保存当前结点下标
	int num;					//保存孩子结点中较大结点的下标
	while (cur <= hp->_size)
	{
		int _left = cur * 2 + 1;		//当前结点的左孩子结点下标
		int _right = cur * 2 + 2;
		//保留左右孩子结点较大结点的下标
		if (hp->_data[_left] > hp->_data[_right])
		{
			num = _left;
		}  else
			num = _right;
		//比较父亲节点与孩子结点大小,小于则交换
		if (hp->_data[cur] < hp->_data[num])
		{
			Swap(hp->_data[cur], hp->_data[num]);
			cur = num;
		}  else
			break;
	}
}
//堆初始化
void HeapInit(Heap* hp, int* arr, int n)
{
	hp->_size = n;
	hp->_capacity = n * 2;
	hp->_data = (HPDataType*)malloc(n * sizeof(HPDataType));
	int num = hp->_size / 2 - 1;		//堆倒数第一个叶子结点下标
	for (int i = 0; i < n; i++)
	{
		hp->_data[i] = arr[i];
	}
	for (; num > 0; num--)
	{
		Adjustdown(hp, num);
	}
}
//删除堆顶元素
void HeapPop(Heap* hp)
{
	hp->_data[0] = hp->_data[hp->_size];
	hp->_size--;
	int cur = 0;

	//删除堆顶元素后,堆的结构被破坏,重新向下调整;
	Adjustdown(hp, cur);
}
HPDataType HeapTop(Heap* hp)
{
	return hp->_data[0];
}

//找堆中第 n 大的数
HPDataType Heap_num(Heap* hp,int n)
{
	for (int i = 0; i < n; i++)
	{
		HeapPop(hp);
	}
	return HeapTop;
}