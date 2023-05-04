#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//打印
void PrintArray(int* a, int n);

//插入排序
void InsertSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//堆排序
void HeapSort(int* a, int n);

//向下调整
void AdjustDown(int* a, int n, int parent);

//交换函数
void Swap(int* p1, int* p2);

//冒泡排序
void BubbleSort(int* a, int n);

//快速排序
void QuickSort(int* a,int begin , int end);

//快速排序(非递归)
void QuickSortNonR(int* a, int begin, int end);