#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

// 初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;

}

// 销毁队列
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

// 队尾入队列
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

// 队头出队列
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

// 获取队列头部元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL && pq->tail == NULL;
}

//返回队列大小
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
