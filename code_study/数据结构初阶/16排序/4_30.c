#define _CRT_SECURE_NO_WARNINGS 1	
#include "Sort.h"

void InsertSortText()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void ShellSortText()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	InsertSortText();
	ShellSortText();
	return 0;
}