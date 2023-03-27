#define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"


//Î²²å
void SLPushBack(SL* ps,SLDataType x)
{
	//À©ÈÝ
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
	ps->a[ps->size] = x;
	ps->size++;

}

void SLPrint(SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//³õÊ¼»¯
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


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

void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}