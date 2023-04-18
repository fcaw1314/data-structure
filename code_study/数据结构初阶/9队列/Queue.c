#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

// ��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;

}

// ���ٶ���
void QueueDestroy(Queue* pq)
{
	assert(pq);
	Qnode* cur = pq->head;
	while (cur)
	{
		Qnode* del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

// ��β�����
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	Qnode* newnode = (Qnode*)malloc(sizeof(Qnode));
	if (newnode == NULL)
	{
		perror("malloc: fail");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

// ��ͷ������
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		Qnode* del = pq->head;
		pq->head = pq->head->next;
		free(del);
	}
	pq->size--;
}

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL && pq->tail == NULL;
}

//���ض��д�С
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
