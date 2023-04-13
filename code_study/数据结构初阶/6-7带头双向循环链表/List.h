#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

//创建结点
LTNode* BuyListNode(LTDataType x);

//初始化
LTNode* LTInit();

//尾插
void LTPushBack(LTNode* phead, LTDataType x);

//尾删
void LTPopBack(LTNode* phead);

//头插
void LTPushFront(LTNode* phead, LTDataType x);

//头删
void LTPopFront(LTNode* phead);

//打印
void LTPrint(LTNode* phead);

//在pos之前插入x
void LTInsert(LTNode* pos, LTDataType x);

//查找
LTNode* LTFind(LTNode* phead, LTDataType x);

//删除pos位置
void LTErase(LTNode* pos);

bool LTEmpty(LTNode* phead);

size_t LTSize(LTNode* phead);

void LTDestroy(LTNode* phead);