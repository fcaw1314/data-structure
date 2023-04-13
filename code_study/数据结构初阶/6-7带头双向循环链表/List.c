#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//�������
LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//��ӡ����
void LTPrint(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//��ʼ��
LTNode* LTInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next =phead;
	phead->prev =phead;
	return phead;
}

//β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/
	LTInsert(phead, x);
}

//βɾ
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	/*LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;

	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);*/
	LTErase(phead->prev);
}


//ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	//˳�򲻿��Ա�
	/*LTNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	newnode->prev = phead;
	phead->next = newnode;*/

	//˳����Ա�
	/*LTNode* newnode = BuyListNode(x);
	LTNode* first = phead->next;
	newnode->next = first;
	first->prev = newnode;
	newnode->prev = phead;
	phead->next = newnode;*/
	LTInsert(phead->next,x);
}

//ͷɾ
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	/*LTNode* first = phead->next;
	LTNode* second = first->next;
	free(first);
	phead->next = second;
	second->prev = phead;*/
	LTErase(phead->next);
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//��pos֮ǰ����x
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}

bool LTEmpty(LTNode* phead)
{
	assert(phead);
	/*if (phead->next == phead)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return phead->next == phead;
}

size_t LTSize(LTNode* phead)
{
	assert(phead);
	size_t size = 0;
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		++size;
		cur = cur->next;
	}

	return size;
}

void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);

		cur = next;
	}

	free(phead);
	//phead = NULL;
}