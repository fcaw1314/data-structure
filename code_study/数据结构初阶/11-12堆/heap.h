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

//�ѵĳ�ʼ��
void HeapInit(HP* hph);

//�ѵĴ���
void HeapCreat(HP* hph, HPDataType* a, int n);

//�ѵ�����
void HeapDestory(HP* hph);

//�ѵĴ�ӡ
void HeapPrint(HP* hph);

// �ѵĲ���
void HeapPush(HP * hph, HPDataType x);

// �ѵ�ɾ��
void HeapPop(HP* hph);

// ȡ�Ѷ�������
HPDataType HeapTop(HP* hph);

// �ѵ����ݸ���
int HeapSize(HP* hph);

// �ѵ��п�
int HeapEmpty(HP* hph);

//���ϵ���
//child��parent�����±�
void AdjusUp(HPDataType* a, int child);

//���µ���
void AdjustDown(HPDataType* a, int n, int parent);

void Swap(HPDataType* p1, HPDataType* p2);
