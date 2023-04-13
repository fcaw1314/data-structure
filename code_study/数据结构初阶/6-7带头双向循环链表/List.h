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

//�������
LTNode* BuyListNode(LTDataType x);

//��ʼ��
LTNode* LTInit();

//β��
void LTPushBack(LTNode* phead, LTDataType x);

//βɾ
void LTPopBack(LTNode* phead);

//ͷ��
void LTPushFront(LTNode* phead, LTDataType x);

//ͷɾ
void LTPopFront(LTNode* phead);

//��ӡ
void LTPrint(LTNode* phead);

//��pos֮ǰ����x
void LTInsert(LTNode* pos, LTDataType x);

//����
LTNode* LTFind(LTNode* phead, LTDataType x);

//ɾ��posλ��
void LTErase(LTNode* pos);

bool LTEmpty(LTNode* phead);

size_t LTSize(LTNode* phead);

void LTDestroy(LTNode* phead);