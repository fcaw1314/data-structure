#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//��ӡ
void PrintArray(int* a, int n);

//��������
void InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

//������
void HeapSort(int* a, int n);

//���µ���
void AdjustDown(int* a, int n, int parent);

//��������
void Swap(int* p1, int* p2);

//ð������
void BubbleSort(int* a, int n);

//��������
void QuickSort(int* a,int begin , int end);

//��������(�ǵݹ�)
void QuickSortNonR(int* a, int begin, int end);

//�鲢����
void MergeSort(int* a, int n);

//�鲢�ǵݹ�����
void MergeSortNonR(int* a, int n);

//��������
void CountSort(int* a, int n);