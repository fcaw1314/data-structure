#define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"

SLCheckCapacity(SL* ps)
{
	//扩容
	assert(ps);

	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail :");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}

//尾插
void SLPushBack(SL* ps,SLDataType x)
{/*
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;*/
	SLInsert(ps, ps->size,x);
}

//打印
void SLPrint(SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//初始化
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//销毁
void SLDestory(SL* ps)
{
	assert(ps);
	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->capacity = ps->size = 0;
	}
}

//尾删
void SLPopBack(SL* ps)
{
	/*assert(ps);
	assert(ps->size > 0);
	ps->size--;*/
	SLErase(ps, ps->size - 1);
}

//头插
void SLPushFront(SL* ps, SLDataType x)
{
	//SLCheckCapacity(ps);
	////挪动数据
	//int end = ps->size - 1;
	//while (end>=0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->size++;
	SLInsert(ps, 0, x);
}

void SLPopFront(SL* ps)
{
	//assert(ps);
	//assert(ps->size > 0);
	//int begin = 1;
	//while (begin<ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}
	//ps->size--;
	SLErase(ps, 0);
}

//从中间位置插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos <= ps->size);
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	while (pos <= end)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

// 删除pos位置数据
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos < ps->size);
	int begin = pos;
	int end = ps->size - 1;
	while (begin <= end)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}

// begin查找x的起始位置
int SLFind(SL* ps, SLDataType x, int begin)
{
	assert(ps);
	for (int i=0 ; i < ps->size; i++)
	{
		if (x == ps->a[i])
		{
			printf("%d\n", i);
			return i;
		}
	}
	return -1;
}