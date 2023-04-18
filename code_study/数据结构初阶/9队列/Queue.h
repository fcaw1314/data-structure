#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int QDataType;

// ��ʽ�ṹ����ʾ����
typedef struct QueueNode
{
	QDataType data;
	struct Queue* next;
}Qnode;

// ���еĽṹ
typedef struct Queue
{
	Qnode* head;
	Qnode* tail;
	int size;
}Queue;

// ��ʼ������
void QueueInit(Queue* pq);

// ���ٶ���
void QueueDestroy(Queue* pq);

// ��β�����
void QueuePush(Queue* pq, QDataType x);

// ��ͷ������
void QueuePop(Queue* pq);

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq);

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* pq);

//���ض��д�С
int QueueSize(Queue* pq);
