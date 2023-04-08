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
int main()
{
	TextSList3();
	return 0;
}