//#include "heap.h"
//void AdjustHeap(Heap* hp,int n)
//{
//	int cur = n;					//��ǰ����±�
//	int num;						
//	while (cur <= hp->_size)
//	{
//		//���Һ��ӽ��Ƚ�,�����ϴ��ӵ��±�
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
//	int cur = hp->_size;				//�����²�������±�
//	int father = (hp->_size - 1) / 2;	//�����²�����ĸ��׽����±�
//	//��ǰ����븸�׽ڵ�Ƚ�,���ڸ��׽���򽻻�(����),��������
//	while (father >= 0)
//	{
//		if (hp->data[cur] > hp->data[father])
//		{
//			int tmp = hp->data[cur];
//			hp->data[cur] = hp->data[father];
//			hp->data[father] = tmp;
//			cur = father;
//			father = (cur - 1) / 2;			//�������ϱ���
//		}  else
//			break;
//	}
//}
//
////ɾ���Ѷ�Ԫ��֮��,�ѵĽṹ���ƻ�,�����¹����
////����:���Ѷ�Ԫ�����ĩβԪ�ػ���,size-1,ɾ�����Ѷ�Ԫ��,Ȼ��ԶѶ�Ԫ�ؽ���һ�����϶��µĶѵ���(����)
//void HeapPop(Heap* hp)
//{
//	//hp->data[0] = hp->data[--hp->_size];	//�����һ��Ԫ���滻�Ѷ�Ԫ��,Ȼ��--,�Ѷ�Ԫ�ر�ɾ��
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
//// ������
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
