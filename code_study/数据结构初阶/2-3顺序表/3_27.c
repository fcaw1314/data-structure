#define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"

TextSeqList1()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(&sl);


	SLDestory(&sl);
}

TextSeqList2()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	SLPushFront(&sl, 7);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);
	SLDestory(&sl);

}

TextSeqList3()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(&sl);
	SLInsert(&sl, 3, 100);
	SLPrint(&sl);
	

	
	 SLFind(&sl, 100, 0);
	/*if (pos != -1)
	{
		SLErase(&sl, pos);
	}*/
	 SLErase(&sl,2);
	 SLPrint(&sl);
	SLDestory(&sl);

}
int main()
{
	TextSeqList3();
	return 0;
}