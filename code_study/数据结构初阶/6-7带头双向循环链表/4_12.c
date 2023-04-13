#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void TestList1()
{
	LTNode* phead = LTInit();
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPushBack(phead, 5);
	LTPrint(phead);
	LTPopBack(phead);
	LTPrint(phead);
	LTPushFront(phead, 100);
	LTPrint(phead);
	LTPopFront(phead);
	LTPrint(phead);

}

void TestList2()
{
	LTNode* phead = LTInit();
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPushBack(phead, 5);
	LTPrint(phead);
	LTPopFront(phead);
	LTPrint(phead);
}

void TestList3()
{
	LTNode* phead = LTInit();
	LTPushFront(phead, 1);
	LTPushFront(phead, 3);
	LTPushFront(phead, 5);
	LTPushFront(phead, 7);
	LTPushFront(phead, 9);
	LTPrint(phead);
	LTNode* pos = LTFind(phead, 3);
	if (pos)
	{
		LTInsert(pos, 100);
	}
	LTPrint(phead);
	LTErase(pos);
	LTPrint(phead);


}


void TestList4()
{
	LTNode* phead = LTInit();
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPrint(phead);
	LTPushFront(phead, 7);
	LTPushFront(phead, 8);
	LTPushFront(phead, 9);
	LTPushFront(phead, 10);
	LTPushFront(phead, 11);
	LTPrint(phead);

}
void TestList5()
{
	LTNode* phead = LTInit();
	LTPushFront(phead, 1);
	LTPushFront(phead, 2);
	LTPushFront(phead, 3);
	LTPushFront(phead, 4);
	LTPushFront(phead, 5);
	LTPrint(phead);

	LTNode* pos = LTFind(phead, 3);
	if (pos)
	{
		pos->data *= 10;
	}
	LTPrint(phead);

	LTDestroy(phead);
	phead = NULL;
}
int main()
{
	TestList5();
	return 0;
}