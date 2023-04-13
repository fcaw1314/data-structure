#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"
//动态申请一个结点
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail:");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	return newnode;
}

//循环创建结点
SLTNode* CreateSList(int n)
{
	SLTNode* phead = NULL, * ptail = NULL;
	for (int i = 0; i < n; ++i)
	{
		SLTNode* newnode = BuySLTNode(i);
		if (phead == NULL)
		{
			phead = ptail = newnode;
		}
		else
		{
			ptail->next = newnode;
			ptail = newnode;
		}
	}
	return phead;
}
// 单链表打印
void SLTPrint(SLTNode *phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
		//找尾
	{
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

void SLTPopBack(SLTNode** pphead)
{
	assert(*pphead);

	if ((*pphead) == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		SLTNode* prev = NULL;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;

}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLTNode* nextNode = pos->next;
		pos->next = nextNode->next;
		free(nextNode);
	}
}
// 在pos之前插入x
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	if (pos == *pphead)
	{
		SLTPushFront(pphead,x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* newnode = BuySLTNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}
// 删除pos位置
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pos);
	if (pos==*pphead)
	{
		SLTPopFront(pphead);	
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

void SLTDestory(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur=next;
	}
	*pphead = NULL;
}