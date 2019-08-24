#include "sort.h"
#include "Queue.h"


// 插入排序(升序)
void InsertSort(int* src, int n)
{
	int i, j;
	int tmp;
	for (i = 1; i < n; i++)
	{
		tmp = src[i];								// 保存待排序元素,
		//当 待排序元素比它前面的元素小时,用前面的元素 向后移 一位
		for (j = i; j > 0 && src[j-1] > tmp; j--)	
		{
			src[j] = src[j - 1];
		}
		src[j] = tmp;			//将 待排元素的值 赋给比较后合适的位置处
	}
}

// 希尔排序(升序)
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

// 归并排序
void MergeSort(int* src, int n)
{
	int* tmp = (int*)malloc(n*sizeof(int));
	DealMergeSort(src, tmp, 0, n - 1);

	free(tmp);
}
// 归并排序 具体实现
// src 源数组  start 排序起始位置(数组下标)
void DealMergeSort(int* src, int* tmp, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;				// 将数组通过下标分成两部分
	DealMergeSort(src, tmp, start, mid);		// 通过递归的方式,将数组一直分解成 单个元素 然后在一层一层向上归并
	DealMergeSort(src, tmp, mid + 1, end);

	int a = start;
	int b = mid + 1;
	int c = start;

	// 将分成两部分数组的值依次比较 较小的按顺序 依次 赋给 tmp数组
	// 比较时 将较小的值 赋给 tmp 后 下标移动,较大值的下标不动 等待下次比较
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
	// 此时 分成的两部分数组 有一部分值已经按顺序都赋给了 tmp 
	// 将另一部分 依次 赋给 tmp
	for (; a <= mid; a++,c++)
	{
		tmp[c] = src[a];
	}
	for (; b <= end; b++, c++)
	{
		tmp[c] = src[b];
	}

	// 将 已排好序的 数组 赋回原数组
	int i;
	for (i = start; i <= end; i++)
	{
		src[i] = tmp[i];
	}
}
// 交换函数
void SwapArgs(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
// 快排
void QuickSort(int* src, int n)
{
	DealQuickSort(src, 0, n - 1);
}
// 快排递归实现
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
// 双指针法实现快排 方法1:
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
		while (b >= 0 && src[b] >= src[a])	// 防止第一次取基准值 取到最小
		{
			flag ? a++ : b--;
		}
		
	}
	return flag ? b : a;
}
// 双指针法实现快排 方法二:
// 将所选取的基准值 保存起来
int DoublePointWay2(int* src, int start, int end)
{
	int a = start, b = end;
	int mid = (start + end) / 2;
	SwapArgs(src + mid, src + end);
	while (a < b)
	{
		while (a < b && src[a] <= src[end])				// 判断条件 没有 = 有相同值 会死循环  有 = 需要加上 边界校验 a < b
		{
			a++;
		}
		while (b > a && src[b] >= src[end])
		{
			b--;
		}
		//if (a == b && (a == 0 || a == end))			// 边界判断 由 a < end b>0 改为 a<b b>a后 不需要此处判断条件
		//	break;
		if (a < b)
			SwapArgs(src + a, src + b);

	}
	SwapArgs(src + a, src + end);
	return a;
}
// 挖坑法实现快排 
// 指定一个元素值作为 坑(基准)
// start 起初指向数组开头位置 循环向后寻找 比基准大的值 将大的值填入坑中
// end 起初指向数组末尾位置 循环向前寻找 比基准小的值 将小的值放到 start 位置
int HoleQuickSort(int* src, int start, int end)
{
	int a = start, b = end;
	int tmp = src[b];		// 选取坑(记录基准值)

	while (a < b)
	{
		while (a < b && src[a] <= tmp)		// 从起始位置向后遍历 遇到比基准值 大的元素 跳出遍历 将该元素放入坑中
		{
			a++;
		}
		src[b] = src[a];
		while (b > a && src[b] >= tmp)		// 从数组末尾向前遍历 遇到比基准值 小的元素 跳出遍历 
		{
			b--;
		}
		src[a] = src[b];					// b 的位置作为新坑
	}
	src[a] = tmp;	// 将所选取的 基准值 赋给他们的相遇点, 保证 tmp 左边都是比他小 右边都比他大
	return a;		// 返回中间位置
}
/*****************************************
	***选择排序***
1. 在元素集合中选取最小(最大)元素,如果该元素不是数组首(尾)元素,则与数组首(尾)元素交换
2. 接下来在剩余元素中重复该操作
	** 不稳定的排序
******************************************/
void SelectSort(int* src, int n)
{
	int start = 0;
	int end = n - 1;
	int min = 0;			// 记录 最小元素下标
	int i = 0;				// 记录每趟 比较起始元素下标
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

// 非递归 快速排序(队列实现)
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

