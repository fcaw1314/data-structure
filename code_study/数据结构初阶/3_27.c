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

	SLPopBack(&sl);
	SLPrint(&sl);
}



int main()
{
	TextSeqList1();
	return 0;
}