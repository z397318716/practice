#include "sort.h"
#include "Queue.h"


// ��������(����)
void InsertSort(int* src, int n)
{
	int i, j;
	int tmp;
	for (i = 1; i < n; i++)
	{
		tmp = src[i];								// ���������Ԫ��,
		//�� ������Ԫ�ر���ǰ���Ԫ��Сʱ,��ǰ���Ԫ�� ����� һλ
		for (j = i; j > 0 && src[j-1] > tmp; j--)	
		{
			src[j] = src[j - 1];
		}
		src[j] = tmp;			//�� ����Ԫ�ص�ֵ �����ȽϺ���ʵ�λ�ô�
	}
}

// ϣ������(����)
void ShellSort(int* src, int n)
{
	int i, j, k;
	int gap, tmp;
	for (gap = n / 2; gap; gap /= 2)
	{
		for (k = 0; k < gap; k++)
		{
			for (i = gap + k; i < n; i += gap)
			{
				tmp = src[i];
				for (j = i; j >= gap && src[j - gap] > tmp; j--)
				{
					src[j] = src[j - gap];
				}
				src[j] = tmp;
			}
		}
	}
}

// �鲢����
void MergeSort(int* src, int n)
{
	int* tmp = (int*)malloc(n*sizeof(int));
	DealMergeSort(src, tmp, 0, n - 1);

	free(tmp);
}
// �鲢���� ����ʵ��
// src Դ����  start ������ʼλ��(�����±�)
void DealMergeSort(int* src, int* tmp, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;				// ������ͨ���±�ֳ�������
	DealMergeSort(src, tmp, start, mid);		// ͨ���ݹ�ķ�ʽ,������һֱ�ֽ�� ����Ԫ�� Ȼ����һ��һ�����Ϲ鲢
	DealMergeSort(src, tmp, mid + 1, end);

	int a = start;
	int b = mid + 1;
	int c = start;

	// ���ֳ������������ֵ���αȽ� ��С�İ�˳�� ���� ���� tmp����
	// �Ƚ�ʱ ����С��ֵ ���� tmp �� �±��ƶ�,�ϴ�ֵ���±겻�� �ȴ��´αȽ�
	while (a <= mid && b <= end)
	{
		if (src[a] < src[b])
		{
			tmp[c] = src[a];
			a++;
		}
		else
		{
			tmp[c] = src[b];
			b++;
		}
		c++;
	}
	// ��ʱ �ֳɵ����������� ��һ����ֵ�Ѿ���˳�򶼸����� tmp 
	// ����һ���� ���� ���� tmp
	for (; a <= mid; a++,c++)
	{
		tmp[c] = src[a];
	}
	for (; b <= end; b++, c++)
	{
		tmp[c] = src[b];
	}

	// �� ���ź���� ���� ����ԭ����
	int i;
	for (i = start; i <= end; i++)
	{
		src[i] = tmp[i];
	}
}
// ��������
void SwapArgs(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
// ����
void QuickSort(int* src, int n)
{
	DealQuickSort(src, 0, n - 1);
}
// ���ŵݹ�ʵ��
void DealQuickSort(int* src, int start, int end)
{
	int mid;
	if (start + 8 < end)
	{
		//mid = DoublePointWay1(src, start, end);
		//mid = DoublePointWay2(src, start, end);
		//mid = HoleQuickSort(src, start, end);
		mid = HoareWay(src, start, end);
		
		
		DealQuickSort(src, start, mid - 1);
		DealQuickSort(src, mid + 1, end);
	}
	else
	{
		InsertSort(src + start, end - start + 1);
	}
}
// ˫ָ�뷨ʵ�ֿ��� ����1:
int DoublePointWay1(int* src, int start, int end)
{
	int a = start;
	int b = end;
	int flag = 1;

	while (src[b] > src[a])
	{
		b--;
	}

	while (a < b)
	{
		/*while (src[b] < src[a])
		{
			b--;
		}
		SwapArgs(src + b, src + a);
		while (src[a] < src[b])
		{
			a++;
		}
		SwapArgs(src + a, src + b);*/
		SwapArgs(src + b, src + a);
		flag = !flag;
		while (b >= 0 && src[b] >= src[a])	// ��ֹ��һ��ȡ��׼ֵ ȡ����С
		{
			flag ? a++ : b--;
		}
		
	}
	return flag ? b : a;
}
// ˫ָ�뷨ʵ�ֿ��� ������:
// ����ѡȡ�Ļ�׼ֵ ��������
int DoublePointWay2(int* src, int start, int end)
{
	int a = start, b = end;
	int mid = (start + end) / 2;
	SwapArgs(src + mid, src + end);
	while (a < b)
	{
		while (a < b && src[a] <= src[end])				// �ж����� û�� = ����ֵͬ ����ѭ��  �� = ��Ҫ���� �߽�У�� a < b
		{
			a++;
		}
		while (b > a && src[b] >= src[end])
		{
			b--;
		}
		//if (a == b && (a == 0 || a == end))			// �߽��ж� �� a < end b>0 ��Ϊ a<b b>a�� ����Ҫ�˴��ж�����
		//	break;
		if (a < b)
			SwapArgs(src + a, src + b);

	}
	SwapArgs(src + a, src + end);
	return a;
}
// �ڿӷ�ʵ�ֿ��� 
// ָ��һ��Ԫ��ֵ��Ϊ ��(��׼)
// start ���ָ�����鿪ͷλ�� ѭ�����Ѱ�� �Ȼ�׼���ֵ �����ֵ�������
// end ���ָ������ĩβλ�� ѭ����ǰѰ�� �Ȼ�׼С��ֵ ��С��ֵ�ŵ� start λ��
int HoleQuickSort(int* src, int start, int end)
{
	int a = start, b = end;
	int tmp = src[b];		// ѡȡ��(��¼��׼ֵ)

	while (a < b)
	{
		while (a < b && src[a] <= tmp)		// ����ʼλ�������� �����Ȼ�׼ֵ ���Ԫ�� �������� ����Ԫ�ط������
		{
			a++;
		}
		src[b] = src[a];
		while (b > a && src[b] >= tmp)		// ������ĩβ��ǰ���� �����Ȼ�׼ֵ С��Ԫ�� �������� 
		{
			b--;
		}
		src[a] = src[b];					// b ��λ����Ϊ�¿�
	}
	src[a] = tmp;	// ����ѡȡ�� ��׼ֵ �������ǵ�������, ��֤ tmp ��߶��Ǳ���С �ұ߶�������
	return a;		// �����м�λ��
}
/*****************************************
	***ѡ������***
1. ��Ԫ�ؼ�����ѡȡ��С(���)Ԫ��,�����Ԫ�ز���������(β)Ԫ��,����������(β)Ԫ�ؽ���
2. ��������ʣ��Ԫ�����ظ��ò���
	** ���ȶ�������
******************************************/
void SelectSort(int* src, int n)
{
	int start = 0;
	int end = n - 1;
	int min = 0;			// ��¼ ��СԪ���±�
	int i = 0;				// ��¼ÿ�� �Ƚ���ʼԪ���±�
	while (start <= end)
	{
		i = start;
		min = i;
		while (i <= end)
		{
			if (src[i] < src[min])
			{
				min = i;
				SwapArgs(src + i,src + min);
				//min = i;
			}
			i++;
		}
		SwapArgs(src + start,src + min);
		start++;

	}
}

int HoareWay(int*src, int start, int end)
{
	int a = start + 1;
	int b = end - 2;
	int mid = (start + end) / 2;
	if (src[start] > src[mid])
	{
		SwapArgs(src + start, src + mid);
	}
	if (src[mid] > src[end])
	{
		SwapArgs(src + mid, src + end);
	}
	if (src[start] > src[mid])
	{
		SwapArgs(src + start, src + mid);
	}

	if (end - start <= 2)					//
		return mid;
	
	
	SwapArgs(src + mid, src + end - 1);
	int tmp = src[end - 1];
	
	while (a < b)
	{

		while (a < b && src[a] <= tmp)
		{
			a++;
		}
		src[b] = src[a];
		while (b > start && src[b] >= tmp)
		{
			b--;
		}
		src[a] = src[b];
	}
	src[a] = tmp;
	return a;
}

// �ǵݹ� ��������(����ʵ��)
void QuickSortNonR(int* src, int n)
{
	int start = 0, end = n - 1;
	int mid;
	Queue qu;
	QueueInit(&qu);

	QueuePush(&qu, 0);
	QueuePush(&qu, n - 1);
	while (!QueueIsEmpty(&qu))
	{
		start = QueueTop(&qu);
		QueuePop(&qu);
		end = QueueTop(&qu);
		QueuePop(&qu);
		mid = HoareWay(src, start, end);

		if (start < end - 1)
		{
			QueuePush(&qu, start);
			QueuePush(&qu, mid);
		}
		if (mid + 1 < end - 1)
		{
			QueuePush(&qu, mid + 1);
			QueuePush(&qu, end);
		}
	}
	QueueDestroy(&qu);
}

