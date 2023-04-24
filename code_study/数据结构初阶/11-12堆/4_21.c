#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"

void Heap()
{
	int arry[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HP hph;
	HeapInit(&hph);
	HeapPrint(&hph);
	for (int i = 0; i < sizeof(arry) / sizeof(int); i++)
	{
		HeapPush(&hph, arry[i]);
	}
	HeapPrint(&hph);
	HeapPush(&hph, 100);
	HeapPrint(&hph);
	HeapPop(&hph);
	HeapPrint(&hph);
	HeapDestory(&hph);
}

void TestHeap2()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
	{
		HeapPush(&hp, array[i]);
	}
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);

	//while (!HeapEmpty(&hp))
	//{
	//	printf("%d ", HeapTop(&hp));
	//	HeapPop(&hp);
	//}

	HeapDestory(&hp);
}


void TestHeap3()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HP hp;
	HeapCreat(&hp, array, sizeof(array) / sizeof(int));
	HeapPrint(&hp);

	HeapDestory(&hp);
}

void HeapSort(HPDataType* a,int n)
{
	//这里采用向下调整O(n)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)	
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	
	//N*O(m=n)
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
void TestHeap4()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapSort(array, sizeof(array) / sizeof(HPDataType));
	for (int i = 0; i < sizeof(array) / sizeof(HPDataType); i++)
	{
		printf("%d ", array[i]);
	}
}

void TestHeap5()
{
	int minHeap[5];
	FILE* fp = fopen("Data.txt", "r");
	if(fp == NULL)
	{
		perror("fopen fail:");
		return;
	}
	int k = 5;
	for (int i = 0; i < k; i++)
	{
		//读文件
		fscanf(fp, "%d", &minHeap[i]);
	}
	//建小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(minHeap, k, i);
	}
	int val = 0;
	while (fscanf(fp, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			AdjustDown(minHeap, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	printf("\n");
	fclose(fp);
}


int main()
{
	TestHeap4();
	return 0;
}