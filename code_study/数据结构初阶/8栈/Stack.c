#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//��ʼ��ջ
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		perror("realloc fail:");
		exit(-1);
	}

	ps->capacity = 0;
	ps->top = 0;
}

// ����ջ
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

// ��ջ
void StackPush(ST* ps, STDataType data)
{
	assert(ps);
	//����
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail:");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->top] = data;
	ps->top++;
}

// ɾ��ջ��Ԫ��
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top = 0;
}

// ��ȡջ��Ԫ��
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->top - 1;
}

int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}









