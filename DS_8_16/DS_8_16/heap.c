//#include "heap.h"
//void AdjustHeap(Heap* hp,int n)
//{
//	int cur = n;					//当前结点下标
//	int num;						
//	while (cur <= hp->_size)
//	{
//		//左右孩子结点比较,保留较大孩子的下标
//		if (hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2])
//			num = cur * 2 + 1;
//		else
//			num = cur * 2 + 2;
//		if (hp->data[cur] > hp->data[num])
//			break;
//		else
//		{
//			int tmp = hp->data[num];
//			hp->data[num] = hp->data[cur];
//			hp->data[cur] = tmp;
//
//			cur = num;
//		}
//	}
//}
//void HeapInit(Heap* hp, HPDataType* a, int n)
//{
//	hp->_capacity = n * 2;
//	hp->_size = n;
//	hp->data = (HPDataType*)calloc(hp->_capacity, sizeof(HPDataType));
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		hp->data[i] = a[i];
//	}
//	for (i = n / 2 - 1; i >= 0; i--)
//	{
//		AdjustHeap(&hp, i);
//	}
//}
//
//
//void HeapDestory(Heap* hp)
//{
//	free(hp->data);
//	hp->_size = 0;
//}
//void HeapPush(Heap* hp, HPDataType x)
//{
//	if (hp->_size == hp->_capacity)
//	{
//		hp->data = (HPDataType*)realloc(hp->data, hp->_size*sizeof(HPDataType));
//	}
//	hp->data[hp->_size] = x;
//	hp->_size++;
//	int cur = hp->_size;				//保存新插入结点的下标
//	int father = (hp->_size - 1) / 2;	//保存新插入结点的父亲结点的下标
//	//当前结点与父亲节点比较,大于父亲结点则交换(上溢),否则跳出
//	while (father >= 0)
//	{
//		if (hp->data[cur] > hp->data[father])
//		{
//			int tmp = hp->data[cur];
//			hp->data[cur] = hp->data[father];
//			hp->data[father] = tmp;
//			cur = father;
//			father = (cur - 1) / 2;			//继续向上遍历
//		}  else
//			break;
//	}
//}
//
////删除堆顶元素之后,堆的结构被破坏,需重新构造堆
////方法:将堆顶元素与堆末尾元素互换,size-1,删除掉堆顶元素,然后对堆顶元素进行一个自上而下的堆调整(下滤)
//void HeapPop(Heap* hp)
//{
//	//hp->data[0] = hp->data[--hp->_size];	//用最后一个元素替换堆顶元素,然后--,堆顶元素被删除
//	hp->data[0] = hp->data[hp->_size ];
//	hp->_size--;
//
//	int cur = 0;
//	int left_child = cur * 2 + 1;
//	int right_child = left_child + 1;
//	while (left_child < hp->_size && max(hp->data[left_child],hp->data[right_child]) > hp->data[cur])
//	{
//		if (hp->data[left_child] > hp->data[right_child])
//		{
//			swap(hp->data[left_child], hp->data[cur]);
//			cur = left_child;
//		} else
//		{
//			swap(hp->data[right_child], hp->data[cur]);
//			cur = right_child;
//		}
//	}
//	left_child = cur * 2 + 1;
//	right_child = left_child + 1;
//}
//HPDataType HeapTop(Heap* hp)
//{
//	return hp->data[0];
//}
//int HeapSize(Heap* hp)
//{
//	return hp->_size;
//}
//int HeapEmpty(Heap* hp);
//// 堆排序
//void HeapSort(Heap* hp)
//{
//	int tmp = hp->_size;
//
//	while (hp->_size > 1)
//	{
//		HeapPop(hp);
//	}
//	hp->_size = tmp;
//}
//void TestHeap();
