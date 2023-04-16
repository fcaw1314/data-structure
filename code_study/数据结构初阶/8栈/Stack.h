#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

// �����Ƕ����ľ�̬ջ�Ľṹ��ʵ����һ�㲻ʵ�ã�����������Ҫʵ�������֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top; // ջ��
	int capacity; // ����
}ST;
// ��ʼ��ջ
void StackInit(ST* ps);

// ��ջ
void StackPush(ST* ps, STDataType data);

// ɾ��ջ
void StackPop(ST* ps);

// ��ȡջ��Ԫ��
STDataType StackTop(ST* ps);

// ��ȡջ����ЧԪ�ظ���
int StackSize(ST* ps);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(ST* ps);

// ����ջ
void StackDestroy(ST* ps);

