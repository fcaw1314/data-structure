#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//初始化栈
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

// 销毁栈
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

// 入栈
void StackPush(ST* ps, STDataType data)
{
	assert(ps);
	//扩容
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

// 删除栈顶元素
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top = 0;
}

// 获取栈顶元素
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









