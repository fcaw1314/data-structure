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

//����
void SLDestory(SL* ps);

//��ʼ��
void SLPrint(SL* ps);


//ͷ��ͷɾ
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

// �м����ɾ��
// ��posλ�ò�������
void SLInsert(SL* ps, int pos, SLDataType x);
// ɾ��posλ������
void SLErase(SL* ps, int pos);

//int SLFind(SL* ps, SLDataType x);

// begin����x����ʼλ��
int SLFind(SL* ps, SLDataType x, int begin);




