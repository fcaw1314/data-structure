#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//动态顺序表
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;       // 记录存储多少个有效数据
	int capacity;   // 空间容量大小 
}SL;

//初始化
void SLInit(SL* ps);

//尾插尾删
void SLPushBack(SL* ps,SLDataType x);
void SLPopBack(SL* ps);

//销毁
void SLDestory(SL* ps);

//初始化
void SLPrint(SL* ps);


//头插头删
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

// 中间插入删除
// 在pos位置插入数据
void SLInsert(SL* ps, int pos, SLDataType x);
// 删除pos位置数据
void SLErase(SL* ps, int pos);

//int SLFind(SL* ps, SLDataType x);

// begin查找x的起始位置
int SLFind(SL* ps, SLDataType x, int begin);




