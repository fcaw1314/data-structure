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

	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}

	HeapDestroy(&hp);
}

int main()
{
	TestHeap2();
	return 0;
}