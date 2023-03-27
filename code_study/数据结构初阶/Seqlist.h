#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//��̬˳���
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;       // ��¼�洢���ٸ���Ч����
	int capacity;   // �ռ�������С 
}SL;

//��ʼ��
void SLInit(SL* ps);

//β��βɾ
void SLPushBack(SL* ps,SLDataType x);
void SLPopBack(SL* ps);

void SLDestory(SL* ps);

void SLPrint(SL* ps);