#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"


void TextStack1()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	printf("%d\n", StackTop(&st));
	
	//printf("size:%d\n", StackSize(&st)); // 不关心底层实现
	//printf("size:%d\n", st.top);  // 关心
	//printf("size:%d\n", st.top + 1);  // 关心

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	printf("%d\n", StackTop(&st));

	//StackPop(&st);
	

	StackDestroy(&st);
}
int main()
{
	TextStack1();
	return 0;
}