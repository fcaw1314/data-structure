#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"


//�ѵĴ�ӡ
void HeapPrint(HP* hph)
{
	for (int i = 0; i < hph->size; ++i)
	{
		printf("%d ", hph->a[i]);
	}
	printf("\n");
}

//�ѵĳ�ʼ��
void HeapInit(HP* hph)
{
	assert(hph);
	hph->a = NULL;
	hph->capacity = hph->size = 0;
}

//�ѵĴ���
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

	//�����㷨
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hph->a, n, i);
	}
}

//�ѵ�����
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

//���ϵ���
//child��parent�����±�
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

// �ѵĲ���
void HeapPush(HP* hph, HPDataType x)
{
	assert(hph);
	//����
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

	//���ϵ���
	AdjusUp(hph->a, hph->size - 1);
}

//���µ���
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1< n && a[child + 1] < a[child])
		{
			child = child + 1;
		}
		//child ���� parent �ͽ���
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

// �ѵ�ɾ��
void HeapPop(HP* hph)
{
	assert(hph);
	assert(!HeapEmpty(hph));
	Swap(&hph->a[0], &hph->a[hph->size - 1]);

	hph->size--;
	AdjustDown(hph->a, hph->size, 0);
}

// ȡ�Ѷ�������
HPDataType HeapTop(HP* hph)
{
	assert(hph);
	assert(hph->size > 0);
	return hph->a[0];
}

// �ѵ����ݸ���
int HeapSize(HP* hph)
{
	assert(hph);
	return hph->size;
}

// �ѵ��п�
int HeapEmpty(HP* hph)
{
	assert(hph);
	return hph->size == 0;
}
