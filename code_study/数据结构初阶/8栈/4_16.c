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

	printf("size:%d\n", StackSize(&st)); // �����ĵײ�ʵ��
	//printf("size:%d\n", st.top);  // ����
	printf("size:%d\n", st.top + 1);  // ����


	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	//StackPop(&st);
	//printf("%d\n", StackTop(&st));

	StackDestroy(&st);
}
int main()
{

	return 0;
}