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

void SLDestory(SL* ps);

void SLPrint(SL* ps);