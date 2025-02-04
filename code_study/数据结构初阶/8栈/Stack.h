#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

// 下面是定长的静态栈的结构，实际中一般不实用，所以我们主要实现下面的支持
//动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top; // 栈顶
	int capacity; // 容量
}ST;
// 初始化栈
void StackInit(ST* ps);

// 销毁栈
void StackDestroy(ST* ps);

// 入栈
void StackPush(ST* ps, STDataType data);

// 删除栈
void StackPop(ST* ps);

// 获取栈顶元素
STDataType StackTop(ST* ps);

// 获取栈中有效元素个数
int StackSize(ST* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool StackEmpty(ST* ps);



