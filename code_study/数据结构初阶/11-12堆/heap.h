#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int HPDataType;
typedef struct heap
{
	HPDataType* a;
	int capacity;
	int size;
}HP;

//堆的初始化
void HeapInit(HP* hph);

//堆的创建
void HeapCreat(HP* hph, HPDataType* a, int n);

//堆的销毁
void HeapDestory(HP* hph);

//堆的打印
void HeapPrint(HP* hph);

// 堆的插入
void HeapPush(HP * hph, HPDataType x);

// 堆的删除
void HeapPop(HP* hph);

// 取堆顶的数据
HPDataType HeapTop(HP* hph);

// 堆的数据个数
int HeapSize(HP* hph);

// 堆的判空
int HeapEmpty(HP* hph);

//向上调整
//child和parent都是下标
void AdjusUp(HPDataType* a, int child);

//向下调整
void AdjustDown(HPDataType* a, int n, int parent);

void Swap(HPDataType* p1, HPDataType* p2);
