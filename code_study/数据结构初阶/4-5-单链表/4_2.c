#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"
TextSList1()
{
	SLTNode* plist = CreateSList(10);
	SLTPrint(plist);

}

TextSList2()
{
	SLTNode* plist =NULL;
	SLTPushBack(&plist, 100);
	SLTPushBack(&plist, 200);
	SLTPushBack(&plist, 300);
	SLTPushBack(&plist, 400);

	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);


}

TextSList3()
{
	SLTNode* plist = NULL;
	SLTPushFront(&plist, 100);
	SLTPushFront(&plist, 200);
	SLTPushFront(&plist,500);
	SLTPushFront(&plist, 800);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);

}

TextSList4()
{
	SLTNode* plist = NULL;
	SLTPushFront(&plist, 100);
	SLTPushFront(&plist, 200);
	SLTPushFront(&plist, 500);
	SLTPushFront(&plist, 800);
	SLTPrint(plist);
	SLTNode* pos = SLTFind(plist,200);
	if (pos)
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}
}

TextSList5()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 100);
	SLTPushBack(&plist, 200);
	SLTPushBack(&plist, 300);
	SLTPushBack(&plist, 400);
	SLTPrint(plist);
	SLTNode* p = SLTFind(plist, 200);
	if (p)
	{
		SLTInsertAfter(p, 2);
		printf("找到了\n");
		SLTPrint(plist);
		SLTEraseAfter(p);
		SLTPrint(plist);
		SLTErase(&plist, p);
		SLTPrint(plist);
		
	}
	else
	{
		printf("找不到\n");
	}

}
TextSList6()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 100);
	SLTPushBack(&plist, 200);
	SLTPushBack(&plist, 300);
	SLTPushBack(&plist, 400);
	SLTPrint(plist);
	SLTNode* p = SLTFind(plist, 200);
	if (p)
	{
		SLTInsert(&plist, p, 1);
		SLTPrint(plist);
		SLTDestory(&plist);
		SLTPrint(plist);
	}
	else
	{
		printf("找不到了\n");
	}
}

int main()
{
	TextSList6();
	return 0;
}