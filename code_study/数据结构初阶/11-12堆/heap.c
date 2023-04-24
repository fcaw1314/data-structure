#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"


//堆的打印
void HeapPrint(HP* hph)
{
	for (int i = 0; i < hph->size; ++i)
	{
		printf("%d ", hph->a[i]);
	}
	printf("\n");
}

//堆的初始化
void HeapInit(HP* hph)
{
	assert(hph);
	hph->a = NULL;
	hph->capacity = hph->size = 0;
}

//堆的创建
void HeapCreat(HP* hph, HPDataType* a, int n)
{
	assert(hph);
	hph->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (hph->a == NULL)
	{
		perror("malloc fail:");
		exit(-1);
	}
	memcpy(hph->a, a, sizeof(HPDataType) * n);
	hph->size = hph->capacity = n;

	//建堆算法
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hph->a, n, i);
	}
}

//堆的销毁
void HeapDestory(HP* hph)
{
	assert(hph);
	free(hph->a);
	hph->a = NULL;
	hph->capacity = 0;
	hph->size = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向上调整
//child和parent都是下标
void AdjusUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// 堆的插入
void HeapPush(HP* hph, HPDataType x)
{
	assert(hph);
	//扩容
	if (hph->capacity == hph->size)
	{
		int newcapacity = hph->capacity == 0 ? 4 : hph->capacity * 2;
		HPDataType* tmp = (HPDataType* )realloc(hph->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail:");
			exit(-1);
		}
		hph->a = tmp;
		hph->capacity = newcapacity;
	}
	hph->a[hph->size] = x;
	hph->size++;

	//向上调整
	AdjusUp(hph->a, hph->size - 1);
}

//向下调整
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1< n && a[child + 1] < a[child])
		{
			child = child + 1;
		}
		//child 大于 parent 就交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆的删除
void HeapPop(HP* hph)
{
	assert(hph);
	assert(!HeapEmpty(hph));
	Swap(&hph->a[0], &hph->a[hph->size - 1]);

	hph->size--;
	AdjustDown(hph->a, hph->size, 0);
}

// 取堆顶的数据
HPDataType HeapTop(HP* hph)
{
	assert(hph);
	assert(hph->size > 0);
	return hph->a[0];
}

// 堆的数据个数
int HeapSize(HP* hph)
{
	assert(hph);
	return hph->size;
}

// 堆的判空
int HeapEmpty(HP* hph)
{
	assert(hph);
	return hph->size == 0;
}
